//
// Created by epsilion on 18.05.22.
//

#ifndef KOLEJKA_KOLEJKA_H
#define KOLEJKA_KOLEJKA_H


class Kolejka{
    int *pierwszy_element;
    int wielkosc;
    struct element{
        float wartosc;
        int *pozycja_nastepny;
    };
public:
    void dodaj_element(int);
    float pobierz_wartosc();
    int *pobierz_adres();
    void usun_element();
};


#endif //KOLEJKA_KOLEJKA_H
