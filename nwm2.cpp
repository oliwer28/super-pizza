#include <iostream>

using namespace std;

int main()
{
    int x = 1, y = 2, z=8;
    int &rx=x;
    rx = y;// za pomocą referencji przypisuje do zmiennej x watrosc y
    z=rx;

    cout<<"y="<<y;
    cout<<"x="<<x;
    cout<<"z="<<z;
    //mozliwe jest zadeklarowanie referencji do obiektow stalych
    //wtedy obiektu do ktorego odnosi sie referencja nie bedzie mozna zmienic
    int a=0;
    const int &ref_a = a;
    cout <<endl<<"zmienna= "<<a;
    cout <<endl<<"referencja= "<<ref_a; // wypisze 0
    a=5;
    cout <<endl<<"zmienna= "<<a;
    //ref_a = 1;

    return 0;
}