#include <iostream>

using namespace std;

class Baza {
    protected:
        int x;
    public:
        Baza(int a =0) : x(a) {}
        Baza(Baza& ob): x(ob.x) {} // constrcutor explicit 
};

class Derivata : public Baza {
    int y;
    public:
        Derivata(int a = 0, int b = 0): Baza(a),y(b) {}  // va afisa x = 2 y =3 
        // Derivata(int a = 0, int b = 0): y(b) {} va afisa 0 3 -> x = 0, y = 3

        // daca punem constructorul de copiere in clasa derivata, se strica un pic treaba
        //Derivata(Derivata& ob) : y(ob.y) {} ne va afisa 0 3, nu merge pentru x
        //Derivata(Derivata& ob) : Baza(ob), y(ob.y) {} // aici va face object slicing, va lua derivata chiar daca nu avem derivata in Baza
        //alocare de memorie si setare de valoare in acelas timp pentru y(ob.y)

        Derivata(Derivata& ob) { y = ob.y; }
        void afis(){cout << x << " "<< y << "\n";}
};

int main()
{
    Derivata ob(2,3);
    ob.afis();
    Derivata ob2(ob); // va merge bine, 2 3, fara nici un constructor explicit
    ob2.afis();
}