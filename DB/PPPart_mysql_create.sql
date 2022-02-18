CREATE TABLE `Interni_ID` (
	`ID` INT(32) NOT NULL AUTO_INCREMENT,
	`Název` TEXT NOT NULL,
	PRIMARY KEY (`ID`)
);

CREATE TABLE `Kategorie` (
	`ID` INT(16) NOT NULL AUTO_INCREMENT,
	`Nazev` TEXT NOT NULL,
	PRIMARY KEY (`ID`)
);

CREATE TABLE `Usporadani_kategorii` (
	`ID` INT(16) NOT NULL AUTO_INCREMENT,
	`Kategorie` INT(16) NOT NULL,
	`Nadrazena` INT(16),
	`Uzivatel` INT(8) NOT NULL,
	PRIMARY KEY (`ID`)
);

CREATE TABLE `EAN` (
	`ID` INT NOT NULL AUTO_INCREMENT,
	`Interni_ID` INT(32) NOT NULL,
	`EAN` INT(16) NOT NULL,
	PRIMARY KEY (`ID`)
);

CREATE TABLE `Prirazeni_kategorii` (
	`ID` INT(64) NOT NULL AUTO_INCREMENT,
	`Soucastka` INT(32) NOT NULL,
	`Kategorie` INT(16) NOT NULL,
	`Uzivatel` INT(8) NOT NULL,
	PRIMARY KEY (`ID`)
);

CREATE TABLE `Objednací číslo` (
	`ID` INT NOT NULL AUTO_INCREMENT,
	`Interni_ID` INT(32) NOT NULL,
	`Objednací číslo` TEXT NOT NULL,
	PRIMARY KEY (`ID`)
);

CREATE TABLE `Číslo výrobce` (
	`ID` INT NOT NULL AUTO_INCREMENT,
	`Interni_ID` INT(32) NOT NULL,
	`Číslo výrobce` TEXT NOT NULL,
	PRIMARY KEY (`ID`)
);

CREATE TABLE `Vlastní označení` (
	`ID` INT NOT NULL AUTO_INCREMENT,
	`Interni_ID` INT(32) NOT NULL,
	`Vlastní označení` TEXT NOT NULL,
	PRIMARY KEY (`ID`)
);

CREATE TABLE `Výrobce` (
	`ID` INT NOT NULL AUTO_INCREMENT,
	`Interni_ID` INT(32) NOT NULL,
	`Výrobce_W` TEXT NOT NULL,
	`Výrobce_S` INT(16),
	PRIMARY KEY (`ID`)
);

CREATE TABLE `Dodavatel` (
	`ID` INT NOT NULL AUTO_INCREMENT,
	`Interni_ID` INT(32) NOT NULL,
	`Dodavatel_W` TEXT NOT NULL,
	`Dodavetl_S` INT(16),
	PRIMARY KEY (`ID`)
);

CREATE TABLE `Poznámka` (
	`ID` INT NOT NULL AUTO_INCREMENT,
	`Interni_ID` INT(32) NOT NULL,
	`Poznámka` TEXT NOT NULL,
	PRIMARY KEY (`ID`)
);

CREATE TABLE `Pozice ve skladu` (
	`ID` INT NOT NULL AUTO_INCREMENT,
	`Interni_ID` INT(32) NOT NULL,
	`Pozice ve skladu` INT(16) NOT NULL,
	PRIMARY KEY (`ID`)
);

CREATE TABLE `Počet skladem` (
	`ID` INT NOT NULL AUTO_INCREMENT,
	`Interni_ID` INT(32) NOT NULL,
	`Počet skladem` INT NOT NULL,
	`Datum` DATETIME NOT NULL,
	PRIMARY KEY (`ID`)
);

CREATE TABLE `Stav` (
	`ID` INT NOT NULL AUTO_INCREMENT,
	`Interni_ID` INT(32) NOT NULL,
	`Stav_S` INT(8),
	`Stav_W` TEXT NOT NULL,
	PRIMARY KEY (`ID`)
);

CREATE TABLE `Minimální počet skladem` (
	`ID` INT NOT NULL AUTO_INCREMENT,
	`Interni_ID` INT(32) NOT NULL,
	`Minimální počet skladem` INT NOT NULL,
	PRIMARY KEY (`ID`)
);

CREATE TABLE `Pouzdro` (
	`ID` INT NOT NULL AUTO_INCREMENT,
	`Interni_ID` INT(32) NOT NULL,
	`Pouzdro_W` TEXT NOT NULL,
	`Pouzdro_S` INT(16),
	PRIMARY KEY (`ID`)
);

CREATE TABLE `Cena` (
	`ID` INT NOT NULL AUTO_INCREMENT,
	`Interni_ID` INT(32) NOT NULL,
	`Cena` INT NOT NULL,
	`Datum` DATETIME NOT NULL,
	PRIMARY KEY (`ID`)
);

CREATE TABLE `Délka` (
	`ID` INT NOT NULL AUTO_INCREMENT,
	`Interni_ID` INT(32) NOT NULL,
	`Délka` INT NOT NULL,
	`Datum` DATETIME NOT NULL,
	`Jednotka` INT(16) NOT NULL,
	PRIMARY KEY (`ID`)
);

CREATE TABLE `Jednotky` (
	`ID` INT(16) NOT NULL AUTO_INCREMENT,
	`Zkratka` TEXT NOT NULL,
	`Název` TEXT NOT NULL,
	PRIMARY KEY (`ID`)
);

CREATE TABLE `Tolerance` (
	`ID` INT NOT NULL AUTO_INCREMENT,
	`Interni_ID` INT(32) NOT NULL,
	`Tolerance` INT NOT NULL,
	PRIMARY KEY (`ID`)
);

CREATE TABLE `Hmotnost` (
	`ID` INT NOT NULL AUTO_INCREMENT,
	`Interni_ID` INT(32) NOT NULL,
	`Hmotnost` INT NOT NULL,
	`Datum` DATETIME NOT NULL,
	`Jednotka` INT(16) NOT NULL,
	PRIMARY KEY (`ID`)
);

CREATE TABLE `Hodnota` (
	`ID` INT NOT NULL AUTO_INCREMENT,
	`Interni_ID` INT(32) NOT NULL,
	`Hodnota` INT NOT NULL,
	`Datum` DATETIME NOT NULL,
	`Jednotka` INT(16) NOT NULL,
	PRIMARY KEY (`ID`)
);

CREATE TABLE `Záporná tolerance` (
	`ID` INT NOT NULL AUTO_INCREMENT,
	`Interni_ID` INT(32) NOT NULL,
	`Záporná tolerance` INT NOT NULL,
	PRIMARY KEY (`ID`)
);

CREATE TABLE `Kladná tolerance` (
	`ID` INT NOT NULL AUTO_INCREMENT,
	`Interni_ID` INT(32) NOT NULL,
	`Kladná tolerance` INT NOT NULL,
	PRIMARY KEY (`ID`)
);

CREATE TABLE `Koncovka 1` (
	`ID` INT NOT NULL AUTO_INCREMENT,
	`Interni_ID` INT(32) NOT NULL,
	`Koncovka` INT(16) NOT NULL,
	PRIMARY KEY (`ID`)
);

CREATE TABLE `Koncovka 2` (
	`ID` INT NOT NULL AUTO_INCREMENT,
	`Interni_ID` INT(32) NOT NULL,
	`Koncovka` INT(16) NOT NULL,
	PRIMARY KEY (`ID`)
);

CREATE TABLE `Koncovky` (
	`ID` INT(16) NOT NULL AUTO_INCREMENT,
	`Název` TEXT NOT NULL,
	PRIMARY KEY (`ID`)
);

CREATE TABLE `Počet vodičů` (
	`ID` INT NOT NULL AUTO_INCREMENT,
	`Interni_ID` INT(32) NOT NULL,
	`Počet vodičů` INT NOT NULL,
	PRIMARY KEY (`ID`)
);

CREATE TABLE `Materiál` (
	`ID` INT NOT NULL AUTO_INCREMENT,
	`Interni_ID` INT(32) NOT NULL,
	`Materiál_W` TEXT NOT NULL,
	`Materiál_S` INT(16),
	PRIMARY KEY (`ID`)
);

CREATE TABLE `Jmenovité napětí` (
	`ID` INT NOT NULL AUTO_INCREMENT,
	`Interni_ID` INT(32) NOT NULL,
	`Jmenovité napětí` INT NOT NULL,
	PRIMARY KEY (`ID`)
);

CREATE TABLE `Kapacita` (
	`ID` INT NOT NULL AUTO_INCREMENT,
	`Interni_ID` INT(32) NOT NULL,
	`Kapacita` INT NOT NULL,
	`Datum` DATETIME NOT NULL,
	`Jednotka` INT(16) NOT NULL,
	PRIMARY KEY (`ID`)
);

CREATE TABLE `Barva` (
	`ID` INT NOT NULL AUTO_INCREMENT,
	`Interni_ID` INT(32) NOT NULL,
	`Barva_W` TEXT NOT NULL,
	`Barva_S` INT(16),
	PRIMARY KEY (`ID`)
);

CREATE TABLE `Jmenovitý výkon` (
	`ID` INT NOT NULL AUTO_INCREMENT,
	`Interni_ID` INT(32) NOT NULL,
	`Jmenovitý výkon` INT NOT NULL,
	PRIMARY KEY (`ID`)
);

CREATE TABLE `Označení v knihovně` (
	`ID` INT NOT NULL AUTO_INCREMENT,
	`Interni_ID` INT(32) NOT NULL,
	`Označení v knihovně` TEXT NOT NULL,
	PRIMARY KEY (`ID`)
);

CREATE TABLE `Datum přidání` (
	`ID` INT NOT NULL AUTO_INCREMENT,
	`Interni_ID` INT(32) NOT NULL,
	`Datum přidání` DATE NOT NULL,
	PRIMARY KEY (`ID`)
);

CREATE TABLE `Datum poslední manipulace` (
	`ID` INT NOT NULL AUTO_INCREMENT,
	`Interni_ID` INT(32) NOT NULL,
	`Datum poslední manipulace` DATETIME NOT NULL,
	PRIMARY KEY (`ID`)
);

CREATE TABLE `Balení` (
	`ID` INT NOT NULL AUTO_INCREMENT,
	`Interni_ID` INT(32) NOT NULL,
	`Balení_W` TEXT NOT NULL,
	`Balení_S` INT(16),
	PRIMARY KEY (`ID`)
);

CREATE TABLE `Stavy` (
	`ID` INT(8) NOT NULL AUTO_INCREMENT,
	`Název` TEXT NOT NULL,
	PRIMARY KEY (`ID`)
);

CREATE TABLE `Pouzdra` (
	`ID` INT(16) NOT NULL AUTO_INCREMENT,
	`Název` TEXT NOT NULL,
	PRIMARY KEY (`ID`)
);

CREATE TABLE `Dodavatelé` (
	`ID` INT(16) NOT NULL AUTO_INCREMENT,
	`Název` TEXT NOT NULL,
	PRIMARY KEY (`ID`)
);

CREATE TABLE `Výrobci` (
	`ID` INT(16) NOT NULL AUTO_INCREMENT,
	`Název` TEXT NOT NULL,
	PRIMARY KEY (`ID`)
);

CREATE TABLE `Materiály` (
	`ID` INT(16) NOT NULL AUTO_INCREMENT,
	`Název` TEXT NOT NULL,
	PRIMARY KEY (`ID`)
);

CREATE TABLE `Obaly` (
	`ID` INT(16) NOT NULL AUTO_INCREMENT,
	`Název` TEXT NOT NULL,
	PRIMARY KEY (`ID`)
);

CREATE TABLE `Barvy` (
	`ID` INT(16) NOT NULL AUTO_INCREMENT,
	`Název` TEXT NOT NULL,
	PRIMARY KEY (`ID`)
);

CREATE TABLE `Uzivatele` (
	`ID` INT(8) NOT NULL AUTO_INCREMENT,
	PRIMARY KEY (`ID`)
);

ALTER TABLE `Usporadani_kategorii` ADD CONSTRAINT `Usporadani_kategorii_fk0` FOREIGN KEY (`Kategorie`) REFERENCES `Kategorie`(`ID`);

ALTER TABLE `Usporadani_kategorii` ADD CONSTRAINT `Usporadani_kategorii_fk1` FOREIGN KEY (`Nadrazena`) REFERENCES `Kategorie`(`ID`);

ALTER TABLE `Usporadani_kategorii` ADD CONSTRAINT `Usporadani_kategorii_fk2` FOREIGN KEY (`Uzivatel`) REFERENCES `Uzivatele`(`ID`);

ALTER TABLE `EAN` ADD CONSTRAINT `EAN_fk0` FOREIGN KEY (`Interni_ID`) REFERENCES `Interni_ID`(`ID`);

ALTER TABLE `Prirazeni_kategorii` ADD CONSTRAINT `Prirazeni_kategorii_fk0` FOREIGN KEY (`Soucastka`) REFERENCES `Interni_ID`(`ID`);

ALTER TABLE `Prirazeni_kategorii` ADD CONSTRAINT `Prirazeni_kategorii_fk1` FOREIGN KEY (`Kategorie`) REFERENCES `Kategorie`(`ID`);

ALTER TABLE `Prirazeni_kategorii` ADD CONSTRAINT `Prirazeni_kategorii_fk2` FOREIGN KEY (`Uzivatel`) REFERENCES `Uzivatele`(`ID`);

ALTER TABLE `Objednací číslo` ADD CONSTRAINT `Objednací číslo_fk0` FOREIGN KEY (`Interni_ID`) REFERENCES `Interni_ID`(`ID`);

ALTER TABLE `Číslo výrobce` ADD CONSTRAINT `Číslo výrobce_fk0` FOREIGN KEY (`Interni_ID`) REFERENCES `Interni_ID`(`ID`);

ALTER TABLE `Vlastní označení` ADD CONSTRAINT `Vlastní označení_fk0` FOREIGN KEY (`Interni_ID`) REFERENCES `Interni_ID`(`ID`);

ALTER TABLE `Výrobce` ADD CONSTRAINT `Výrobce_fk0` FOREIGN KEY (`Interni_ID`) REFERENCES `Interni_ID`(`ID`);

ALTER TABLE `Výrobce` ADD CONSTRAINT `Výrobce_fk1` FOREIGN KEY (`Výrobce_S`) REFERENCES `Výrobci`(`ID`);

ALTER TABLE `Dodavatel` ADD CONSTRAINT `Dodavatel_fk0` FOREIGN KEY (`Interni_ID`) REFERENCES `Interni_ID`(`ID`);

ALTER TABLE `Dodavatel` ADD CONSTRAINT `Dodavatel_fk1` FOREIGN KEY (`Dodavetl_S`) REFERENCES `Dodavatelé`(`ID`);

ALTER TABLE `Poznámka` ADD CONSTRAINT `Poznámka_fk0` FOREIGN KEY (`Interni_ID`) REFERENCES `Interni_ID`(`ID`);

ALTER TABLE `Pozice ve skladu` ADD CONSTRAINT `Pozice ve skladu_fk0` FOREIGN KEY (`Interni_ID`) REFERENCES `Interni_ID`(`ID`);

ALTER TABLE `Počet skladem` ADD CONSTRAINT `Počet skladem_fk0` FOREIGN KEY (`Interni_ID`) REFERENCES `Interni_ID`(`ID`);

ALTER TABLE `Stav` ADD CONSTRAINT `Stav_fk0` FOREIGN KEY (`Interni_ID`) REFERENCES `Interni_ID`(`ID`);

ALTER TABLE `Stav` ADD CONSTRAINT `Stav_fk1` FOREIGN KEY (`Stav_S`) REFERENCES `Stavy`(`ID`);

ALTER TABLE `Minimální počet skladem` ADD CONSTRAINT `Minimální počet skladem_fk0` FOREIGN KEY (`Interni_ID`) REFERENCES `Interni_ID`(`ID`);

ALTER TABLE `Pouzdro` ADD CONSTRAINT `Pouzdro_fk0` FOREIGN KEY (`Interni_ID`) REFERENCES `Interni_ID`(`ID`);

ALTER TABLE `Pouzdro` ADD CONSTRAINT `Pouzdro_fk1` FOREIGN KEY (`Pouzdro_S`) REFERENCES `Pouzdra`(`ID`);

ALTER TABLE `Cena` ADD CONSTRAINT `Cena_fk0` FOREIGN KEY (`Interni_ID`) REFERENCES `Interni_ID`(`ID`);

ALTER TABLE `Délka` ADD CONSTRAINT `Délka_fk0` FOREIGN KEY (`Interni_ID`) REFERENCES `Interni_ID`(`ID`);

ALTER TABLE `Délka` ADD CONSTRAINT `Délka_fk1` FOREIGN KEY (`Jednotka`) REFERENCES `Jednotky`(`ID`);

ALTER TABLE `Tolerance` ADD CONSTRAINT `Tolerance_fk0` FOREIGN KEY (`Interni_ID`) REFERENCES `Interni_ID`(`ID`);

ALTER TABLE `Hmotnost` ADD CONSTRAINT `Hmotnost_fk0` FOREIGN KEY (`Interni_ID`) REFERENCES `Interni_ID`(`ID`);

ALTER TABLE `Hmotnost` ADD CONSTRAINT `Hmotnost_fk1` FOREIGN KEY (`Jednotka`) REFERENCES `Jednotky`(`ID`);

ALTER TABLE `Hodnota` ADD CONSTRAINT `Hodnota_fk0` FOREIGN KEY (`Interni_ID`) REFERENCES `Interni_ID`(`ID`);

ALTER TABLE `Hodnota` ADD CONSTRAINT `Hodnota_fk1` FOREIGN KEY (`Jednotka`) REFERENCES `Jednotky`(`ID`);

ALTER TABLE `Záporná tolerance` ADD CONSTRAINT `Záporná tolerance_fk0` FOREIGN KEY (`Interni_ID`) REFERENCES `Interni_ID`(`ID`);

ALTER TABLE `Kladná tolerance` ADD CONSTRAINT `Kladná tolerance_fk0` FOREIGN KEY (`Interni_ID`) REFERENCES `Interni_ID`(`ID`);

ALTER TABLE `Koncovka 1` ADD CONSTRAINT `Koncovka 1_fk0` FOREIGN KEY (`Interni_ID`) REFERENCES `Interni_ID`(`ID`);

ALTER TABLE `Koncovka 1` ADD CONSTRAINT `Koncovka 1_fk1` FOREIGN KEY (`Koncovka`) REFERENCES `Koncovky`(`ID`);

ALTER TABLE `Koncovka 2` ADD CONSTRAINT `Koncovka 2_fk0` FOREIGN KEY (`Interni_ID`) REFERENCES `Interni_ID`(`ID`);

ALTER TABLE `Koncovka 2` ADD CONSTRAINT `Koncovka 2_fk1` FOREIGN KEY (`Koncovka`) REFERENCES `Koncovky`(`ID`);

ALTER TABLE `Počet vodičů` ADD CONSTRAINT `Počet vodičů_fk0` FOREIGN KEY (`Interni_ID`) REFERENCES `Interni_ID`(`ID`);

ALTER TABLE `Materiál` ADD CONSTRAINT `Materiál_fk0` FOREIGN KEY (`Interni_ID`) REFERENCES `Interni_ID`(`ID`);

ALTER TABLE `Materiál` ADD CONSTRAINT `Materiál_fk1` FOREIGN KEY (`Materiál_S`) REFERENCES `Materiály`(`ID`);

ALTER TABLE `Jmenovité napětí` ADD CONSTRAINT `Jmenovité napětí_fk0` FOREIGN KEY (`Interni_ID`) REFERENCES `Interni_ID`(`ID`);

ALTER TABLE `Kapacita` ADD CONSTRAINT `Kapacita_fk0` FOREIGN KEY (`Interni_ID`) REFERENCES `Interni_ID`(`ID`);

ALTER TABLE `Kapacita` ADD CONSTRAINT `Kapacita_fk1` FOREIGN KEY (`Jednotka`) REFERENCES `Jednotky`(`ID`);

ALTER TABLE `Barva` ADD CONSTRAINT `Barva_fk0` FOREIGN KEY (`Interni_ID`) REFERENCES `Interni_ID`(`ID`);

ALTER TABLE `Barva` ADD CONSTRAINT `Barva_fk1` FOREIGN KEY (`Barva_S`) REFERENCES `Barvy`(`ID`);

ALTER TABLE `Jmenovitý výkon` ADD CONSTRAINT `Jmenovitý výkon_fk0` FOREIGN KEY (`Interni_ID`) REFERENCES `Interni_ID`(`ID`);

ALTER TABLE `Označení v knihovně` ADD CONSTRAINT `Označení v knihovně_fk0` FOREIGN KEY (`Interni_ID`) REFERENCES `Interni_ID`(`ID`);

ALTER TABLE `Datum přidání` ADD CONSTRAINT `Datum přidání_fk0` FOREIGN KEY (`Interni_ID`) REFERENCES `Interni_ID`(`ID`);

ALTER TABLE `Datum poslední manipulace` ADD CONSTRAINT `Datum poslední manipulace_fk0` FOREIGN KEY (`Interni_ID`) REFERENCES `Interni_ID`(`ID`);

ALTER TABLE `Balení` ADD CONSTRAINT `Balení_fk0` FOREIGN KEY (`Interni_ID`) REFERENCES `Interni_ID`(`ID`);

ALTER TABLE `Balení` ADD CONSTRAINT `Balení_fk1` FOREIGN KEY (`Balení_S`) REFERENCES `Obaly`(`ID`);














































