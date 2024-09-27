#include "pagrindas.h"
#include "studentas.h"
#include "skaiciavimai.h"

int main()
{
    vector<Stud> studentai;
    Stud laikinas;
    string failas, eilute;
    int n, m=0,a,nd;

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
                        valymas(laikinas);
                    }
                }
                m=studentai[0].ND.size();
                in.close();
                failas_perskaitytas = true;
            }
            catch(std::exception& e)
            {
                cout<<"Klaida perskaitant faila"<<endl;

            }
        }

        n=studentai.size();
    }


    for(int i=0; i<n; i++)
    {
        vidurkis(studentai.at(i),m);
        galutinisvid(studentai.at(i));
        mediana(studentai.at(i),m);
        galutinismed(studentai.at(i));
    }
    rikiavimas(studentai);
    isvedimasgal(studentai, n);
    return 0;
}
