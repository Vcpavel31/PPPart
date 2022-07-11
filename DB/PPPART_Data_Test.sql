-- phpMyAdmin SQL Dump
-- version 4.9.1
-- https://www.phpmyadmin.net/
--
-- Počítač: innodb.endora.cz:3306
<<<<<<< Updated upstream:DB/PPPART_Data_Test.sql
-- Vytvořeno: Úte 05. čec 2022, 14:35
=======
-- Vytvořeno: Pon 11. čec 2022, 19:54
>>>>>>> Stashed changes:DB/PPPART_TestData.sql
-- Verze serveru: 5.6.45-86.1
-- Verze PHP: 7.3.9

--
-- PPPART_pre-Alpha
--
--
SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Databáze: `vcpave1644611634`
--
CREATE DATABASE IF NOT EXISTS `vcpave1644611634` DEFAULT CHARACTER SET utf8 COLLATE utf8_czech_ci;
USE `vcpave1644611634`;

-- --------------------------------------------------------

--
-- Struktura tabulky `Amounts`
--
-- Vytvořeno: Pon 11. čec 2022, 07:34
--

DROP TABLE IF EXISTS `Amounts`;
CREATE TABLE `Amounts` (
  `ID` bigint(20) NOT NULL,
  `Item_ID` bigint(20) UNSIGNED NOT NULL,
  `Date` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  `Amount` double NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_czech_ci;

--
-- Vypisuji data pro tabulku `Amounts`
--

INSERT INTO `Amounts` (`ID`, `Item_ID`, `Date`, `Amount`) VALUES
(1, 1, '2022-06-30 19:19:03', 245),
(2, 1, '2022-06-30 19:43:04', 350),
(3, 1, '2022-07-01 11:55:00', 0),
(4, 1, '2022-07-02 12:54:25', 1000);

-- --------------------------------------------------------

--
-- Struktura tabulky `Attribute`
--
-- Vytvořeno: Pon 11. čec 2022, 07:34
--

DROP TABLE IF EXISTS `Attribute`;
CREATE TABLE `Attribute` (
  `ID` bigint(20) UNSIGNED NOT NULL,
  `Item_ID` bigint(20) UNSIGNED NOT NULL,
  `Attribute_Option` int(10) UNSIGNED NOT NULL,
  `Attribute_Value` tinytext COLLATE utf8mb4_czech_ci NOT NULL,
  `Attribute_Info` text COLLATE utf8mb4_czech_ci,
  `Attribute_Date` timestamp NULL DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_czech_ci;

--
-- Vypisuji data pro tabulku `Attribute`
--

INSERT INTO `Attribute` (`ID`, `Item_ID`, `Attribute_Option`, `Attribute_Value`, `Attribute_Info`, `Attribute_Date`) VALUES
(2, 1, 6, 'PLA', NULL, NULL),
(3, 1, 5, 'Zelená', 'Metalická', NULL);

-- --------------------------------------------------------

--
-- Struktura tabulky `Attributes`
--
-- Vytvořeno: Pon 11. čec 2022, 07:34
--

DROP TABLE IF EXISTS `Attributes`;
CREATE TABLE `Attributes` (
  `ID` int(10) UNSIGNED NOT NULL,
  `Attribute_Name` tinytext COLLATE utf8mb4_czech_ci NOT NULL,
  `Writable` tinyint(1) NOT NULL DEFAULT '0',
  `Alias` text COLLATE utf8mb4_czech_ci,
  `Type` int(4) NOT NULL,
  `Unit` text COLLATE utf8mb4_czech_ci,
  `Options_Type` tinyint(1) NOT NULL DEFAULT '0',
  `Options` longtext COLLATE utf8mb4_czech_ci,
  `Options_Selected` mediumint(9) DEFAULT '0',
  `Helper_Type` tinyint(1) NOT NULL DEFAULT '0',
  `Helper_Querry` longtext COLLATE utf8mb4_czech_ci,
  `Helper` tinyint(2) NOT NULL DEFAULT '0'
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_czech_ci;

--
-- Vypisuji data pro tabulku `Attributes`
--

INSERT INTO `Attributes` (`ID`, `Attribute_Name`, `Writable`, `Alias`, `Type`, `Unit`, `Options_Type`, `Options`, `Options_Selected`, `Helper_Type`, `Helper_Querry`, `Helper`) VALUES
(1, 'Výrobce', 0, NULL, 1, NULL, 0, NULL, NULL, 0, NULL, 0),
(2, 'Název', 0, NULL, 1, NULL, 0, NULL, NULL, 0, NULL, 0),
(3, 'EAN', 0, NULL, 1, NULL, 0, NULL, NULL, 0, NULL, 0),
(4, 'Číslo výrobce', 0, NULL, 1, NULL, 0, NULL, NULL, 0, NULL, 0),
(5, 'Barva', 1, NULL, 9, NULL, 0, NULL, NULL, 0, NULL, 0),
(6, 'Materiál', 1, NULL, 1, NULL, 0, NULL, NULL, 0, NULL, 0),
(7, 'Množství', 1, 'Počet položek pro naskladnění', 2, NULL, 0, NULL, NULL, 0, NULL, 0),
(8, 'Dodavatel', 1, NULL, 1, NULL, 0, NULL, NULL, 1, 'SELECT `Supplier_Name` AS \'Name\' FROM `Supplier`', 1),
(9, 'Cena', 1, NULL, 4, NULL, 0, 'Kč, €, $, £', 0, 0, NULL, 0),
(10, 'Stav', 1, NULL, 1, NULL, 0, NULL, NULL, 0, 'Nový, Použitý, Nefunkční, Rozbalený', 1),
(11, 'Poznámka', 1, NULL, 3, NULL, 0, NULL, NULL, 0, NULL, 0),
(12, 'Označení v knihovně', 1, NULL, 1, NULL, 0, NULL, NULL, 0, NULL, 0),
(13, 'Balení', 1, NULL, 1, NULL, 0, NULL, NULL, 0, NULL, 0),
(14, 'Interní označení', 1, NULL, 1, NULL, 0, NULL, NULL, 0, NULL, 0),
(15, 'Minimální počet položek ve skladu', 1, NULL, 2, NULL, 0, NULL, NULL, 0, NULL, 0),
(16, 'Délka', 1, NULL, 5, NULL, 0, 'mm, cm, dm, m, km', 0, 0, NULL, 0),
(17, 'Pouzdro', 1, NULL, 1, NULL, 0, NULL, NULL, 1, 'SELECT `Attribute_Value` AS \'Name\' FROM `Attribute` WHERE `Attribute_Option` = 17', 1),
(18, 'Tolerance', 1, NULL, 6, '%', 0, NULL, NULL, 0, NULL, 0),
(19, 'Hmotnost', 1, NULL, 5, NULL, 0, 'mg, g, dkg, kg, t', 1, 0, NULL, 0),
(20, 'Odpor', 1, NULL, 5, NULL, 0, 'mΩ, Ω, KΩ, MΩ', 1, 0, NULL, 0),
(21, 'Koncovka', 1, 'Koncovka 1', 1, NULL, 0, NULL, NULL, 0, NULL, 0),
(22, 'Koncovka', 1, 'Koncovka 2', 1, NULL, 0, NULL, NULL, 0, NULL, 0),
(23, 'Záporná tolerance', 1, NULL, 6, '%', 0, NULL, NULL, 0, NULL, 0),
(24, 'Kladná tolerance', 1, NULL, 6, '%', 0, NULL, NULL, 0, NULL, 0),
(25, 'Počet vodičů', 1, NULL, 2, NULL, 0, NULL, NULL, 0, NULL, 0),
(26, 'Materiál_3D', 1, 'Materíál', 1, NULL, 0, NULL, NULL, 0, 'ABS, PET, PETG, PLA, ASA, TPE, TPU, NYLON, CPE, HIPS, Speciální', 1),
(27, 'Kapacita-F', 1, 'Kapacita', 5, NULL, 0, 'pF, nF, uF, mF, F', 2, 0, NULL, 0),
(28, 'Kapacita', 1, NULL, 5, NULL, 0, 'B, KB, MB, GB, TB', 2, 0, NULL, 0),
(29, 'Kapacita-Disk', 1, 'Kapacita', 5, NULL, 0, 'B, KB, MB, GB, TB', 3, 0, NULL, 0),
(30, 'Jmenovitý výkon', 1, NULL, 6, 'W', 0, NULL, NULL, 0, NULL, 0),
(31, 'Jmenovité napětí', 1, NULL, 6, 'V', 0, NULL, NULL, 0, NULL, 0),
(32, 'Průměr filament', 1, 'Průměr filamentu', 8, NULL, 0, '1,75 mm, 2,85mm', 0, 0, NULL, 0),
(33, 'Délka filament', 1, NULL, 5, NULL, 0, 'mm, cm, dm, m, km', 3, 0, NULL, 0);

-- --------------------------------------------------------

--
-- Struktura tabulky `Categories`
--
-- Vytvořeno: Pon 11. čec 2022, 07:34
--

DROP TABLE IF EXISTS `Categories`;
CREATE TABLE `Categories` (
  `ID` mediumint(8) UNSIGNED NOT NULL,
  `Name` tinytext COLLATE utf8mb4_czech_ci NOT NULL,
  `Hidden` tinyint(1) UNSIGNED NOT NULL DEFAULT '0'
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_czech_ci;

--
-- Vypisuji data pro tabulku `Categories`
--

INSERT INTO `Categories` (`ID`, `Name`, `Hidden`) VALUES
(1, 'Filamenty', 0),
(2, 'PLA', 0),
(3, 'PETG', 0),
(4, 'ASA', 0);

-- --------------------------------------------------------

--
-- Struktura tabulky `Categories_Arrangement`
--
-- Vytvořeno: Pon 11. čec 2022, 07:34
--

DROP TABLE IF EXISTS `Categories_Arrangement`;
CREATE TABLE `Categories_Arrangement` (
  `ID` mediumint(8) UNSIGNED NOT NULL,
  `Category` mediumint(8) UNSIGNED NOT NULL,
  `Ordered` mediumint(8) UNSIGNED DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_czech_ci;

--
-- Vypisuji data pro tabulku `Categories_Arrangement`
--

INSERT INTO `Categories_Arrangement` (`ID`, `Category`, `Ordered`) VALUES
(2, 1, NULL),
(1, 2, 1),
(3, 3, 1),
(4, 4, 1);

-- --------------------------------------------------------

--
-- Struktura tabulky `Categories_Attributes`
--
-- Vytvořeno: Pon 11. čec 2022, 07:34
--

DROP TABLE IF EXISTS `Categories_Attributes`;
CREATE TABLE `Categories_Attributes` (
  `ID` mediumint(9) NOT NULL,
  `Category` mediumint(9) UNSIGNED NOT NULL,
  `Attributes` int(11) UNSIGNED NOT NULL,
<<<<<<< Updated upstream:DB/PPPART_Data_Test.sql
  `Hidden` tinyint(1) UNSIGNED NOT NULL DEFAULT '0',
  `Unit` varchar(3) COLLATE utf8mb4_czech_ci DEFAULT NULL
=======
  `Hidden` tinyint(1) UNSIGNED NOT NULL DEFAULT '0'
>>>>>>> Stashed changes:DB/PPPART_TestData.sql
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_czech_ci;

--
-- Vypisuji data pro tabulku `Categories_Attributes`
--

INSERT INTO `Categories_Attributes` (`ID`, `Category`, `Attributes`, `Hidden`) VALUES
(1, 2, 3, 0),
(2, 2, 2, 0),
(3, 4, 3, 0),
(4, 4, 2, 0),
(5, 1, 6, 0),
(6, 2, 5, 0),
(7, 2, 32, 0),
(8, 2, 33, 0),
(9, 2, 18, 0),
(10, 2, 19, 0);

-- --------------------------------------------------------

--
-- Struktura tabulky `Categories_Items`
--
-- Vytvořeno: Pon 11. čec 2022, 07:34
--

DROP TABLE IF EXISTS `Categories_Items`;
CREATE TABLE `Categories_Items` (
  `ID` bigint(20) NOT NULL,
  `Item_ID` bigint(20) UNSIGNED NOT NULL,
  `Category_ID` mediumint(8) UNSIGNED NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_czech_ci;

--
-- Vypisuji data pro tabulku `Categories_Items`
--

INSERT INTO `Categories_Items` (`ID`, `Item_ID`, `Category_ID`) VALUES
(1, 1, 2),
(2, 2, 4),
(3, 3, 2);

-- --------------------------------------------------------

--
-- Struktura tabulky `Items`
--
-- Vytvořeno: Pon 11. čec 2022, 07:34
--

DROP TABLE IF EXISTS `Items`;
CREATE TABLE `Items` (
  `ID` bigint(20) UNSIGNED NOT NULL,
  `Name` tinytext COLLATE utf8mb4_czech_ci NOT NULL,
  `EAN` bigint(11) DEFAULT NULL,
  `Product_number` tinytext COLLATE utf8mb4_czech_ci,
  `Producer` smallint(5) UNSIGNED NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_czech_ci;

--
-- Vypisuji data pro tabulku `Items`
--

INSERT INTO `Items` (`ID`, `Name`, `EAN`, `Product_number`, `Producer`) VALUES
(1, 'PLA - Metalická Zelená', 8594185641186, '050290000', 1),
(2, 'ASA Extrafill \"Traffic White\"', 8595632824008, 'ASA175_9016', 2),
(3, 'PLA - Bílá', 8594185640028, '050060000', 1);

-- --------------------------------------------------------

--
-- Struktura tabulky `Producer`
--
-- Vytvořeno: Pon 11. čec 2022, 07:34
--

DROP TABLE IF EXISTS `Producer`;
CREATE TABLE `Producer` (
  `ID` smallint(6) UNSIGNED NOT NULL,
  `Name` tinytext COLLATE utf8mb4_czech_ci NOT NULL,
  `URL` text COLLATE utf8mb4_czech_ci
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_czech_ci;

--
-- Vypisuji data pro tabulku `Producer`
--

INSERT INTO `Producer` (`ID`, `Name`, `URL`) VALUES
(1, 'Filament PM', NULL),
(2, 'Fillamentum', NULL);

-- --------------------------------------------------------

--
-- Struktura tabulky `Supplier`
--
-- Vytvořeno: Pon 11. čec 2022, 07:34
--

DROP TABLE IF EXISTS `Supplier`;
CREATE TABLE `Supplier` (
  `ID` smallint(5) UNSIGNED NOT NULL,
  `Supplier_Name` tinytext COLLATE utf8mb4_czech_ci NOT NULL,
  `Supplier_Site` tinytext COLLATE utf8mb4_czech_ci NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_czech_ci;

--
-- Vypisuji data pro tabulku `Supplier`
--

INSERT INTO `Supplier` (`ID`, `Supplier_Name`, `Supplier_Site`) VALUES
(1, 'Fillamentum', 'https://shop.fillamentum.com/'),
(2, 'Materialpro3d', 'https://www.materialpro3d.cz/'),
(3, 'Filament PM', 'https://www.filament-pm.cz/');

-- --------------------------------------------------------

--
-- Struktura tabulky `Suppliers`
--
-- Vytvořeno: Pon 11. čec 2022, 07:34
--

DROP TABLE IF EXISTS `Suppliers`;
CREATE TABLE `Suppliers` (
  `ID` int(11) NOT NULL,
  `Item_ID` bigint(20) UNSIGNED NOT NULL,
  `Supplier` smallint(6) UNSIGNED NOT NULL,
  `Supplier_Name` tinytext COLLATE utf8mb4_czech_ci,
  `Supplier_Code` tinytext COLLATE utf8mb4_czech_ci,
  `Supplier_Link` mediumtext COLLATE utf8mb4_czech_ci
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_czech_ci;

--
-- Klíče pro exportované tabulky
--

--
-- Klíče pro tabulku `Amounts`
--
ALTER TABLE `Amounts`
  ADD PRIMARY KEY (`ID`),
  ADD KEY `Item_ID` (`Item_ID`);

--
-- Klíče pro tabulku `Attribute`
--
ALTER TABLE `Attribute`
  ADD PRIMARY KEY (`ID`),
  ADD KEY `Attribute_Option` (`Attribute_Option`),
  ADD KEY `Item_ID` (`Item_ID`);

--
-- Klíče pro tabulku `Attributes`
--
ALTER TABLE `Attributes`
  ADD PRIMARY KEY (`ID`);

--
-- Klíče pro tabulku `Categories`
--
ALTER TABLE `Categories`
  ADD PRIMARY KEY (`ID`);

--
-- Klíče pro tabulku `Categories_Arrangement`
--
ALTER TABLE `Categories_Arrangement`
  ADD PRIMARY KEY (`ID`),
  ADD UNIQUE KEY `Category_2` (`Category`,`Ordered`),
  ADD KEY `Category` (`Category`),
  ADD KEY `Ordered` (`Ordered`);

--
-- Klíče pro tabulku `Categories_Attributes`
--
ALTER TABLE `Categories_Attributes`
  ADD PRIMARY KEY (`ID`),
  ADD KEY `Category` (`Category`),
  ADD KEY `Attributes` (`Attributes`);

--
-- Klíče pro tabulku `Categories_Items`
--
ALTER TABLE `Categories_Items`
  ADD PRIMARY KEY (`ID`),
  ADD KEY `Item_ID` (`Item_ID`),
  ADD KEY `Category_ID` (`Category_ID`);

--
-- Klíče pro tabulku `Items`
--
ALTER TABLE `Items`
  ADD PRIMARY KEY (`ID`),
  ADD KEY `Producer` (`Producer`);

--
-- Klíče pro tabulku `Producer`
--
ALTER TABLE `Producer`
  ADD PRIMARY KEY (`ID`);

--
-- Klíče pro tabulku `Supplier`
--
ALTER TABLE `Supplier`
  ADD PRIMARY KEY (`ID`);

--
-- Klíče pro tabulku `Suppliers`
--
ALTER TABLE `Suppliers`
  ADD PRIMARY KEY (`ID`),
  ADD KEY `Item_ID` (`Item_ID`),
  ADD KEY `Supplier` (`Supplier`);

--
-- AUTO_INCREMENT pro tabulky
--

--
-- AUTO_INCREMENT pro tabulku `Amounts`
--
ALTER TABLE `Amounts`
  MODIFY `ID` bigint(20) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=5;

--
-- AUTO_INCREMENT pro tabulku `Attribute`
--
ALTER TABLE `Attribute`
  MODIFY `ID` bigint(20) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=4;

--
-- AUTO_INCREMENT pro tabulku `Attributes`
--
ALTER TABLE `Attributes`
  MODIFY `ID` int(10) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=34;

--
-- AUTO_INCREMENT pro tabulku `Categories`
--
ALTER TABLE `Categories`
  MODIFY `ID` mediumint(8) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=5;

--
-- AUTO_INCREMENT pro tabulku `Categories_Arrangement`
--
ALTER TABLE `Categories_Arrangement`
  MODIFY `ID` mediumint(8) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=5;

--
-- AUTO_INCREMENT pro tabulku `Categories_Attributes`
--
ALTER TABLE `Categories_Attributes`
  MODIFY `ID` mediumint(9) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=11;

--
-- AUTO_INCREMENT pro tabulku `Categories_Items`
--
ALTER TABLE `Categories_Items`
  MODIFY `ID` bigint(20) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=4;

--
-- AUTO_INCREMENT pro tabulku `Items`
--
ALTER TABLE `Items`
  MODIFY `ID` bigint(20) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=4;

--
-- AUTO_INCREMENT pro tabulku `Producer`
--
ALTER TABLE `Producer`
  MODIFY `ID` smallint(6) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=3;

--
-- AUTO_INCREMENT pro tabulku `Supplier`
--
ALTER TABLE `Supplier`
  MODIFY `ID` smallint(5) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=4;

--
-- AUTO_INCREMENT pro tabulku `Suppliers`
--
ALTER TABLE `Suppliers`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT;

--
-- Omezení pro exportované tabulky
--

--
-- Omezení pro tabulku `Amounts`
--
ALTER TABLE `Amounts`
  ADD CONSTRAINT `Amounts_ibfk_1` FOREIGN KEY (`Item_ID`) REFERENCES `Items` (`ID`);

--
-- Omezení pro tabulku `Attribute`
--
ALTER TABLE `Attribute`
  ADD CONSTRAINT `Attribute_ibfk_2` FOREIGN KEY (`Attribute_Option`) REFERENCES `Attributes` (`ID`),
  ADD CONSTRAINT `Attribute_ibfk_3` FOREIGN KEY (`Item_ID`) REFERENCES `Items` (`ID`);

--
-- Omezení pro tabulku `Categories_Arrangement`
--
ALTER TABLE `Categories_Arrangement`
  ADD CONSTRAINT `Categories_Arrangement_ibfk_1` FOREIGN KEY (`Category`) REFERENCES `Categories` (`ID`),
  ADD CONSTRAINT `Categories_Arrangement_ibfk_2` FOREIGN KEY (`Ordered`) REFERENCES `Categories` (`ID`);

--
-- Omezení pro tabulku `Categories_Attributes`
--
ALTER TABLE `Categories_Attributes`
  ADD CONSTRAINT `Categories_Attributes_ibfk_1` FOREIGN KEY (`Category`) REFERENCES `Categories` (`ID`),
  ADD CONSTRAINT `Categories_Attributes_ibfk_2` FOREIGN KEY (`Attributes`) REFERENCES `Attributes` (`ID`);

--
-- Omezení pro tabulku `Categories_Items`
--
ALTER TABLE `Categories_Items`
  ADD CONSTRAINT `Categories_Items_ibfk_1` FOREIGN KEY (`Item_ID`) REFERENCES `Items` (`ID`),
  ADD CONSTRAINT `Categories_Items_ibfk_2` FOREIGN KEY (`Category_ID`) REFERENCES `Categories` (`ID`);

--
-- Omezení pro tabulku `Items`
--
ALTER TABLE `Items`
  ADD CONSTRAINT `Items_ibfk_1` FOREIGN KEY (`Producer`) REFERENCES `Producer` (`ID`);

--
-- Omezení pro tabulku `Suppliers`
--
ALTER TABLE `Suppliers`
  ADD CONSTRAINT `Suppliers_ibfk_1` FOREIGN KEY (`Item_ID`) REFERENCES `Items` (`ID`),
  ADD CONSTRAINT `Suppliers_ibfk_2` FOREIGN KEY (`Supplier`) REFERENCES `Supplier` (`ID`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
