

[Põhimõisted](README.md) | [ProtseduuridSql](protsedur.md) | [ProtseduuridXAMPP](protseduurXammp.md) | [kasutajadSql](kasutajadsql.md) | [TrigerSql](trigger.md) | [TriggerXAMPP](trigerXampp.md) | [keys.md](keys.md) | [Hotelliruum.md](hotelliruum.md) | [Kusimused](kusimused.md) |
## Andmebass Hotelliruumi reserveerimine
```sql
CREATE TABLE guest(
guestID int Primary key identity(1,1),
firstname varchar(80),
lastname varchar(80)not null,
memberSince DATE);

SELECT * FROM guest;
INSERT INTO guest
VALUES ('Roman', 'Aristov','2026-08-23');
```
<img width="299" height="83" alt="{8202C68B-50A7-4DE8-A9D7-E6B80886ACE2}" src="https://github.com/user-attachments/assets/3735b00e-74c6-41e4-935b-fcce5b5ce991" />

```sql
CREATE TABLE reservation(
reservationID int PRIMARY KEY identity(1,1),
date_in DATE,
date_out DATE,
made_by varchar(20),
guestID int,
FOREIGN KEY (guestID) REFERENCES guest(guestID));

SELECT * FROM reservation;
INSERT INTO reservation
VALUES ('2026-09-1','2025-04-01','admin',3);
```
<img width="368" height="82" alt="{82112CA7-C546-433D-BE38-EFEFF00297DD}" src="https://github.com/user-attachments/assets/1c3a8380-3d2f-4806-b677-9c82c74b9f6a" />

```sql
CREATE TABLE room_type(
id int PRIMARY KEY identity(1,1),
description varchar(80),
max_capacity int);

SELECT * FROM room_type;
INSERT INTO room_type
VALUES ('Family Room',3);
```
<img width="229" height="82" alt="{1B208C12-BE3D-4EFB-83BB-5A36D50AF463}" src="https://github.com/user-attachments/assets/c4b72375-ccb0-4f83-b052-7948f4b6a1a8" />

```sql
CREATE TABLE room(
    id int PRIMARY KEY IDENTITY(1,1),
    number varchar(10),
    name varchar(40),
    status varchar(10),
    smoke bit,
    room_type_id int,
    FOREIGN KEY (room_type_id) REFERENCES room_type(id)
);

SELECT * FROM room;
INSERT INTO room
VALUES ('103','Double Delux', 'free', 0, 2);
```
<img width="387" height="82" alt="{124CB4AD-89EE-4F45-8F89-01B122D922B4}" src="https://github.com/user-attachments/assets/754dac26-9612-4252-a6f2-2b641844c41d" />

```sql
CREATE TABLE reserved_room(
id int PRIMARY KEY IDENTITY(1,1),
number_of_rooms int,
room_type_id int,
reservation_id int,
status varchar(20),
FOREIGN KEY (room_type_id) REFERENCES room_type(id),
FOREIGN KEY (reservation_id) REFERENCES reservation(reservationID));

SELECT * FROM reserved_room;
INSERT INTO reserved_room
VALUES (3,2,2,'ready');
```
<img width="367" height="79" alt="{4BA2C75B-E4D6-462D-9DDB-01FA3B73D18D}" src="https://github.com/user-attachments/assets/4faeaccf-9d11-43f8-a8c4-4d41c473ec2c" />

```sql
CREATE TABLE occupied_room(
    id int PRIMARY KEY IDENTITY(1,1),
    check_in datetime,
    check_out datetime,
    room_id int,
    reservation_id int,
    FOREIGN KEY (room_id) REFERENCES room(id),
    FOREIGN KEY (reservation_id) REFERENCES reservation(reservationID));

SELECT * FROM occupied_room;
INSERT INTO occupied_room
VALUES ('2025-12-01 13:00','2026-07-01 18:00',3,1)
```
<img width="465" height="82" alt="{24AA4FDF-8E6D-4607-BB75-2721BEF9286D}" src="https://github.com/user-attachments/assets/5f3848f3-17c0-44f5-befa-ec34f63d59c1" />

```sql
CREATE TABLE hosted_at(
    id int PRIMARY KEY IDENTITY(1,1),
    guest_id int,
    occupied_room_id int,
    FOREIGN KEY (guest_id) REFERENCES guest(guestID),
    FOREIGN KEY (occupied_room_id) REFERENCES occupied_room(id)
);

SELECT * FROM hosted_at;
INSERT INTO hosted_at
VALUES (3,2);
```
<img width="219" height="76" alt="{0B5FC6DB-AD3A-4364-AE4D-19A8CC4D1C1D}" src="https://github.com/user-attachments/assets/53c0e0d9-5ead-471f-8227-f396adb30174" />

## Diagramm
<img width="717" height="823" alt="{05ABD06F-ABC1-4308-A1F2-FA4DA1D951BC}" src="https://github.com/user-attachments/assets/471b3bed-8faa-4033-9367-86f4ad22b986" />


