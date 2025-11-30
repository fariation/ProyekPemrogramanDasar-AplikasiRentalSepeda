#include "Sepeda.h"

Sepeda::Sepeda(const std::string &nomor)
    : nomor(nomor) {}

std::string Sepeda::getNomor() const { return nomor; }
bool Sepeda::isDipinjam() const { return sedangDipinjam; }
std::string Sepeda::getTanggalPinjam() const { return tanggalPinjam; }

void Sepeda::pinjam(const std::string &tanggal)
{
    sedangDipinjam = true;
    tanggalPinjam = tanggal;
}

void Sepeda::kembalikan()
{
    sedangDipinjam = false;
    tanggalPinjam = "";
}
