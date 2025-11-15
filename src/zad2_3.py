#FRANCISZEK DUDKA
def zad2_3(symbole):
    mapowanie = {'o': 0, '+': 1, '*': 2}

    def wartosc(sym):
        wart = 0
        for znak in sym:
            wart = wart * 3 + mapowanie[znak]
        return wart

    napisy = []
    try:
        with open('zalaczniki-2025/symbole.txt', 'r') as plik:
            for linia in plik:
                czysta_linia = linia.strip()
                if czysta_linia:
                    napisy.append(czysta_linia)
    except FileNotFoundError:
        return f"❌ Błąd: Nie znaleziono pliku 'zalaczniki-2025/symbole.txt'.", None

    if not napisy:
        return "Brak danych do przetworzenia w pliku.", None

    
    max_napis = napisy[0]
    max_wartosc = wartosc(max_napis)
    
    for napis in napisy[1:]:
        obecna_wartosc = wartosc(napis)

        if obecna_wartosc > max_wartosc:
            max_wartosc = obecna_wartosc
            max_napis = napis

    return max_wartosc, max_napis


wynik_dziesietny = zad2_3('zalaczniki-2025/symbole.txt')
wynik_do_zapisu = f"{wynik_dziesietny[0]} {wynik_dziesietny[1]}"
with open('src/wynik2_3.txt', 'w') as plik: plik.write(wynik_do_zapisu)


