//
// Created by epsilion on 18.05.22.
//

#ifndef KOLEJKA_KOLEJKA_H
#define KOLEJKA_KOLEJKA_H

struct element{
    float wartosc;
    element *pozycja_nastepny;
    element *pozycja_poprzedni;
};
class Kolejka{
public:
    element *pierwszy;
    element *kursor;
    element *ostatni;
    int wielkosc;
    element * dodaj_element(float, element *);
    void wypisz_wartosci();
    element *pobierz_adres() const;
    void usun_element();
    Kolejka();
    ~Kolejka();
};


#endif //KOLEJKA_KOLEJKA_H
