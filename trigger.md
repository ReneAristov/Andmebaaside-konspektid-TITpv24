## Trigger - triger - päästik
- andmebaasi objekt, mis automaatselt käivitub tabeli sündmused (INSERT, UPDATE, DELETE).

```sql
create database trigertitpv24;
use trigertitpv24;

--
Create table linnad(
linnID int PRIMARY KEY IDENTITY (1,1),
linnanimi varchar(15) NOT NULL,
rahvaarv int);

 --tabel, mis täidab triger
Create table logi(
id int PRIMARY KEY IDENTITY (1,1),
kasutaja varchar(25),
aeg DATETIME,
toiming  varchar(100),
andmed TEXT --triger automaatselt lisab mida sekretaar lisas/kustutas tabelisse linnad
)

select * from linnad;
select * from logi;

--Trigger lisatud kirjeid jälgimiseks tabelis “linnad” – INSERT
--Jälgib andmete sisestamine tabelis linnad ja teeb vastava kirje tabelis logi


CREATE TRIGGER linnaLisamine
ON linnad --tabelinimi, mis on vaja jälgida
FOR INSERT
AS
INSERT INTO logi(kasutaja, aeg, toiming, andmed)
SELECT
SYSTEM_USER,
GETDATE(),  --aeg
'on tehtud INSERT käsk',  --toiming
inserted.linnanimi  --andmed
FROM inserted;

--kontrollimiseks Insert into linnad
INSERT INTO linnad(linnanimi, rahvaarv)
VALUES ('Tallinn', 26000);

select * from linnad;
select * from logi;

--trigeri muutmine
ALTER TRIGGER linnaLisamine
ON linnad --tabelinimi, mis on vaja jälgida
FOR INSERT
AS
INSERT INTO logi(kasutaja, aeg, toiming, andmed)
SELECT
SYSTEM_USER,
GETDATE(),  --aeg
'on tehtud INSERT käsk',  --toiming
CONCAT('linn: ', inserted.linnanimi , ' rahvaarv: ', inserted.rahvaarv)  --andmed
FROM inserted;
```
<img width="561" height="491" alt="{EE692E60-4441-4F30-83C9-CC1CE7DE8043}" src="https://github.com/user-attachments/assets/d086bcca-02c5-48ac-8ccf-bcc7bb2a202e" />
