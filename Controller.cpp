#include "controller.h"
#include <iostream>
#include <fstream>
#include <conio.h>
#include "Register.h"
#include "Person.h"

using namespace std;

Registrasi reg;

void Controller::commandLoop()
{
    char choice;
    do
    {
        cout << "===== RENTAL SEPEDA UGM =====" << endl;
        cout << "Pilih sebuah opsi:" << endl;
        cout << "1. Registrasi Mahasiswa" << endl;
        cout << "2. Kelola Data Mahasiswa" << endl;
        cout << "3. Peminjaman Sepeda" << endl;
        cout << "4. Pengembalian Sepeda" << endl;
        cout << "Tekan tombol apa saja untuk keluar" << endl;

        choice = getch();
        switch (choice)
        {
        case '1':
            reg.registrasiMahasiswa();
            break;

        case '2':
        {
            char subChoice;
            do
            {
                cout << "\nKelola Data Mahasiswa" << endl;
                cout << "a. Lihat Data Mahasiswa" << endl;
                cout << "b. Edit Data Mahasiswa" << endl;
                cout << "c. Hapus Data Mahasiswa" << endl;
                cout << "Tekan tombol apa saja untuk keluar" << endl;

                subChoice = getch();
                switch (subChoice)
                {
                case 'a':
                    reg.lihatDataMahasiswa();
                    break;
                case 'b':
                    reg.editDataMahasiswa();
                    break;
                case 'c':
                    reg.hapusDataMahasiswa();
                    break;
                default:
                    cout << "Kembali ke menu utama" << endl;
                    break;
                }
            } while (subChoice == 'a' || subChoice == 'b' || subChoice == 'c');
            break;
        }
        case '3':
            reg.peminjamanSepeda();
            break;
        case '4':
            reg.pengembalianSepeda();
            break;
        default:
            cout << "Keluar dari program" << endl;
            return;
        }
    } while (true);
}