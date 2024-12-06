#ifndef STUDENTAS_H_INCLUDED
#define STUDENTAS_H_INCLUDED

#include "pagrindas.h"
#include <iostream>
#include <vector>
#include <string>

class Student {
private:
    std::string vardas = "Nezinomas", pavarde = "Nezinomas";
    std::vector<int> ND;
    double egzaminas = 0;
    double vidurkis = 0;
    double mediana = 0;
    double galutinisvid = 0;
    double galutinismed = 0;

public:
// Constructor

Student(const std::string& vardas = "", const std::string& pavarde = "", double egzaminas = 0.0);

// Copy Constructor
Student(const Student& other)
    : vardas(other.vardas), pavarde(other.pavarde), ND(other.ND), egzaminas(other.egzaminas),
      vidurkis(other.vidurkis), mediana(other.mediana), galutinisvid(other.galutinisvid),
      galutinismed(other.galutinismed){}

// Copy Assignment Operator
Student& operator=(const Student& other) {
    if (this == &other) return *this; // Handle self-assignment
    vardas = other.vardas;
    pavarde = other.pavarde;
    ND = other.ND;
    egzaminas = other.egzaminas;
    vidurkis = other.vidurkis;
    mediana = other.mediana;
    galutinisvid = other.galutinisvid;
    galutinismed = other.galutinismed;

    return *this;
}

// Destructor
~Student() {
    ND.clear();
}

    // Setters
    void setVardas(const std::string& vardas) { this->vardas = vardas; }
    void setPavarde(const std::string& pavarde) { this->pavarde = pavarde; }
    void addNamudarbai(int nd) { ND.push_back(nd); }
    void setEgzaminas(double egzaminas) { this->egzaminas = egzaminas; }

    // Getters
    std::string getVardas() const { return vardas; }
    std::string getPavarde() const { return pavarde; }
    double getGalutinisVid() const { return galutinisvid; }
    double getGalutinisMed() const { return galutinismed; }

    // Member Functions
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

    // Static Functions
    static void Rikiavimas(std::vector<Student>& studentai);
    static void Skirstymas1(std::vector<Student>& studentai, std::vector<Student>& vargsiukai, std::vector<Student>& kietiakai);
    static void Skirstymas2(std::vector<Student>& studentai, std::vector<Student>& vargsiukai);
    static void Skirstymas3(std::vector<Student>& studentai, std::vector<Student>& vargsiukai);

    friend std::ostream& operator<<(std::ostream& os, const Student& student);
};

#endif // STUDENTAS_H_INCLUDED


#endif // STUDENTAS_H_INCLUDED
