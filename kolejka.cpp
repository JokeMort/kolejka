//
// Created by epsilion on 18.05.22.
//
#include <iostream>
#include "kolejka.h"
using namespace std;
element *Kolejka::dodaj_element(int user_input, int *pozycja_nowy) {
    kursor = new element;
    ostatni = new  element;
    if (wielkosc == 0){
        (*pierwszy).wartosc = user_input;
        (*pierwszy).pozycja_nastepny = kursor;
        wielkosc++;
        return pierwszy->pozycja_nastepny;
    }
    kursor->wartosc = user_input;
    kursor->pozycja_nastepny = ostatni;
    wielkosc++;
    return (*kursor).pozycja_nastepny;
}

int Kolejka::pobierz_wartosc(int pozycja){
    if (pozycja > wielkosc){
        cout << "przekroczenie parametrow kolejki\n";
    }
    kursor = pierwszy;
    int zwracana_wartosc;
    for (int n = 0; n < pozycja; n++){
        zwracana_wartosc = kursor->wartosc;
        kursor = reinterpret_cast<element *>((*kursor).pozycja_nastepny);
    }
    return zwracana_wartosc;
}
ele *Kolejka::pobierz_adres() {
    if (wielkosc == 0){
        return (int*)&pierwszy;
    }
    return kursor->pozycja_nastepny;
}
void Kolejka::usun_element() {

}
Kolejka::Kolejka(){
    wielkosc = 0;
    pierwszy = new element;
}