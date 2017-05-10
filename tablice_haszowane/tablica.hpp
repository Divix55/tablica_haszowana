#ifndef tablica_hpp
#define tablica_hpp

#define ROZMIAR 97
#define NAZWA 16

#include <stdio.h>
#include <iostream>

struct ElemListy{
    char calyKlucz[2*NAZWA];
    int ile;
    ElemListy *next;
    
    ElemListy();
};

struct Lista{
    ElemListy *glowa;
    
    void dodajDoListy(char[], int);
    Lista();
};

struct Tablica{
    Lista *tablica[ROZMIAR];
    
    int haszuj(char[]);
    void dodajDoTablicy(char[], int);
    void wypiszLiczbe(char[]);
    Tablica();
};

void stworzKlucz(char[], char[], char[]);
#endif /* tablica_hpp */
