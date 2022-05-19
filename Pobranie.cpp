//
// Created by tomas on 21.04.2022.
//

#include <iostream>
#include "Pobranie.h"
using namespace std;

void Znaki::wpisz_liczby(string element, int rozmiar_element, bool znak, int pozycja) {  //funkcja przetwarzająca liczby i wpisująca je do obiektu
    tablica_liczb[rozmiar_liczb] = 0;                                                   //zerowanie liczb na kolejnej pozycji
    for (int z = 0; z < rozmiar_element; z++){                                          //preztwarzanie liczby w formacie string na float
        float zmienna = element[z];
        *(tablica_liczb+rozmiar_liczb) = *(tablica_liczb+rozmiar_liczb)*10 + zmienna - 48; //pętla pobierająca kolejne wartości i przeliczająca z ASCII na binarny
    }
    if (znak){                                                                              //jezeli jest ujemna pomnozyc razy -1
        *(tablica_liczb+rozmiar_liczb) *= -1;
    }
    if (pozycja != 0){
        pozycja = rozmiar_element - pozycja;                                                //mnozenie razy 0,1 do momentu uzyskania prawidlowej wartosci
        for(int h = 0; h < pozycja; h++){
            *(tablica_liczb+rozmiar_liczb) *= 0.1;
        }
    }
    rozmiar_liczb++;                                                                        //Zwiększenie zapisanej ilości elementów
}

int Znaki::pobierz_rozmiar_znakow() const {                                                        //funkcja zwracająca rozmiar
    return rozmiar_znakow;
}
int Znaki::pobierz_rozmiar_liczb() const {                                                         //funkcja zwracająca rozmiar
    return rozmiar_liczb;
}
void Znaki::wpisz_znaki(string element) {                                                          //Wpisanie danych stringa nie wymaga na tym etapie żadnych korekcji
    tablica_znakow[rozmiar_znakow] = std::move(element);
    rozmiar_znakow++;                                                                              //Doliczenie kolejnego wpisanego elementu
}
float Znaki::pobierz_element_liczb(int pozycja){                                                   //zwracanie ilosci wpisanych liczb
    return *(tablica_liczb+pozycja);
}
string Znaki::pobierz_element_znakow(int pozycja){                                                 //zwracanie ilosci wpisanych slow
    return tablica_znakow[pozycja];
}
int Znaki::pobierz_maks_rozmiar() const {                                                          //zwracanie maksymalnej ilosci wpisanych danych
    return maks_rozmiar;
}
void wpisanie_danych(int rozmiar, float *wsk_tablica_liczb, string *wsk_tablica_znakow, int * rozmiary) {
    Znaki znaki(rozmiar);                                                                                   //tworzenie obiektu
    for (int n = 0; n < rozmiar; n++) {                                                                     //pobieranie elementów w ilosci podanej przez uzytkownika
        string element;                                                                                     //zmienna przechowywujaca pobrane dane, czyszczona na koncu petli
        bool znak = false;                                                                                  //zmienna okreslajaca ujemnosc liczby
        int pozycja = 0;                                                                                    //zmienna okreslajaca zmiennoprzecinkowosc
        cin >> element;                                                                                     //pobranie n-tego elementu
        int rozmiar_element = element.size(), typ = 0;                                                      //sprawdzenie jak dlugi jest string, ustawienie domyslnego typu
        for (int p = 0; p < rozmiar_element;) {                                                             //sprawdzenie typu elementu 1 - liczba, 2 - litera 3 - mieszany
            if (((element[p] >= 48 && element[p] <= 57)||((element[p] == 45) && p==0)                       //48 - 57 liczby 0 - 9, 45 - minus, 44 - kropka 46 - przecinek
            ||((element[p] == 46)||(element[p] == 44))) && (typ == 0 || typ == 1)) {                        //sprawdzane są kolejne znaki w podanym stringu
                typ = 1;
                if(element[p] == 45 && p == 0){                                                             //sprawdzenie czy minus jest na 0 pozycji
                    znak = true;                                                                            //ustawienie zmiennej okreslajacej znak
                    for(int t = 0; t<rozmiar_element; t++){                                                 //usuniecie minusa ze stringa
                        swap(element[t], element [t+1]);
                    }
                    rozmiar_element--;                                                                      //zmniejszenie zmiennej okreslajacej dlugosc znakow
                }
                else {
                    if (element[p] == 44 || element[p] == 46) {                                             //sprawdzenie czy badany znak jest krpoka lub przecinkiem
                        pozycja = p;                                                                        //pobranie pozycji w liczbie
                        for(int t = p; t<rozmiar_element; t++){                                             //usuniecie symbolu ze stringa
                            swap(element[t], element [t+1]);
                        }
                        rozmiar_element--;
                    }
                    else {
                        p++;
                    }
                }
            }
            else {                                                                                        //małe litery są zamieniane na duże w celu ujednolicenia wynikow
                if (element[p] >= 97 && element[p] <= 122 && (typ == 0 || typ == 2)) {
                    element[p] = element[p] - 32;
                    typ = 2;
                    p++;
                }
                else {
                    if (element[p] >= 65 && element[p] <= 90 && (typ == 0 || typ == 2)) {
                        typ = 2;
                        p++;
                    } else {                                                                                //jeśli użytkownik poda mieszanke liter i cyfr
                        cout << "Podano niewlasciwa wartosc" << endl;                                       //albo nieprawidłowe znaki to zostaną one wychwycone
                        typ = 3;
                        p += rozmiar_element;                                                               //zakończenie sprawdzania tego stringa
                    }
                }
            }
        }
        if (typ == 1) {
            znaki.wpisz_liczby(element, rozmiar_element, znak, pozycja);                             //jezeli w stringu jest liczba wpisanie jej do tabeli liczb
        }
        if (typ == 2){
            znaki.wpisz_znaki(element);                                                              //jezeli w stringu sa same znaki wpisanie ich do tabeli slow
        }
    }
    for (int n = 0; n < znaki.pobierz_rozmiar_liczb(); n++){
        *(wsk_tablica_liczb + n) = znaki.pobierz_element_liczb(n);                                          //przepisanie tabeli liczb do wkazanej tabeli
    }
    for (int n = 0; n < znaki.pobierz_rozmiar_znakow(); n++){
        *(wsk_tablica_znakow + n) = znaki.pobierz_element_znakow(n);                                        //przepisanie tabli znakow do wskazanej tabeli
    }
    *(rozmiary) = znaki.pobierz_rozmiar_liczb();                                                            //wpisanie ilosci liczb do tabeli
    *(rozmiary + 1) = znaki.pobierz_rozmiar_znakow();                                                       //wpisanie ilosci slow do tabeli
}

Znaki::Znaki(int rozmiar) {                                                                                 //konstruktor
    maks_rozmiar = rozmiar;
    tablica_liczb = (float*) malloc(pobierz_maks_rozmiar()*sizeof(float));                                  //dynamiczne przypisanie pamieci do tablicy floatow
    rozmiar_liczb = 0;
    rozmiar_znakow = 0;
}
Znaki::~Znaki() {                                                                                           //destruktor
    free(tablica_liczb);                                                                                    //zwolnienie pamieci
}