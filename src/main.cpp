//Franciszek dudka
using namespace std;
#include <iostream>
#include <fstream>
#include <string>

string z_2_symbole = "../zalaczniki-2025/symbole.txt";

bool czy_palindrom(string tekst){
    int ile_znakow = tekst.length();
    for(int i = 0; i<ile_znakow/2; i++){
        if(tekst[i] != tekst[ile_znakow-i-1])
            return false;
        }
        return true;
    }




void zadanie2_1(){
    ifstream plik(z_2_symbole);
    if(!plik.is_open()){
            cerr << "Niemozna otwozyc pliku" << endl;
    }

    
    string linia;
    while(plik >> linia){
        if(czy_palindrom(linia)){
            cout << linia << endl;
        }
    }






    plik.close();
}

    

int main() {
   zadanie2_1();
    return 0;
}
