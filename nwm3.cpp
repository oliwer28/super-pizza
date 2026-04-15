#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    char napis[20]="Ala ma kota";
    cout << napis<<endl;

    //spowoduje blad:
    //napis="kot";
    //cout << napis<<endl;

    //nie spowoduje bledu:

    char *napis2="Ala ma kota2";
    cout << napis2<<endl;
    napis2="Inny napis";
    cout << napis2<<endl;

    //pokaz konkretny znak:
    cout<<napis[0]<<endl;

    //sprawdz plec uzytkownika:
    string imie;
    cout<<"Podaj imie: ";
    cin>>imie;

    int dlugosc_imienia=imie.length();
    cout<<"Dlugosc: "<<dlugosc_imienia<<endl;

    if (imie[dlugosc_imienia-1]=='a')//stosujemy "" dla napisow a '' dla znakow pojedynczych
        cout<<"Wydaje mi sie, ze jestes kobieta"<<endl;
    else cout<<"Wydaje mi sie, ze jestes mezczyzna"<<endl;

    //odwracanie wyrazow:
    string wyraz;
    cout<<"Podaj wyraz do odwrocenia (bez spacji): ";
    cin>>wyraz;

    int dlugosc=wyraz.length();
    for (int i=dlugosc-1; i>=0; i--)//dlugosc -1 bo nr w tablicy od zera
    {
        cout<<wyraz[i];
    }

    //uzycie getline - zapis ze spacjami://cin wczytuje tylko do spcji
    string napis3;
    cout<<endl<<"Podaj wyraz ze spacjami: ";
    cin.ignore(); //"wyczysc" strumien
    getline(cin,napis3);//pobiera cala linie ze spacjami az do nacisniecia entera
    cout<<napis3<<endl;

    //wyznacz dlugosc napisu i wyswietl na ekranie:
    int dlugosc2=napis3.length();
    cout<<dlugosc2<<endl;

    // laczenie dwoch stringow:
    string jeden="Ala ma";
    string dwa=" psa";
    string trzy=jeden+dwa;
    cout<<trzy<<endl;

    //Zmiana wielkosci liter:
    string napis4="Ala ma kota";

    transform(napis4.begin(), napis4.end(), napis4.begin(), ::tolower);
    cout<<napis4<<endl;

    transform(napis4.begin(), napis4.end(), napis4.begin(), ::toupper);
    cout<<napis4<<endl;


    //Znajdz fraze:
    string napis5="Ala ma kota";
    string szukaj="kot";
    size_t pozycja = napis5.find(szukaj);//typ size_t

    if (pozycja!=string::npos)
        cout << "znaleziono na pozycji: " << pozycja << endl;
    else cout<<"nie znaleziono"<< endl;

    //Wykasuj czesc lancucha:
    string napis6="Ala ma kota";
    napis6.erase(3,3);//pierwszy argument od jakiego znaku zaczac kasowanie , drugi ile znakow skasowac
    cout<<napis6<< endl;

    //Zastap czesc lancucha:
    string napis7="Ala ma kota";
    napis7.replace(4,2,"nie ma");//od ktorego znaku zaczac, ile znakow zastapic i czym zastapic
    cout<<napis7<< endl;

    //Wstaw do lancucha:
    string napis8="Ala ma kota";
    napis8.insert(11," Filemona");
    cout<<napis8<< endl;

    //Wyciagnij czesc napisu do nowego lancucha:
    string napis9="Ala ma kota";
    string nowynapis = napis9.substr (4,7); //od 4 znaku zaczynaj¹c wyjmij 7 znakow
    cout<<nowynapis;



    return 0;
}