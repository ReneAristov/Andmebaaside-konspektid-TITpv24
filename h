Create database retsepti_raamat
use retsepti_raamat

create table kasutaja(
kasutajaId int primary key identity(1,1),
eesnimi varchar(50),
perenimi varchar(50),
email varchar(50)
)
INSERT INTO kasutaja
VALUES ('Rene','Aristov','rene@mail.ee'),
('Mari','Liis','mari@mail.ee'),
('Jaan','Kek','jaan@mail.ee'),
('Marko','Loh','Marko@mail.ee'),
('Sanja','netu','sanja@mail.ee');

SELECT * FROM kasutaja;






create table kategooria(
kategooriaId int primary key identity(1,1),
kategooriaNimi varchar(50)
)
INSERT INTO kategooria
VALUES('Supid'),
('Magustoidud'),
('Pasta'),
('Salatid'),
('Lihatoidud');

SELECT * FROM kategooria;





create table toiduaine(
toiduaineId int primary key identity(1,1),
toiduaineNimi varchar(50)
)
INSERT INTO toiduaine
VALUES
('Piim'),
('Suhkur'),
('Jahu'),
('Kanafilee'),
('Tomat');

SELECT * FROM toiduaine;




create table yhik(
    yhikId int primary key identity(1,1),
    yhikNimi varchar(50)
)
INSERT INTO yhik
VALUES
('tk'),
('ml'),
('kg'),
('g'),
('g');

SELECT * FROM yhik;






create table retsept(
retseptId int primary key identity(1,1),
retseptiNimi varchar(50),
kirjeldus varchar(50),
juhend varchar(50),
sisestatudKp date,
kasutajaId int foreign key references kasutaja(kasutajaId),
kategooriaId int foreign key references kategooria(kategooriaId)
)
INSERT INTO retsept
VALUES
('Pannkoogid','Magusad','Sega','2024-01-01',1,2),
('Tomatisupp','Supp','Keeda','2024-01-02',2,1),
('Kana pasta','Pasta','Prae','2024-01-03',3,3),
('Salat','Värske','Haki','2024-01-04',4,4),
('Kook','Magus','Küpseta','2024-01-05',5,2);

SELECT * FROM retsept;





create table koostis(
koostisId int primary key identity(1,1),
kogus int,
retseptRetseptId int foreign key references retsept(retseptId),
toiduaineId int foreign key references toiduaine(toiduaineId),
yhikId int foreign key references yhik(yhikId)
)
INSERT INTO koostis
VALUES
(200,1,1,3),
(50,1,2,1),
(100,2,5,3),
(300,3,4,1),
(2,4,5,5);
SELECT * FROM koostis;




create table tehtud(
tehtudId int primary key identity(1,1),
tehtudKp date,
retseptId int foreign key references retsept(retseptId)
)
INSERT INTO tehtud
VALUES
('2024-02-01',1),
('2024-02-02',2),
('2024-02-03',3),
('2024-02-04',4),
('2024-02-05',5);

SELECT * FROM tehtud;







--Minu uus tabel

CREATE TABLE toiduaineHind (
    hindId INT PRIMARY KEY IDENTITY(1,1),
    toiduaineId INT FOREIGN KEY REFERENCES toiduaine(toiduaineId),
    hind DECIMAL(10,2),
    lisatudKp DATE DEFAULT GETDATE()
);
INSERT INTO toiduaineHind (toiduaineId, hind)
VALUES
(1, 1.20),   
(2, 0.80),  
(3, 3.50),   
(4, 7.00),  
(5, 2.20);   







--Protseduurid 3



CREATE PROCEDURE muudaTabeliNimi
@vanaNimi varchar(50),
@uusNimi varchar(50)
AS
BEGIN
EXEC sp_rename @vanaNimi, @uusNimi;

SELECT name FROM sys.tables;
END
EXEC muudaTabeliNimi 'kasutaja', 'kasutaja2';








CREATE PROCEDURE lisaVeerg
@tabel varchar(50),
@veeruNimi varchar(50),
@tyyp varchar(50)
AS
BEGIN
DECLARE @sql varchar(200);
SET @sql = 'ALTER TABLE ' + @tabel + ' ADD ' + @veeruNimi + ' ' + @tyyp;
EXEC(@sql);
SELECT name FROM sys.columns WHERE object_id = OBJECT_ID(@tabel);
END
EXEC lisaVeerg 'kasutaja2', 'telefon', 'varchar(20)';







CREATE PROCEDURE muudaVeer
@tabel varchar(50),
@veerg varchar(50),
@uusTyyp varchar(50)
AS
BEGIN
DECLARE @sql varchar(200);
SET @sql = 'ALTER TABLE ' + @tabel + ' ALTER COLUMN ' + @veerg + ' ' + @uusTyyp;
EXEC(@sql);
SELECT name, system_type_id 
FROM sys.columns 
WHERE object_id = OBJECT_ID(@tabel) AND name=@veerg;
END

EXEC muudaVeer 'kasutaja2', 'email', 'varchar(200)';








--Minu protseduur

CREATE PROCEDURE leiaKoigeKallim
AS
BEGIN
    SELECT TOP 1
        t.toiduaineNimi,
        h.hind,
        CASE 
            WHEN h.hind < 2 THEN 'soodne'
            ELSE 'kallis'
        END AS hinnang
    FROM toiduaineHind h
    JOIN toiduaine t ON t.toiduaineId = h.toiduaineId
    ORDER BY h.hind DESC;
END;

EXEC leiaKoigeKallim;









CREATE PROCEDURE otsiKasutajaTahega
    @otsiTaht VARCHAR(50)
AS
BEGIN
    SELECT *
    FROM kasutaja
    WHERE eesnimi LIKE '%' + @otsiTaht + '%'
       OR perenimi LIKE '%' + @otsiTaht + '%'
       OR email LIKE '%' + @otsiTaht + '%';
END;

EXEC otsiKasutajaTahega 'r';



