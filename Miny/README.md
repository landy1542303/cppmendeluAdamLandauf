Vytvořte konzolovou hru Hledání min rozdělenou do tříd:
Cell – uchovává informaci o tom, zda políčko obsahuje minu (isMine) a zda je odhalené (isRevealed).
Board – spravuje 2D pole instancí Cell. Ze souboru mines.txt načte pozice min. Poskytuje metodu pro odhalení políčka a kontrolu vítězství (všechna bezpečná políčka odhalena).
Game – řídí herní smyčku: přijímá souřadnice $[r, c]$ od hráče, kontroluje výbuch miny a ukončuje hru.
