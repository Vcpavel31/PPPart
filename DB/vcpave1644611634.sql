-- phpMyAdmin SQL Dump
-- version 4.9.1
-- https://www.phpmyadmin.net/
--
-- Počítač: innodb.endora.cz:3306
-- Vytvořeno: Sob 26. úno 2022, 20:13
-- Verze serveru: 5.6.45-86.1
-- Verze PHP: 7.3.9

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

-- --------------------------------------------------------

--
-- Struktura tabulky `Balení`
--

CREATE TABLE `Balení` (
  `ID` int(11) NOT NULL,
  `Interni_ID` int(32) NOT NULL,
  `Balení_W` text COLLATE utf8_czech_ci NOT NULL,
  `Balení_S` int(16) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_czech_ci;

-- --------------------------------------------------------

--
-- Struktura tabulky `Barva`
--

CREATE TABLE `Barva` (
  `ID` int(11) NOT NULL,
  `Interni_ID` int(32) NOT NULL,
  `Barva_W` text COLLATE utf8_czech_ci NOT NULL,
  `Barva_S` int(16) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_czech_ci;

-- --------------------------------------------------------

--
-- Struktura tabulky `Barvy`
--

CREATE TABLE `Barvy` (
  `ID` int(16) NOT NULL,
  `Název` text COLLATE utf8_czech_ci NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_czech_ci;

-- --------------------------------------------------------

--
-- Struktura tabulky `Cena`
--

CREATE TABLE `Cena` (
  `ID` int(11) NOT NULL,
  `Interni_ID` int(32) NOT NULL,
  `Cena` int(11) NOT NULL,
  `Datum` datetime NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_czech_ci;

-- --------------------------------------------------------

--
-- Struktura tabulky `Datum poslední manipulace`
--

CREATE TABLE `Datum poslední manipulace` (
  `ID` int(11) NOT NULL,
  `Interni_ID` int(32) NOT NULL,
  `Datum poslední manipulace` datetime NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_czech_ci;

-- --------------------------------------------------------

--
-- Struktura tabulky `Datum přidání`
--

CREATE TABLE `Datum přidání` (
  `ID` int(11) NOT NULL,
  `Interni_ID` int(32) NOT NULL,
  `Datum přidání` date NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_czech_ci;

-- --------------------------------------------------------

--
-- Struktura tabulky `Dodavatel`
--

CREATE TABLE `Dodavatel` (
  `ID` int(11) NOT NULL,
  `Interni_ID` int(32) NOT NULL,
  `Dodavatel_W` text COLLATE utf8_czech_ci NOT NULL,
  `Dodavetl_S` int(16) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_czech_ci;

-- --------------------------------------------------------

--
-- Struktura tabulky `Dodavatelé`
--

CREATE TABLE `Dodavatelé` (
  `ID` int(16) NOT NULL,
  `Název` text COLLATE utf8_czech_ci NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_czech_ci;

-- --------------------------------------------------------

--
-- Struktura tabulky `Délka`
--

CREATE TABLE `Délka` (
  `ID` int(11) NOT NULL,
  `Interni_ID` int(32) NOT NULL,
  `Délka` int(11) NOT NULL,
  `Datum` datetime NOT NULL,
  `Jednotka` int(16) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_czech_ci;

-- --------------------------------------------------------

--
-- Struktura tabulky `EAN`
--

CREATE TABLE `EAN` (
  `ID` int(11) NOT NULL,
  `Interni_ID` int(32) NOT NULL,
  `EAN` int(16) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_czech_ci;

--
-- Vypisuji data pro tabulku `EAN`
--

INSERT INTO `EAN` (`ID`, `Interni_ID`, `EAN`) VALUES
(1, 1, 11111),
(2, 2, 22),
(3, 3, 3333);

-- --------------------------------------------------------

--
-- Struktura tabulky `Hmotnost`
--

CREATE TABLE `Hmotnost` (
  `ID` int(11) NOT NULL,
  `Interni_ID` int(32) NOT NULL,
  `Hmotnost` int(11) NOT NULL,
  `Datum` datetime NOT NULL,
  `Jednotka` int(16) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_czech_ci;

-- --------------------------------------------------------

--
-- Struktura tabulky `Hodnota`
--

CREATE TABLE `Hodnota` (
  `ID` int(11) NOT NULL,
  `Interni_ID` int(32) NOT NULL,
  `Hodnota` int(11) NOT NULL,
  `Datum` datetime NOT NULL,
  `Jednotka` int(16) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_czech_ci;

-- --------------------------------------------------------

--
-- Struktura tabulky `Interni_ID`
--

CREATE TABLE `Interni_ID` (
  `ID` int(32) NOT NULL,
  `Název` text COLLATE utf8_czech_ci NOT NULL,
  `Uzivatel` int(8) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_czech_ci;

--
-- Vypisuji data pro tabulku `Interni_ID`
--

INSERT INTO `Interni_ID` (`ID`, `Název`, `Uzivatel`) VALUES
(1, 'BY228G', 1),
(2, '1N5401G', 1),
(3, 'L-53ID', 1);

-- --------------------------------------------------------

--
-- Struktura tabulky `Jednotky`
--

CREATE TABLE `Jednotky` (
  `ID` int(16) NOT NULL,
  `Zkratka` text COLLATE utf8_czech_ci NOT NULL,
  `Název` text COLLATE utf8_czech_ci NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_czech_ci;

-- --------------------------------------------------------

--
-- Struktura tabulky `Jmenovité napětí`
--

CREATE TABLE `Jmenovité napětí` (
  `ID` int(11) NOT NULL,
  `Interni_ID` int(32) NOT NULL,
  `Jmenovité napětí` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_czech_ci;

-- --------------------------------------------------------

--
-- Struktura tabulky `Jmenovitý výkon`
--

CREATE TABLE `Jmenovitý výkon` (
  `ID` int(11) NOT NULL,
  `Interni_ID` int(32) NOT NULL,
  `Jmenovitý výkon` int(11) NOT NULL,
  `Jednotka` int(16) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_czech_ci;

-- --------------------------------------------------------

--
-- Struktura tabulky `Kapacita`
--

CREATE TABLE `Kapacita` (
  `ID` int(11) NOT NULL,
  `Interni_ID` int(32) NOT NULL,
  `Kapacita` int(11) NOT NULL,
  `Datum` datetime NOT NULL,
  `Jednotka` int(16) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_czech_ci;

-- --------------------------------------------------------

--
-- Struktura tabulky `Kategorie`
--

CREATE TABLE `Kategorie` (
  `ID` int(16) NOT NULL,
  `Nazev` text COLLATE utf8_czech_ci NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_czech_ci;

--
-- Vypisuji data pro tabulku `Kategorie`
--

INSERT INTO `Kategorie` (`ID`, `Nazev`) VALUES
(1, 'Slaboproud'),
(2, 'Rezistory'),
(3, 'Pevné rezistory'),
(4, 'Nastavitelné rezistory'),
(5, 'Potenciometry '),
(6, 'Trimry'),
(7, 'Reostaty'),
(8, 'PTC'),
(9, 'NTC'),
(10, 'Kondenzátory'),
(11, 'Keramické'),
(12, 'Fóliové'),
(13, 'Tantalové'),
(14, 'Superkondenzátory'),
(15, 'Elektrolytické'),
(16, 'Cívky/tlumivky'),
(17, 'Diody'),
(18, 'Usměrňovací'),
(19, 'Zenerovy'),
(20, 'Schottkyho'),
(21, 'LED'),
(22, 'Tunelové'),
(23, 'Usměrňovače'),
(24, 'Tranzistory'),
(25, 'Bipolární'),
(26, 'PNP'),
(27, 'NPN'),
(28, 'IGBT'),
(29, 'Unipolární'),
(30, 'Mos-FET'),
(31, 'J-FET'),
(32, 'Elektronky'),
(33, 'Jištění'),
(34, 'Přepětí'),
(35, 'Transil'),
(36, 'Trysil'),
(37, 'Varistor'),
(38, 'Nadproud'),
(39, 'Pojistky'),
(40, 'Polyswitch'),
(41, 'Integrované obvody'),
(42, 'Paměti'),
(43, 'FLASH'),
(44, 'EPROM / EEPROM'),
(45, 'SRAM / DRAM'),
(46, 'Mikroprocesory'),
(47, 'Hradla'),
(48, 'AND'),
(49, 'NAND'),
(50, 'OR'),
(51, 'NOR'),
(52, 'Invertory'),
(53, 'Ostatní'),
(54, 'Analaogové a kombinované obvody'),
(55, 'Převodníky A/D'),
(56, 'Převodníky D/A'),
(57, 'Operační zesilovače'),
(58, 'Stabilizátory'),
(59, 'Periferní obvody'),
(60, 'Multiplexery'),
(61, 'Dekodéry'),
(62, 'Posuvné registry'),
(63, 'Spínací prvky'),
(64, 'Relé do 10A'),
(65, 'Triaky'),
(66, 'Tyristory'),
(67, 'Diaky'),
(68, 'Optoelektronika'),
(69, 'Vývojové platformy'),
(70, 'RPI'),
(71, 'Shieldy'),
(72, 'Arduino'),
(73, 'Shieldy'),
(74, 'PLC'),
(75, 'Čidla'),
(76, 'Teplota / Vlhkost'),
(77, 'Pohyb'),
(78, 'Tlak'),
(79, 'CO2'),
(80, 'Plyn'),
(81, 'Ostatní'),
(82, 'Konektory'),
(83, 'Konstrukční díly'),
(84, 'Elektromechanické'),
(85, 'Silnoproud'),
(86, 'Rozvodnice'),
(87, 'Modulární přístroje'),
(88, 'Jističe'),
(89, 'MIR (Multifunkční impulzní relé)'),
(90, 'MCR (Multifunkční časové relé)'),
(91, 'Nadproudové jistící relé'),
(92, 'Ochranné relé'),
(93, 'Stykače'),
(94, 'Chrániče'),
(95, 'KOMBI (jistič + chránič) '),
(96, 'Elektroměry na DIN'),
(97, 'Oblouková ochrana'),
(98, 'Odpínače'),
(99, 'Pomocné kontakty'),
(100, 'Propojovací lišty'),
(101, 'Relé'),
(102, 'Vypínače na DIN'),
(103, 'Ostatní'),
(104, 'Rozváděče'),
(105, 'Instalace'),
(106, 'Krabice'),
(107, 'Ventilátory'),
(108, 'Svítidla'),
(109, 'Světelné zdroje'),
(110, 'Svítidla'),
(111, 'Stmívače'),
(112, 'Objímky'),
(113, 'Zásuvky a spínače'),
(114, 'Zásuvky 230V'),
(115, 'Zásuvky 400V'),
(116, 'Zásuvky speciální'),
(117, 'Spínače'),
(118, 'Svorky'),
(119, 'WAGO + Čokolády'),
(120, 'RSA'),
(121, 'Můstky'),
(122, 'Fotovoltaika'),
(123, 'Pojistky'),
(124, 'Nožové'),
(125, 'Šroubové'),
(126, 'Ochranné materiály'),
(127, 'Nehořlavé'),
(128, 'Výstražné (Cedule, pásky, nálepky)'),
(129, 'Bužírky / pásky'),
(130, 'Kabely'),
(131, 'Vodiče'),
(132, 'Pevné (K)'),
(133, 'Lankové (S)'),
(134, 'Sdělovací '),
(135, 'UTP'),
(136, 'STP'),
(137, 'KOAX'),
(138, 'Optické'),
(139, 'Speciální'),
(140, 'Ovládací'),
(141, 'Speciální'),
(142, 'Stavebniny'),
(143, 'Hrubá stavba'),
(144, 'Klempířské prvky'),
(145, 'Drenáže a odvodnění'),
(146, 'Stavební směsi'),
(147, 'Dřevo'),
(148, 'Sádrokarton'),
(149, 'Ostatní'),
(150, 'Spojovací materiál'),
(151, 'Vruty'),
(152, 'Šrouby metrické'),
(153, 'Šrouby Whitwort'),
(154, 'Šrouby ostatní'),
(155, 'Kování'),
(156, 'Ostatní'),
(157, 'Voda topení sanita'),
(158, 'Trubky vodovodní / topenářské'),
(159, 'Plastové'),
(160, 'Měděné'),
(161, 'Kovové'),
(162, 'Trubky sanitní'),
(163, 'Fitinky'),
(164, 'Plastové '),
(165, 'Měděné'),
(166, 'Kovové'),
(167, 'Kohouty'),
(168, 'Ostatní'),
(169, 'Kov'),
(170, 'Profily'),
(171, 'Armování'),
(172, 'Sváření'),
(173, 'MMA (111)'),
(174, 'MIG/MAG (131/136)'),
(175, 'TIG (141)'),
(176, 'Plamen (311)'),
(177, 'Obrábění'),
(178, 'Frézování'),
(179, 'Soustružení'),
(180, 'Strojní součásti'),
(181, 'Ložiska'),
(182, 'Gufera'),
(183, 'Auta'),
(184, 'Těžká technika'),
(185, 'Stroje'),
(186, 'Pneu'),
(187, 'Maziva'),
(188, 'Oleje'),
(189, 'Vazelíny'),
(190, 'Maznice'),
(191, 'Sítě'),
(192, 'Routery'),
(193, 'Switche'),
(194, 'Patchpanely / síťové zásuvky'),
(195, 'Konektory'),
(196, 'Optika'),
(197, 'Antény'),
(198, 'Ostatní'),
(199, '3D tisk'),
(200, 'Filamenty'),
(201, 'PLA'),
(202, 'PETG'),
(203, 'ABS'),
(204, 'ASA'),
(205, 'CPE'),
(206, 'Nylon'),
(207, 'FLEX'),
(208, 'Speciální'),
(209, 'Trysky'),
(210, 'Náhradní díly');

-- --------------------------------------------------------

--
-- Struktura tabulky `Kladná tolerance`
--

CREATE TABLE `Kladná tolerance` (
  `ID` int(11) NOT NULL,
  `Interni_ID` int(32) NOT NULL,
  `Kladná tolerance` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_czech_ci;

-- --------------------------------------------------------

--
-- Struktura tabulky `Koncovka 1`
--

CREATE TABLE `Koncovka 1` (
  `ID` int(11) NOT NULL,
  `Interni_ID` int(32) NOT NULL,
  `Koncovka` int(16) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_czech_ci;

-- --------------------------------------------------------

--
-- Struktura tabulky `Koncovka 2`
--

CREATE TABLE `Koncovka 2` (
  `ID` int(11) NOT NULL,
  `Interni_ID` int(32) NOT NULL,
  `Koncovka` int(16) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_czech_ci;

-- --------------------------------------------------------

--
-- Struktura tabulky `Koncovky`
--

CREATE TABLE `Koncovky` (
  `ID` int(16) NOT NULL,
  `Název` text COLLATE utf8_czech_ci NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_czech_ci;

-- --------------------------------------------------------

--
-- Struktura tabulky `Materiál`
--

CREATE TABLE `Materiál` (
  `ID` int(11) NOT NULL,
  `Interni_ID` int(32) NOT NULL,
  `Materiál_W` text COLLATE utf8_czech_ci NOT NULL,
  `Materiál_S` int(16) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_czech_ci;

-- --------------------------------------------------------

--
-- Struktura tabulky `Materiály`
--

CREATE TABLE `Materiály` (
  `ID` int(16) NOT NULL,
  `Název` text COLLATE utf8_czech_ci NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_czech_ci;

-- --------------------------------------------------------

--
-- Struktura tabulky `Minimální počet skladem`
--

CREATE TABLE `Minimální počet skladem` (
  `ID` int(11) NOT NULL,
  `Interni_ID` int(32) NOT NULL,
  `Minimální počet skladem` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_czech_ci;

-- --------------------------------------------------------

--
-- Struktura tabulky `Obaly`
--

CREATE TABLE `Obaly` (
  `ID` int(16) NOT NULL,
  `Název` text COLLATE utf8_czech_ci NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_czech_ci;

-- --------------------------------------------------------

--
-- Struktura tabulky `Objednací číslo`
--

CREATE TABLE `Objednací číslo` (
  `ID` int(11) NOT NULL,
  `Interni_ID` int(32) NOT NULL,
  `Objednací číslo` text COLLATE utf8_czech_ci
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_czech_ci;

--
-- Vypisuji data pro tabulku `Objednací číslo`
--

INSERT INTO `Objednací číslo` (`ID`, `Interni_ID`, `Objednací číslo`) VALUES
(1, 3, 'L-53ID'),
(2, 2, '1863154'),
(3, 1, NULL);

-- --------------------------------------------------------

--
-- Struktura tabulky `Označení v knihovně`
--

CREATE TABLE `Označení v knihovně` (
  `ID` int(11) NOT NULL,
  `Interni_ID` int(32) NOT NULL,
  `Označení v knihovně` text COLLATE utf8_czech_ci NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_czech_ci;

-- --------------------------------------------------------

--
-- Struktura tabulky `pma__bookmark`
--

CREATE TABLE `pma__bookmark` (
  `id` int(10) UNSIGNED NOT NULL,
  `dbase` varchar(255) COLLATE utf8_bin NOT NULL DEFAULT '',
  `user` varchar(255) COLLATE utf8_bin NOT NULL DEFAULT '',
  `label` varchar(255) CHARACTER SET utf8 NOT NULL DEFAULT '',
  `query` text COLLATE utf8_bin NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_bin COMMENT='Bookmarks';

-- --------------------------------------------------------

--
-- Struktura tabulky `pma__central_columns`
--

CREATE TABLE `pma__central_columns` (
  `db_name` varchar(64) COLLATE utf8_bin NOT NULL,
  `col_name` varchar(64) COLLATE utf8_bin NOT NULL,
  `col_type` varchar(64) COLLATE utf8_bin NOT NULL,
  `col_length` text COLLATE utf8_bin,
  `col_collation` varchar(64) COLLATE utf8_bin NOT NULL,
  `col_isNull` tinyint(1) NOT NULL,
  `col_extra` varchar(255) COLLATE utf8_bin DEFAULT '',
  `col_default` text COLLATE utf8_bin
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_bin COMMENT='Central list of columns';

-- --------------------------------------------------------

--
-- Struktura tabulky `pma__column_info`
--

CREATE TABLE `pma__column_info` (
  `id` int(5) UNSIGNED NOT NULL,
  `db_name` varchar(64) COLLATE utf8_bin NOT NULL DEFAULT '',
  `table_name` varchar(64) COLLATE utf8_bin NOT NULL DEFAULT '',
  `column_name` varchar(64) COLLATE utf8_bin NOT NULL DEFAULT '',
  `comment` varchar(255) CHARACTER SET utf8 NOT NULL DEFAULT '',
  `mimetype` varchar(255) CHARACTER SET utf8 NOT NULL DEFAULT '',
  `transformation` varchar(255) COLLATE utf8_bin NOT NULL DEFAULT '',
  `transformation_options` varchar(255) COLLATE utf8_bin NOT NULL DEFAULT '',
  `input_transformation` varchar(255) COLLATE utf8_bin NOT NULL DEFAULT '',
  `input_transformation_options` varchar(255) COLLATE utf8_bin NOT NULL DEFAULT ''
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_bin COMMENT='Column information for phpMyAdmin';

-- --------------------------------------------------------

--
-- Struktura tabulky `pma__designer_settings`
--

CREATE TABLE `pma__designer_settings` (
  `username` varchar(64) COLLATE utf8_bin NOT NULL,
  `settings_data` text COLLATE utf8_bin NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_bin COMMENT='Settings related to Designer';

-- --------------------------------------------------------

--
-- Struktura tabulky `pma__export_templates`
--

CREATE TABLE `pma__export_templates` (
  `id` int(5) UNSIGNED NOT NULL,
  `username` varchar(64) COLLATE utf8_bin NOT NULL,
  `export_type` varchar(10) COLLATE utf8_bin NOT NULL,
  `template_name` varchar(64) COLLATE utf8_bin NOT NULL,
  `template_data` text COLLATE utf8_bin NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_bin COMMENT='Saved export templates';

-- --------------------------------------------------------

--
-- Struktura tabulky `pma__favorite`
--

CREATE TABLE `pma__favorite` (
  `username` varchar(64) COLLATE utf8_bin NOT NULL,
  `tables` text COLLATE utf8_bin NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_bin COMMENT='Favorite tables';

-- --------------------------------------------------------

--
-- Struktura tabulky `pma__history`
--

CREATE TABLE `pma__history` (
  `id` bigint(20) UNSIGNED NOT NULL,
  `username` varchar(64) COLLATE utf8_bin NOT NULL DEFAULT '',
  `db` varchar(64) COLLATE utf8_bin NOT NULL DEFAULT '',
  `table` varchar(64) COLLATE utf8_bin NOT NULL DEFAULT '',
  `timevalue` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `sqlquery` text COLLATE utf8_bin NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_bin COMMENT='SQL history for phpMyAdmin';

-- --------------------------------------------------------

--
-- Struktura tabulky `pma__navigationhiding`
--

CREATE TABLE `pma__navigationhiding` (
  `username` varchar(64) COLLATE utf8_bin NOT NULL,
  `item_name` varchar(64) COLLATE utf8_bin NOT NULL,
  `item_type` varchar(64) COLLATE utf8_bin NOT NULL,
  `db_name` varchar(64) COLLATE utf8_bin NOT NULL,
  `table_name` varchar(64) COLLATE utf8_bin NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_bin COMMENT='Hidden items of navigation tree';

-- --------------------------------------------------------

--
-- Struktura tabulky `pma__pdf_pages`
--

CREATE TABLE `pma__pdf_pages` (
  `db_name` varchar(64) COLLATE utf8_bin NOT NULL DEFAULT '',
  `page_nr` int(10) UNSIGNED NOT NULL,
  `page_descr` varchar(50) CHARACTER SET utf8 NOT NULL DEFAULT ''
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_bin COMMENT='PDF relation pages for phpMyAdmin';

-- --------------------------------------------------------

--
-- Struktura tabulky `pma__recent`
--

CREATE TABLE `pma__recent` (
  `username` varchar(64) COLLATE utf8_bin NOT NULL,
  `tables` text COLLATE utf8_bin NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_bin COMMENT='Recently accessed tables';

--
-- Vypisuji data pro tabulku `pma__recent`
--

INSERT INTO `pma__recent` (`username`, `tables`) VALUES
('vcpavel', '[{\"db\":\"vcpave1644611634\",\"table\":\"Kategorie\"},{\"db\":\"vcpave1644611634\",\"table\":\"Usporadani_kategorii\"},{\"db\":\"vcpave1644611634\",\"table\":\"EAN\"},{\"db\":\"vcpave1644611634\",\"table\":\"Interni_ID\"},{\"db\":\"vcpave1644611634\",\"table\":\"Objednac\\u00ed \\u010d\\u00edslo\"},{\"db\":\"vcpave1644611634\",\"table\":\"\\u010c\\u00edslo v\\u00fdrobce\"},{\"db\":\"vcpave1644611634\",\"table\":\"Uzivatele\"}]');

-- --------------------------------------------------------

--
-- Struktura tabulky `pma__relation`
--

CREATE TABLE `pma__relation` (
  `master_db` varchar(64) COLLATE utf8_bin NOT NULL DEFAULT '',
  `master_table` varchar(64) COLLATE utf8_bin NOT NULL DEFAULT '',
  `master_field` varchar(64) COLLATE utf8_bin NOT NULL DEFAULT '',
  `foreign_db` varchar(64) COLLATE utf8_bin NOT NULL DEFAULT '',
  `foreign_table` varchar(64) COLLATE utf8_bin NOT NULL DEFAULT '',
  `foreign_field` varchar(64) COLLATE utf8_bin NOT NULL DEFAULT ''
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_bin COMMENT='Relation table';

-- --------------------------------------------------------

--
-- Struktura tabulky `pma__savedsearches`
--

CREATE TABLE `pma__savedsearches` (
  `id` int(5) UNSIGNED NOT NULL,
  `username` varchar(64) COLLATE utf8_bin NOT NULL DEFAULT '',
  `db_name` varchar(64) COLLATE utf8_bin NOT NULL DEFAULT '',
  `search_name` varchar(64) COLLATE utf8_bin NOT NULL DEFAULT '',
  `search_data` text COLLATE utf8_bin NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_bin COMMENT='Saved searches';

-- --------------------------------------------------------

--
-- Struktura tabulky `pma__table_coords`
--

CREATE TABLE `pma__table_coords` (
  `db_name` varchar(64) COLLATE utf8_bin NOT NULL DEFAULT '',
  `table_name` varchar(64) COLLATE utf8_bin NOT NULL DEFAULT '',
  `pdf_page_number` int(11) NOT NULL DEFAULT '0',
  `x` float UNSIGNED NOT NULL DEFAULT '0',
  `y` float UNSIGNED NOT NULL DEFAULT '0'
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_bin COMMENT='Table coordinates for phpMyAdmin PDF output';

-- --------------------------------------------------------

--
-- Struktura tabulky `pma__table_info`
--

CREATE TABLE `pma__table_info` (
  `db_name` varchar(64) COLLATE utf8_bin NOT NULL DEFAULT '',
  `table_name` varchar(64) COLLATE utf8_bin NOT NULL DEFAULT '',
  `display_field` varchar(64) COLLATE utf8_bin NOT NULL DEFAULT ''
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_bin COMMENT='Table information for phpMyAdmin';

-- --------------------------------------------------------

--
-- Struktura tabulky `pma__table_uiprefs`
--

CREATE TABLE `pma__table_uiprefs` (
  `username` varchar(64) COLLATE utf8_bin NOT NULL,
  `db_name` varchar(64) COLLATE utf8_bin NOT NULL,
  `table_name` varchar(64) COLLATE utf8_bin NOT NULL,
  `prefs` text COLLATE utf8_bin NOT NULL,
  `last_update` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_bin COMMENT='Tables'' UI preferences';

-- --------------------------------------------------------

--
-- Struktura tabulky `pma__tracking`
--

CREATE TABLE `pma__tracking` (
  `db_name` varchar(64) COLLATE utf8_bin NOT NULL,
  `table_name` varchar(64) COLLATE utf8_bin NOT NULL,
  `version` int(10) UNSIGNED NOT NULL,
  `date_created` datetime NOT NULL,
  `date_updated` datetime NOT NULL,
  `schema_snapshot` text COLLATE utf8_bin NOT NULL,
  `schema_sql` text COLLATE utf8_bin,
  `data_sql` longtext COLLATE utf8_bin,
  `tracking` set('UPDATE','REPLACE','INSERT','DELETE','TRUNCATE','CREATE DATABASE','ALTER DATABASE','DROP DATABASE','CREATE TABLE','ALTER TABLE','RENAME TABLE','DROP TABLE','CREATE INDEX','DROP INDEX','CREATE VIEW','ALTER VIEW','DROP VIEW') COLLATE utf8_bin DEFAULT NULL,
  `tracking_active` int(1) UNSIGNED NOT NULL DEFAULT '1'
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_bin COMMENT='Database changes tracking for phpMyAdmin';

-- --------------------------------------------------------

--
-- Struktura tabulky `pma__userconfig`
--

CREATE TABLE `pma__userconfig` (
  `username` varchar(64) COLLATE utf8_bin NOT NULL,
  `timevalue` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  `config_data` text COLLATE utf8_bin NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_bin COMMENT='User preferences storage for phpMyAdmin';

--
-- Vypisuji data pro tabulku `pma__userconfig`
--

INSERT INTO `pma__userconfig` (`username`, `timevalue`, `config_data`) VALUES
('vcpavel', '2022-02-26 14:40:01', '{\"Console\\/Mode\":\"collapse\",\"lang\":\"cs\"}');

-- --------------------------------------------------------

--
-- Struktura tabulky `pma__usergroups`
--

CREATE TABLE `pma__usergroups` (
  `usergroup` varchar(64) COLLATE utf8_bin NOT NULL,
  `tab` varchar(64) COLLATE utf8_bin NOT NULL,
  `allowed` enum('Y','N') COLLATE utf8_bin NOT NULL DEFAULT 'N'
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_bin COMMENT='User groups with configured menu items';

-- --------------------------------------------------------

--
-- Struktura tabulky `pma__users`
--

CREATE TABLE `pma__users` (
  `username` varchar(64) COLLATE utf8_bin NOT NULL,
  `usergroup` varchar(64) COLLATE utf8_bin NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_bin COMMENT='Users and their assignments to user groups';

-- --------------------------------------------------------

--
-- Struktura tabulky `Pouzdra`
--

CREATE TABLE `Pouzdra` (
  `ID` int(16) NOT NULL,
  `Název` text COLLATE utf8_czech_ci NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_czech_ci;

-- --------------------------------------------------------

--
-- Struktura tabulky `Pouzdro`
--

CREATE TABLE `Pouzdro` (
  `ID` int(11) NOT NULL,
  `Interni_ID` int(32) NOT NULL,
  `Pouzdro_W` text COLLATE utf8_czech_ci NOT NULL,
  `Pouzdro_S` int(16) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_czech_ci;

-- --------------------------------------------------------

--
-- Struktura tabulky `Pozice ve skladu`
--

CREATE TABLE `Pozice ve skladu` (
  `ID` int(11) NOT NULL,
  `Interni_ID` int(32) NOT NULL,
  `Pozice ve skladu` int(16) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_czech_ci;

-- --------------------------------------------------------

--
-- Struktura tabulky `Poznámka`
--

CREATE TABLE `Poznámka` (
  `ID` int(11) NOT NULL,
  `Interni_ID` int(32) NOT NULL,
  `Poznámka` text COLLATE utf8_czech_ci NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_czech_ci;

-- --------------------------------------------------------

--
-- Struktura tabulky `Počet skladem`
--

CREATE TABLE `Počet skladem` (
  `ID` int(11) NOT NULL,
  `Interni_ID` int(32) NOT NULL,
  `Počet skladem` int(11) NOT NULL,
  `Datum` datetime NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_czech_ci;

-- --------------------------------------------------------

--
-- Struktura tabulky `Počet vodičů`
--

CREATE TABLE `Počet vodičů` (
  `ID` int(11) NOT NULL,
  `Interni_ID` int(32) NOT NULL,
  `Počet vodičů` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_czech_ci;

-- --------------------------------------------------------

--
-- Struktura tabulky `Prirazeni_kategorii`
--

CREATE TABLE `Prirazeni_kategorii` (
  `ID` int(64) NOT NULL,
  `Soucastka` int(32) NOT NULL,
  `Kategorie` int(16) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_czech_ci;

-- --------------------------------------------------------

--
-- Struktura tabulky `Stav`
--

CREATE TABLE `Stav` (
  `ID` int(11) NOT NULL,
  `Interni_ID` int(32) NOT NULL,
  `Stav_S` int(8) DEFAULT NULL,
  `Stav_W` text COLLATE utf8_czech_ci NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_czech_ci;

-- --------------------------------------------------------

--
-- Struktura tabulky `Stavy`
--

CREATE TABLE `Stavy` (
  `ID` int(8) NOT NULL,
  `Název` text COLLATE utf8_czech_ci NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_czech_ci;

-- --------------------------------------------------------

--
-- Struktura tabulky `Tolerance`
--

CREATE TABLE `Tolerance` (
  `ID` int(11) NOT NULL,
  `Interni_ID` int(32) NOT NULL,
  `Tolerance` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_czech_ci;

-- --------------------------------------------------------

--
-- Struktura tabulky `Usporadani_kategorii`
--

CREATE TABLE `Usporadani_kategorii` (
  `ID` int(16) NOT NULL,
  `Kategorie` int(16) NOT NULL,
  `Nadrazena` int(16) DEFAULT NULL,
  `Uzivatel` int(8) NOT NULL DEFAULT '1'
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_czech_ci;

--
-- Vypisuji data pro tabulku `Usporadani_kategorii`
--

INSERT INTO `Usporadani_kategorii` (`ID`, `Kategorie`, `Nadrazena`, `Uzivatel`) VALUES
(2, 1, NULL, 1),
(3, 85, NULL, 1),
(4, 130, NULL, 1),
(5, 142, NULL, 1),
(6, 150, NULL, 1),
(7, 157, NULL, 1),
(8, 169, NULL, 1),
(9, 180, NULL, 1),
(10, 191, NULL, 1),
(11, 199, NULL, 1),
(12, 2, 1, 1),
(13, 3, 2, 1),
(14, 4, 2, 1),
(15, 5, 4, 1),
(16, 6, 4, 1),
(17, 7, 4, 1),
(18, 8, 4, 1),
(19, 9, 4, 1),
(20, 10, 1, 1),
(21, 11, 10, 1),
(22, 12, 10, 1),
(23, 13, 10, 1),
(24, 14, 10, 1),
(25, 15, 10, 1),
(26, 16, 1, 1),
(27, 17, 1, 1),
(28, 18, 17, 1),
(29, 19, 17, 1),
(30, 20, 17, 1),
(31, 21, 17, 1),
(32, 22, 17, 1),
(33, 23, 1, 1),
(34, 24, 1, 1),
(35, 25, 24, 1),
(36, 26, 25, 1),
(37, 27, 25, 1),
(38, 28, 24, 1),
(39, 29, 24, 1),
(40, 30, 29, 1),
(41, 31, 29, 1),
(42, 32, 1, 1),
(43, 33, 1, 1),
(44, 34, 33, 1),
(45, 35, 34, 1),
(46, 36, 34, 1),
(47, 37, 34, 1),
(48, 38, 34, 1),
(49, 39, 38, 1),
(50, 40, 38, 1),
(51, 41, 1, 1),
(52, 42, 41, 1),
(53, 43, 42, 1),
(54, 44, 42, 1),
(55, 45, 42, 1),
(56, 46, 41, 1),
(57, 47, 41, 1),
(58, 48, 47, 1),
(59, 49, 47, 1),
(60, 50, 47, 1),
(61, 51, 47, 1),
(62, 52, 47, 1),
(63, 53, 47, 1),
(64, 54, 41, 1),
(65, 55, 54, 1),
(66, 56, 54, 1),
(67, 57, 54, 1),
(68, 58, 41, 1),
(69, 59, 41, 1),
(70, 60, 41, 1),
(71, 61, 41, 1),
(72, 62, 41, 1),
(73, 63, 1, 1),
(74, 64, 63, 1),
(75, 65, 63, 1),
(76, 66, 63, 1),
(77, 67, 63, 1),
(78, 68, 1, 1),
(79, 69, 1, 1),
(80, 70, 69, 1),
(81, 71, 70, 1),
(82, 72, 69, 1),
(83, 73, 72, 1),
(84, 74, 69, 1),
(85, 75, 1, 1),
(86, 76, 75, 1),
(87, 77, 75, 1),
(88, 78, 75, 1),
(89, 79, 75, 1),
(90, 80, 75, 1),
(91, 81, 75, 1),
(92, 82, 1, 1),
(93, 83, 1, 1),
(94, 84, 1, 1),
(95, 86, 85, 1),
(96, 87, 86, 1),
(97, 88, 87, 1),
(98, 89, 87, 1),
(99, 90, 87, 1),
(100, 91, 87, 1),
(101, 92, 87, 1),
(102, 93, 87, 1),
(103, 94, 87, 1),
(104, 95, 87, 1),
(105, 96, 87, 1),
(106, 97, 87, 1),
(107, 98, 87, 1),
(108, 99, 87, 1),
(109, 100, 87, 1),
(110, 101, 87, 1),
(111, 102, 87, 1),
(112, 103, 87, 1),
(113, 104, 86, 1),
(114, 105, 85, 1),
(115, 106, 105, 1),
(116, 107, 105, 1),
(117, 108, 105, 1),
(118, 109, 108, 1),
(119, 110, 108, 1),
(120, 111, 108, 1),
(121, 112, 108, 1),
(122, 113, 105, 1),
(123, 114, 113, 1),
(124, 115, 113, 1),
(125, 116, 113, 1),
(126, 117, 113, 1),
(127, 118, 105, 1),
(128, 119, 118, 1),
(129, 120, 118, 1),
(130, 121, 118, 1),
(131, 122, 85, 1),
(132, 123, 85, 1),
(133, 124, 123, 1),
(134, 125, 123, 1),
(135, 126, 85, 1),
(136, 127, 126, 1),
(137, 128, 126, 1),
(138, 129, 126, 1),
(139, 131, 130, 1),
(140, 132, 130, 1),
(141, 133, 130, 1),
(142, 134, 130, 1),
(143, 135, 134, 1),
(144, 136, 134, 1),
(145, 137, 134, 1),
(146, 138, 134, 1),
(147, 139, 134, 1),
(148, 140, 130, 1),
(149, 141, 130, 1),
(150, 143, 142, 1),
(151, 144, 142, 1),
(152, 145, 142, 1),
(153, 146, 142, 1),
(154, 147, 142, 1),
(155, 148, 142, 1),
(156, 149, 142, 1),
(157, 151, 150, 1),
(158, 152, 150, 1),
(159, 153, 150, 1),
(160, 154, 150, 1),
(161, 155, 150, 1),
(162, 156, 150, 1),
(163, 158, 157, 1),
(164, 159, 158, 1),
(165, 160, 158, 1),
(166, 161, 158, 1),
(167, 162, 157, 1),
(168, 163, 157, 1),
(169, 164, 163, 1),
(170, 165, 163, 1),
(171, 166, 163, 1),
(172, 167, 157, 1),
(173, 168, 157, 1),
(174, 170, 169, 1),
(175, 171, 169, 1),
(176, 172, 169, 1),
(177, 173, 172, 1),
(178, 174, 172, 1),
(179, 175, 172, 1),
(180, 176, 172, 1),
(181, 177, 169, 1),
(182, 178, 177, 1),
(183, 179, 177, 1),
(184, 181, 180, 1),
(185, 182, 180, 1),
(186, 183, 180, 1),
(187, 184, 180, 1),
(188, 185, 180, 1),
(189, 186, 180, 1),
(190, 187, 180, 1),
(191, 188, 187, 1),
(192, 189, 187, 1),
(193, 190, 187, 1),
(194, 192, 191, 1),
(195, 193, 191, 1),
(196, 194, 191, 1),
(197, 195, 191, 1),
(198, 196, 191, 1),
(199, 197, 191, 1),
(200, 198, 191, 1),
(201, 200, 199, 1),
(202, 201, 200, 1),
(203, 202, 200, 1),
(204, 203, 200, 1),
(205, 204, 200, 1),
(206, 205, 200, 1),
(207, 206, 200, 1),
(208, 207, 200, 1),
(209, 208, 200, 1),
(210, 209, 199, 1),
(211, 210, 199, 1);

-- --------------------------------------------------------

--
-- Struktura tabulky `Uzivatele`
--

CREATE TABLE `Uzivatele` (
  `ID` int(8) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_czech_ci;

--
-- Vypisuji data pro tabulku `Uzivatele`
--

INSERT INTO `Uzivatele` (`ID`) VALUES
(1);

-- --------------------------------------------------------

--
-- Struktura tabulky `Vlastní označení`
--

CREATE TABLE `Vlastní označení` (
  `ID` int(11) NOT NULL,
  `Interni_ID` int(32) NOT NULL,
  `Vlastní označení` text COLLATE utf8_czech_ci NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_czech_ci;

-- --------------------------------------------------------

--
-- Struktura tabulky `Výrobce`
--

CREATE TABLE `Výrobce` (
  `ID` int(11) NOT NULL,
  `Interni_ID` int(32) NOT NULL,
  `Výrobce_W` text COLLATE utf8_czech_ci NOT NULL,
  `Výrobce_S` int(16) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_czech_ci;

-- --------------------------------------------------------

--
-- Struktura tabulky `Výrobci`
--

CREATE TABLE `Výrobci` (
  `ID` int(16) NOT NULL,
  `Název` text COLLATE utf8_czech_ci NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_czech_ci;

-- --------------------------------------------------------

--
-- Struktura tabulky `Záporná tolerance`
--

CREATE TABLE `Záporná tolerance` (
  `ID` int(11) NOT NULL,
  `Interni_ID` int(32) NOT NULL,
  `Záporná tolerance` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_czech_ci;

-- --------------------------------------------------------

--
-- Struktura tabulky `Číslo výrobce`
--

CREATE TABLE `Číslo výrobce` (
  `ID` int(11) NOT NULL,
  `Interni_ID` int(32) NOT NULL,
  `Číslo výrobce` text COLLATE utf8_czech_ci
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_czech_ci;

--
-- Vypisuji data pro tabulku `Číslo výrobce`
--

INSERT INTO `Číslo výrobce` (`ID`, `Interni_ID`, `Číslo výrobce`) VALUES
(1, 2, '1N5401G'),
(2, 3, 'L-53ID'),
(3, 1, NULL);

--
-- Klíče pro exportované tabulky
--

--
-- Klíče pro tabulku `Balení`
--
ALTER TABLE `Balení`
  ADD PRIMARY KEY (`ID`),
  ADD KEY `Balení_fk0` (`Interni_ID`),
  ADD KEY `Balení_fk1` (`Balení_S`);

--
-- Klíče pro tabulku `Barva`
--
ALTER TABLE `Barva`
  ADD PRIMARY KEY (`ID`),
  ADD KEY `Barva_fk0` (`Interni_ID`),
  ADD KEY `Barva_fk1` (`Barva_S`);

--
-- Klíče pro tabulku `Barvy`
--
ALTER TABLE `Barvy`
  ADD PRIMARY KEY (`ID`);

--
-- Klíče pro tabulku `Cena`
--
ALTER TABLE `Cena`
  ADD PRIMARY KEY (`ID`),
  ADD KEY `Cena_fk0` (`Interni_ID`);

--
-- Klíče pro tabulku `Datum poslední manipulace`
--
ALTER TABLE `Datum poslední manipulace`
  ADD PRIMARY KEY (`ID`),
  ADD KEY `Datum poslední manipulace_fk0` (`Interni_ID`);

--
-- Klíče pro tabulku `Datum přidání`
--
ALTER TABLE `Datum přidání`
  ADD PRIMARY KEY (`ID`),
  ADD KEY `Datum přidání_fk0` (`Interni_ID`);

--
-- Klíče pro tabulku `Dodavatel`
--
ALTER TABLE `Dodavatel`
  ADD PRIMARY KEY (`ID`),
  ADD KEY `Dodavatel_fk0` (`Interni_ID`),
  ADD KEY `Dodavatel_fk1` (`Dodavetl_S`);

--
-- Klíče pro tabulku `Dodavatelé`
--
ALTER TABLE `Dodavatelé`
  ADD PRIMARY KEY (`ID`);

--
-- Klíče pro tabulku `Délka`
--
ALTER TABLE `Délka`
  ADD PRIMARY KEY (`ID`),
  ADD KEY `Délka_fk0` (`Interni_ID`),
  ADD KEY `Délka_fk1` (`Jednotka`);

--
-- Klíče pro tabulku `EAN`
--
ALTER TABLE `EAN`
  ADD PRIMARY KEY (`ID`),
  ADD KEY `EAN_fk0` (`Interni_ID`);

--
-- Klíče pro tabulku `Hmotnost`
--
ALTER TABLE `Hmotnost`
  ADD PRIMARY KEY (`ID`),
  ADD KEY `Hmotnost_fk0` (`Interni_ID`),
  ADD KEY `Hmotnost_fk1` (`Jednotka`);

--
-- Klíče pro tabulku `Hodnota`
--
ALTER TABLE `Hodnota`
  ADD PRIMARY KEY (`ID`),
  ADD KEY `Hodnota_fk0` (`Interni_ID`),
  ADD KEY `Hodnota_fk1` (`Jednotka`);

--
-- Klíče pro tabulku `Interni_ID`
--
ALTER TABLE `Interni_ID`
  ADD PRIMARY KEY (`ID`),
  ADD KEY `Interni_ID_fk0` (`Uzivatel`);

--
-- Klíče pro tabulku `Jednotky`
--
ALTER TABLE `Jednotky`
  ADD PRIMARY KEY (`ID`);

--
-- Klíče pro tabulku `Jmenovité napětí`
--
ALTER TABLE `Jmenovité napětí`
  ADD PRIMARY KEY (`ID`),
  ADD KEY `Jmenovité napětí_fk0` (`Interni_ID`);

--
-- Klíče pro tabulku `Jmenovitý výkon`
--
ALTER TABLE `Jmenovitý výkon`
  ADD PRIMARY KEY (`ID`),
  ADD KEY `Jmenovitý výkon_fk0` (`Interni_ID`),
  ADD KEY `Jmenovitý výkon_fk1` (`Jednotka`);

--
-- Klíče pro tabulku `Kapacita`
--
ALTER TABLE `Kapacita`
  ADD PRIMARY KEY (`ID`),
  ADD KEY `Kapacita_fk0` (`Interni_ID`),
  ADD KEY `Kapacita_fk1` (`Jednotka`);

--
-- Klíče pro tabulku `Kategorie`
--
ALTER TABLE `Kategorie`
  ADD PRIMARY KEY (`ID`);

--
-- Klíče pro tabulku `Kladná tolerance`
--
ALTER TABLE `Kladná tolerance`
  ADD PRIMARY KEY (`ID`),
  ADD KEY `Kladná tolerance_fk0` (`Interni_ID`);

--
-- Klíče pro tabulku `Koncovka 1`
--
ALTER TABLE `Koncovka 1`
  ADD PRIMARY KEY (`ID`),
  ADD KEY `Koncovka 1_fk0` (`Interni_ID`),
  ADD KEY `Koncovka 1_fk1` (`Koncovka`);

--
-- Klíče pro tabulku `Koncovka 2`
--
ALTER TABLE `Koncovka 2`
  ADD PRIMARY KEY (`ID`),
  ADD KEY `Koncovka 2_fk0` (`Interni_ID`),
  ADD KEY `Koncovka 2_fk1` (`Koncovka`);

--
-- Klíče pro tabulku `Koncovky`
--
ALTER TABLE `Koncovky`
  ADD PRIMARY KEY (`ID`);

--
-- Klíče pro tabulku `Materiál`
--
ALTER TABLE `Materiál`
  ADD PRIMARY KEY (`ID`),
  ADD KEY `Materiál_fk0` (`Interni_ID`),
  ADD KEY `Materiál_fk1` (`Materiál_S`);

--
-- Klíče pro tabulku `Materiály`
--
ALTER TABLE `Materiály`
  ADD PRIMARY KEY (`ID`);

--
-- Klíče pro tabulku `Minimální počet skladem`
--
ALTER TABLE `Minimální počet skladem`
  ADD PRIMARY KEY (`ID`),
  ADD KEY `Minimální počet skladem_fk0` (`Interni_ID`);

--
-- Klíče pro tabulku `Obaly`
--
ALTER TABLE `Obaly`
  ADD PRIMARY KEY (`ID`);

--
-- Klíče pro tabulku `Objednací číslo`
--
ALTER TABLE `Objednací číslo`
  ADD PRIMARY KEY (`ID`),
  ADD KEY `Objednací číslo_fk0` (`Interni_ID`);

--
-- Klíče pro tabulku `Označení v knihovně`
--
ALTER TABLE `Označení v knihovně`
  ADD PRIMARY KEY (`ID`),
  ADD KEY `Označení v knihovně_fk0` (`Interni_ID`);

--
-- Klíče pro tabulku `pma__bookmark`
--
ALTER TABLE `pma__bookmark`
  ADD PRIMARY KEY (`id`);

--
-- Klíče pro tabulku `pma__central_columns`
--
ALTER TABLE `pma__central_columns`
  ADD PRIMARY KEY (`db_name`,`col_name`);

--
-- Klíče pro tabulku `pma__column_info`
--
ALTER TABLE `pma__column_info`
  ADD PRIMARY KEY (`id`),
  ADD UNIQUE KEY `db_name` (`db_name`,`table_name`,`column_name`);

--
-- Klíče pro tabulku `pma__designer_settings`
--
ALTER TABLE `pma__designer_settings`
  ADD PRIMARY KEY (`username`);

--
-- Klíče pro tabulku `pma__export_templates`
--
ALTER TABLE `pma__export_templates`
  ADD PRIMARY KEY (`id`),
  ADD UNIQUE KEY `u_user_type_template` (`username`,`export_type`,`template_name`);

--
-- Klíče pro tabulku `pma__favorite`
--
ALTER TABLE `pma__favorite`
  ADD PRIMARY KEY (`username`);

--
-- Klíče pro tabulku `pma__history`
--
ALTER TABLE `pma__history`
  ADD PRIMARY KEY (`id`),
  ADD KEY `username` (`username`,`db`,`table`,`timevalue`);

--
-- Klíče pro tabulku `pma__navigationhiding`
--
ALTER TABLE `pma__navigationhiding`
  ADD PRIMARY KEY (`username`,`item_name`,`item_type`,`db_name`,`table_name`);

--
-- Klíče pro tabulku `pma__pdf_pages`
--
ALTER TABLE `pma__pdf_pages`
  ADD PRIMARY KEY (`page_nr`),
  ADD KEY `db_name` (`db_name`);

--
-- Klíče pro tabulku `pma__recent`
--
ALTER TABLE `pma__recent`
  ADD PRIMARY KEY (`username`);

--
-- Klíče pro tabulku `pma__relation`
--
ALTER TABLE `pma__relation`
  ADD PRIMARY KEY (`master_db`,`master_table`,`master_field`),
  ADD KEY `foreign_field` (`foreign_db`,`foreign_table`);

--
-- Klíče pro tabulku `pma__savedsearches`
--
ALTER TABLE `pma__savedsearches`
  ADD PRIMARY KEY (`id`),
  ADD UNIQUE KEY `u_savedsearches_username_dbname` (`username`,`db_name`,`search_name`);

--
-- Klíče pro tabulku `pma__table_coords`
--
ALTER TABLE `pma__table_coords`
  ADD PRIMARY KEY (`db_name`,`table_name`,`pdf_page_number`);

--
-- Klíče pro tabulku `pma__table_info`
--
ALTER TABLE `pma__table_info`
  ADD PRIMARY KEY (`db_name`,`table_name`);

--
-- Klíče pro tabulku `pma__table_uiprefs`
--
ALTER TABLE `pma__table_uiprefs`
  ADD PRIMARY KEY (`username`,`db_name`,`table_name`);

--
-- Klíče pro tabulku `pma__tracking`
--
ALTER TABLE `pma__tracking`
  ADD PRIMARY KEY (`db_name`,`table_name`,`version`);

--
-- Klíče pro tabulku `pma__userconfig`
--
ALTER TABLE `pma__userconfig`
  ADD PRIMARY KEY (`username`);

--
-- Klíče pro tabulku `pma__usergroups`
--
ALTER TABLE `pma__usergroups`
  ADD PRIMARY KEY (`usergroup`,`tab`,`allowed`);

--
-- Klíče pro tabulku `pma__users`
--
ALTER TABLE `pma__users`
  ADD PRIMARY KEY (`username`,`usergroup`);

--
-- Klíče pro tabulku `Pouzdra`
--
ALTER TABLE `Pouzdra`
  ADD PRIMARY KEY (`ID`);

--
-- Klíče pro tabulku `Pouzdro`
--
ALTER TABLE `Pouzdro`
  ADD PRIMARY KEY (`ID`),
  ADD KEY `Pouzdro_fk0` (`Interni_ID`),
  ADD KEY `Pouzdro_fk1` (`Pouzdro_S`);

--
-- Klíče pro tabulku `Pozice ve skladu`
--
ALTER TABLE `Pozice ve skladu`
  ADD PRIMARY KEY (`ID`),
  ADD KEY `Pozice ve skladu_fk0` (`Interni_ID`);

--
-- Klíče pro tabulku `Poznámka`
--
ALTER TABLE `Poznámka`
  ADD PRIMARY KEY (`ID`),
  ADD KEY `Poznámka_fk0` (`Interni_ID`);

--
-- Klíče pro tabulku `Počet skladem`
--
ALTER TABLE `Počet skladem`
  ADD PRIMARY KEY (`ID`),
  ADD KEY `Počet skladem_fk0` (`Interni_ID`);

--
-- Klíče pro tabulku `Počet vodičů`
--
ALTER TABLE `Počet vodičů`
  ADD PRIMARY KEY (`ID`),
  ADD KEY `Počet vodičů_fk0` (`Interni_ID`);

--
-- Klíče pro tabulku `Prirazeni_kategorii`
--
ALTER TABLE `Prirazeni_kategorii`
  ADD PRIMARY KEY (`ID`),
  ADD KEY `Prirazeni_kategorii_fk0` (`Soucastka`),
  ADD KEY `Prirazeni_kategorii_fk1` (`Kategorie`);

--
-- Klíče pro tabulku `Stav`
--
ALTER TABLE `Stav`
  ADD PRIMARY KEY (`ID`),
  ADD KEY `Stav_fk0` (`Interni_ID`),
  ADD KEY `Stav_fk1` (`Stav_S`);

--
-- Klíče pro tabulku `Stavy`
--
ALTER TABLE `Stavy`
  ADD PRIMARY KEY (`ID`);

--
-- Klíče pro tabulku `Tolerance`
--
ALTER TABLE `Tolerance`
  ADD PRIMARY KEY (`ID`),
  ADD KEY `Tolerance_fk0` (`Interni_ID`);

--
-- Klíče pro tabulku `Usporadani_kategorii`
--
ALTER TABLE `Usporadani_kategorii`
  ADD PRIMARY KEY (`ID`),
  ADD KEY `Usporadani_kategorii_fk0` (`Kategorie`),
  ADD KEY `Usporadani_kategorii_fk1` (`Nadrazena`),
  ADD KEY `Usporadani_kategorii_fk2` (`Uzivatel`);

--
-- Klíče pro tabulku `Uzivatele`
--
ALTER TABLE `Uzivatele`
  ADD PRIMARY KEY (`ID`);

--
-- Klíče pro tabulku `Vlastní označení`
--
ALTER TABLE `Vlastní označení`
  ADD PRIMARY KEY (`ID`),
  ADD KEY `Vlastní označení_fk0` (`Interni_ID`);

--
-- Klíče pro tabulku `Výrobce`
--
ALTER TABLE `Výrobce`
  ADD PRIMARY KEY (`ID`),
  ADD KEY `Výrobce_fk0` (`Interni_ID`),
  ADD KEY `Výrobce_fk1` (`Výrobce_S`);

--
-- Klíče pro tabulku `Výrobci`
--
ALTER TABLE `Výrobci`
  ADD PRIMARY KEY (`ID`);

--
-- Klíče pro tabulku `Záporná tolerance`
--
ALTER TABLE `Záporná tolerance`
  ADD PRIMARY KEY (`ID`),
  ADD KEY `Záporná tolerance_fk0` (`Interni_ID`);

--
-- Klíče pro tabulku `Číslo výrobce`
--
ALTER TABLE `Číslo výrobce`
  ADD PRIMARY KEY (`ID`),
  ADD KEY `Číslo výrobce_fk0` (`Interni_ID`);

--
-- AUTO_INCREMENT pro tabulky
--

--
-- AUTO_INCREMENT pro tabulku `Balení`
--
ALTER TABLE `Balení`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT pro tabulku `Barva`
--
ALTER TABLE `Barva`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT pro tabulku `Barvy`
--
ALTER TABLE `Barvy`
  MODIFY `ID` int(16) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT pro tabulku `Cena`
--
ALTER TABLE `Cena`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT pro tabulku `Datum poslední manipulace`
--
ALTER TABLE `Datum poslední manipulace`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT pro tabulku `Datum přidání`
--
ALTER TABLE `Datum přidání`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT pro tabulku `Dodavatel`
--
ALTER TABLE `Dodavatel`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT pro tabulku `Dodavatelé`
--
ALTER TABLE `Dodavatelé`
  MODIFY `ID` int(16) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT pro tabulku `Délka`
--
ALTER TABLE `Délka`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT pro tabulku `EAN`
--
ALTER TABLE `EAN`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=4;

--
-- AUTO_INCREMENT pro tabulku `Hmotnost`
--
ALTER TABLE `Hmotnost`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT pro tabulku `Hodnota`
--
ALTER TABLE `Hodnota`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT pro tabulku `Interni_ID`
--
ALTER TABLE `Interni_ID`
  MODIFY `ID` int(32) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=4;

--
-- AUTO_INCREMENT pro tabulku `Jednotky`
--
ALTER TABLE `Jednotky`
  MODIFY `ID` int(16) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT pro tabulku `Jmenovité napětí`
--
ALTER TABLE `Jmenovité napětí`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT pro tabulku `Jmenovitý výkon`
--
ALTER TABLE `Jmenovitý výkon`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT pro tabulku `Kapacita`
--
ALTER TABLE `Kapacita`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT pro tabulku `Kategorie`
--
ALTER TABLE `Kategorie`
  MODIFY `ID` int(16) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=211;

--
-- AUTO_INCREMENT pro tabulku `Kladná tolerance`
--
ALTER TABLE `Kladná tolerance`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT pro tabulku `Koncovka 1`
--
ALTER TABLE `Koncovka 1`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT pro tabulku `Koncovka 2`
--
ALTER TABLE `Koncovka 2`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT pro tabulku `Koncovky`
--
ALTER TABLE `Koncovky`
  MODIFY `ID` int(16) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT pro tabulku `Materiál`
--
ALTER TABLE `Materiál`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT pro tabulku `Materiály`
--
ALTER TABLE `Materiály`
  MODIFY `ID` int(16) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT pro tabulku `Minimální počet skladem`
--
ALTER TABLE `Minimální počet skladem`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT pro tabulku `Obaly`
--
ALTER TABLE `Obaly`
  MODIFY `ID` int(16) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT pro tabulku `Objednací číslo`
--
ALTER TABLE `Objednací číslo`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=4;

--
-- AUTO_INCREMENT pro tabulku `Označení v knihovně`
--
ALTER TABLE `Označení v knihovně`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT pro tabulku `pma__bookmark`
--
ALTER TABLE `pma__bookmark`
  MODIFY `id` int(10) UNSIGNED NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT pro tabulku `pma__column_info`
--
ALTER TABLE `pma__column_info`
  MODIFY `id` int(5) UNSIGNED NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT pro tabulku `pma__export_templates`
--
ALTER TABLE `pma__export_templates`
  MODIFY `id` int(5) UNSIGNED NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT pro tabulku `pma__history`
--
ALTER TABLE `pma__history`
  MODIFY `id` bigint(20) UNSIGNED NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT pro tabulku `pma__pdf_pages`
--
ALTER TABLE `pma__pdf_pages`
  MODIFY `page_nr` int(10) UNSIGNED NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT pro tabulku `pma__savedsearches`
--
ALTER TABLE `pma__savedsearches`
  MODIFY `id` int(5) UNSIGNED NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT pro tabulku `Pouzdra`
--
ALTER TABLE `Pouzdra`
  MODIFY `ID` int(16) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT pro tabulku `Pouzdro`
--
ALTER TABLE `Pouzdro`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT pro tabulku `Pozice ve skladu`
--
ALTER TABLE `Pozice ve skladu`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT pro tabulku `Poznámka`
--
ALTER TABLE `Poznámka`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT pro tabulku `Počet skladem`
--
ALTER TABLE `Počet skladem`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT pro tabulku `Počet vodičů`
--
ALTER TABLE `Počet vodičů`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT pro tabulku `Prirazeni_kategorii`
--
ALTER TABLE `Prirazeni_kategorii`
  MODIFY `ID` int(64) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT pro tabulku `Stav`
--
ALTER TABLE `Stav`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT pro tabulku `Stavy`
--
ALTER TABLE `Stavy`
  MODIFY `ID` int(8) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT pro tabulku `Tolerance`
--
ALTER TABLE `Tolerance`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT pro tabulku `Usporadani_kategorii`
--
ALTER TABLE `Usporadani_kategorii`
  MODIFY `ID` int(16) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=212;

--
-- AUTO_INCREMENT pro tabulku `Uzivatele`
--
ALTER TABLE `Uzivatele`
  MODIFY `ID` int(8) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=2;

--
-- AUTO_INCREMENT pro tabulku `Vlastní označení`
--
ALTER TABLE `Vlastní označení`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT pro tabulku `Výrobce`
--
ALTER TABLE `Výrobce`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT pro tabulku `Výrobci`
--
ALTER TABLE `Výrobci`
  MODIFY `ID` int(16) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT pro tabulku `Záporná tolerance`
--
ALTER TABLE `Záporná tolerance`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT pro tabulku `Číslo výrobce`
--
ALTER TABLE `Číslo výrobce`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=4;

--
-- Omezení pro exportované tabulky
--

--
-- Omezení pro tabulku `Balení`
--
ALTER TABLE `Balení`
  ADD CONSTRAINT `Balení_fk0` FOREIGN KEY (`Interni_ID`) REFERENCES `Interni_ID` (`ID`),
  ADD CONSTRAINT `Balení_fk1` FOREIGN KEY (`Balení_S`) REFERENCES `Obaly` (`ID`);

--
-- Omezení pro tabulku `Barva`
--
ALTER TABLE `Barva`
  ADD CONSTRAINT `Barva_fk0` FOREIGN KEY (`Interni_ID`) REFERENCES `Interni_ID` (`ID`),
  ADD CONSTRAINT `Barva_fk1` FOREIGN KEY (`Barva_S`) REFERENCES `Barvy` (`ID`);

--
-- Omezení pro tabulku `Cena`
--
ALTER TABLE `Cena`
  ADD CONSTRAINT `Cena_fk0` FOREIGN KEY (`Interni_ID`) REFERENCES `Interni_ID` (`ID`);

--
-- Omezení pro tabulku `Datum poslední manipulace`
--
ALTER TABLE `Datum poslední manipulace`
  ADD CONSTRAINT `Datum poslední manipulace_fk0` FOREIGN KEY (`Interni_ID`) REFERENCES `Interni_ID` (`ID`);

--
-- Omezení pro tabulku `Datum přidání`
--
ALTER TABLE `Datum přidání`
  ADD CONSTRAINT `Datum přidání_fk0` FOREIGN KEY (`Interni_ID`) REFERENCES `Interni_ID` (`ID`);

--
-- Omezení pro tabulku `Dodavatel`
--
ALTER TABLE `Dodavatel`
  ADD CONSTRAINT `Dodavatel_fk0` FOREIGN KEY (`Interni_ID`) REFERENCES `Interni_ID` (`ID`),
  ADD CONSTRAINT `Dodavatel_fk1` FOREIGN KEY (`Dodavetl_S`) REFERENCES `Dodavatelé` (`ID`);

--
-- Omezení pro tabulku `Délka`
--
ALTER TABLE `Délka`
  ADD CONSTRAINT `Délka_fk0` FOREIGN KEY (`Interni_ID`) REFERENCES `Interni_ID` (`ID`),
  ADD CONSTRAINT `Délka_fk1` FOREIGN KEY (`Jednotka`) REFERENCES `Jednotky` (`ID`);

--
-- Omezení pro tabulku `EAN`
--
ALTER TABLE `EAN`
  ADD CONSTRAINT `EAN_fk0` FOREIGN KEY (`Interni_ID`) REFERENCES `Interni_ID` (`ID`);

--
-- Omezení pro tabulku `Hmotnost`
--
ALTER TABLE `Hmotnost`
  ADD CONSTRAINT `Hmotnost_fk0` FOREIGN KEY (`Interni_ID`) REFERENCES `Interni_ID` (`ID`),
  ADD CONSTRAINT `Hmotnost_fk1` FOREIGN KEY (`Jednotka`) REFERENCES `Jednotky` (`ID`);

--
-- Omezení pro tabulku `Hodnota`
--
ALTER TABLE `Hodnota`
  ADD CONSTRAINT `Hodnota_fk0` FOREIGN KEY (`Interni_ID`) REFERENCES `Interni_ID` (`ID`),
  ADD CONSTRAINT `Hodnota_fk1` FOREIGN KEY (`Jednotka`) REFERENCES `Jednotky` (`ID`);

--
-- Omezení pro tabulku `Interni_ID`
--
ALTER TABLE `Interni_ID`
  ADD CONSTRAINT `Interni_ID_fk0` FOREIGN KEY (`Uzivatel`) REFERENCES `Uzivatele` (`ID`);

--
-- Omezení pro tabulku `Jmenovité napětí`
--
ALTER TABLE `Jmenovité napětí`
  ADD CONSTRAINT `Jmenovité napětí_fk0` FOREIGN KEY (`Interni_ID`) REFERENCES `Interni_ID` (`ID`);

--
-- Omezení pro tabulku `Jmenovitý výkon`
--
ALTER TABLE `Jmenovitý výkon`
  ADD CONSTRAINT `Jmenovitý výkon_fk0` FOREIGN KEY (`Interni_ID`) REFERENCES `Interni_ID` (`ID`),
  ADD CONSTRAINT `Jmenovitý výkon_fk1` FOREIGN KEY (`Jednotka`) REFERENCES `Jednotky` (`ID`);

--
-- Omezení pro tabulku `Kapacita`
--
ALTER TABLE `Kapacita`
  ADD CONSTRAINT `Kapacita_fk0` FOREIGN KEY (`Interni_ID`) REFERENCES `Interni_ID` (`ID`),
  ADD CONSTRAINT `Kapacita_fk1` FOREIGN KEY (`Jednotka`) REFERENCES `Jednotky` (`ID`);

--
-- Omezení pro tabulku `Kladná tolerance`
--
ALTER TABLE `Kladná tolerance`
  ADD CONSTRAINT `Kladná tolerance_fk0` FOREIGN KEY (`Interni_ID`) REFERENCES `Interni_ID` (`ID`);

--
-- Omezení pro tabulku `Koncovka 1`
--
ALTER TABLE `Koncovka 1`
  ADD CONSTRAINT `Koncovka 1_fk0` FOREIGN KEY (`Interni_ID`) REFERENCES `Interni_ID` (`ID`),
  ADD CONSTRAINT `Koncovka 1_fk1` FOREIGN KEY (`Koncovka`) REFERENCES `Koncovky` (`ID`);

--
-- Omezení pro tabulku `Koncovka 2`
--
ALTER TABLE `Koncovka 2`
  ADD CONSTRAINT `Koncovka 2_fk0` FOREIGN KEY (`Interni_ID`) REFERENCES `Interni_ID` (`ID`),
  ADD CONSTRAINT `Koncovka 2_fk1` FOREIGN KEY (`Koncovka`) REFERENCES `Koncovky` (`ID`);

--
-- Omezení pro tabulku `Materiál`
--
ALTER TABLE `Materiál`
  ADD CONSTRAINT `Materiál_fk0` FOREIGN KEY (`Interni_ID`) REFERENCES `Interni_ID` (`ID`),
  ADD CONSTRAINT `Materiál_fk1` FOREIGN KEY (`Materiál_S`) REFERENCES `Materiály` (`ID`);

--
-- Omezení pro tabulku `Minimální počet skladem`
--
ALTER TABLE `Minimální počet skladem`
  ADD CONSTRAINT `Minimální počet skladem_fk0` FOREIGN KEY (`Interni_ID`) REFERENCES `Interni_ID` (`ID`);

--
-- Omezení pro tabulku `Objednací číslo`
--
ALTER TABLE `Objednací číslo`
  ADD CONSTRAINT `Objednací číslo_fk0` FOREIGN KEY (`Interni_ID`) REFERENCES `Interni_ID` (`ID`);

--
-- Omezení pro tabulku `Označení v knihovně`
--
ALTER TABLE `Označení v knihovně`
  ADD CONSTRAINT `Označení v knihovně_fk0` FOREIGN KEY (`Interni_ID`) REFERENCES `Interni_ID` (`ID`);

--
-- Omezení pro tabulku `Pouzdro`
--
ALTER TABLE `Pouzdro`
  ADD CONSTRAINT `Pouzdro_fk0` FOREIGN KEY (`Interni_ID`) REFERENCES `Interni_ID` (`ID`),
  ADD CONSTRAINT `Pouzdro_fk1` FOREIGN KEY (`Pouzdro_S`) REFERENCES `Pouzdra` (`ID`);

--
-- Omezení pro tabulku `Pozice ve skladu`
--
ALTER TABLE `Pozice ve skladu`
  ADD CONSTRAINT `Pozice ve skladu_fk0` FOREIGN KEY (`Interni_ID`) REFERENCES `Interni_ID` (`ID`);

--
-- Omezení pro tabulku `Poznámka`
--
ALTER TABLE `Poznámka`
  ADD CONSTRAINT `Poznámka_fk0` FOREIGN KEY (`Interni_ID`) REFERENCES `Interni_ID` (`ID`);

--
-- Omezení pro tabulku `Počet skladem`
--
ALTER TABLE `Počet skladem`
  ADD CONSTRAINT `Počet skladem_fk0` FOREIGN KEY (`Interni_ID`) REFERENCES `Interni_ID` (`ID`);

--
-- Omezení pro tabulku `Počet vodičů`
--
ALTER TABLE `Počet vodičů`
  ADD CONSTRAINT `Počet vodičů_fk0` FOREIGN KEY (`Interni_ID`) REFERENCES `Interni_ID` (`ID`);

--
-- Omezení pro tabulku `Prirazeni_kategorii`
--
ALTER TABLE `Prirazeni_kategorii`
  ADD CONSTRAINT `Prirazeni_kategorii_fk0` FOREIGN KEY (`Soucastka`) REFERENCES `Interni_ID` (`ID`),
  ADD CONSTRAINT `Prirazeni_kategorii_fk1` FOREIGN KEY (`Kategorie`) REFERENCES `Kategorie` (`ID`);

--
-- Omezení pro tabulku `Stav`
--
ALTER TABLE `Stav`
  ADD CONSTRAINT `Stav_fk0` FOREIGN KEY (`Interni_ID`) REFERENCES `Interni_ID` (`ID`),
  ADD CONSTRAINT `Stav_fk1` FOREIGN KEY (`Stav_S`) REFERENCES `Stavy` (`ID`);

--
-- Omezení pro tabulku `Tolerance`
--
ALTER TABLE `Tolerance`
  ADD CONSTRAINT `Tolerance_fk0` FOREIGN KEY (`Interni_ID`) REFERENCES `Interni_ID` (`ID`);

--
-- Omezení pro tabulku `Usporadani_kategorii`
--
ALTER TABLE `Usporadani_kategorii`
  ADD CONSTRAINT `Usporadani_kategorii_fk0` FOREIGN KEY (`Kategorie`) REFERENCES `Kategorie` (`ID`),
  ADD CONSTRAINT `Usporadani_kategorii_fk1` FOREIGN KEY (`Nadrazena`) REFERENCES `Kategorie` (`ID`),
  ADD CONSTRAINT `Usporadani_kategorii_fk2` FOREIGN KEY (`Uzivatel`) REFERENCES `Uzivatele` (`ID`);

--
-- Omezení pro tabulku `Vlastní označení`
--
ALTER TABLE `Vlastní označení`
  ADD CONSTRAINT `Vlastní označení_fk0` FOREIGN KEY (`Interni_ID`) REFERENCES `Interni_ID` (`ID`);

--
-- Omezení pro tabulku `Výrobce`
--
ALTER TABLE `Výrobce`
  ADD CONSTRAINT `Výrobce_fk0` FOREIGN KEY (`Interni_ID`) REFERENCES `Interni_ID` (`ID`),
  ADD CONSTRAINT `Výrobce_fk1` FOREIGN KEY (`Výrobce_S`) REFERENCES `Výrobci` (`ID`);

--
-- Omezení pro tabulku `Záporná tolerance`
--
ALTER TABLE `Záporná tolerance`
  ADD CONSTRAINT `Záporná tolerance_fk0` FOREIGN KEY (`Interni_ID`) REFERENCES `Interni_ID` (`ID`);

--
-- Omezení pro tabulku `Číslo výrobce`
--
ALTER TABLE `Číslo výrobce`
  ADD CONSTRAINT `Číslo výrobce_fk0` FOREIGN KEY (`Interni_ID`) REFERENCES `Interni_ID` (`ID`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
