#FRANCISZEK DUDKA
def zad2_4(symbole):
    mapowanie = {'o': 0, '+': 1, '*': 2}
    MAP_SYM = {0: 'o', 1: '+', 2: '*'}

    suma_dec = 0
    
    def wartosc(sym):
        wart = 0
        for znak in sym:
            wart = wart * 3 + mapowanie[znak]
        return wart


    try:
        with open('zalaczniki-2025/symbole.txt', 'r') as f:
            for linia in f:
                napis = linia.strip()
                if napis:
                    wartosc = 0
                    for znak in napis:
                        wartosc = wartosc * 3 + mapowanie[znak]
                    suma_dec += wartosc
    except FileNotFoundError:
        return f" Błąd: Nie znaleziono pliku 'zalaczniki-2025/symbole.txt'.", None



    
    suma_trzy = ""
    liczba = suma_dec
    while liczba > 0:
        reszta = liczba % 3
        suma_trzy = MAP_SYM[reszta] + suma_trzy
        liczba //= 3
        
    return suma_dec, suma_trzy

wynik_dziesietny = zad2_4('zalaczniki-2025/symbole.txt')
wynik_do_zapisu = f"{wynik_dziesietny[0]} {wynik_dziesietny[1]}"
with open('src/wynik2_4.txt', 'w') as plik: plik.write(wynik_do_zapisu)







