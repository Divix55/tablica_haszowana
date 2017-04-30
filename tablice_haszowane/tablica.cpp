#include "tablica.hpp"

using namespace std;

void Lista::dodajDoListy(char odKogoPrzelew[], char doKogoPrzelew[], int ile){
    ElemListy *nowy = new ElemListy;
    for(int i=0; i<NAZWA; i++){
        nowy->odKogo[i]=odKogoPrzelew[i];
        nowy->doKogo[i]=doKogoPrzelew[i];
    }
    nowy->ile=ile;
    nowy->next=glowa;
    glowa=nowy;
}

int Tablica::haszuj(char odKogoPrzelew[], char doKogoPrzelew[]){
    int wynik=0;
    wynik+=(int)odKogoPrzelew[0];
    if(odKogoPrzelew[1]!='\0'){
        wynik+=odKogoPrzelew[1];
    }
    else
        wynik+=(int)doKogoPrzelew[0];
    return wynik%ROZMIAR;
}

void Tablica::dodajDoTablicy(char odKogoPrzelew[], char doKogoPrzelew[], int ilePieniedzy){
    int numer=haszuj(odKogoPrzelew, doKogoPrzelew);
    if(tablica[numer]==nullptr){
        tablica[numer] = new Lista;
    }
    tablica[numer]->dodajDoListy(odKogoPrzelew, doKogoPrzelew, ilePieniedzy);
}

void Tablica::wypiszLiczbe(char odKogoPrzelew[], char doKogoPrzelew[]){
    int numerElementu = haszuj(odKogoPrzelew, doKogoPrzelew), wynik=0, i;
    if(tablica[numerElementu]!=nullptr){
        ElemListy *tmp=tablica[numerElementu]->glowa;
        while(tmp!=nullptr){
            bool test1=true, test2=true;
            i=-1;
            /*for(int i=0; i<NAZWA; i++){
                if(tmp->odKogo[i]){
                    if(tmp->odKogo[i]!=odKogoPrzelew[i]){
                        test1=false;
                    }
                }
                if(tmp->doKogo[i]){
                    if(tmp->doKogo[i]!=doKogoPrzelew[i]){
                        test2=false;
                    }
                }
            }*/
            do{
                i++;
                if(tmp->odKogo[i]){
                    if(tmp->odKogo[i]!=odKogoPrzelew[i]){
                        test1=false;
                    }
                }
                if(tmp->doKogo[i]){
                    if(tmp->doKogo[i]!=doKogoPrzelew[i]){
                        test2=false;
                    }
                }
            }while(tmp->odKogo[i]!='\0' && tmp->doKogo[i]!='\0');
            if(test2 && test1){
                wynik+=tmp->ile;
            }
            tmp=tmp->next;
        }
    }
    cout<<wynik<<endl;
}
