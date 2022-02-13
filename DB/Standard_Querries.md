# Získat hlavní kategorie do levého sloupce
``` SQL
SELECT `Kategorie` FROM `Usporadani_kategorii` WHERE `Nadrazena` IS NULL
```
# Získávání podkategorií
Musíme odeslat ID kategorie, jejichž podřízené buňky chceme získat
``` SQL
SELECT `Kategorie` FROM `Usporadani_kategorii` WHERE `Nadrazena` = ""
```
# Získání názvu kategorie
Musíme odeslat ID kategorie
``` SQL
SELECT `Nazev` FROM `Kategorie` WHERE `ID` = ""
```

# Získávání součástek v kategorii
Odesíláme ID kategorie, pro kteou chceme získat součástky. Vrací ID jednotlivých součástek.
``` SQL
SELECT `Soucastka` FROM `Prirazeni_kategorii` WHERE `Kategorie` = ""
```
# Získání názvu součástky z jejího ID
Odesíláme ID součástky
``` SQL
SELECT `Název` FROM `Interni_ID` WHERE `ID` = ""
```
# Získání dat pro sloupec do tabulky se součástkami z jejího ID
Odesíláme ID součástky
Název sloupce odpovídá názvu tabulky a názvu sloupce v DB
``` SQL
SELECT `Jmenovité napětí` FROM `Jmenovité napětí` WHERE `Interni_ID` = ""
```

# Vyprázdnění tabulky "Usporadani_kategorii"
``` SQL
TRUNCATE `Usporadani_kategorii`
```
# Vyprázdnění tabulky "Kategorie"
``` SQL
TRUNCATE `Kategorie`
```
