#include "studentas.h"

int main() {
    std::vector<Student> studentai, vargsiukai;
    Student laikinas;
    std::string failas, eilute;
    int n = 0, a = 0, m = 0, nd = 0;

    std::cout << "Ar duomenis norite nuskaityti is failo? (0 - ne, 1 - taip): ";
    std::cin >> a;
    if (std::cin.fail()) {
        std::cout << "Netinkamas simbolis" << std::endl;
        return 0;
    }

    if (a == 0) {
        std::cout << "Kiek studentu yra jusu kurse?: ";
        std::cin >> n;
        if (std::cin.fail()) {
            std::cout << "Netinkamas simbolis" << std::endl;
            return 0;
        }
        for (int i = 0; i < n; i++) {
            std::cout << "Iveskite studento duomenis: " << std::endl;
                laikinas.Ivedimas(m, false);
            studentai.push_back(laikinas);
        }
    } else if (a == 1) {
        bool failas_perskaitytas = false;

        while (!failas_perskaitytas) {
            std::cout << "Iveskite failo pavadinima formatu pavadinimas.txt: ";
            std::cin >> failas;

            try {
                auto start = std::chrono::high_resolution_clock::now();
                std::ifstream in(failas);
                if (!in) {
                    std::cout << "Failas nerastas" << std::endl;
                    return 0;
                } else {
                    std::getline(in, eilute);
                    while (std::getline(in, eilute)) {
                        std::istringstream iss(eilute);
                        std::string vardas, pavarde;
                        std::vector<int> ND;
                        int egzaminas;

                        iss >> vardas >> pavarde;
                        while (iss >> nd) {
                            ND.push_back(nd);
                        }
                        egzaminas = ND.back();
                        ND.pop_back();

                        Student student(vardas, pavarde);
                        for (int grade : ND) student.addNamudarbai(grade);
                        student.setEgzaminas(egzaminas);
                        studentai.push_back(student);
                    }
                }
                in.close();
                failas_perskaitytas = true;

                auto stop = std::chrono::high_resolution_clock::now();
                std::chrono::duration<double> duration = stop - start;
                std::cout << failas << " failo nuskaitymo laikas: " << std::fixed << std::setprecision(6) << duration.count() << std::endl;
            } catch (std::exception& e) {
                std::cout << "Klaida perskaitant faila" << std::endl;
            }
        }
        m = studentai[0].getVardas().size();
        n = studentai.size();
    }

    for (Student& student : studentai) {
        student.Vidurkis();
        student.GalutinisVid();
        student.Mediana();
        student.Galutinismed();
    }

    auto start = std::chrono::high_resolution_clock::now();
    Student::Rikiavimas(studentai);
    auto stop = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = stop - start;
    std::cout << "Studentu duomenu rikiavimo laikas (vector): " << std::fixed << std::setprecision(6) << duration.count() << std::endl;
    start = std::chrono::high_resolution_clock::now();
    Student::Skirstymas(studentai, vargsiukai);
    stop = std::chrono::high_resolution_clock::now();
    duration = stop - start;
    if (!failas.empty()) {
        std::cout << failas << " failo studentu skirstymo i dvi grupes laikas: " << std::fixed << std::setprecision(6) << duration.count() << std::endl;
    } else {
        std::cout << "Studentu skirstymo i dvi grupes laikas: " << std::fixed << std::setprecision(6) << duration.count() << std::endl;
    }

    start = std::chrono::high_resolution_clock::now();
    laikinas.Isvedimas(studentai, "kietiakai.txt");
    stop = std::chrono::high_resolution_clock::now();
    duration = stop - start;
    if (!failas.empty()) {
        std::cout << failas << " failo studentu duomenu isvedimo i faila kietiakai.txt laikas (vector): " << std::fixed << std::setprecision(6) << duration.count() << std::endl;
    } else {
        std::cout << "Studentu duomenu isvedimo i faila kietiakai.txt laikas: " << std::fixed << std::setprecision(6) << duration.count() << std::endl;
    }

    laikinas.Isvedimas(vargsiukai, "vargsiukai.txt");
    std::cout << "Failai isvesti" << std::endl;

    return 0;
}
