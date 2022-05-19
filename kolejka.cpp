//
// Created by epsilion on 18.05.22.
//
#include <iostream>
#include "kolejka.h"
using namespace std;
element *Kolejka::dodaj_element(int user_input, element *pozycja_nowy) {
    element *temp = kursor;
    kursor = pozycja_nowy;
    ostatni = new element;
    if (wielkosc == 0){
        (*pierwszy).wartosc = user_input;
        (*pierwszy).pozycja_nastepny = ostatni;
        (*pierwszy).pozycja_poprzedni = nullptr;
        kursor = ostatni;
        wielkosc++;
        return pierwszy->pozycja_nastepny;
    }
    kursor->wartosc = user_input;
    (*kursor).pozycja_poprzedni = temp;
    (*kursor).pozycja_nastepny = ostatni;
    wielkosc++;
    return (*kursor).pozycja_nastepny;
}

int Kolejka::pobierz_wartosc(int pozycja){
    if (pozycja > wielkosc){
        cout << "przekroczenie parametrow kolejki\n";
    }
    kursor = pierwszy;
    for (int n = 0; n < pozycja; n++){
        kursor = (*kursor).pozycja_nastepny;
    }
    return kursor->wartosc;
}
element *Kolejka::pobierz_adres() {
    if (wielkosc == 0){
        return pierwszy;
    }
    return kursor->pozycja_nastepny;
}
void Kolejka::usun_element() {
    ostatni = (*ostatni).pozycja_poprzedni;
    wielkosc--;
}
Kolejka::Kolejka(){
    wielkosc = 0;
    pierwszy = new element;
}