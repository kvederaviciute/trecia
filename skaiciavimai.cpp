#include "skaiciavimai.h"

void vidurkis(Stud & student, int m){
    double sum=0;
    for(int i=0;i<m;i++){
        sum=sum + student.ND.at(i);
    }
    student.vidurkis=sum/m;
}
void galutinis(Stud & student){
    student.galutinis = student.vidurkis*0.4 + student.egzaminas*0.6;
}
