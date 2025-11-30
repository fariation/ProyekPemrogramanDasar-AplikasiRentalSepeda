#ifndef SEPEDA_H
#define SEPEDA_H

#include <string>

class Sepeda
{
private:
    std::string nomor;
    bool sedangDipinjam = false;
    std::string tanggalPinjam;

public:
    Sepeda(const std::string &nomor = "");

    std::string getNomor() const;
    bool isDipinjam() const;
    std::string getTanggalPinjam() const;

    void pinjam(const std::string &tanggal);
    void kembalikan();
};

#endif
