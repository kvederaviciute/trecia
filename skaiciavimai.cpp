#include "skaiciavimai.h"

void vidurkis(Stud & student, int m){
    double sum=0;
    for(int i=0;i<m;i++){
        sum=sum + student.ND.at(i);
    }
    student.vidurkis=sum/m;
}
void galutinisvid(Stud & student){
    student.galutinisvid = student.vidurkis*0.4 + student.egzaminas*0.6;
}
void mediana(Stud & student, int m){
    double d=2;
    vector<int> nd = student.ND;
    sort(nd.begin(), nd.end());
    if(m%2==0){
        student.mediana = (nd[m / 2 - 1] + nd[m / 2]) / d;
    }
    else{
        student.mediana = nd[m/2];
    }
}

void rikiavimas(vector<Stud>& studentai) {
    sort(studentai.begin(), studentai.end(), [](const Stud& a, const Stud& b) {
        return a.vardas < b.vardas;
    });
}

void galutinismed(Stud & student){
    student.galutinismed = student.mediana*0.4 + student.egzaminas*0.6;
}
