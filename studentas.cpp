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
    else
    {
        cout<<"skaicius turi buti arba 0 arba 1"<<endl;
        exit(1);
    }
    cout <<"Studento saugojamo atmintyje adresas: "<< &student <<endl;
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
void isvedimasgal(vector<Stud> student,int n,string m)
{
    ofstream out(m);
    out<<left<<setw(15)<<"Vardas "<<left<<setw(20)<<"Pavarde "<<left<<setw(18)<<"Galutinis (Vid.) "<<left<<setw(18)<<"Galutinis (Med.) "<<endl;
    out<<"--------------------------------------------------------------------"<<endl;
    for(int i=0; i<n; i++)
    {
        out<<left<<setw(15)<<student.at(i).vardas<<left<<setw(20)<<student.at(i).pavarde<<left<<setw(18)<<fixed<<setprecision(2)<<student.at(i).galutinisvid<<left<<setw(18)<<fixed<<setprecision(2)<<student.at(i).galutinismed<<endl;
    }
}
void generavimas(int n,string m)
{
    auto start = std::chrono::high_resolution_clock::now();
    ofstream out(m);
    int ndk = rand() % 20 + 1;

    out << "Vardas Pavarde ";
    for (int i = 1; i <= ndk; i++)
    {
        out << "ND" << i << " ";
    }
    out << "Egzaminas" << endl;
    for (int i = 1; i <= n; i++)
    {
        out << "Vardas" << i << " Pavarde" << i << " ";
        for (int j = 0; j < ndk; j++)
        {
            out << rand() % 10 + 1 << " ";
        }
        out << rand() % 10 + 1 << endl;
    }

    out.close();

    auto stop = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = stop - start;

    cout<<m<<" failo kurimo laikas: "<<fixed<<setprecision(6)<<duration.count()<<endl;
}
