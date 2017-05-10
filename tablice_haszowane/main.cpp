#include "tablica.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    Tablica *nowaTablica = new Tablica;
    char polecenie='\0', odKogo[NAZWA]={'\0'}, doKogo[NAZWA]={'\0'}, klucz[2*NAZWA]={'\0'};
    int ile=0;
    while(cin>>polecenie){
        if(polecenie=='+'){
            cin>>odKogo>>doKogo>>ile;
            stworzKlucz(odKogo, doKogo, klucz);
            nowaTablica->dodajDoTablicy(klucz, ile);
        }
        else if(polecenie=='?'){
            cin>>odKogo>>doKogo;
            stworzKlucz(odKogo, doKogo, klucz);
            nowaTablica->wypiszLiczbe(klucz);
        }
    }
    delete nowaTablica;
    return 0;
}
