CREATE TABLE `Interni_ID` (
	`ID` INT(32) NOT NULL AUTO_INCREMENT,
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
	`Nadrazena` INT(16) NOT NULL,
	PRIMARY KEY (`ID`)
);

ALTER TABLE `Usporadani_kategorii` ADD CONSTRAINT `Usporadani_kategorii_fk0` FOREIGN KEY (`Kategorie`) REFERENCES `Kategorie`(`ID`);

ALTER TABLE `Usporadani_kategorii` ADD CONSTRAINT `Usporadani_kategorii_fk1` FOREIGN KEY (`Nadrazena`) REFERENCES `Kategorie`(`ID`);




