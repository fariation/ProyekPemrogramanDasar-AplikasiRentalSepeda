#include "Register.h"
#include <iostream>
#include <limits> // untuk numeric_limits
using namespace std;

void Registrasi::registrasiMahasiswa()
{
    string Nama, NIM, Fakultas, Telepon;

    // Bersihkan buffer
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
    if (sepedaSedangDipinjam)
    {
        cout << "Sepeda sedang dipinjam (Nomor: " << sepedaDipinjamNomor
             << ", Tanggal: " << sepedaTanggalPinjam << ")\n";
        return;
    }

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

    cout << "Masukkan nomor sepeda: ";
    cin >> sepedaDipinjamNomor;

    cout << "Masukkan tanggal peminjaman (DD/MM/YY): ";
    cin >> sepedaTanggalPinjam;

    sepedaSedangDipinjam = true;

    cout << "Sepeda " << sepedaDipinjamNomor
         << " berhasil dipinjam!\n";
}

void Registrasi::pengembalianSepeda()
{
    if (!sepedaSedangDipinjam)
    {
        cout << "Tidak ada sepeda yang sedang dipinjam.\n";
        return;
    }

    string nomor;
    cout << "Masukkan nomor sepeda yang dikembalikan: ";
    cin >> nomor;

    if (nomor != sepedaDipinjamNomor)
    {
        cout << "Nomor sepeda tidak cocok!\n";
        return;
    }

    sepedaSedangDipinjam = false;
    sepedaDipinjamNomor = "";
    sepedaTanggalPinjam = "";

    cout << "Sepeda berhasil dikembalikan.\n";
}
