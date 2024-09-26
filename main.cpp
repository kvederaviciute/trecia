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
    if(a==0)
    {
        cout<<"Kiek studentu yra jusu kurse?: ";
        cin>>n;
        for(int i=0; i<n; i++)
        {
            cout<<"Iveskite studento duomenis: "<<endl;
            ivedimas(laikinas, m);
            studentai.push_back(laikinas);
            valymas(laikinas);
        }
    }
    else
    {
        cout<<"Iveskite failo pavadinima formatu pavadinimas.txt: ";
        cin>>failas;
        ifstream in(failas);
        if(!in)
        {
            cout<<"failas nerastas"<<endl;
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
        n=studentai.size();
    }

    for(int i=0; i<n; i++)
    {
        vidurkis(studentai.at(i),m);
        galutinisvid(studentai.at(i));
        mediana(studentai.at(i),m);
        galutinismed(studentai.at(i));
    }
    isvedimasgal(studentai, n);
    return 0;
}
