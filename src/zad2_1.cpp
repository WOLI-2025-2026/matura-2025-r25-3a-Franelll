// Franciszek Dudka
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string z_2_symbole = "../zalaczniki-2025/symbole.txt";

bool czy_palindrom(const string &tekst) {
    int ile_znakow = tekst.length();
    for (int i = 0; i < ile_znakow / 2; i++) {
        if (tekst[i] != tekst[ile_znakow - i - 1])
            return false;
    }
    return true;
}

void zadanie2_1() {
    ifstream plik(z_2_symbole);
    if (!plik.is_open()) {
        cerr << "Nie można otworzyć pliku!" << endl;
        return;
    }

    ofstream wynik("wynik2_1.txt");
    if (!wynik.is_open()) {
        cerr << "Nie można otworzyć pliku wynikowego!" << endl;
        return;
    }

    string linia;
    while (plik >> linia) {
        if (czy_palindrom(linia)) {
            cout << linia << endl;
            wynik << linia << endl;
        }
    }

    plik.close();
    wynik.close();
}

int main() {
    zadanie2_1();
    return 0;
}
