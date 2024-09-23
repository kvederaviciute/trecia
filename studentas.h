#ifndef STUDENTAS_H_INCLUDED
#define STUDENTAS_H_INCLUDED

#include "pagrindas.h"

struct Stud{
    string vardas, pavarde;
    vector<int> ND;
    int egzaminas;
};

void ivedimas(Stud & student,int m);

#endif // STUDENTAS_H_INCLUDED
