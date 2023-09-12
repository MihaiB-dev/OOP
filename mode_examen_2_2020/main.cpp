#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
#include "Header_Files/Produse.h"
#include "Header_Files/Meniu.h"

class litera : public exception {
public:
    const char* what() const throw(){
        return "Numarul trb sa fie intre 0 si 6";
    }
};
void verificare_numar(string numar){
    for(auto& lit: numar){
        if(lit < '0' || lit > '6')throw litera();
    }
}
int main(){


    Meniu* meniu = Meniu::get_instanta();

    bool active = true;
    string numar;
    while(active){
        cout<<"Insereaza produse = 1"<<endl<<"Afisarea produse = 2"<<endl<<"Editare produs = 3"<<endl<<"Ordonare Crescatoare a produselor dupa pret = 4"<<endl<<"Cautarea unei carti dupa titlu = 5"<<endl<<"Cea mai mare cantitate disponibila = 6"<<endl<<"Terminat = 0"<<endl<<"Numar: ";cin>>numar;
        try{
            verificare_numar(numar);
            switch(stoi(numar)){
                case 1: {meniu->inserare();break;}
                case 2: {meniu->afisare(); break;}
                case 3: {meniu->editare(); break;}
                case 4: {meniu->Ordonare_pret(); break;}
                //adaugam si restul mai incolo
                case 6: {meniu->celMaiMare(); break;}
                case 0: {active = false;break;}
            }

        }catch(exception &obj){
            cout<<endl<<obj.what()<<endl<<endl;
        }

    }
}