# Andmebaasi võtmed (Keys)
## 1. PRIMARY KEY
Definitsioon:
Primary Key on veerg või veergude kombinatsioon, mis identifitseerib iga kirje tabelis unikaalselt.

Kasutamine:
Tagab, et tabelis ei ole kahte sama identifikaatoriga kirjet.

Erinevus teistest võtmetest:
Ei luba NULL väärtusi ja tabelis saab olla ainult üks Primary Key

### Praktiline näide (SQL):
```sql
CREATE TABLE Opilased (
    opilane_id INT PRIMARY KEY,
    nimi VARCHAR(50)
);

SELECT * FROM Opilased;
```
<img width="389" height="188" alt="image" src="https://github.com/user-attachments/assets/918a8800-751b-4799-8bc5-77ea55e694dc" />


## 2. FOREIGN KEY
Definitsioon:
Foreign Key on veerg, mis loob seose teise tabeli Primary Key-ga.

Kasutamine:
Tagab tabelitevaheliste seoste ja andmete terviklikkuse säilimise.

Erinevus teistest võtmetest:
Võib sisaldada korduvaid väärtusi ning viitab teise tabeli andmetele.

### Praktiline näide (SQL):
```sql
CREATE TABLE Registreerimine (
    reg_id INT PRIMARY KEY,
    kursus_id INT,
    FOREIGN KEY (kursus_id) REFERENCES Kursused(kursus_id)
);

SELECT * FROM Registreerimine;
```


## 3. UNIQUE KEY
Definitsioon:
Unique Key tagab, et kõik väärtused veerus on unikaalsed.

Kasutamine:
Väldib korduvaid andmeid (nt e-mail, isikukood).

Erinevus teistest võtmetest:
Võib sisaldada NULL väärtust ja ühes tabelis võib olla mitu UNIQUE võtmet.
### Praktiline näide (SQL):
```sql
CREATE TABLE Kasutajad (
    kasutaja_id INT PRIMARY KEY,
    email VARCHAR(100) UNIQUE
);

SELECT * FROM Kasutajad;
```
<img width="455" height="218" alt="image" src="https://github.com/user-attachments/assets/91cfd30e-1a94-4949-820d-c86f6d1f0800" />

## 4. SIMPLE KEY
Definitsioon:
Simple Key on võti, mis koosneb ühest veerust.

Kasutamine:
Kasutatakse lihtsaks kirje tuvastamiseks.

Erinevus teistest võtmetest:
Koosneb ainult ühest veerust.
### Praktiline näide (SQL):
```sql
CREATE TABLE Tootajad (
    tootaja_id INT PRIMARY KEY,
    nimi VARCHAR(50)
);

SELECT * FROM Tootajad;
```
<img width="351" height="224" alt="image" src="https://github.com/user-attachments/assets/1bfe5850-2e57-4f17-89d3-e231a716b80d" />

## 5. COMPOSITE KEY
Definitsioon:
Composite Key koosneb kahest või enamast veerust.

Kasutamine:
Kui üks veerg ei taga unikaalsust.

Erinevus teistest võtmetest:
Koosneb mitmest veerust.
### Praktiline näide (SQL):
```sql
CREATE TABLE Hinded (
    opilane_id INT,
    aine_id INT,
    hinne INT,
    PRIMARY KEY (opilane_id, aine_id)
);

SELECT * FROM Hinded;
```
<img width="439" height="219" alt="image" src="https://github.com/user-attachments/assets/c038100b-0a96-4c54-a0b8-8bd0f28794da" />


## 6. COMPOUND KEY
Definitsioon:
Compound Key on Composite Key, kus kõik osad on Foreign Key-d.

Kasutamine:
Many-to-many seoste jaoks.

Erinevus teistest võtmetest:
Kõik veerud on välisvõtmed.

### Praktiline näide (SQL):
```sql
CREATE TABLE Tellimused (
    klient_id INT,
    toode_id INT,
    kogus INT,
    PRIMARY KEY (klient_id, toode_id)
);

SELECT * FROM Tellimused;
```
<img width="410" height="222" alt="image" src="https://github.com/user-attachments/assets/1081ecf4-5108-4c23-87fc-2728ed3bf8cf" />

## 7. SUPERKEY
Definitsioon:
Superkey on veerg või veergude kombinatsioon, mis tuvastab kirje unikaalselt.

Kasutamine:
Kandidaatvõtmete leidmiseks.

Erinevus teistest võtmetest:
Võib sisaldada liigseid veerge.

### Praktiline näide (SQL):
```sqlCREATE TABLE Isikud (
    id INT PRIMARY KEY,
    email VARCHAR(100) UNIQUE,
    nimi VARCHAR(50)
);

SELECT * FROM Isikud;
```
<img width="381" height="220" alt="image" src="https://github.com/user-attachments/assets/bbd71fe7-37f9-4b21-a9ec-d71fe708a901" />


## 8. Candidate Key (Kandidaatvõti)
Definitsioon:
Candidate Key on minimaalne supervõti, mis tuvastab kirje üheselt ilma liigsete veergudeta.

Kasutamine:
Valitakse Primary Key kandidaadiks.

Erinevus teistest võtmetest:
Ei sisalda ühtegi üleliigset atribuuti ja iga Candidate Key võib olla Primary Key.
```sql
CREATE TABLE Opetajad (
    opetaja_id INT PRIMARY KEY,
    isikukood VARCHAR(11) UNIQUE,
    nimi VARCHAR(50)
);

SELECT * FROM Opetajad;
```
<img width="375" height="231" alt="image" src="https://github.com/user-attachments/assets/488cb077-5aad-4f31-b382-1dc2e7b21b74" />

## 9. Alternate Key (Alternatiivvõti)
Definitsioon:
Alternate Key on Candidate Key, mida ei valitud Primary Keyks.

Kasutamine:
Tagab unikaalsuse juhtudel, kus Primary Key ei ole ainus võimalik identifikaator.

Erinevus teistest võtmetest:
On Candidate Key, mis jäi Primary Key valikust välja, kuid säilitab unikaalsuse nõude.
### Praktiline näide (SQL):
```sql
CREATE TABLE Raamatud (
    raamat_id INT PRIMARY KEY,
    isbn VARCHAR(20) UNIQUE,
    pealkiri VARCHAR(100)
);

SELECT * FROM Raamatud;

```


## Kasutatud allikad
1. [https://www.geeksforgeeks.org/dbms/difference-between-primary-key-and-foreign-key/ ](https://dev.mysql.com/doc/refman/8.0/en/create-table.html)
2. [https://en.wikipedia.org/wiki/Unique_key](https://dev.mysql.com/doc/refman/8.0/en/create-table-constraints.html 
3. https://www.theknowledgeacademy.com/blog/keys-in-sql/
4. https://dba.stackexchange.com/questions/3134/in-sql-is-it-composite-or-compound-keys
5. https://medium.com/@dewmithranaweera/different-types-of-database-keys-8ec93f5d3726
