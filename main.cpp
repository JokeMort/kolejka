#include <iostream>
#include "kolejka.h"
using namespace std;

int main() {
class Kolejka kolejka;
int *pointer = kolejka.pobierz_adres();
for (int n = 0; n < 5 ; n++) {
    pointer = kolejka.dodaj_element(n, pointer);
}
return 0;
}

