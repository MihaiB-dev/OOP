#include <iostream>
#include <vector>
#include <string>
#include "sofer.h"
using namespace std;
class Masina{
    string nr;
    int NrSoferi;

    vector<Sofer> So;

public:
    //initializarea Masinii cu elemente nule
    Masina(){
        NrSoferi = 0;
        So = {};
        }
    // ~Masina();
    //Constructor de initializare
    Masina(const string nr_fc, const int NrSoferi_fc = 0, const Sofer So_fc[] = {}) //Masina m1("B 05 tgo", 4, s3) unde s3 = s1[5]
    {
        nr = nr_fc;
        NrSoferi= NrSoferi_fc;

        for(int i = 0; i< NrSoferi_fc ;i++)
        {
            So.push_back(So_fc[i]);
        }
            
    }

    //constructor de initializare cu element Masina
    Masina(const Masina& masina){
        nr = masina.nr;
        NrSoferi= masina.NrSoferi;
        for (int i=0; i<masina.NrSoferi; i++) So.push_back(masina.So[i]);
    }
    string getNr()const{
        return nr;
    }
    int getSize()const{
        return So.size();
    }
    bool operator==(const Masina& masina_fc) const //egaleaza 2 masini in functie de soferi
    {   // go with each elements of the first item and search on the second item
        // vedem daca So[i].get_nume() == un element din masina_fc.So[i].get_nume()
        for(int i = 0; i < NrSoferi; i++)
            {int ok = 0;
            for(int j = 0; j < masina_fc.NrSoferi; j++)
                {
                    if (So[i] == masina_fc.So[j]) {ok = 1; break;} //trb sa facem dubla egalitate si la soferi
                }
            if (ok == 0) return false;
            }
        return true;
    }
    //supraincarcarea operatorului = 
    Masina& operator=(const Masina& ob_masina)
	{   
        nr = ob_masina.nr;
        NrSoferi = ob_masina.NrSoferi;

        So.clear();
        for(int i = 0; i< ob_masina.NrSoferi ;i++)
        {
            So.push_back(ob_masina.So[i]);
        }
		return *this;
	}
    //supraincarcarea operatorului +=
    Masina& operator+=(const Sofer& x) // adaugam soferi la masina
    {   NrSoferi ++;
        So.push_back(x);
        return *this;
    }

    
    friend istream& operator>>(istream& os, Masina& masina_fc);
};

   

//supraincarcarea operatorului <<
ostream& operator<<(ostream& os, const Masina& obj)
    { 
        os << obj.nr << " " << obj.NrSoferi << " ";
        for (int i = 0; i < obj.NrSoferi; i++ )
            os << obj.So[i] << " ";

        return os;
    }


istream& operator>>(istream& os, Masina& masina_fc) // citeste de la tastaura un string care semnifica numarul masinii
{
    getline(os,masina_fc.nr);
    return os;
}

