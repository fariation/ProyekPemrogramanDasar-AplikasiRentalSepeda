#include "Register.h"
#include <iostream>
#include <limits>
using namespace std;

void Registrasi::registrasiMahasiswa()
{
    string Nama, NIM, Fakultas, Telepon;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Nama: ";
    getline(cin, Nama);

    cout << "NIM: ";
    cin >> NIM;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Fakultas: ";
    getline(cin, Fakultas);

    cout << "Telepon: ";
    getline(cin, Telepon);

    data.emplace_back(Nama, NIM, Fakultas, Telepon);

    cout << "Mahasiswa berhasil didaftarkan!\n";
}

void Registrasi::lihatDataMahasiswa()
{
    if (data.empty())
    {
        cout << "Belum ada data mahasiswa.\n";
        return;
    }

    cout << "\n===== DATA MAHASISWA =====\n";
    for (const auto &m : data)
    {
        cout << "Nama       : " << m.getNama() << endl;
        cout << "NIM        : " << m.getNIM() << endl;
        cout << "Fakultas   : " << m.getFakultas() << endl;
        cout << "Telepon    : " << m.getTelepon() << endl;
        cout << "------------------------------\n";
    }
}

void Registrasi::editDataMahasiswa()
{
    string NIM;
    cout << "Masukkan NIM mahasiswa yang ingin diedit: ";
    cin >> NIM;

    bool found = false;

    for (auto &m : data)
    {
        if (m.getNIM() == NIM)
        {
            found = true;

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            string Nama, Fakultas, Telepon;
            cout << "Nama baru: ";
            getline(cin, Nama);

            cout << "Fakultas baru: ";
            getline(cin, Fakultas);

            cout << "Telepon baru: ";
            getline(cin, Telepon);

            m.setNama(Nama);
            m.setFakultas(Fakultas);
            m.setTelepon(Telepon);

            cout << "Data berhasil diedit!\n";
            break;
        }
    }

    if (!found)
        cout << "Data tidak ditemukan!\n";
}

void Registrasi::hapusDataMahasiswa()
{
    string NIM;
    cout << "Masukkan NIM mahasiswa yang ingin dihapus: ";
    cin >> NIM;

    for (auto it = data.begin(); it != data.end(); ++it)
    {
        if (it->getNIM() == NIM)
        {
            data.erase(it);
            cout << "Data berhasil dihapus!\n";
            return;
        }
    }

    cout << "Data tidak ditemukan!\n";
}

void Registrasi::peminjamanSepeda()
{
    string nim;
    cout << "Masukkan NIM peminjam: ";
    cin >> nim;

    bool ada = false;
    for (auto &m : data)
    {
        if (m.getNIM() == nim)
        {
            ada = true;
            break;
        }
    }

    if (!ada)
    {
        cout << "Mahasiswa tidak ditemukan!\n";
        return;
    }

    int nomor;
    cout << "Masukkan nomor sepeda (1-1000): ";
    cin >> nomor;

    if (nomor < 1 || nomor > 1000)
    {
        cout << "Nomor sepeda tidak valid!\n";
        return;
    }

    for (auto &s : daftarSepeda)
    {
        if (s.nomor == nomor)
        {
            if (s.dipinjam)
            {
                cout << "Sepeda sudah dipinjam!\n";
                return;
            }

            string tgl;
            cout << "Masukkan tanggal peminjaman (DD/MM/YY): ";
            cin >> tgl;

            s.dipinjam = true;
            s.nimPeminjam = nim;
            s.tanggalPinjam = tgl;

            cout << "Sepeda " << nomor << " berhasil dipinjam!\n";
            return;
        }
    }

    string tgl;
    cout << "Masukkan tanggal peminjaman (DD/MM/YY): ";
    cin >> tgl;

    Sepeda s;
    s.nomor = nomor;
    s.dipinjam = true;
    s.nimPeminjam = nim;
    s.tanggalPinjam = tgl;

    daftarSepeda.push_back(s);

    cout << "Sepeda " << nomor << " berhasil dipinjam!\n";
}

void Registrasi::pengembalianSepeda()
{
    int nomor;
    cout << "Masukkan nomor sepeda yang dikembalikan: ";
    cin >> nomor;

    for (auto &s : daftarSepeda)
    {
        if (s.nomor == nomor)
        {
            if (!s.dipinjam)
            {
                cout << "Sepeda ini tidak sedang dipinjam.\n";
                return;
            }

            s.dipinjam = false;
            s.nimPeminjam = "";
            s.tanggalPinjam = "";

            cout << "Sepeda berhasil dikembalikan.\n";
            return;
        }
    }

    cout << "Sepeda tidak terdaftar!\n";
}
