//
// Created by epsilion on 18.05.22.
//
#include <iostream>
#include "kolejka.h"
using namespace std;
element *Kolejka::dodaj_element(int user_input, element *pozycja_nowy) {
    element *temp = kursor;                     //zapisywanie n-1 kursora
    kursor = pozycja_nowy;                      //przesuniecie kursora na n pozycje
    ostatni = new element;                      //utworzenie n+1  elementu
    if (wielkosc == 0){                         //tworzenie 1 elementu
        (*pierwszy).wartosc = user_input;       //ustawienie wartosci pierwszego elementu
        (*pierwszy).pozycja_nastepny = ostatni; //ustawienie pointera na nastepny element
        (*pierwszy).pozycja_poprzedni = nullptr;
        kursor = ostatni;                       //przesuniecie kursora
        wielkosc++;                             //zwiekszenie wielkosci
        return pierwszy->pozycja_nastepny;      //zwrot pontera na 2 element
    }
    kursor->wartosc = user_input;               //ustawienie wartosci n-tego elementu
    (*kursor).pozycja_poprzedni = temp;         //zapisanie wskaznika na n-1 element
    (*kursor).pozycja_nastepny = ostatni;       //zapisanie wskaznika na n+1 element
    wielkosc++;                                 //zwiekszenie wielkosci
    return (*kursor).pozycja_nastepny;          //zwrot wskaznika na nastepny element
}

void Kolejka::wypisz_wartosci(){
    if (wielkosc < 1){                    //sprawdzenie czy talica jest pusta
        cout << "Kolejka jest pusta\n";
    }
    kursor = pierwszy;                         //ustawienie kursora na pierwszym miejscu
    cout << "Kolejka sklada sie z " << wielkosc << " elementow\n";
    for (int n = 0; n < wielkosc; n++){         //wypisanie zawartosci kolejki
        cout << kursor->wartosc << "\t";
        kursor = (*kursor).pozycja_nastepny;
    }
    cout << endl;
}
element *Kolejka::pobierz_adres() {
    if (wielkosc == 0){
        return pierwszy;
    }
    return kursor->pozycja_nastepny;
}
void Kolejka::usun_element() {
    pierwszy = (*pierwszy).pozycja_nastepny;            //usuwania pierwszego elementu
    wielkosc--;                                         //zmniejszenie wielkosci
}
Kolejka::Kolejka(){                                     //konstruktor
    wielkosc = 0;
    pierwszy = new element;
}
Kolejka::~Kolejka(){                                    //destructor
    delete pierwszy;
    delete kursor;
    delete ostatni;
};