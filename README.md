# Objektinisprog

"Rule of three" implementacija: 

Ši klasė naudoja dinaminę atmintį std::vector<int> lauke ND. Todėl reikia užtikrinti taisyklingą valdymą, kai objektas kopijuojamas ar naikinamas:

- Destruktorius užtikrina, kad atmintis, skirta namų darbų sąrašui, yra atlaisvinama.
- Kopijavimo konstruktorius užtikrina taisyklingą duomenų kopijavimą.
- Kopijavimo priskyrimo operatorius užtikrina, kad esami duomenys yra išvalomi prieš naujų duomenų kopijavimą."

Visi "Rule of three" metodai vis dar veikia:
![image](https://github.com/user-attachments/assets/37488ed8-4c92-4000-8ffd-563d803a61f6)


Sukurta bazinė klasė Žmogus yra abstrakti:
![image](https://github.com/user-attachments/assets/67b3da90-97ca-420a-9310-cd5c84d7aa8a)


Naudojami įvesties būdai:
- Rankiniu būdu: vartotojas pats įveda vardą, pavardę, namų darbus ir egzaminą.![image](https://github.com/user-attachments/assets/69cd4dbc-4a74-4ee1-8a28-3f9bb80c1ff3)

- Automatiškai: programa sugeneruoja atsitiktinius namų darbus ir egzaminų rezultatus.![image](https://github.com/user-attachments/assets/1ec762b6-2876-474e-a9c6-87ea8a87c48b)

- Iš failo: duomenys nuskaitomi iš pateikto .txt failo.![image](https://github.com/user-attachments/assets/d1291d50-4f1c-4f74-8eeb-dc01f067e19e)


Naudojami išvesties būdai:
- I faila: duomenys išvedami į .txt failus dėl galimo didelio duomenų kiekio ir galimybės juos prarasti. ![image](https://github.com/user-attachments/assets/502b1c13-083c-4ff0-8c95-5b5aa558a5a4)
