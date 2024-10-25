#include "pagrindas.h"
#include "studentas.h"
#include "skaiciavimai.h"

int main()
{
    Stud laikinas;
    string failas, eilute;
    int n, a, m=0,nd;
    vector<Stud> studentai, vargsiukai, kietiakai;
    list<Stud> studentail, vargsiukail, kietiakail;

    cout<<"Ar norite generuoti failus?(0 - ne, 1 - taip): ";
    cin>>a;
    if(std::cin.fail())
    {
        cout<<"Netinkamas simbolis"<<endl;
        return(0);
    }
    else if(a==1)
    {
        srand(time(0));
        generavimas(1000, "studentai_1000.txt");
        generavimas(10000, "studentai_10000.txt");
        generavimas(100000, "studentai_100000.txt");
        generavimas(1000000, "studentai_1000000.txt");
        generavimas(10000000, "studentai_10000000.txt");
    }
    cout<<"Ar duomenis norite nuskaityti is failo? (0 - ne, 1 - taip): ";
    cin>>a;
    if(std::cin.fail())
    {
        cout<<"Netinkamas simbolis"<<endl;
        return(0);
    }
    else if(a==0)
    {
        cout<<"Kiek studentu yra jusu kurse?: ";
        cin>>n;
        if(std::cin.fail())
        {
            cout<<"Netinkamas simbolis"<<endl;
            return(0);
        }
        else
        {
            for(int i=0; i<n; i++)
            {
                cout<<"Iveskite studento duomenis: "<<endl;
                ivedimas(laikinas, m);
                studentai.push_back(laikinas);
                studentail.push_back(laikinas);
                valymas(laikinas);
            }
        }
    }
    else if(a==1)
    {
        bool failas_perskaitytas = false;

        while(!failas_perskaitytas)
        {
            n, m, a, nd = 0;
            cout<<"Iveskite failo pavadinima formatu pavadinimas.txt: ";
            cin>>failas;
            try
            {
                auto start = std::chrono::high_resolution_clock::now();
                ifstream in(failas);
                if(!in)
                {
                    cout<<"failas nerastas"<<endl;
                    return(0);
                }
                else
                {
                    getline(in, eilute);
                    while (getline(in, eilute))
                    {
                        istringstream iss(eilute);

                        iss >> laikinas.vardas >> laikinas.pavarde;
                        while (iss >> nd)
                        {
                            laikinas.ND.push_back(nd);
                        }
                        laikinas.egzaminas = laikinas.ND.back();
                        laikinas.ND.pop_back();
                        studentai.push_back(laikinas);
                        studentail.push_back(laikinas);
                        valymas(laikinas);
                    }
                }
                in.close();
                failas_perskaitytas = true;
                auto stop = std::chrono::high_resolution_clock::now();
                std::chrono::duration<double> duration = stop - start;
                cout<<failas<<" failo nuskaitymo laikas: "<<fixed<<setprecision(6)<<duration.count()<<endl;
            }
            catch(std::exception& e)
            {
                cout<<"Klaida perskaitant faila"<<endl;
            }
        }
        m=studentai[0].ND.size();
        n=studentai.size();
    }


    for(int i=0; i<n; i++)
    {
        vidurkis(studentai.at(i),m);
        galutinisvid(studentai.at(i));
        mediana(studentai.at(i),m);
        galutinismed(studentai.at(i));
    }
            for (auto it = studentail.begin(); it != studentail.end(); ++it) {
            vidurkis(*it, m);
            galutinisvid(*it);
            mediana(*it, m);
            galutinismed(*it);
        }
    auto start = std::chrono::high_resolution_clock::now();
    skirstymas(studentai,kietiakai,vargsiukai);
    auto stop = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = stop - start;
    if(!failas.empty())
    {
        cout<<failas<<" failo studentu skirstymo i dvi grupes laikas(vector): "<<fixed<<setprecision(6)<<duration.count()<<endl;
    }
    else
    {
        cout<<"studentu skirstymo i dvi grupes laikas: "<<fixed<<setprecision(6)<<duration.count()<<endl;
    }
    start = std::chrono::high_resolution_clock::now();
    skirstymasl(studentail,kietiakail,vargsiukail);
    stop = std::chrono::high_resolution_clock::now();
    duration = stop - start;
    if(!failas.empty())
    {
        cout<<failas<<" failo studentu skirstymo i dvi grupes laikas(list): "<<fixed<<setprecision(6)<<duration.count()<<endl;
    }
    else
    {
        cout<<"studentu skirstymo i dvi grupes laikas: "<<fixed<<setprecision(6)<<duration.count()<<endl;
    }

    rikiavimas(kietiakai);
    rikiavimas(vargsiukai);
    start = std::chrono::high_resolution_clock::now();
    rikiavimas(studentai);
    stop = std::chrono::high_resolution_clock::now();
    duration = stop - start;
    cout<<"studentu duomenu rikiavimo laikas(vector): "<<fixed<<setprecision(6)<<duration.count()<<endl;
    start = std::chrono::high_resolution_clock::now();
    rikiavimasl(studentail);
    stop = std::chrono::high_resolution_clock::now();
    duration = stop - start;
    cout<<"studentu duomenu rikiavimo laikas(list): "<<fixed<<setprecision(6)<<duration.count()<<endl;
    start = std::chrono::high_resolution_clock::now();
    isvedimasgal(studentai, n, "studentai.txt");
    stop = std::chrono::high_resolution_clock::now();
    duration = stop - start;
    if(!failas.empty())
    {
        cout<<failas<<" failo studentu duomenu isvedimo i faila studentai.txt laikas(vector): "<<fixed<<setprecision(6)<<duration.count()<<endl;
    }
    else
    {
        cout<<"studentu duomenu isvedimo i faila studentai.txt laikas: "<<fixed<<setprecision(6)<<duration.count()<<endl;
    }
        start = std::chrono::high_resolution_clock::now();
    isvedimasgall(studentail, n, "studentail.txt");
    stop = std::chrono::high_resolution_clock::now();
    duration = stop - start;
    if(!failas.empty())
    {
        cout<<failas<<" failo studentu duomenu isvedimo i faila studentai.txt laikas(list): "<<fixed<<setprecision(6)<<duration.count()<<endl;
    }
    else
    {
        cout<<"studentu duomenu isvedimo i faila studentai.txt laikas: "<<fixed<<setprecision(6)<<duration.count()<<endl;
    }
    isvedimasgal(kietiakai, kietiakai.size(), "kietiakai.txt");
    isvedimasgal(vargsiukai, vargsiukai.size(), "vargsiukai.txt");
    cout<<"Failai isvesti";
    return 0;
}
