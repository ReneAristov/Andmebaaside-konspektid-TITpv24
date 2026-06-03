

[Põhimõisted](README.md) | [ProtseduuridSql](protsedur.md) | [ProtseduuridXAMPP](protseduurXammp.md) | [kasutajadSql](kasutajadsql.md) | [TrigerSql](trigger.md) | [TriggerXAMPP](trigerXampp.md) | [keys.md](keys.md) | [Hotellaristov.sql](hotellaristov.sql) | [Hotelliruum.md](hotelliruum.md) | [Kusimused](kusimused.md) |


-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Loomise aeg: Aprill 30, 2026 kell 10:05 EL
-- Serveri versioon: 10.4.32-MariaDB
-- PHP versioon: 8.2.12

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Andmebaas: `hotellaristov`
--

-- --------------------------------------------------------

--
-- Tabeli struktuur tabelile `guest`
--

CREATE TABLE `guest` (
  `guestID` int(11) NOT NULL,
  `firstname` varchar(80) DEFAULT NULL,
  `lastname` varchar(80) NOT NULL,
  `memberSince` date DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Andmete tõmmistamine tabelile `guest`
--

INSERT INTO `guest` (`guestID`, `firstname`, `lastname`, `memberSince`) VALUES
(1, 'Rene', 'Aristov', '2026-04-09'),
(2, 'Roman', 'Aristov', '2026-04-13'),
(3, 'Alina', 'Aristova', '2026-04-28');

-- --------------------------------------------------------

--
-- Tabeli struktuur tabelile `hosted_at`
--

CREATE TABLE `hosted_at` (
  `id` int(11) NOT NULL,
  `guest_id` int(11) DEFAULT NULL,
  `occupied_room_id` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Andmete tõmmistamine tabelile `hosted_at`
--

INSERT INTO `hosted_at` (`id`, `guest_id`, `occupied_room_id`) VALUES
(1, 3, 1),
(2, 1, 2),
(3, 2, 3);

-- --------------------------------------------------------

--
-- Tabeli struktuur tabelile `occupied_room`
--

CREATE TABLE `occupied_room` (
  `id` int(11) NOT NULL,
  `check_in` date DEFAULT NULL,
  `check_out` date DEFAULT NULL,
  `room_id` int(11) DEFAULT NULL,
  `reservation_id` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Andmete tõmmistamine tabelile `occupied_room`
--

INSERT INTO `occupied_room` (`id`, `check_in`, `check_out`, `room_id`, `reservation_id`) VALUES
(1, '2026-04-14', '2026-04-17', 2, 2),
(2, '2026-04-21', '2026-04-28', 3, 3),
(3, '2026-04-01', '2026-04-02', 1, 3);

-- --------------------------------------------------------

--
-- Tabeli struktuur tabelile `reservation`
--

CREATE TABLE `reservation` (
  `reservationID` int(11) NOT NULL,
  `date_in` date DEFAULT NULL,
  `date_out` date DEFAULT NULL,
  `made_by` varchar(20) DEFAULT NULL,
  `guestID` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Andmete tõmmistamine tabelile `reservation`
--

INSERT INTO `reservation` (`reservationID`, `date_in`, `date_out`, `made_by`, `guestID`) VALUES
(1, '2026-04-15', '2026-04-16', 'Tallinn', 1),
(2, '2026-04-16', '2026-04-08', 'rene', 1),
(3, '2026-04-14', '2026-04-16', 'Koristaja', 2);

-- --------------------------------------------------------

--
-- Tabeli struktuur tabelile `reserved_room`
--

CREATE TABLE `reserved_room` (
  `id` int(11) NOT NULL,
  `number_of_rooms` int(11) DEFAULT NULL,
  `room_type_id` int(11) DEFAULT NULL,
  `reservation_id` int(11) DEFAULT NULL,
  `status` varchar(20) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Andmete tõmmistamine tabelile `reserved_room`
--

INSERT INTO `reserved_room` (`id`, `number_of_rooms`, `room_type_id`, `reservation_id`, `status`) VALUES
(1, 2, 2, 2, 'ready'),
(2, 3, 3, 1, 'ready'),
(3, 1, 1, 3, 'Closed');

-- --------------------------------------------------------

--
-- Tabeli struktuur tabelile `room`
--

CREATE TABLE `room` (
  `id` int(11) NOT NULL,
  `number` varchar(10) DEFAULT NULL,
  `name` varchar(40) DEFAULT NULL,
  `status` varchar(10) DEFAULT NULL,
  `smoke` bit(1) DEFAULT NULL,
  `room_type_id` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Andmete tõmmistamine tabelile `room`
--

INSERT INTO `room` (`id`, `number`, `name`, `status`, `smoke`, `room_type_id`) VALUES
(1, '112', 'RENE', 'READY', b'1', 3),
(2, '113', 'VIP', 'READY', b'0', 3),
(3, '115', 'PREMIUM', 'CLOSE', b'0', 1);

-- --------------------------------------------------------

--
-- Tabeli struktuur tabelile `room_type`
--

CREATE TABLE `room_type` (
  `id` int(11) NOT NULL,
  `description` varchar(80) DEFAULT NULL,
  `max_capacity` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Andmete tõmmistamine tabelile `room_type`
--

INSERT INTO `room_type` (`id`, `description`, `max_capacity`) VALUES
(1, 'Single Room', 1),
(2, 'Double Room', 2),
(3, 'Family Room', 4),
(4, 'Single Basic', NULL),
(5, 'Single Basic', 1),
(6, 'Single Basic', 2),
(7, 'VIP', 4);

--
-- Indeksid tõmmistatud tabelitele
--

--
-- Indeksid tabelile `guest`
--
ALTER TABLE `guest`
  ADD PRIMARY KEY (`guestID`);

--
-- Indeksid tabelile `hosted_at`
--
ALTER TABLE `hosted_at`
  ADD PRIMARY KEY (`id`),
  ADD KEY `guest_id` (`guest_id`),
  ADD KEY `occupied_room_id` (`occupied_room_id`);

--
-- Indeksid tabelile `occupied_room`
--
ALTER TABLE `occupied_room`
  ADD PRIMARY KEY (`id`),
  ADD KEY `room_id` (`room_id`),
  ADD KEY `reservation_id` (`reservation_id`);

--
-- Indeksid tabelile `reservation`
--
ALTER TABLE `reservation`
  ADD PRIMARY KEY (`reservationID`),
  ADD KEY `guestID` (`guestID`);

--
-- Indeksid tabelile `reserved_room`
--
ALTER TABLE `reserved_room`
  ADD PRIMARY KEY (`id`),
  ADD KEY `room_type_id` (`room_type_id`),
  ADD KEY `reservation_id` (`reservation_id`);

--
-- Indeksid tabelile `room`
--
ALTER TABLE `room`
  ADD PRIMARY KEY (`id`),
  ADD KEY `room_type_id` (`room_type_id`);

--
-- Indeksid tabelile `room_type`
--
ALTER TABLE `room_type`
  ADD PRIMARY KEY (`id`);

--
-- AUTO_INCREMENT tõmmistatud tabelitele
--

--
-- AUTO_INCREMENT tabelile `guest`
--
ALTER TABLE `guest`
  MODIFY `guestID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=4;

--
-- AUTO_INCREMENT tabelile `hosted_at`
--
ALTER TABLE `hosted_at`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=4;

--
-- AUTO_INCREMENT tabelile `occupied_room`
--
ALTER TABLE `occupied_room`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=4;

--
-- AUTO_INCREMENT tabelile `reservation`
--
ALTER TABLE `reservation`
  MODIFY `reservationID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=4;

--
-- AUTO_INCREMENT tabelile `reserved_room`
--
ALTER TABLE `reserved_room`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=4;

--
-- AUTO_INCREMENT tabelile `room`
--
ALTER TABLE `room`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=4;

--
-- AUTO_INCREMENT tabelile `room_type`
--
ALTER TABLE `room_type`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=8;

--
-- Tõmmistatud tabelite piirangud
--

--
-- Piirangud tabelile `hosted_at`
--
ALTER TABLE `hosted_at`
  ADD CONSTRAINT `hosted_at_ibfk_1` FOREIGN KEY (`guest_id`) REFERENCES `guest` (`guestID`),
  ADD CONSTRAINT `hosted_at_ibfk_2` FOREIGN KEY (`occupied_room_id`) REFERENCES `occupied_room` (`id`);

--
-- Piirangud tabelile `occupied_room`
--
ALTER TABLE `occupied_room`
  ADD CONSTRAINT `occupied_room_ibfk_1` FOREIGN KEY (`room_id`) REFERENCES `room` (`id`),
  ADD CONSTRAINT `occupied_room_ibfk_2` FOREIGN KEY (`reservation_id`) REFERENCES `reservation` (`reservationID`);

--
-- Piirangud tabelile `reservation`
--
ALTER TABLE `reservation`
  ADD CONSTRAINT `reservation_ibfk_1` FOREIGN KEY (`guestID`) REFERENCES `guest` (`guestID`);

--
-- Piirangud tabelile `reserved_room`
--
ALTER TABLE `reserved_room`
  ADD CONSTRAINT `reserved_room_ibfk_1` FOREIGN KEY (`room_type_id`) REFERENCES `room_type` (`id`),
  ADD CONSTRAINT `reserved_room_ibfk_2` FOREIGN KEY (`reservation_id`) REFERENCES `reservation` (`reservationID`);

--
-- Piirangud tabelile `room`
--
ALTER TABLE `room`
  ADD CONSTRAINT `room_ibfk_1` FOREIGN KEY (`room_type_id`) REFERENCES `room_type` (`id`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
