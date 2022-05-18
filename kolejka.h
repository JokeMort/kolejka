//
// Created by epsilion on 18.05.22.
//

#ifndef KOLEJKA_KOLEJKA_H
#define KOLEJKA_KOLEJKA_H


class Kolejka{
public:

    struct element{
        int wartosc = 0;
        int *pozycja_nastepny = nullptr;
    };
    element *pierwszy_element;
    int wielkosc;
    void dodaj_element(int, element*);
    float pobierz_wartosc();
    int *pobierz_adres();
    void usun_element();
    Kolejka();
};


#endif //KOLEJKA_KOLEJKA_H
