#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <ctime>
#include <memory>
#include <functional> // -|
//for password
#include <stdio.h>
#include <unistd.h>
#include<ios> //used to get stream size
#include<limits> //used to get numeric limits
using namespace std;
#include "Header_Files/musician.hpp"
#include "Header_Files/song.hpp"
#include "Header_Files/Record_labels.hpp"
#include "Header_Files/Playlist.h"
#include "Header_Files/Meniu.h"
int main()
{
    cout<<"Record Labels app\n Ce puteti face cu aceasta aplicatie:\n";


    Meniu* meniu = Meniu::get_instanta();
    // vector<vinyls> vinyls;

    //cautam in record labels, daca gasim unul cu numele citit anterior, adaugam musicianul la record_label.

    int main_menu = 1;
    while(main_menu)
    {   cout<<"-------------------------\n";
        cout<<"|Locatie: meniu principal|\n";
        cout<<"-------------------------\n";
        cout<<"Add/Create objects = 1 \033[1;32m(You can now create a playlist, try out!)\033[00m\nSee details about a record label = 2\nSee Playlists = 3 \033[1;32m(New)\033[00m \nClose = 0\n";
        cout<<"Numar: ";
        // cout << "apasati 1 pentru a adauga un Record Label\n apasati 2 pentru a adauga un cantaret\n apasati 3 pentru a adauga un Band Music\n apasati 4 pentru a crea un vinyl\n \n apasati 0 pentru a iesi din aplicatie\n Numar: ";
        int optiune_meniu_principal;
        try{
            cin>>optiune_meniu_principal;
            switch(optiune_meniu_principal)
        {   
            //ADD
            case 1: { meniu->add_function();break;}
            case 2: { meniu->see_record_label(); break;}
            case 3: { meniu->see_playlist(); break;}
            case 0: {main_menu = 0;cout<<"Va multumim pentru vizita!";}
        } 
            
        }
        catch(int n){
            if(n == 900){cout << "\x1B[33m\nNu exista Record labels, creeaza unul\033[0m\t\n";}
            else if (n == 111)
            {
                cout<<"\x1B[33m The passowrd is incorrect.\033[0m\t\n";
            }
            else if (n == 901){cout <<"\x1B[33m Nu exista nici un playlist, creati unul\033[0m\t\n";}
        }     
    }
}