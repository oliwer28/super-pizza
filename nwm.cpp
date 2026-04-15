#include <iostream>

using namespace std;
class CBufor //nazwa klasy
{
private:
    int* bufor; //pole klasy, wskaznik na typ calkowity
    int rozmiar; //pole klasy
    int liczbaElementow; //pole klasy
public:
    CBufor(int rozmBuf) //konstruktor
    {
        rozmiar=rozmBuf;
        liczbaElementow=0; //ustawienie wartosci poczatkowej liczbyElementow, na samym poczatku jest 0
        bufor=new int[rozmiar]; //zaalokowanie pamieci - bufor tablica jednowymiarowa
    }
   CBufor(CBufor &b) //konstruktor kopiujacy, np. jesli chcemy utworzyc kopie obiektow, ktore zawieraja wskaznik jako pole klasy
    { //konstruktor jako paramter przyjmuje obiekt, na jego podstawie wykonywana jest kopia
        /* *this=b; //wersja skrocona
        bufor=new int[rozmiar];
          for(int i=0;i<liczbaElementow;i++){
             bufor[i]= b.bufor[i];
          } */

        rozmiar=b.rozmiar;
        liczbaElementow=b.liczbaElementow;

        bufor=new int[rozmiar];
        for(int i=0; i<liczbaElementow; i++)
        {
            bufor[i]= b.bufor[i]; //przepisywanie elmentow z jednej tablicy ( jednego obiketu) do drugiej tablicy ( drugiego obiketu)
        }
        cout<<"Konstruktor kopiujacy"<<endl;
    }
    ~CBufor() //destuktor, tutaj nalezy zwolnic przydzielona pamiec
    {
        delete [] bufor; //zwolnienie pamieci
    }

    void dodajElem(int elem) //metoda dodajaca element do tablicy
    {
        if(rozmiar>liczbaElementow) //sprawdzenie czy mozna dodac kolejny element
        {
            bufor[liczbaElementow]=elem; //podstawienie nowego elementu
            liczbaElementow++;    //zwiekszenie liczby elementow
        }
        else
        {
            cout<<"Bufor pelny, element "<<elem<<" nie zostal dodany"<<endl;
        }
    }
    void wyswietlBufor() //metoda
    {
       cout<<"Wyswietlenie elementow bufora"<<endl;
        for(int i=0; i<liczbaElementow; i++)
        {

            cout<<bufor[i]<<endl;
        }
    }

    void setElemTab0(int e) //modyfikacja elementu znajdujacego sie pod indeksem 0
    {
        bufor[0]=e;
    }

};
void funkcja(CBufor buf) //funkcja NIE metoda
{   cout<<"W funkcja"<<endl;
    buf.setElemTab0(111);
    buf.wyswietlBufor();
}
void funkcja1(CBufor &buf) //funkcja NIE metoda
{   cout<<"W funkcj1 z &"<<endl;
    buf.setElemTab0(111);
    buf.wyswietlBufor();
}
int main()
{
    CBufor b(5); //stworzenie obiektu
    b.dodajElem(1);
    b.wyswietlBufor();
    b.dodajElem(2);
    b.wyswietlBufor();
    b.dodajElem(3);
    b.wyswietlBufor();
    b.dodajElem(4);
    b.wyswietlBufor();
    b.dodajElem(5);
    b.wyswietlBufor();
    b.dodajElem(6);

   //kopia obiektu wersja 1
    CBufor b1=b; //obiekt b1 ma swoja tablice bufor oraz obiekt b ma swoja tablice bufor
    cout<<"Poprawne kopiowanie obiektu wersja 1"<<endl;
    b1.wyswietlBufor();
    b1.setElemTab0(333);

    b1.wyswietlBufor(); ////wartosc elementu pod indeksem 0 w buforze obiektu b1 zostala zmieniona
    b.wyswietlBufor(); // wartosc elementu pod indeksem 0 w buforze obiektu b nie zmienila sie

    //kopia obiektu wersja 2
    cout<<"Poprawne skopiowanie obiektu wersja 2"<<endl;
    CBufor b2(b); //obiekt b2 ma swoja tablice bufor oraz obiekt b ma swoja tablice bufor
    b2.setElemTab0(444);
    b2.wyswietlBufor(); //wartosc elementu pod indeksem 0 w buforze obiektu b2 zostala zmieniona
    b.wyswietlBufor(); // wartosc elementu pod indeksem 0 w buforze obiektu b nie zmienila sie

    //wywolanie funkcji w ktorej wartosci pol sa modyfikowane
    funkcja(b); // w funkcja wartosc elementu zostala zmieniona
    cout<<"Po wyjsciu z funkcji"<<endl;
    b.wyswietlBufor(); // po wyjsciu z funkcji wartosc ta nie zostala zachowana

    funkcja1(b); //przekazanie argumentu przez referencje spowodowalo ze wartosc argumentu przekazana w parametrze
    cout<<"Po wyjsciu z funkcji1 z &"<<endl;
    b.wyswietlBufor();//zostala zmieniona rowniez po wyjsciu z funkcji

    return 0;
}
