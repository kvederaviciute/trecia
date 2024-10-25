#ifndef STUDENTAS_H_INCLUDED
#define STUDENTAS_H_INCLUDED

#include "pagrindas.h"

struct Stud
{
    string vardas, pavarde;
    vector<int> ND;
    double galutinisvid, egzaminas, vidurkis, mediana,galutinismed;
};

void ivedimas(Stud & student, int & m);
void namudarbaibe(Stud & student, int & m);
void namudarbaisu(Stud & student, int m);
void valymas(Stud & student);
void isvedimasgal(vector<Stud> student,int n,string m);
void isvedimasgall(list<Stud> student,int n,string m);
void generavimas(int n,string m);

#endif // STUDENTAS_H_INCLUDED
