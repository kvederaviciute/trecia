#include "pagrindas.h"
#include "studentas.h"
#include "skaiciavimai.h"

int main()
{
    vector<Stud> studentai;
    Stud laikinas;
    int n, m=0;
    cout<<"Kiek studentu yra jusu kurse?: ";
    cin>>n;
    for(int i=0; i<n; i++){
        cout<<"Iveskite studento duomenis: "<<endl;
        ivedimas(laikinas, m);
        studentai.push_back(laikinas);
        valymas(laikinas);
    }
    for(int i=0; i<n; i++){
        vidurkis(studentai.at(i),m);
        galutinisvid(studentai.at(i));
        mediana(studentai.at(i),m);
        galutinismed(studentai.at(i));
    }
    isvedimasgal(studentai, n);
    return 0;
}
