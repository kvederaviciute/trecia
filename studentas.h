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
     // Default Constructor
    Student() : vardas("Nezinomas"), pavarde("Studentas") {}

    // Parameterized Constructor
    Student(const std::string& vardas, const std::string& pavarde)
        : vardas(vardas), pavarde(pavarde) {}

    // Copy Constructor (Rule of Three)
    Student(const Student& other);

    // Copy Assignment Operator (Rule of Three)
    Student& operator=(const Student& other);

    // Destructor (Rule of Three)
    ~Student();

    void setVardas(const std::string& vardas) { this->vardas = vardas; }
    void setPavarde(const std::string& pavarde) { this->pavarde = pavarde; }
    void addNamudarbai(int nd) { ND.push_back(nd); }
    void setEgzaminas(double egzaminas) { this->egzaminas = egzaminas; }

    std::string getVardas() const { return vardas; }
    std::string getPavarde() const { return pavarde; }
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
