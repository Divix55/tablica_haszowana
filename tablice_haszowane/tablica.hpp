#ifndef tablica_hpp
#define tablica_hpp

#define ROZMIAR 101
#define NAZWA 16
//13 - liczba pierwsza 6173 test duza pierwsza

#include <stdio.h>
#include <iostream>

struct ElemListy{
    char odKogo[NAZWA];
    char doKogo[NAZWA];
    int ile;
    ElemListy *next;
    
    ElemListy(){
        for(int i=0; i<NAZWA; i++){
            odKogo[i]='\0';
            doKogo[i]='\0';
        }
        ile=0;
        next=nullptr;
    }
};

struct Lista{
    ElemListy *glowa;
    
    void dodajDoListy(char[], char[], int);
    Lista(){
        glowa=nullptr;
    }
};

struct Tablica{
    Lista *tablica[ROZMIAR];
    
    int haszuj(char[], char[]);
    void dodajDoTablicy(char[], char[], int);
    void wypiszLiczbe(char[], char[]);
    Tablica(){
        for(int i=0; i<ROZMIAR; i++){
            tablica[i]=nullptr;
        }
    }
};

#endif /* tablica_hpp */
