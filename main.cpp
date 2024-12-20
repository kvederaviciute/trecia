#include "studentas.h"

int main()
{
    std::vector<Student> studentai, vargsiukai, kietiakai;
    Student laikinas;
    std::string failas, eilute;
    int n = 0, a = 0, m = 0, nd = 0;

///Zmogus zmogus("Abstract", "Person");

    Student s1("abc", "def");
    s1.addNamudarbai(8);
    s1.addNamudarbai(7);
    s1.setEgzaminas(9);
    s1.printInfo();

    // Copy constructor
    Student s2 = s1;
    s2.printInfo();

    // Copy assignment
    Student s3("uvw", "xyz");
    s3.printInfo();
    s3 = s1;
    s3.printInfo();

    std::cout << "Ar duomenis norite nuskaityti is failo? (0 - ne, 1 - taip): ";
    std::cin >> a;
    if (std::cin.fail())
    {
        std::cout << "Netinkamas simbolis" << std::endl;
        return 0;
    }

    if (a == 0)
    {
        std::cout << "Kiek studentu yra jusu kurse?: ";
        std::cin >> n;
        if (std::cin.fail())
        {
            std::cout << "Netinkamas simbolis" << std::endl;
            return 0;
        }
        for (int i = 0; i < n; i++)
        {
            std::cout << "Iveskite studento duomenis: " << std::endl;
            laikinas.Ivedimas(m, false);
            studentai.push_back(laikinas);
        }
    }
    else if (a == 1)
    {
        bool failas_perskaitytas = false;

        while (!failas_perskaitytas)
        {
            std::cout << "Iveskite failo pavadinima formatu pavadinimas.txt: ";
            std::cin >> failas;

            try
            {
                auto start = std::chrono::high_resolution_clock::now();
                std::ifstream in(failas);
                if (!in)
                {
                    std::cout << "Failas nerastas" << std::endl;
                    return 0;
                }
                else
                {
                    std::getline(in, eilute);
                    while (std::getline(in, eilute))
                    {
                        std::istringstream iss(eilute);
                        std::string vardas, pavarde;
                        std::vector<int> ND;
                        int egzaminas;

                        iss >> vardas >> pavarde;
                        while (iss >> nd)
                        {
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
            }
            catch (std::exception& e)
            {
                std::cout << "Klaida perskaitant faila" << std::endl;
            }
        }
        m = studentai[0].getVardas().size();
        n = studentai.size();
    }

    for (Student& student : studentai)
    {
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
    //Student::Skirstymas1(studentai, vargsiukai,kietiakai);
    Student::Skirstymas2(studentai, vargsiukai);
    //Student::Skirstymas3(studentai, vargsiukai);
    stop = std::chrono::high_resolution_clock::now();
    duration = stop - start;
    if (!failas.empty())
    {
        std::cout << failas << " failo studentu skirstymo i dvi grupes laikas: " << std::fixed << std::setprecision(6) << duration.count() << std::endl;
    }
    else
    {
        std::cout << "Studentu skirstymo i dvi grupes laikas: " << std::fixed << std::setprecision(6) << duration.count() << std::endl;
    }

    start = std::chrono::high_resolution_clock::now();
    //laikinas.Isvedimas(kietiakai, "kietiakai.txt");
    laikinas.Isvedimas(studentai, "kietiakai.txt");
    stop = std::chrono::high_resolution_clock::now();
    duration = stop - start;
    if (!failas.empty())
    {
        std::cout << failas << " failo studentu duomenu isvedimo i faila kietiakai.txt laikas (vector): " << std::fixed << std::setprecision(6) << duration.count() << std::endl;
    }
    else
    {
        std::cout << "Studentu duomenu isvedimo i faila kietiakai.txt laikas: " << std::fixed << std::setprecision(6) << duration.count() << std::endl;
    }
    start = std::chrono::high_resolution_clock::now();
    laikinas.Isvedimas(vargsiukai, "vargsiukai.txt");
    stop = std::chrono::high_resolution_clock::now();
    duration = stop - start;
    if (!failas.empty())
    {
        std::cout << failas << " failo studentu duomenu isvedimo i faila vargsiukai.txt laikas (vector): " << std::fixed << std::setprecision(6) << duration.count() << std::endl;
    }
    else
    {
        std::cout << "Studentu duomenu isvedimo i faila vargsiukai.txt laikas: " << std::fixed << std::setprecision(6) << duration.count() << std::endl;
    }
    std::cout << "Failai isvesti" << std::endl;

    std::cout << "Paspauskite bet kuri klavisa, kad uzdarytumete programa..." << std::endl;
    std::cin.get();
    std::cin.get();
    return 0;
}

