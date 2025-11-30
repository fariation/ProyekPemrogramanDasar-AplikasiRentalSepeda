#ifndef _REGISTER_H
#define _REGISTER_H

#include "Person.h"
#include <vector>
#include <string>

struct Sepeda
{
    int nomor = 0;
    bool dipinjam = false;
    std::string tanggalPinjam;
    std::string nimPeminjam;
};

class Registrasi
{
private:
    std::vector<Mahasiswa> data;
    std::vector<Sepeda> daftarSepeda;

public:
    Registrasi() = default;

    void registrasiMahasiswa();
    void lihatDataMahasiswa();
    void editDataMahasiswa();
    void hapusDataMahasiswa();

    void peminjamanSepeda();
    void pengembalianSepeda();
};

#endif
