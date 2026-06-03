# Andmebaaside konspektid | Rene

[Põhimõisted](README.md) | [ProtseduuridSql](protsedur.md) | [ProtseduuridXAMPP](protseduurXammp.md) | [kasutajadSql](kasutajadsql.md) | [TrigerSql](trigger.md) | [TriggerXAMPP](trigerXampp.md) | [keys.md](keys.md) | [Hotelliruum.md](hotelliruum.md) | [Kusimused](kusimused.md) |

andmebaasidega seotud SQL ja konspektid
## Sisukord
- [Põhimõisted](#põhimõisted)
- [Andmetüübid](#andmetüübid)
- [SQL - structure Query Language - struktureeritud päringu keel](#SQL-structure-Query-Language-struktureeritud-päringu-keel)
- [Seosed tabelivahelised seosed](#Seosed-tabelivahelised-seosed)
- [Piirangud](#Piirangud)
- [ALTER TABLE](#ALTER-TABLE)


# Põhimõisted
- andmebaas - struktureeritud andme kogus
- tabel - olem - сущность - ENTITY
- veerg - väli - поле - столбец
- rida - kirja - записи
- andmebaasi haaldussüsteem - tarkvara mille abil saab luua andmebaas - MariaDB / XAMPP, SQL Server 
  <img width="474" height="505" alt="{5A884E26-31F8-4733-B59C-C6B4C44D1044}" src="https://github.com/user-attachments/assets/753e2137-4a27-4ba7-aba1-65587077dfbd" />

- primaarne võti - Primary key - veerg(tavaliselt id nimega), unikaalne indifikaator, mis eristab iga kirje
- välisvõti - Foregein key - FK- veerg, mis loob seos teise tabeli primaarvõtmega
- päring - QUERY - запрос

# Andmetüübid
```
1. Numbrilised: INT, SmallINT, float, decimal(5,2)
2. Tekst/Sümbolised: varchar(255), char(5), TEXT
3. Loogilised: boolean, true/false, bit, bool
4. Kuupäeva: date, time, tatetime
```

## SQL-structure Query Language-struktureeritud päringu keel
- Tabeli loomine
```
CREATE DATABASE TITpv24baas;
--ab kustutamine
Drop DATABASE Logitpv24Baas;
use TITPV24baas;
--tabeli loomine
Create table opilane(
opilaneID int Primary Key identity(1,1), --automaatselt täidab numbritega
eesnimi varchar(25),
perenimi varchar(30) NOT NULL,
synniaeg DATE,
stip bit,
mobiil varchar(13),
aadress TEXT,
keskmineHinne decimal(2,1) );--(2--kokku, 1- peale komat nt 4.5)
SELECT * FROM opilane;
```
- Andmete sisestamine tabelisse
```
INSERT INTO opilane
VALUES ('Rene','Aristov', '2007-08-23',1,'+3725138479','Tallinn', 4.5)
Insert INTO opilane(perenimi, eesnimi, keskmineHinne)
VALUES ('Holovanov', 'Ivan', 4.2),
('Holovanov', 'Ivan', 4.2),
('Sereda', 'Ivan', 4.2),
('Suvorov', 'Marko', 4.2);
```
# Seosed tabelivahelised seosed
- üks-ühele (nt mees-naine)
- üks-mitmele (nt ema-lapsed)
<img width="223" height="489" alt="{B9182944-284F-46E8-8C16-39DECC36AF26}" src="https://github.com/user-attachments/assets/cff14ab8-b20e-4f18-90e6-90e2318251de" />

- mitu-mitmele (nt õpilased - õpetajad)

## Piirangud
- constraint - ограничения
1. PRIMARY KEY
2. FOREIGN KEY
3. CHECK
4. NOT NULL
5. UNIQUE

```sql
CREATE TABLE opitamine(
opetamineID int PRIMARY KEY identity(1,1),
kuupaev DATE,
oppeaine varchar(30),
opilaneID int,
FOREIGN KEY (opilaneID) REFERENCES opilane(opilaneID),
hinne int CHECK(hinne<=5));

SELECT * FROM opitamine;
SELECT * FROM opilane;

INSERT INTO opitamine
VALUES ('2026-04-16', 'andmebaasid', 1, 5)
```

## ALTER TABLE
-tabeli struktuuri muutmine (struktuur: veerudeandmed,andmetüübid, piirangud)

```sql
--uue veeru lisamine
ALTER TABLE opilane ADD isikukood varchar(11);

--veeru kustutamine
ALTER TABLE opilane DROP COLUMN isikukood;

--andmetüübi muutmine varchar(11)-->char(11)
ALTER TABLE opilane ALTER COLUMN isikukood char(11);

--SISSEEHITATUD PROTSEDUUR, MIS NÄITAB TABELI STRUKTUUR
sp_help opilane;

```
```sql
--PK lisamine
ALTER TABLE ryhm ADD CONSTRAINT pk_ryhm PRIMARY KEY (ryhmId);
--UNIQUE lisamine
ALTER TABLE ryhm ADD CONSTRAINT un_ryhm UNIQUE (ryhmNimi);

--kontrollimiseks täidame tabilit ryhm
SELECT * FROM ryhm;
INSERT INTO ryhm (ryhmId, ryhmNimi)
VALUES (2, 'TITpe24');

--lisamine Foregein Key - võõrvõti-välivõti
ALTER TABLE opilane ADD ryhmID int;
SELECT * FROM opilane;
ALTER TABLE opilane ADD CONSTRAINT fk_ryhm
FOREIGN KEY (ryhmId) REFERENCES ryhm(ryhmId);

--kontrollimiseks- täidame tabeli opilane
Insert INTO opilane
VALUES ('Grika', 'Renon', '2002-12-3',1,'+35423','Tallinn', 4.5, '5454545', 1);
```
