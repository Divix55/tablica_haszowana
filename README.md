# tablica_haszowana
Napisz program śledzący ilość przelanych pieniędzy. Na wejście podane będą polecenia w formacie:
+ od do ile - od wpłaca na konto do ile pieniędzy
? od do - polecenie wypisania na ekran dotychczasowej sumy pieniędzy przelanych przez od na konto do

Uwaga: nie należy liczyć stanu konta, tylko sumę przelanych pieniędzy:
+ A B 10
+ A B 10
+ B A 5
? A B
? B A
powinno wypisać:
20
5

Nazwy od i do będą napisami składającymi się z maksymalnie 16 małych liter i znaku podkreślenia. Suma wpłat dla każdej pary nie przekroczy zakresu int-a.
Należy skorzystać z tablicy haszowanej z łańcuchowaniem oddzielnym do rozwiązywania kolizji
