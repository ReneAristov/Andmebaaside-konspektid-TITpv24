# SQL Server – Kasutajate autentimine ja õiguste haldamine
Mis on autentimine SQL Serveris?
Autentimine tähendab kasutaja tuvastamist ehk kontrollimist, kas kasutajal on õigus SQL Serverisse sisse logida.

SQL Serveris kasutatakse kahte peamist autentimise tüüpi:

## 1. Windows Authentication
Selle puhul kasutatakse samu kasutajaandmeid, millega logitakse sisse Windows operatsioonisüsteemi.

Kasutajanimi ja parool on seotud Windowsiga
Turvalisem lahendus
Paroole haldab Windows
Kasutaja ei pea eraldi SQL Serveri parooli teadma
## 2. SQL Server Authentication
Selle puhul luuakse kasutaja otse SQL Serverisse.

Kasutaja ei ole seotud Windowsiga
Määratakse eraldi kasutajanimi ja parool
Sobib veebirakenduste jaoks
----------------------------------
Näide kasutajast: DirectorElina
Parool: director
----------------------------------
# Kasutaja loomine SQL Serveris
## 1. Serveritaseme kasutaja loomine (Login)
Sammud
Ava:

Security → Logins
Tee paremklikk ja vali:

New Login...

<img width="698" height="645" alt="{E16E0438-0744-45B5-8704-CE028DC231F5}" src="https://github.com/user-attachments/assets/740f1b51-8803-4072-a958-1757d7ce2b93" />

Harjutamiseks võib eemaldada linnukese:  User must change password at next login
Server Roles
Menüüst Server Roles saab määrata serveri üldised õigused.

Tavaliselt piisab rollist: public


<img width="695" height="657" alt="{145DCB27-787E-4D4C-9D33-49A241F94227}" src="https://github.com/user-attachments/assets/7fcc93b4-c403-48eb-8123-e589901596a9" />
<img width="287" height="607" alt="{42E1311D-D6AC-4C24-870F-C90D4382112E}" src="https://github.com/user-attachments/assets/90346578-f9a1-4738-94e5-c7bb72e1d713" />


## 2. Andmebaasi kasutaja loomine (User)
Ava:

Database → Security → Users
Tee paremklikk:  New User...

Seosta kasutaja loginiga

Membership ja õigused
Menüüst Membership saab määrata kasutaja rollid.

db_datareader → võib lugeda
db_datawriter → võib kirjutada
<img width="498" height="499" alt="{260D7F18-7608-4D68-A0AF-48A01DFC8F39}" src="https://github.com/user-attachments/assets/dc5825ac-db85-4841-aa89-eefe23177495" />

SQL Server Authentication Mode muutmine
Kui ilmub viga: Error 18456, siis on tavaliselt lubatud ainult Windows Authentication.
Lahendus
Server → Properties
Security
Vali: SQL Server and Windows Authentication mode
GRANT käsud õiguste jagamiseks
GRANT käsuga antakse kasutajale õigused.

Käsk	Tähendus
SELECT	Lugemine
INSERT	Lisamine
UPDATE	Muutmine
DELETE	Kustutamine

- 
<img width="493" height="210" alt="{F7035FD2-859A-4ADE-AA4A-0DB9FC608D4B}" src="https://github.com/user-attachments/assets/00cbd5ac-0262-4286-8ecc-9a89b4ea4756" />


```sql
-- õiguste määramine
-- GRANT - õiguste lubamine - разрешение прав пользователю
--DENY -kasutaja õiguste keelamine - запрет
grant select on loomad to DirectorElina;
grant insert on loomad to DirectorElina;

deny delete on loomad to DirectorElina;
```
-
<img width="267" height="225" alt="{61DB6A4B-228B-4E54-BBB3-8AC23AA53248}" src="https://github.com/user-attachments/assets/75153fa1-c376-49a9-9eac-b24baa3cb141" />

-
<img width="671" height="264" alt="{1A2622C9-78BC-41E0-ACA4-BFCCF98DEA6E}" src="https://github.com/user-attachments/assets/722503d8-897f-48bc-beef-5180bf48357c" />

-
<img width="446" height="137" alt="{F1333917-80B1-4308-9A28-277860A2577B}" src="https://github.com/user-attachments/assets/c3910f60-f3a6-43a4-9e67-69476ae4304d" />

-
<img width="328" height="318" alt="{4A1DDEBC-C8C9-4961-AD41-D1B7408596D7}" src="https://github.com/user-attachments/assets/027b06a3-d092-4025-aea4-d61d836925b7" />

-
<img width="341" height="200" alt="{EC585A0C-5524-4EFF-989C-E9AB31821776}" src="https://github.com/user-attachments/assets/0f69c487-1017-44c3-886b-53ecd222bb86" />

