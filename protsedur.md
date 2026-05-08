## SQL Protseduurid
- store protcedure - salvestatud protseduurid - хранимые процедуры
- sama nagu funktsioonid programmerimises - mingid tefevused mis käivitakse automaatselt protseduuri kasutamisel
  
```sql
CREATE PROCEDURE lisaGuest
-- @parameetrid
@uusNimi varchar(25),
@uusPerenimi varchar(30),
@kuupäev date
AS
BEGIN
--protseduuri sisu
	insert into guest(firstname , lastname, membersince)
	values(@uusNimi,@uusPerenimi,@kuupäev);
	select * from guest;
END
```



<img width="203" height="143" alt="{C4CED160-B198-4EEE-B753-E4E9C70508E6}" src="https://github.com/user-attachments/assets/32acda5f-45b3-4012-a289-66eb215abc94" />

<img width="479" height="242" alt="{E29041E1-E8F2-4272-A311-50B535851DB2}" src="https://github.com/user-attachments/assets/28bdc918-fbc1-4916-a6a0-2fe80774dc4d" />

<img width="509" height="619" alt="{F2259D21-2A33-4994-AEE5-765FE785A3F4}" src="https://github.com/user-attachments/assets/d660ade3-d274-4d85-868e-7b0cecbc1936" />
```sql

CREATE PRoCEDURE kustutasGuest
@kustutaId int
AS
BEGIN
select * from guest;
delete from guest where guestID=@kustutaId;
select * from guest;
END

--kutse
EXEC kustutasGuest 2;
```

<img width="624" height="368" alt="{6A6D2795-7375-47A0-A296-0EE2ED977B27}" src="https://github.com/user-attachments/assets/6dadfeff-eee7-4cae-85e4-769510fc850a" />

```sql
--otsing esimese tähe järgi
Create procedure otsingtaht
@taht char(1)
AS
BEGIN
SELECT * FROM guest where lastname LIKE @taht + '%'; --% teised sümboolid  
END
--kutse
EXEC otsingtaht 'P'
```

	<img width="524" height="361" alt="{578F0FE4-0BB0-46FB-8176-79418944F471}" src="https://github.com/user-attachments/assets/455dc607-f34a-4be9-abd1-1c5a1eaa57c7" />

```sql
--lisame uus veerg
ALTER TABLE guest ADD arveSumma money;
select * from guest;

Update guest set arveSumma=1939 where guestID=5
```

```sql
---kutse

DECLARE @minArve MONEY, @maxArve MONEY;

EXEC minmaxArve @minArve OUTPUT, @maxArve OUTPUT;

PRINT 'Min arve = ' + CONVERT(varchar, @minArve);
PRINT 'Max arve = ' + CONVERT(varchar, @maxArve);
```

<img width="540" height="363" alt="{A8A5D3FD-75EB-41A7-9369-0E8922231C5C}" src="https://github.com/user-attachments/assets/767b054b-e871-44ec-b354-aa79592dde30" />


<img width="527" height="293" alt="{4B430CCC-DC54-4079-9569-CB6F205DFF9C}" src="https://github.com/user-attachments/assets/0333c7d6-e4f4-439a-9d24-a8db2714ceb6" />


```sql
--Protseduur veeru lisamiseks või kustutamiseks
CREATE PROCEDURE muudatus
    @tegevus varchar(10),
    @tabelinimi varchar(25),
    @veerunimi varchar(25),
    @tyyp varchar(25) = NULL
AS
BEGIN
    DECLARE @sqltegevus varchar(max);

    SET @sqltegevus = CASE 
        WHEN @tegevus = 'add' THEN 
            CONCAT('ALTER TABLE ', @tabelinimi, ' ADD ', @veerunimi, ' ', @tyyp)

        WHEN @tegevus = 'drop' THEN 
            CONCAT('ALTER TABLE ', @tabelinimi, ' DROP COLUMN ', @veerunimi)
    END;

    PRINT @sqltegevus;
    EXEC (@sqltegevus);
END;

--kutse
Exec muudatus 'add', 'guest', 'testVeerg', int 
Select * from guest
Exec muudatus 'drop', 'guest', 'testVeerg' 
```


<img width="612" height="516" alt="{575C00D3-BB4B-40E7-846A-6CB8AF7D9349}" src="https://github.com/user-attachments/assets/1681b790-1a0d-4258-9275-ec580183a521" />


```sql
--7. Protseduur, mis kuvab eesnimi, arveSumma ja lisab automaatselt hinnangu 

        kui hind < 2 → "soodne"
        muidu → "kallis"


        CREATE PROCEDURE kuvaArveHinnang
        AS
        BEGIN
            SELECT 
                firstname,
                arveSumma,
                CASE 
                    WHEN arveSumma < 750 THEN 'väike summa'
                    ELSE 'suur summa'
                END AS hinnang
            FROM guest;
        END;

		--kutse
		EXEC kuvaArveHinnang
```
