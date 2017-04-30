#include "tablica.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    Tablica *nowaTablica = new Tablica;
    char polecenie='\0', odKogo[NAZWA]={'\0'}, doKogo[NAZWA]={'\0'};
    int ile=0;
    while(cin>>polecenie){
        if(polecenie=='+'){
            cin>>odKogo>>doKogo>>ile;
            nowaTablica->dodajDoTablicy(odKogo, doKogo, ile);
        }
        else if(polecenie=='?'){
            cin>>odKogo>>doKogo;
            nowaTablica->wypiszLiczbe(odKogo, doKogo);
        }
    }
    delete nowaTablica;
    return 0;
}
