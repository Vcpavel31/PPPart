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

# Vyprázdnění tabulky "Usporadani_kategorii"
``` SQL
TRUNCATE `Usporadani_kategorii`
```
# Vyprázdnění tabulky "Kategorie"
``` SQL
TRUNCATE `Kategorie`
```