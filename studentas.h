#ifndef STUDENTAS_H_INCLUDED
#define STUDENTAS_H_INCLUDED

#include "pagrindas.h"

class Zmogus {
protected:
    std::string vardas, pavarde;

public:
    Zmogus() : vardas("Nezinomas"), pavarde("Zmogaicius") {}
    Zmogus(const std::string& vardas, const std::string& pavarde)
        : vardas(vardas), pavarde(pavarde) {}

    virtual ~Zmogus() = default; 

    // Getteriai
    std::string getVardas() const { return vardas; }
    std::string getPavarde() const { return pavarde; }

    // Setteriai
    void setVardas(const std::string& vardas) { this->vardas = vardas; }
    void setPavarde(const std::string& pavarde) { this->pavarde = pavarde; }

    // Virtualus metodas
    virtual void printInfo() const = 0; // Grynai virtualus metodas, užtikrina abstraktumą
};

class Student : public Zmogus {
private:
    std::vector<int> ND;
    double egzaminas = 0;
    double vidurkis = 0;
    double mediana = 0;
    double galutinisvid = 0;
    double galutinismed = 0;

public:
    // Konstruktoriai
    Student() : Zmogus() {}
    Student(const std::string& vardas, const std::string& pavarde)
        : Zmogus(vardas, pavarde) {}

    // Destruktorius
    ~Student() { ND.clear(); }

    // Trejų metodų taisyklė
    Student(const Student& other)
        : Zmogus(other.vardas, other.pavarde), ND(other.ND), egzaminas(other.egzaminas),
          vidurkis(other.vidurkis), mediana(other.mediana),
          galutinisvid(other.galutinisvid), galutinismed(other.galutinismed) {}

    Student& operator=(const Student& other) {
        if (this != &other) {
            vardas = other.vardas;
            pavarde = other.pavarde;
            ND = other.ND;
            egzaminas = other.egzaminas;
            vidurkis = other.vidurkis;
            mediana = other.mediana;
            galutinisvid = other.galutinisvid;
            galutinismed = other.galutinismed;
        }
        return *this;
    }

    void printInfo() const override {
        std::cout << "Vardas: " << vardas << ", Pavarde: " << pavarde << std::endl;
    }
    void addNamudarbai(int nd) { ND.push_back(nd); }
    void setEgzaminas(double egzaminas) { this->egzaminas = egzaminas; }

    double getGalutinisVid() const { return galutinisvid; }
    double getGalutinisMed() const { return galutinismed; }

    friend std::ostream& operator<<(std::ostream& os, const Student& student) {
        os << std::left << std::setw(15) << student.vardas
           << std::setw(20) << student.pavarde
           << std::setw(10) << std::fixed << std::setprecision(2) << student.galutinisvid
           << std::setw(10) << student.galutinismed;
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Student& student) {
        std::cout << "Įveskite vardą: ";
        is >> student.vardas;
        std::cout << "Įveskite pavardę: ";
        is >> student.pavarde;

        int nd;
        std::cout << "Įveskite namų darbų pažymius (baigti su -1): ";
        while (is >> nd && nd != -1) {
            student.ND.push_back(nd);
        }

        std::cout << "Įveskite egzamino pažymį: ";
        is >> student.egzaminas;

        student.Vidurkis();
        student.Mediana();
        student.GalutinisVid();
        student.Galutinismed();

        return is;
    }


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
    static void Skirstymas1(std::vector<Student>& studentai, std::vector<Student>& vargsiukai, std::vector<Student>& kietiakai);
    static void Skirstymas2(std::vector<Student>& studentai, std::vector<Student>& vargsiukai);
    static void Skirstymas3(std::vector<Student>& studentai, std::vector<Student>& vargsiukai);
};

#endif // STUDENTAS_H_INCLUDED
