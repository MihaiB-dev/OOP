#include <iostream>
#include  <vector>
#include <typeinfo>
using namespace std;

class Auto
{   
    string culoare;
    const int nr_roti;

    public:
        Auto():nr_roti(0){}
        Auto(string culoare, int nr_roti):nr_roti(nr_roti){
            this->culoare = culoare;
        }
        virtual void Afis()
        {
            cout << culoare << " " << nr_roti << " ";
        }
        
};

class masina : public Auto
{
    string marca;
    public:
        masina(string marca, string culoare, int nr_roti):Auto(culoare,nr_roti), marca(marca){}
        void Afis(){
            cout << marca << " ";
            Auto::Afis();
            cout << endl;
        }
};

class moto : public Auto
{
    int cp;
    public:
        moto(string culoare, int nr_roti, int cp): Auto(culoare, nr_roti), cp(cp) {}
        void Afis()
        {
            Auto::Afis();
            cout << cp << endl;
        }
        int get_cp(){
            return cp;
        }
};

class bicicleta_mo : public moto 
{
    public:
        bicicleta_mo(string culoare,int nr_roti): moto(culoare, nr_roti,0) {}
};

int main()
{   
    //Auto ob("rosu", 0);
    masina ob("Dacia","rosu",4);
    ob.Afis();
    moto ob_3("negru",2,100);
    ob_3.Afis();

    int n;
    vector <Auto*> v; //putem stoca acum obiecte diferite la un loc.
    cin >> n;
    for(int i = 0; i < n; i ++){
        int optiune;
        cin >> optiune;
        if (optiune == 1)
            {
                int roti;
                string marca,culoare;
                cin >> marca >> culoare >> roti;
                v.push_back(new masina(marca, culoare, roti));//marca culoare roti
            }
        else if (optiune == 2)
        {
                int roti, cp;
                string culoare;
                cin >> culoare >> roti >> cp;
                v.push_back(new moto(culoare, roti, cp));//culoare nr roti, cp
        }
        else
        {
                int roti;
                string culoare;
                cin >> culoare >> roti;
                v.push_back(new bicicleta_mo(culoare, roti));//culoare, roti
        
        }
    }

    for(int i = 0; i < n; i++) v[i]-> Afis(); //afisam normal

     for(int i = 0; i < n; i++){
        if(typeid(*v[i]) == typeid(moto) && ((moto*)(v[i]))->get_cp() <= 100) // am verificat daca suntem in clasa moto
                v[i]->Afis();
     }
    // citire stocare afisare n auto cu toate datele necesare/ Afisarea doar a motocicletelor cu capacitate pana in 100cp
}