-- phpMyAdmin SQL Dump
-- version 5.0.4deb2+deb11u1
-- https://www.phpmyadmin.net/
--
-- Počítač: innodb.endora.cz:3306
-- Vytvořeno: Stř 14. pro 2022, 22:19
-- Verze serveru: 10.3.35-MariaDB
-- Verze PHP: 7.4.33

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Databáze: `vcpave1644611634`
--

-- --------------------------------------------------------

--
-- Struktura tabulky `Amounts`
--

CREATE TABLE `Amounts` (
  `ID` bigint(20) NOT NULL,
  `Item_ID` bigint(20) UNSIGNED NOT NULL,
  `Date` timestamp NOT NULL DEFAULT current_timestamp() ON UPDATE current_timestamp(),
  `Amount` double NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_czech_ci ROW_FORMAT=DYNAMIC;

-- --------------------------------------------------------

--
-- Struktura tabulky `Attribute`
--

CREATE TABLE `Attribute` (
  `ID` bigint(20) UNSIGNED NOT NULL,
  `Item_ID` bigint(20) UNSIGNED NOT NULL,
  `Attribute_Option` int(10) UNSIGNED NOT NULL,
  `Attribute_Value` tinytext COLLATE utf8mb4_czech_ci NOT NULL,
  `Attribute_Info` text COLLATE utf8mb4_czech_ci DEFAULT NULL,
  `Attribute_Date` timestamp NULL DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_czech_ci ROW_FORMAT=DYNAMIC;

-- --------------------------------------------------------

--
-- Struktura tabulky `Attributes`
--

CREATE TABLE `Attributes` (
  `ID` int(10) UNSIGNED NOT NULL,
  `Attribute_Name` tinytext COLLATE utf8mb4_czech_ci NOT NULL,
  `Writable` tinyint(1) NOT NULL DEFAULT 0,
  `Alias` text COLLATE utf8mb4_czech_ci DEFAULT NULL,
  `Type` int(4) NOT NULL,
  `Unit` text COLLATE utf8mb4_czech_ci DEFAULT NULL,
  `Default_Value` tinytext COLLATE utf8mb4_czech_ci DEFAULT NULL,
  `Options_Type` tinyint(1) NOT NULL DEFAULT 0,
  `Options` longtext COLLATE utf8mb4_czech_ci DEFAULT NULL,
  `Options_Selected` mediumint(9) DEFAULT 0,
  `Helper_Type` tinyint(1) NOT NULL DEFAULT 0,
  `Helper_Querry` longtext COLLATE utf8mb4_czech_ci DEFAULT NULL,
  `Helper` tinyint(2) NOT NULL DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_czech_ci ROW_FORMAT=DYNAMIC;

-- --------------------------------------------------------

--
-- Struktura tabulky `Categories`
--

CREATE TABLE `Categories` (
  `ID` mediumint(8) UNSIGNED NOT NULL,
  `Name` tinytext COLLATE utf8mb4_czech_ci NOT NULL,
  `Hidden` tinyint(1) UNSIGNED NOT NULL DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_czech_ci ROW_FORMAT=DYNAMIC;

-- --------------------------------------------------------

--
-- Struktura tabulky `Categories_Arrangement`
--

CREATE TABLE `Categories_Arrangement` (
  `ID` mediumint(8) UNSIGNED NOT NULL,
  `Category` mediumint(8) UNSIGNED NOT NULL,
  `Ordered` mediumint(8) UNSIGNED DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_czech_ci ROW_FORMAT=DYNAMIC;

-- --------------------------------------------------------

--
-- Struktura tabulky `Categories_Attributes`
--

CREATE TABLE `Categories_Attributes` (
  `ID` int(11) NOT NULL,
  `Category` mediumint(9) UNSIGNED NOT NULL,
  `Attributes` int(11) UNSIGNED NOT NULL,
  `Hidden` tinyint(1) UNSIGNED NOT NULL DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_czech_ci ROW_FORMAT=DYNAMIC;

-- --------------------------------------------------------

--
-- Struktura tabulky `Categories_Items`
--

CREATE TABLE `Categories_Items` (
  `ID` bigint(20) NOT NULL,
  `Item_ID` bigint(20) UNSIGNED NOT NULL,
  `Category_ID` mediumint(8) UNSIGNED NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_czech_ci ROW_FORMAT=DYNAMIC;

-- --------------------------------------------------------

--
-- Struktura tabulky `Items`
--

CREATE TABLE `Items` (
  `ID` bigint(20) UNSIGNED NOT NULL,
  `Name` tinytext COLLATE utf8mb4_czech_ci NOT NULL,
  `EAN` bigint(11) DEFAULT NULL,
  `Product_number` tinytext COLLATE utf8mb4_czech_ci DEFAULT NULL,
  `Producer` smallint(5) UNSIGNED NOT NULL,
  `Internal_marking` mediumtext COLLATE utf8mb4_czech_ci DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_czech_ci ROW_FORMAT=DYNAMIC;

-- --------------------------------------------------------

--
-- Struktura tabulky `Producer`
--

CREATE TABLE `Producer` (
  `ID` smallint(6) UNSIGNED NOT NULL,
  `Name` tinytext COLLATE utf8mb4_czech_ci NOT NULL,
  `URL` text COLLATE utf8mb4_czech_ci DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_czech_ci ROW_FORMAT=DYNAMIC;

-- --------------------------------------------------------

--
-- Struktura tabulky `Supplier`
--

CREATE TABLE `Supplier` (
  `ID` smallint(5) UNSIGNED NOT NULL,
  `Supplier_Name` tinytext COLLATE utf8mb4_czech_ci NOT NULL,
  `Supplier_Site` tinytext COLLATE utf8mb4_czech_ci NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_czech_ci ROW_FORMAT=DYNAMIC;

-- --------------------------------------------------------

--
-- Struktura tabulky `Suppliers`
--

CREATE TABLE `Suppliers` (
  `ID` int(11) NOT NULL,
  `Item_ID` bigint(20) UNSIGNED NOT NULL,
  `Supplier` smallint(6) UNSIGNED NOT NULL,
  `Supplier_Name` tinytext COLLATE utf8mb4_czech_ci DEFAULT NULL,
  `Supplier_Code` tinytext COLLATE utf8mb4_czech_ci DEFAULT NULL,
  `Supplier_Link` mediumtext COLLATE utf8mb4_czech_ci DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_czech_ci ROW_FORMAT=DYNAMIC;

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
  ADD PRIMARY KEY (`ID`);

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
-- AUTO_INCREMENT pro tabulky
--

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
-- AUTO_INCREMENT pro tabulku `Categories_Attributes`
--
ALTER TABLE `Categories_Attributes`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT;

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
-- Omezení pro exportované tabulky
--

--
-- Omezení pro tabulku `Items`
--
ALTER TABLE `Items`
  ADD CONSTRAINT `Items_ibfk_1` FOREIGN KEY (`Producer`) REFERENCES `Producer` (`ID`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
