//
// Created by epsilion on 18.05.22.
//

#include "kolejka.h"

void Kolejka::dodaj_element(int user_input, element *pozycja_nowy) {
    struct element kol1;
    pozycja_nowy->wartosc = user_input;
    kol1.pozycja_nastepny = &kol1.wartosc;
    wielkosc++;
}

float Kolejka::pobierz_wartosc(){
    return 0;
}
int *Kolejka::pobierz_adres() {
    return 0;
}
void Kolejka::usun_element() {

}
Kolejka::Kolejka(){
    wielkosc = 0;
    struct element pierwszy;
    pierwszy_element = &pierwszy;
}