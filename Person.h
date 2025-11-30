#ifndef PERSON_H
#define PERSON_H
#include <string>

class Mahasiswa
{
private:
    std::string Nama;
    std::string NIM;
    std::string Fakultas;
    std::string Telepon;

public:
    Mahasiswa(const std::string &Nama = "",
              const std::string &NIM = "",
              const std::string &Fakultas = "",
              const std::string &Telepon = "");

    std::string getNama() const;
    std::string getNIM() const;
    std::string getFakultas() const;
    std::string getTelepon() const;

    void setNama(const std::string &Nama);
    void setNIM(const std::string &NIM);
    void setFakultas(const std::string &Fakultas);
    void setTelepon(const std::string &Telepon);
};

#endif