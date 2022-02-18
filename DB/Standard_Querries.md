# Získat hlavní kategorie do levého sloupce
Musíme zvolit ID uživatele.
``` SQL
SELECT `Kategorie` FROM `Usporadani_kategorii` WHERE `Nadrazena` IS NULL AND `Uzivatel` = ""
```
# Získávání podkategorií
Musíme odeslat ID kategorie, jejichž podřízené buňky chceme získat, také musíme zvolit ID uživatele pro jehož kategorie se ptáme.
``` SQL
SELECT `Kategorie` FROM `Usporadani_kategorii` WHERE `Nadrazena` = ""  AND `Uzivatel` = ""
```
# Získání názvu kategorie
Musíme odeslat ID kategorie
``` SQL
SELECT `Nazev` FROM `Kategorie` WHERE `ID` = ""
```

# Získávání součástek v kategorii
Odesíláme ID kategorie, pro kteou chceme získat součástky. Vrací ID jednotlivých součástek. Musíme zvolit ID uživatele, pro kterého chceme součástky zobrazit.
``` SQL
SELECT `Soucastka` FROM `Prirazeni_kategorii` WHERE `Kategorie` = "" AND `Uzivatel` = ""
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
