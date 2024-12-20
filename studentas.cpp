#include "studentas.h"

void Student::Ivedimas(int& m, bool random) {
    int a;
    double eg = 11;

    std::cout << "Vardas: ";
    std::cin >> vardas;
    std::cout << "Pavarde: ";
    std::cin >> pavarde;

    std::cout << "Ar norite atsitiktinai generuoti rezultatus? (0 - ne, 1 - taip): ";
    std::cin >> a;

    if (std::cin.fail()) {
        std::cout << "Buvo ivestas netinkamas simbolis" << std::endl;
        exit(1);
    } else if (a == 0) {
        if (m == 0) {
            NdBe(m);
        } else {
            NdSu(m);
        }

        while (eg < 0 || eg > 10) {
            std::cout << "Egzamino rezultatas: ";
            std::cin >> eg;
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Buvo ivestas netinkamas simbolis" << std::endl;
                eg = 11;
            } else if (eg >= 0 && eg <= 10) {
                egzaminas = eg;
            } else {
                std::cout << "Egzamino rezultatas turi buti desimtbaleje sistemoje" << std::endl;
            }
        }
    } else if (a == 1) {
        if (m == 0) {
            std::cout << "Kiek namu darbu norite sugeneruoti: ";
            std::cin >> m;
        }

        NdRandom(m);
    } else {
        std::cout << "Skaicius turi buti arba 0 arba 1" << std::endl;
        exit(1);
    }
}

void Student::NdBe(int& m) {
    int nd = 11;
    while (nd != -1) {
        std::cout << "Iveskite namu darbu rezultata (noredami baigti, iveskite -1): ";
        std::cin >> nd;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Buvo ivestas netinkamas simbolis" << std::endl;
            continue;
        }

        if (nd == -1) break;

        if (nd >= 0 && nd <= 10) {
            ND.push_back(nd);
        } else {
            std::cout << "Rezultatas turi buti desimtbaleje sistemoje" << std::endl;
        }
    }
    m=ND.size();
}

void Student::NdSu(int m) {
    int n;
    for (int i = 0; i < m; ++i) {
            std::cout << "Iveskite " << i + 1 << "-uju namu darbu rezultata: ";
            std::cin >> n;
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Buvo ivestas netinkamas simbolis" << std::endl;
            } else if (n >= 0 && n <= 10) {
                ND.push_back(n);
            } else {
                std::cout << "Rezultatas turi buti desimtbaleje sistemoje" << std::endl;
            }
        }
    }

void Student::NdRandom(int m) {
    for (int i = 0; i < m; ++i) {
        ND.push_back(rand() % 10 + 1);
    }
    egzaminas = rand() % 10 + 1;
}

void Student::clearData() {
    vardas.clear();
    pavarde.clear();
    ND.clear();
}

void Student::Isvedimas(const std::vector<Student>& students, const std::string& filename) {
    std::ofstream outFile(filename);
    if (!outFile.is_open()) {
        std::cerr << "Klaida: Nepavyko atidaryti failo " << filename << std::endl;
        return;
    }

    outFile << std::left << std::setw(20) << "Vardas" << std::setw(20) << "Pavarde"
            << std::setw(15) << "Galutinis (Vid.)" << std::setw(15) << "Galutinis (Med.)" << std::endl;
    outFile << std::string(70, '-') << std::endl;

    for (const auto& student : students) {
        outFile << std::left << std::setw(20) << student.getVardas()
                << std::setw(20) << student.getPavarde()
                << std::setw(15) << std::fixed << std::setprecision(2) << student.getGalutinisVid()
                << std::setw(15) << student.getGalutinisMed() << std::endl;
    }

    outFile.close();
    std::cout << "Duomenys sekmingai isvesti i faila " << filename << std::endl;
}
void Student::Rikiavimas(std::vector<Student>& studentai) {
    std::sort(studentai.begin(), studentai.end(), [](const Student& a, const Student& b) {
        if (a.galutinisvid == b.galutinisvid) {
            return a.vardas < b.vardas;
        }
        return a.galutinisvid > b.galutinisvid;
    });
}

void Student::Skirstymas1(std::vector<Student>& studentai, std::vector<Student>& vargsiukai, std::vector<Student>& kietiakai) {
    for(int i=0; i<studentai.size(); i++)
    {
        if(studentai.at(i).galutinisvid<5)
        {
            vargsiukai.push_back(studentai.at(i));
        }
        else
        {
            kietiakai.push_back(studentai.at(i));
        }
    }
}
void Student::Skirstymas2(std::vector<Student>& studentai, std::vector<Student>& vargsiukai) {
    auto it = std::remove_if(studentai.begin(), studentai.end(), [](const Student& student) {
        return student.galutinisvid < 5.0;
    });

    vargsiukai.insert(vargsiukai.end(), it, studentai.end());
    studentai.erase(it, studentai.end());
}
void Student::Skirstymas3(std::vector<Student>& studentai, std::vector<Student>& vargsiukai) {
    auto it = std::partition(studentai.begin(), studentai.end(), [](const Student& student) {
        return student.galutinisvid >= 5;
    });
    vargsiukai.assign(it, studentai.end());
    studentai.erase(it, studentai.end());
}
void Student::Vidurkis() {
    if (!ND.empty()) {
        double sum = std::accumulate(ND.begin(), ND.end(), 0.0);
        vidurkis = sum / ND.size();
    } else {
        vidurkis = 0.0;
    }
}

void Student::GalutinisVid() {
    galutinisvid = 0.4 * vidurkis + 0.6 * egzaminas;
}

void Student::Mediana() {
    if (!ND.empty()) {
        std::sort(ND.begin(), ND.end());
        if (ND.size() % 2 == 0) {
            mediana = (ND[ND.size() / 2 - 1] + ND[ND.size() / 2]) / 2.0;
        } else {
            mediana = ND[ND.size() / 2];
        }
    } else {
        mediana = 0.0;
    }
}

void Student::Galutinismed() {
    galutinismed = 0.4 * mediana + 0.6 * egzaminas;
}
// Copy Constructor
Student::Student(const Student& other)
    : vardas(other.vardas), pavarde(other.pavarde), ND(other.ND),
      egzaminas(other.egzaminas), vidurkis(other.vidurkis),
      mediana(other.mediana), galutinisvid(other.galutinisvid),
      galutinismed(other.galutinismed) {}

// Copy Assignment Operator
Student& Student::operator=(const Student& other) {
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
Student::~Student() {
    ND.clear();
}
