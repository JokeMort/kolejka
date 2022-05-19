//
// Created by tomas on 21.04.2022.
//

#ifndef QUICKSORT_POBRANIE_H
#define QUICKSORT_POBRANIE_H
#include <iostream>
#define maks 1                                                                        //maksymalna ilosc stringow jakie moze podac uzytkownik, do poprawy
using namespace std;
void wpisanie_danych(int, float *, string *, int *);                                    //(maksymalna ilosc danych do pobrania, wksaznik na tablice liczb,
                                                                                        // wskaznik na tablice slow, wskaznik na tablice zawierajaca wielkosc obydwu)
class Znaki{                                                                            //klasa znaki pobierajaca i segregujaca dane
    float *tablica_liczb;                                                               //pointer do dynamicznej tablicy liczb
    string tablica_znakow[maks];                                                        //tablica znakow ze stala wielkoscia, do poprawy
    int rozmiar_liczb;                                                                  //ilosc wykrytych liczb
    int rozmiar_znakow;                                                                 //ilosc wykrytych znakow
    int maks_rozmiar;                                                                   //maksymalna ilosc znakow jaka moze podac uzytkownik
public:
    int pobierz_rozmiar_liczb() const;                                              //metoda pobierajaca ilosc liczb
    int pobierz_rozmiar_znakow() const;                                             //metoda pobierajaca ilosc ilosc slow
    float pobierz_element_liczb(int pozycja);                                       //metoda pobierajaca liczbe na pozycji
    string pobierz_element_znakow(int pozycja);                                     //metoda pobierajaca slowo na pozycji
    void wpisz_liczby(string, int, bool, int);                                      //metoda dopisujaca liczbe do tablicy liczb
    void wpisz_znaki(string);                                                       //metoda dopisujaca slowo do tablicy slow
    int pobierz_maks_rozmiar() const;                                               //metoda zwracajaca maksymalny rozmiar tablic
    explicit Znaki(int rozmiar);                                                    //konstruktor
    ~Znaki();                                                                       //destruktor
};
#endif //QUICKSORT_POBRANIE_H
