-- phpMyAdmin SQL Dump
-- version 5.0.4deb2
-- https://www.phpmyadmin.net/
--
-- Počítač: localhost:3306
-- Vytvořeno: Čtv 02. čen 2022, 18:01
-- Verze serveru: 10.5.15-MariaDB-0+deb11u1
-- Verze PHP: 7.4.28

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Databáze: `PPPART`
--

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
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_czech_ci;

-- --------------------------------------------------------

--
-- Struktura tabulky `Attributes`
--

CREATE TABLE `Attributes` (
  `ID` int(10) UNSIGNED NOT NULL,
  `Attribute_Name` tinytext COLLATE utf8mb4_czech_ci NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_czech_ci;

--
-- Vypisuji data pro tabulku `Attributes`
--

INSERT INTO `Attributes` (`ID`, `Attribute_Name`) VALUES
(1, 'Výrobce'),
(2, 'Název'),
(3, 'EAN'),
(4, 'Číslo výrobce'),
(5, 'Barva'),
(6, 'Materiál');

-- --------------------------------------------------------

--
-- Struktura tabulky `Categories`
--

CREATE TABLE `Categories` (
  `ID` mediumint(8) UNSIGNED NOT NULL,
  `Name` tinytext COLLATE utf8mb4_czech_ci NOT NULL,
  `Hidden` tinyint(1) UNSIGNED NOT NULL DEFAULT 0
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

CREATE TABLE `Categories_Attributes` (
  `ID` mediumint(9) NOT NULL,
  `Category` mediumint(9) UNSIGNED NOT NULL,
  `Attributes` int(11) UNSIGNED NOT NULL,
  `Hidden` tinyint(1) UNSIGNED NOT NULL DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_czech_ci;

--
-- Vypisuji data pro tabulku `Categories_Attributes`
--

INSERT INTO `Categories_Attributes` (`ID`, `Category`, `Attributes`, `Hidden`) VALUES
(1, 2, 3, 0),
(2, 2, 2, 0);

-- --------------------------------------------------------

--
-- Struktura tabulky `Categories_Items`
--

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
(2, 2, 4);

-- --------------------------------------------------------

--
-- Struktura tabulky `Items`
--

CREATE TABLE `Items` (
  `ID` bigint(20) UNSIGNED NOT NULL,
  `Name` tinytext COLLATE utf8mb4_czech_ci NOT NULL,
  `EAN` bigint(11) DEFAULT NULL,
  `Product_number` tinytext COLLATE utf8mb4_czech_ci DEFAULT NULL,
  `Producer` smallint(5) UNSIGNED NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_czech_ci;

--
-- Vypisuji data pro tabulku `Items`
--

INSERT INTO `Items` (`ID`, `Name`, `EAN`, `Product_number`, `Producer`) VALUES
(1, 'PLA - Metalická Zelená', 8594185641186, '050290000', 1),
(2, 'ASA Extrafill \"Traffic White\"', 8595632824008, 'ASA175_9016', 2);

-- --------------------------------------------------------

--
-- Struktura tabulky `Producer`
--

CREATE TABLE `Producer` (
  `ID` smallint(6) UNSIGNED NOT NULL,
  `Name` tinytext COLLATE utf8mb4_czech_ci NOT NULL,
  `URL` text COLLATE utf8mb4_czech_ci DEFAULT NULL
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

CREATE TABLE `Suppliers` (
  `ID` int(11) NOT NULL,
  `Item_ID` bigint(20) UNSIGNED NOT NULL,
  `Supplier` smallint(6) UNSIGNED NOT NULL,
  `Supplier_Name` tinytext COLLATE utf8mb4_czech_ci DEFAULT NULL,
  `Supplier_Code` tinytext COLLATE utf8mb4_czech_ci DEFAULT NULL,
  `Supplier_Link` mediumtext COLLATE utf8mb4_czech_ci DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_czech_ci;

--
-- Klíče pro exportované tabulky
--

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
-- AUTO_INCREMENT pro tabulku `Attribute`
--
ALTER TABLE `Attribute`
  MODIFY `ID` bigint(20) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=2;

--
-- AUTO_INCREMENT pro tabulku `Attributes`
--
ALTER TABLE `Attributes`
  MODIFY `ID` int(10) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=7;

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
  MODIFY `ID` mediumint(9) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=3;

--
-- AUTO_INCREMENT pro tabulku `Categories_Items`
--
ALTER TABLE `Categories_Items`
  MODIFY `ID` bigint(20) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=3;

--
-- AUTO_INCREMENT pro tabulku `Items`
--
ALTER TABLE `Items`
  MODIFY `ID` bigint(20) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=3;

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
