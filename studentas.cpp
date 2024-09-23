#include "studentas.h"

void ivedimas(Stud & student, int m){
    int nd;
    cout<<"Vardas: ";
    cin>>student.vardas;
    cout<<"Pavarde: ";
    cin>>student.pavarde;
    for(int i=0;i<m;i++){
        cout<<i+1<<"-uju namu darbu rezultatas: ";
        cin>>nd;
        if(nd > 10 || nd < 0){
            cout<<"Rezultatai turi buti desimtbaleje sistemoje!"<<endl;
            i--;
        }
        else{
            student.ND.push_back(nd);
        }
    }
    cout<<"Egzamino rezultatas: ";
    cin>>student.egzaminas;
}
