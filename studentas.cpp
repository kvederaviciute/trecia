#include "studentas.h"

void ivedimas(Stud & student, int & m){
    int a,d;
    cout<<"Vardas: ";
    cin>>student.vardas;
    cout<<"Pavarde: ";
    cin>>student.pavarde;
    cout<<"Ar norite atsitiktinai generuoti rezultatus?(0 - ne, 1 - taip): ";
    cin>>a;
    if(a==0){
        if(m==0){
            namudarbaibe(student,m);
        }
        else{
            namudarbaisu(student,m);
        }
        cout<<"Egzamino rezultatas: ";
        cin>>student.egzaminas;
    }
    else{
        if(m==0){
            cout<<"Kiek namu darbu norite sugeneruoti: ";
            cin>>m;
        }
        for(int i=0;i<m;i++){
            d=rand() % 10 + 1;
            student.ND.push_back(d);
        }
        student.egzaminas=rand() % 10 +1;
    }
}
void namudarbaibe(Stud & student, int & m){
    int n=0;
    while(n!=-1){
        cout<<"Iveskite "<<m+1<<"-uju namu darbu rezultata (noredami baigti ivedima, iveskite skaiciu -1): ";
        cin>>n;
        if(n!=-1){
            student.ND.push_back(n);
            m++;
        }
    }
}
void namudarbaisu(Stud & student, int m){
    int n;
    for(int i=0;i<m;i++){
        cout<<"Iveskite "<<i+1<<"-uju namu darbu rezultata: ";
        cin>>n;
        student.ND.push_back(n);
    }
}
void valymas(Stud & student){
    student.vardas.clear();
    student.pavarde.clear();
    student.ND.clear();
}
void isvedimasgal(vector<Stud> student,int n){
    cout<<left<<setw(10)<<"Vardas "<<left<<setw(15)<<"Pavarde "<<left<<setw(18)<<"Galutinis (Vid.) "<<left<<setw(18)<<"Galutinis (Med.) "<<endl;
    cout<<"---------------------------------------------------------"<<endl;
    for(int i=0;i<n;i++){
      cout<<left<<setw(10)<<student.at(i).vardas<<left<<setw(15)<<student.at(i).pavarde<<left<<setw(18)<<fixed<<setprecision(2)<<student.at(i).galutinisvid<<left<<setw(18)<<fixed<<setprecision(2)<<student.at(i).galutinismed<<endl;
    }
}
