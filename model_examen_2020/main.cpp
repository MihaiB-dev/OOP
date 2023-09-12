#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <exception>
#include <fstream>
using namespace std;
ifstream f_copii("copii.in");
ifstream f_jucarii("jucarii.in");

#include "header_files/Jucarii.h"
#include "header_files/Copii.h"
#include "header_files/Meniu.h"
class Litera : public exception {
    const char* what() const throw(){
        return "Trebuie sa fie un numar intre 0 si 5";
    }
};

void verificare(string optiune){
    for(auto& litera : optiune){
            if(litera < '0' || litera > '6')throw Litera();
           }//verificare daca inputul este dat bine.
}
int main(){
    Meniu* meniu = Meniu::get_instanta(); //folosire singleton pentru meniu


    string optiune;
    cout << "Bine ati venit pe aplicatie"<<endl;
    bool active = true;
    while(active){
        cout<<"1. Citire copii, 2.Afisare copii,3.Adaugare jucarii, 4. Afisare Jucarii, 5. Order fapte, 6. Order Varsta 0. stop "<<endl<<"Numar: "; //jucariile vor fi afisate si se vor alege pentru fiecare copil.
        cin >> optiune;
        try{
            verificare(optiune);
            switch(stoi(optiune)){
                case 1: {meniu->citire_copii(); break;}
                case 2: {meniu->afisare_copii(); break;}
                case 3: {meniu->adaugare_jucarii(); break;}
                case 4: {meniu->afisare_jucarii(); break;}
                //case 5: {string nume; cin>> nume;meniu->gaseste_dupa_nume(nume); break;}
                case 5 : {meniu->order_fapte(); break;}
                case 6: {meniu->order_varsta(); break;}
                case 0: {active = false; break;}
            }
            
        }catch(exception& obj){
            cout << obj.what() <<endl;
        }
        
    }
}