#ifndef STUDENTAS_H_INCLUDED
#define STUDENTAS_H_INCLUDED

#include "pagrindas.h"

struct Stud{
    string vardas, pavarde;
    vector<int> ND;
    double galutinis, egzaminas, vidurkis, mediana;
};

void ivedimas(Stud & student,int m);
void valymas(Stud & student);
void isvedimasgal(vector<Stud> student,int n);

#endif // STUDENTAS_H_INCLUDED
