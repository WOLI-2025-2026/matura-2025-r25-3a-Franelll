//FRANCISZEK DUDKA

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility> 

using namespace std;


string Z_2_SYMBOLE_SCIEZKA = "../zalaczniki-2025/symbole.txt";


vector<pair<int, int>> srodki_kwadratow;


vector<string> wczytaj_dane(const string& sciezka_pliku) {
    ifstream plik(Z_2_SYMBOLE_SCIEZKA);
    vector<string> dane;
    string linia;

    if (!plik.is_open()) {
        cerr << "Błąd: Nie można otworzyć pliku: " << sciezka_pliku << endl;
        return dane; 
    }

    // Wczytywanie całych linii
    while (getline(plik, linia)) {
        if (!linia.empty()) {
            dane.push_back(linia);
        }
    }
    plik.close();
    return dane;
}


void zadanie2_2() {
   
    vector<string> dane = wczytaj_dane(Z_2_SYMBOLE_SCIEZKA);

    if (dane.empty() || dane[0].empty()) {
        if (!dane.empty()) { 
             cerr << "Błąd: Plik jest pusty lub nie zawiera danych." << endl;
        }
        return;
    }

    
    int R = dane.size();         
    int C = dane[0].length();    

    
    if (R < 3 || C < 3) {
        cout << "Dane zbyt małe, by zawierały kwadrat 3x3." << endl;
        return;
    }

    
    
    for (int i = 1; i < R - 1; ++i) { 
        for (int j = 1; j < C - 1; ++j) { 

            char symbol_srodkowy = dane[i][j];
            bool czy_kwadrat = true;

            
            for (int di = -1; di <= 1; ++di) { 
                for (int dj = -1; dj <= 1; ++dj) { 
                    
                    
                    if (dane[i + di][j + dj] != symbol_srodkowy) {
                        czy_kwadrat = false;
                        goto next_potential_center; 
                    }
                }
            }

           
            if (czy_kwadrat) {
                
                srodki_kwadratow.push_back({i + 1, j + 1});
            }
            
            next_potential_center:; 
        }
    }


    ofstream wynik("wynik2_2.txt");
    if (!wynik.is_open()) {
        cerr << "Błąd: Nie można otworzyć pliku wynikowego: wynik2_2.txt" << endl;
        return;
    }

    
    wynik << srodki_kwadratow.size() << endl;


    for (const auto& srodek : srodki_kwadratow) {
        
        wynik << srodek.first << " " << srodek.second << endl;
    }

    wynik.close();
    cout << "Zakończono: Znaleziono " << srodki_kwadratow.size() << " kwadratów 3x3." << endl;
    cout << "Wynik zapisano w pliku wynik2_2.txt" << endl;
}


int main() {

    
    zadanie2_2();
    return 0;
}