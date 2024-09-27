#include "studentas.h"

void ivedimas(Stud & student, int & m)
{
    int a,d,eg=11;
    cout<<"Vardas: ";
    cin>>student.vardas;
    cout<<"Pavarde: ";
    cin>>student.pavarde;
    cout<<"Ar norite atsitiktinai generuoti rezultatus?(0 - ne, 1 - taip): ";
    cin>>a;
    if(cin.fail())
    {
        cout<<"Buvo ivestas netinkamas simbolis"<<endl;
        exit(1);
    }
    else if(a==0)
    {
        if(m==0)
        {
            namudarbaibe(student,m);
        }
        else
        {
            namudarbaisu(student,m);
        }
        while(eg<0 || eg>10)
        {
            cout<<"Egzamino rezultatas: ";
            cin>>eg;
            if(cin.fail())
            {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cout<<"buvo ivestas netinkamas simbolis"<<endl;
                eg=11;
            }
            else if(eg>=0 && eg<=10)
            {
                student.egzaminas=eg;
            }
            else
            {
                cout<<"Egzamino rezultatas turi buti desimtbaleje sistemoje"<<endl;
            }
        }
    }
    else if(a==1)
    {
        if(m==0)
        {
            cout<<"Kiek namu darbu norite sugeneruoti: ";
            cin>>m;
            for(int i=0; i<m; i++)
            {
                d=rand() % 10 + 1;
                student.ND.push_back(d);
            }
            student.egzaminas=rand() % 10 +1;
        }
        else
        {
            for(int i=0; i<m; i++)
            {
                d=rand() % 10 + 1;
                student.ND.push_back(d);
            }
            student.egzaminas=rand() % 10 +1;
        }
    }


}

void namudarbaibe(Stud & student, int & m)
{
    int n=11;
    while(n<0 || n>10)
    {
        cout<<"Iveskite "<<m+1<<"-uju namu darbu rezultata (noredami baigti ivedima, iveskite skaiciu -1): ";
        cin>>n;
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout<<"buvo ivestas netinkamas simbolis"<<endl;
            n=11;
        }
        else if(n>=0 && n<=10)
        {
            student.ND.push_back(n);
            m++;
            n=11;
        }
        else if(n==-1)
        {
            break;
        }
        else
        {
            cout<<"Egzamino rezultatas turi buti desimtbaleje sistemoje"<<endl;
        }
    }
}
void namudarbaisu(Stud & student, int m)
{
    int n=11;
    for(int i=0; i<m; i++)
    {
        while(n<0 || n>10)
        {
            cout<<"Iveskite "<<i+1<<"-uju namu darbu rezultata (noredami baigti ivedima, iveskite skaiciu -1): ";
            cin>>n;
            if(cin.fail())
            {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cout<<"buvo ivestas netinkamas simbolis"<<endl;
                n=11;
            }
            else if(n>=0 && n<=10)
            {
                student.ND.push_back(n);
                n=11;
                break;
            }
            else if(n==-1)
            {
                break;
            }
            else
            {
                cout<<"Egzamino rezultatas turi buti desimtbaleje sistemoje"<<endl;
            }
        }
    }

}
void valymas(Stud & student)
{
    student.vardas.clear();
    student.pavarde.clear();
    student.ND.clear();
}
void isvedimasgal(vector<Stud> student,int n)
{
    cout<<left<<setw(10)<<"Vardas "<<left<<setw(15)<<"Pavarde "<<left<<setw(18)<<"Galutinis (Vid.) "<<left<<setw(18)<<"Galutinis (Med.) "<<endl;
    cout<<"---------------------------------------------------------"<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<left<<setw(10)<<student.at(i).vardas<<left<<setw(15)<<student.at(i).pavarde<<left<<setw(18)<<fixed<<setprecision(2)<<student.at(i).galutinisvid<<left<<setw(18)<<fixed<<setprecision(2)<<student.at(i).galutinismed<<endl;
    }
}
