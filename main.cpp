#include <iostream>
#include "kolejka.h"
using namespace std;

int main() {
    class Kolejka kolejka;
    element *pointer = kolejka.pobierz_adres();
    bool kontynuwac = true;
    while (kontynuwac){
        string input;
        cout << "Podaj jedna z instrukcji:\n"
             << "d - aby dodac napis do kolejki\n"
             << "u - aby usunac napis z kolejki\n"
             << "w - aby wyswietlic zawartosc kolejki\n"
             << "x - aby zakonczyc\n";
        cin >> input;
        if (input == "d"){
            cout << "Podaj wartosc do zapisania w kolejce: ";
            int input;
            cin >> input;
            pointer = kolejka.dodaj_element(input, pointer);

        }
        if (input == "u"){
            kolejka.usun_element();
        }
        if (input == "w"){
            kolejka.wypisz_wartosci();
        }
        if (input == "x"){
            kontynuwac = false;
        }
    }
return 0;
}

