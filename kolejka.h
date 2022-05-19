//
// Created by epsilion on 18.05.22.
//

#ifndef KOLEJKA_KOLEJKA_H
#define KOLEJKA_KOLEJKA_H

struct element{
    int wartosc;
    element *pozycja_nastepny;
    element *pozycja_poprzedni;
};
class Kolejka{
public:
    element *pierwszy;
    element *kursor;
    element *ostatni;
    int wielkosc;
    element * dodaj_element(int, element *);
    void wypisz_wartosci();
    element *pobierz_adres();
    void usun_element();
    Kolejka();
};


#endif //KOLEJKA_KOLEJKA_H
