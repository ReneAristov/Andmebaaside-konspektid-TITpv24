```sql
Create database kasutajaTITpv
use kasutajaTITpv

create table loomad(
loomID int Primary key identity (1,1),
loomNimi varchar(25) not null,
vanus int check(vanus>0),
chip bit)

insert into loomad(loomNimi, vanus, chip)
values ('koer Mart', 15, 0)

select * from loomad

-- õiguste määramine
-- GRANT - õiguste lubamine - разрешение прав пользователю
--DENY -kasutaja õiguste keelamine - запрет
grant select on loomad to DirectorElina;
grant insert on loomad to DirectorElina;
grant update(vanus) on loomad to DirectorElina;

deny delete on loomad to DirectorElina;





--ulesanne
Create database MovieBaseTITpv24
use MovieBaseTITpv24

create table movies(
Mid  int Primary key identity (1,1),
moviesNimi varchar(20),
moviesYear int,
movieDir varchar(30),
movieCost money)

create table guest(
Gid  int Primary key identity (1,1),
Nimi varchar(20))

INSERT INTO movies (moviesNimi, moviesYear, movieDir, movieCost)
VALUES ('Inception', 2010, 'Christopher Nolan', 160000000),
('The Matrix', 1999, 'Lana Wachowski', 63000000),
('Interstellar', 2014, 'Christopher Nolan', 165000000),
('Pulp Fiction', 1994, 'Quentin Tarantino', 8500000),
('Fight Club', 1999, 'David Fincher', 63000000),
('Spirited Away', 2001, 'Hayao Miyazaki', 19000000),
('Gladiator', 2000, 'Ridley Scott', 103000000)

INSERT INTO guest (Nimi)
VALUES ('Elina'),
('Savelij'),
('Dasa'),
('Nastja'),
('Dima'),
('Sofja'),
('Ksusa')

select * from movies;
select * from guest

GRANT SELECT (movieDir, movieCost), UPDATE (movieDir, movieCost) ON movies TO Produtsent1;

GRANT ALTER ON movies TO Produtsent1;

GRANT SELECT, INSERT ON guest TO Produtsent1;

DENY DELETE ON movies TO Produtsent1;

DENY DELETE ON guest TO Produtsent1;

----ProdutsentElinaTIT
```

- kasutajal
```sql
select *
from fn_my_permissions('movies ', 'object');

select *
from fn_my_permissions('guest ', 'object')


DELETE FROM guest WHERE Nimi = 'Elina';

update movies set movieDir='Darja' where movieCost=160000000


select movieDir, movieCost from movies;

SELECT * FROM guest;

ALTER table movies add test int
ALTER table movies drop column test
```
