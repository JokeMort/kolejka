#include <iostream>
#include "kolejka.h"
#include "Pobranie.h"
using namespace std;

int main() {
    class Kolejka kolejka;
    string input[1];
    float liczba[1];
    string *wsk_input = &input[0];
    float *wsk_liczba = &liczba[0];
    int ilosci[2] = {0,0};
    int *wsk_ilosci = &ilosci[0];
    element *pointer = kolejka.pobierz_adres();
    bool kontynuwac = true;
    while (kontynuwac){
        cout << "Podaj jedna z instrukcji:\n"
             << "d - aby dodac napis do kolejki\n"
             << "u - aby usunac napis z kolejki\n"
             << "w - aby wyswietlic zawartosc kolejki\n"
             << "x - aby zakonczyc\n";
        wpisanie_danych(1 ,wsk_liczba, wsk_input, wsk_ilosci);
        if (ilosci[1] == 1) {
            if (input[0] == "D") {
                cout << "Podaj wartosc do zapisania w kolejce: ";
                wpisanie_danych(1 ,wsk_liczba, wsk_input, wsk_ilosci);
                if (ilosci[0] == 1) {
                    pointer = kolejka.dodaj_element(liczba[0], pointer);
                }
                else{
                    cout << "Podano niewlasciwy znak\n";
                }
            }
            if (input[0] == "U") {
                kolejka.usun_element();
            }
            if (input[0] == "W") {
                kolejka.wypisz_wartosci();
            }
            if (input[0] == "X") {
                kontynuwac = false;
            }
        }
        input[0].clear();
    }
return 0;
}

