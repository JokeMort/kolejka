#include <iostream>
#include "kolejka.h"
using namespace std;

int main() {
class Kolejka kolejka;
element *pointer = kolejka.pobierz_adres();
    for (int n = 0; n < 5 ; n++) {
        pointer = kolejka.dodaj_element(n, pointer);
    }
    for (int n = 0; n < 5 ; n++) {
        cout << kolejka.pobierz_wartosc(n) << endl;
    }
    kolejka.usun_element();
    for (int n = 0; n < 4 ; n++) {
        cout << kolejka.pobierz_wartosc(n) << endl;
    }
return 0;
}

