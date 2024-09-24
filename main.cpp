#include "pagrindas.h"
#include "studentas.h"
#include "skaiciavimai.h"

int main()
{
    vector<Stud> studentai;
    Stud laikinas;
    int n,m;
    cout<<"Kiek studentu yra jusu kurse?: ";
    cin>>n;
    cout<<"Kiek namu darbu uzduodate?: ";
    cin>>m;
    for(int i=0; i<n; i++){
        cout<<"Iveskite studento duomenis: "<<endl;
        ivedimas(laikinas,m);
        studentai.push_back(laikinas);
    }

    for(int i=0; i<n; i++){
        vidurkis(studentai.at(i),m);
        galutinis(studentai.at(i));
    }
    isvedimasgal(studentai, n);
    
    return 0;
}
