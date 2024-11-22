# Objektinisprog


Releas'ų aprašymas:
* v0.1 release - Paruoštas ir įkeltas pradinis kodas, lėtai veikiantis, neturintis kai kurių reikalingų funkcijų.
* v0.2 - Pridėtas studentų skirstymas į dvi grupes - kietiakus ir vargšiukus (Studentų atžvilgiu išlaikiusius ir neišlaikiusius dalyką).
* v0.3 release - Išanalizuotas ir pasirinktas sparčiau veikiantis duomenų konteineris - vector (Analizuojami įvairių funkcijų atlikimo greičiai naudojant vector ir list konteinerius).
* v1.0 - Naudotos ir lyginamos trys studentų į grupes skirstymo strategijos, pasirinkta spartesnė, kodas sutvarkytas ir paruoštas naudoti.

Programos naudojimo instrukcija:
* Paleidžiama programa
* Pirmas klausimas ar norite generuoti failus įveskite 0 jei ne, 1 - jei taip.
* Įvedus 1 sugeneruos jums 100000 studentu faila, kitu atveju pereis prie kito klausimo
* Antras klausimas ar norėsite duomenis skaityti iš failo įveskite 0 jei ne, 1 - jei taip.
* Įvedus 1 paprašys jūsų įrašyti failo esančio tame pačiame aplanke kaip programa pavadinimą pagal pateiktą formatą ir jei toks failas egzistuos bus atlikti skaičiavimai ir išvesti rezultatų failai, kitu atveju pereis prie kito klausimo.
* Trečias klausimas kiek studentų yra jūsų kurse, įvedamas sveikas skaičius ir pereinama prie kito klausimo
* Studento vardas: Ivedamas vardas
* Studento pavarde: Ivedama pavarde
* Ketvirtas pasirenkamas klausimas ar norite atsitiktinai generuoti studento namu darbu ir egzamino rezultatus 1 - jei taip, 0 - jei ne;
* Jei ivedamas 0: 1. Prašoma įvesti 1-ųjų namų darbų rezultatą ir to pat klausia iki tol kol įvedate -1 (Klausimo sąlygoje tai paminima) 2. Tuomet prašoma įvesti egzamino rezultatą
* Jei įvedamas 1: 1. Jei tai pirmas studentas, klausiama kiek namų darbų norima sugeneruoti: Ivedamas sveikas skaičius
* Studentų įvedimo ciklas kartosis iki tol kol bus aprašyti visi studentai ir tuomet failai išvedami (kietiakai - studentai išlaikę dalyką, vargšiukai - studentai neišlaikę dalyko)
