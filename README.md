# Objektinio programavimo skaičiuoklė
### **Programos veikimas: (v0.1)**

1. Paleidus programą, vartotojo yra prašoma įvesti studento vardą bei pavardę.
2. Tada yra paklausiama kokiu būdu norima įvesti tuos pažymius (įrašyti ranka arba generuoti atsitiktinai).
3. Įrašius visus pažymius ir egzamino įvertinimą, vartotojui leidžiama pasirinkti ar jis nori pridėti dar vieną studentą.
4. Įrašius norimą kiekį studentų, vartotojas turi galimybę pasirinkti rezultatus: vidurkį arba medianą.
5. Pasirinkus vartotojui yra atspausdinamas sąrašas su visais studentais ir jų  galutiniais vidurkiais arba medianomis.

### **Programos Patobulinimas: (v0.2)**
1. Pridėta galimybė nuskaityti iš failo.
2. Irašomi atsakymai į failą.
3. Prie kiekvieno studento rodoma ir mediana ir galutinis vidurkis.
4. Pridėtas rikiavimas pagal studento vardą ir pavardę.

### **Programos Patobulinimas: (v0.3)**
1. Panaudota try-catch funkcija.
2. Sukurtas mylib.cpp failas, kuris laiko visas funkcijas.

### **Programos Patobulinimas: (v0.4)**
1. Pridėtas failo generavimas, vartotojui leidžiama pasirinkti kokio dydžio failą nori sugeneruoti.
2. Pridėta rušiavimo funkcija kuri rušiuoja studentus pagal jų galutinį balą didėjimo tvarka.
3. Išvedimas dabar išveda į du skirtingus failus, viename faile studentai kurių galutinis balas 5 arba daugiau, o kitame faile mažiau nei penki.

### **Programos Patobulinimas: (v0.5)**
1.Pridėtos dvi kodo variacijos (Vienoje yra naudojamas deque, kitoje list).
2.Sudaryta lentelė iš gautų laikų naudojant skirtingas variacijas (sekundėmis):
|       **_List_**       | **1000** | **10000** | **100000** | **1000000** | **10000000** |
|:----------------------:|----------|-----------|------------|-------------|--------------|
| Skaitymas iš failo     | 0.006    | 0.072     | 0.664      | 7.149       | 67.232       |
| Studentų rušiavimas    | 0        | 0.006     | 0.079      | 1.165       | 16.014       |
| Studentų skirtsymas    | 0.004    | 0.022     | 0.235      | 2.270       | 23.914       |
| Visas programos laikas | 0.01     | 0.101     | 0.978      | 10.584      | 107.161      |
|      **_Vector_**      | **1000** | **10000** | **100000** | **1000000** | **10000000** |
| Skaitymas iš failo     | 0.007    | 0.066     | 0.450      | 4.705       | 61.931       |
| Studentų rušiavimas    | 0        | 0.006     | 0.199      | 2.459       | 15.551       |
| Studentų skirtsymas    | 0.003    | 0.023     | 0.217      | 2.051       | 21.715       |
| Visas programos laikas | 0.01     | 0.095     | 0.867      | 9.215       | 99.191       |
|       **_Deque_**      | **1000** | **10000** | **100000** | **1000000** | **10000000** |
| Skaitymas iš failo     | 0.005    | 0.044     | 0.395      | 4.435       | 42.045       |
| Studentų rušiavimas    | 0.001    | 0.031     | 0.430      | 5.721       | 67.746       |
| Studentų skirstymas    | 0.003    | 0.023     | 0.212      | 2.129       | 21.074       |
| Visas programos laikas | 0.01     | 0.098     | 1.039      | 12.286      | 130.867      |
### **Programos Patobulinimas: (v1.0)**
1.Pridėtos dvi studentų skirstymo strategijos 1 ir 2 

| Skirstymas vector | Trukmė |
|:-----------------:|--------|
| Strategija 1      | 0.025  |
| Strategija 2      | 0.039  |
| Skirstynas deque  |        |
| Strategija 1      | 0.054  |
| Strategija 2      | 0.096  |
| Skirstymas list   |        |
| Strategija 1      | 0.167  |
| Strategija 2      | 0.124  |
2. Pirma strategija remiasi skirstimu į du skirtingus vektorius vargsiukus ir kietekus
3. Antra strategija remiasi studentų kurių galutinis pažimys mažiau nei penki išrinkimas į vargšiukų saraša ir išėmimas iš pradinio studentų sarašo.

### **Programos Patobulinimas: (v1.1)**
1.Pakeista funkcija structure į class, pagal tai sutvarkytas visas kodas.
2. 
| Skirstymas vector | 1000000 | 10000000 |
|:-----------------:|---------|----------|
| Class             | 11.102  | 109.006  |
| Struct            | 9.215   | 99.191   |
3.
| Skirstymas vecto | Greitis | Makefile dydis |
|:----------------:|---------|----------------|
| -O3              | 1.00    | 70KB           |
| -O2              | 1.01    | 70KB           |
| -O1              | 1.02    | 70KB           |
| -                | 1.06    | 119KB          |

### **Galutinio skaičiavimo formulė:**
![221124441-e0c14ec4-e460-4933-825f-db93016aa331](https://user-images.githubusercontent.com/114932724/221128880-71e33630-0287-4343-875e-f2d45e2759e7.png)
