-- phpMyAdmin SQL Dump
-- version 4.9.1
-- https://www.phpmyadmin.net/
--
-- Počítač: innodb.endora.cz:3306
-- Vytvořeno: Pon 11. čec 2022, 19:54
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
  `Hidden` tinyint(1) UNSIGNED NOT NULL DEFAULT '0'
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_czech_ci;

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
  MODIFY `ID` bigint(20) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT pro tabulku `Attribute`
--
ALTER TABLE `Attribute`
  MODIFY `ID` bigint(20) UNSIGNED NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT pro tabulku `Attributes`
--
ALTER TABLE `Attributes`
  MODIFY `ID` int(10) UNSIGNED NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT pro tabulku `Categories`
--
ALTER TABLE `Categories`
  MODIFY `ID` mediumint(8) UNSIGNED NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT pro tabulku `Categories_Arrangement`
--
ALTER TABLE `Categories_Arrangement`
  MODIFY `ID` mediumint(8) UNSIGNED NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT pro tabulku `Categories_Attributes`
--
ALTER TABLE `Categories_Attributes`
  MODIFY `ID` mediumint(9) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT pro tabulku `Categories_Items`
--
ALTER TABLE `Categories_Items`
  MODIFY `ID` bigint(20) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT pro tabulku `Items`
--
ALTER TABLE `Items`
  MODIFY `ID` bigint(20) UNSIGNED NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT pro tabulku `Producer`
--
ALTER TABLE `Producer`
  MODIFY `ID` smallint(6) UNSIGNED NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT pro tabulku `Supplier`
--
ALTER TABLE `Supplier`
  MODIFY `ID` smallint(5) UNSIGNED NOT NULL AUTO_INCREMENT;

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
