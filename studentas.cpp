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
void valymas(Stud & student){
    student.vardas.clear();
    student.pavarde.clear();
    student.ND.clear();
}
void isvedimasgal(vector<Stud> student,int n){
    cout<<left<<setw(10)<<"Vardas "<<left<<setw(15)<<"Pavarde "<<left<<setw(10)<<"Galutinis "<<endl;
    cout<<"-----------------------------------------"<<endl;
    for(int i=0;i<n;i++){
      cout<<left<<setw(10)<<student.at(i).vardas<<left<<setw(15)<<student.at(i).pavarde<<left<<setw(10)<<fixed<<setprecision(2)<<student.at(i).galutinis<<endl;
    }
}
