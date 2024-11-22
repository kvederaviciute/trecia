#ifndef STUDENTAS_H_INCLUDED
#define STUDENTAS_H_INCLUDED

#include "pagrindas.h"

class Student {
private:
    std::string vardas, pavarde;
    std::vector<int> ND;
    double egzaminas = 0;
    double vidurkis = 0;
    double mediana = 0;
    double galutinisvid = 0;
    double galutinismed = 0;

public:
    //Konstruktorius
    Student() = default;
    Student(const std::string& vardas, const std::string& pavarde)
        : vardas(vardas), pavarde(pavarde) {}

    ~Student() = default; // Destruktorius

    void setVardas(const std::string& vardas) { this->vardas = vardas; }
    void setPavarde(const std::string& pavarde) { this->pavarde = pavarde; }
    void addNamudarbai(int nd) { ND.push_back(nd); }
    void setEgzaminas(double egzaminas) { this->egzaminas = egzaminas; }

    std::string getVardas() const { return vardas; }
    std::string getPavarde() const { return pavarde; }
    double getGalutinisVid() const { return galutinisvid; }
    double getGalutinisMed() const { return galutinismed; }

    void Ivedimas(int& m, bool random = false);
    void Vidurkis();
    void GalutinisVid();
    void Mediana();
    void Galutinismed();
    void Isvedimas(const std::vector<Student>& students, const std::string& filename);
    void NdBe(int& m);
    void NdSu(int m);
    void NdRandom(int m);
    void clearData();

    static void Rikiavimas(std::vector<Student>& studentai);
    static void Skirstymas(std::vector<Student>& studentai, std::vector<Student>& vargsiukai);
};

#endif // STUDENTAS_H_INCLUDED
