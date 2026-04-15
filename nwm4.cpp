#include <iostream>
using namespace std;


int main() {

    string napis;
    napis="Ala ma kota";
    cout << napis << endl;
    cout<<"Pierwsza litera: "<<napis[0]<<endl;
    cout<<"Dlugosc napisu: "<<napis.length()<<endl;
    cout<<"Wystapienia znaku: "<<napis.find('m')<<endl;//znalezienie indeksu pod którym znajduje się wyszukiwany znak, jesli jest kilka zostanie znaleziony pierwszy
    cout<<"Wyodrebnienie czesci napisu: "<<napis.substr(0,5)<<endl;//nr indeksu od ktorego zaczyna sie napis do nr indeksu przed ktorym skonczy sie napis
    //porownywanie napisow

    string napis1 = "kota ma Ala";
    if(napis.compare(napis1))//na obiekcie napis wywoływana jest metoda comrare do ktorej jako argument przekazywany jest drugi napis1
        // (metoda ta zwraca false jesli napisy sa rowne)
            cout<<"Napisy sa rózne."<<endl;
    else
        cout<<"Napisy sa takie same."<<endl;

    /* if(!napis.compare(napis1))
         cout<<"Napisy sa takie same."<<endl;
     else
         cout<<"Napisy sa rozne"<<endl;*/


    if(napis==napis1)
        cout<<"Napisy sa takie same."<<endl;
    else
        cout<<"Napisy sa rozne"<<endl;

    //laczenie napisow

    string napis2 = " i chomika";
    napis=napis1+napis2;
    cout<<"Polaczony napis: "<<napis<<endl;

    napis=napis+napis2;
    cout<<"Polaczony napis: "<<napis<<endl;

    napis2="7";
    int liczba= stoi(napis2);//jako argument funkcja dostaje string i konwertuje go na liczbe calkowita
    cout<<"Liczba: "<<liczba<<endl;

    //znak jaki ma kod z tablicy ASCI

    char znak=napis[1];//pobrany znak z tablicy napis pod indeksem 1
    int kod = (int)znak;//znak zrzutowac na int, zeby zobaczyc jaki kod ma w tablicy ASCI
    cout<<"Znak: "<<znak<<" "<<"kod: "<<kod<<endl;

    char napiss[100];
    cout<<"podaj imie: ";

    cin.getline(napiss,100); //wczytuje linię, pomija \n

    cout<<"Napis2: "<<napiss<<endl;




    return 0;
}