#include "tablica.hpp"

using namespace std;

ElemListy::ElemListy(){
    for(int i=0; i<NAZWA; i++){
        calyKlucz[i]='\0';
    }
    ile=0;
    next=nullptr;
}

Lista::Lista(){
    glowa=nullptr;
}

Tablica::Tablica(){
    for(int i=0; i<ROZMIAR; i++){
        tablica[i]=nullptr;
    }
}

void Lista::dodajDoListy(char calyKlucz[], int ile){
    ElemListy *nowy = new ElemListy;
    for(int i=0; i<NAZWA; i++){
        nowy->calyKlucz[i]=calyKlucz[i];
    }
    nowy->ile=ile;
    nowy->next=glowa;
    glowa=nowy;
}

int Tablica::haszuj(char calyKlucz[]){
    int wynik=0;
    wynik+=(int)calyKlucz[0];
    wynik+=(int)calyKlucz[1];
    return wynik%ROZMIAR;
}

void Tablica::dodajDoTablicy(char calyKlucz[], int ilePieniedzy){
    int numer=haszuj(calyKlucz);
    if(tablica[numer]==nullptr){
        tablica[numer] = new Lista;
    }
    tablica[numer]->dodajDoListy(calyKlucz, ilePieniedzy);
}

void Tablica::wypiszLiczbe(char calyKlucz[]){
    int numerElementu = haszuj(calyKlucz);
    long long wynik=0;
    if(tablica[numerElementu]!=nullptr){
        ElemListy *tmp=tablica[numerElementu]->glowa;
        while(tmp!=nullptr){
            bool test1=true;
            for(int i=0; tmp->calyKlucz[i]; i++){
                if(tmp->calyKlucz[i]!=calyKlucz[i]){
                    test1=false;
                    break;
                }
            }
            if(test1){
                wynik+=tmp->ile;
            }
            tmp=tmp->next;
        }
    }
    cout<<wynik<<endl;
}

void stworzKlucz(char odKogo[], char doKogo[], char calyKlucz[]){
    for(int i=0, x=0, y=0; i<2*NAZWA; i++){
        if(odKogo[x]!='\0'){
            calyKlucz[i]=odKogo[x];
            x++;
        }
        else if(doKogo[y]!='\0'){
            calyKlucz[i]=doKogo[y];
            y++;
        }
        else{
            calyKlucz[i]='\0';
        }
    }
}
