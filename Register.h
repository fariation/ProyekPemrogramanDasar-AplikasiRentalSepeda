#ifndef _REGISTER_H
#define _REGISTER_H
#include "Person.h"
#include "Sepeda.h"
#include <vector>
#include <string>

class Registrasi
{
private:
    std::vector<Mahasiswa> data;
    std::string sepedaDipinjamNomor;
    std::string sepedaTanggalPinjam;
    bool sepedaSedangDipinjam = false;

public:
    void registrasiMahasiswa();
    void lihatDataMahasiswa();
    void editDataMahasiswa();
    void hapusDataMahasiswa();
    void peminjamanSepeda();
    void pengembalianSepeda();
};

#endif
