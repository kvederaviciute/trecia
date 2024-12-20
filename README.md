# Objektinisprog

Programos įdiegimo ir išdiegimo instrukcija su .exe failu:
- Įdiegimas:
  - Atsisiųskite release.zip failą
  - Pajunkite v3.0setup failą ir pradėkite instaliaciją (paspauskite next ir tuomet spauskite fiinish)
  - Dabar galite rasti programą studentai darbalaukyje ir programų naršyklėje
- Išdiegimas:
  - Atidarius v3.0setup.msi failą pasirinkti "Remove" arba
  - Settings -> Apps -> Installed Apps; Surasti v3.0_setup.exe ir pasirinkti "Remove".

Programos versijų aprašymas:
- v0.1 release - Paruoštas ir įkeltas pradinis kodas, lėtai veikiantis, neturintis kai kurių reikalingų funkcijų.
- v0.2 - Pridėtas studentų skirstymas į dvi grupes - kietiakus ir vargšiukus (Studentų atžvilgiu išlaikiusius ir neišlaikiusius dalyką).
- v0.3 release - Išanalizuotas ir pasirinktas sparčiau veikiantis duomenų konteineris - vector (Analizuojami įvairių funkcijų atlikimo greičiai naudojant vector ir list konteinerius).
- v1.0 - Naudotos ir lyginamos trys studentų į grupes skirstymo strategijos, pasirinkta spartesnė, kodas sutvarkytas ir paruoštas naudoti.
- v1.1 - Buvusią struktūrą pakeitėme į klasę ir lyginome veikimo laikus, taip pat tikrinome skirtingus kompiliavimo flag'us.
- v1.2 - Panaudoti ir sukurti "Rule of three" konstruktoriai ir destruktoriai, perdengti įvesties ir išvesties metodai darbui su Studentų klasę.
- v1.5 - Sukurta bazinė žmogaus klasė, o studento klasė pakeista į dukterinę.
- v2.0 - Sukurta dokumentacija naudojant doxyblocks programą.
- v3.0 - Suteikta galimybė vartotojams parsisiųsti programą ir naudoti iš darbalaukio.

Programos paleidimo ir įdiegimo su cmake failu:
- Pirmiausia reikia parsisiųsti CMake programą, kad būtų galima kurti CMakeLists.txt failus.
- Tuomet reikia parsisiųsti "v1.0 (vector)" arba "v1.0 (list)" (arba abi) direktoriją (-as).
- Taip pat savo kompiuteryje reikia įsijungti "Terminal" ir pirmiausia įvesti kelią iki direktorijos, kuri buvo parsiųsta: "cd "čia įrašyti kelią iki direktorijos"", tuomet paspausti "Enter" ir įvesti "./run.sh" (jei nesuveiktų "./run.sh", prieš "./run.sh" reiktų dar suvesti "chmod +x run.sh").
- Po "./run.sh" paleidomo - programa terminale pasileis.
- Pakartotiniam programos paleidimui terminale vėl reikės įvesti kelią iki direktorijos ir vietoj "./run.sh", gelėsite įvesti "/v1.0_vector" (std::vector atveju) arba "./v1.0_list" (std::list atveju).

Programos naudojimo instrukcija:

- Paleidžiama programa
- Pirmas klausimas ar norite generuoti failus įveskite 0 jei ne, 1 - jei taip.
- Įvedus 1 sugeneruos jums 100000 studentu faila, kitu atveju pereis prie kito klausimo
- Antras klausimas ar norėsite duomenis skaityti iš failo įveskite 0 jei ne, 1 - jei taip.
- Įvedus 1 paprašys jūsų įrašyti failo esančio tame pačiame aplanke kaip programa pavadinimą pagal pateiktą formatą ir jei toks failas egzistuos bus atlikti skaičiavimai ir išvesti rezultatų failai, kitu atveju pereis prie kito klausimo.
- Trečias klausimas kiek studentų yra jūsų kurse, įvedamas sveikas skaičius ir pereinama prie kito klausimo
- Studento vardas: Ivedamas vardas
- Studento pavarde: Ivedama pavarde
- Ketvirtas pasirenkamas klausimas ar norite atsitiktinai generuoti studento namu darbu ir egzamino rezultatus 1 - jei taip, 0 - jei ne;
- Jei ivedamas 0: 1. Prašoma įvesti 1-ųjų namų darbų rezultatą ir to pat klausia iki tol kol įvedate -1 (Klausimo sąlygoje tai paminima) 2. Tuomet prašoma įvesti egzamino rezultatą
- Jei įvedamas 1: 1. Jei tai pirmas studentas, klausiama kiek namų darbų norima sugeneruoti: Ivedamas sveikas skaičius
- Studentų įvedimo ciklas kartosis iki tol kol bus aprašyti visi studentai ir tuomet failai išvedami (kietiakai - studentai išlaikę dalyką, vargšiukai - studentai neišlaikę dalyko)
