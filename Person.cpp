#include "Person.h"
#include <string>

Mahasiswa::Mahasiswa(const std::string &Nama,
                     const std::string &NIM,
                     const std::string &Fakultas,
                     const std::string &Telepon)

{
    this->Nama = Nama;
    this->NIM = NIM;
    this->Fakultas = Fakultas;
    this->Telepon = Telepon;
}

std::string Mahasiswa::getNama() const { return Nama; }
std::string Mahasiswa::getNIM() const { return NIM; }
std::string Mahasiswa::getFakultas() const { return Fakultas; }
std::string Mahasiswa::getTelepon() const { return Telepon; }

void Mahasiswa::setNama(const std::string &Nama) { this->Nama = Nama; }
void Mahasiswa::setNIM(const std::string &NIM) { this->NIM = NIM; }
void Mahasiswa::setFakultas(const std::string &Fakultas) { this->Fakultas = Fakultas; }
void Mahasiswa::setTelepon(const std::string &Telepon) { this->Telepon = Telepon; }