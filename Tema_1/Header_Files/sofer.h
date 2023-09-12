
#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

class Sofer{
    char* nume;
    char* prenume;

public:
    Sofer(){
        nume = new char[50];
        prenume = new char[50];
        }
        
    // ~Sofer(){
    //     delete [] nume;
    //     delete [] prenume;
    // }
    Sofer(const char* nume_fc, const char* prenume_fc) // Sofer s1("Picky","Tudor")
    {   
        nume = new char[strlen(nume_fc)+1];
        prenume = new char[strlen(prenume_fc)+1];
        
        strcpy(nume,nume_fc);
        strcpy(prenume, prenume_fc);
    }

    Sofer& operator=(const Sofer& ob_Sofer)// s1 = s2
	{   
        strcpy(nume, ob_Sofer.nume);
        strcpy(prenume, ob_Sofer.prenume);	
		return *this;
	}

    friend ostream& operator<<(ostream& os, const Sofer& altSofer);

    friend istream& operator>>(istream& os, const Sofer& altSofer);

    bool operator==(const Sofer& sofer_fc) const { //verifica daca 2 soferi au aceleasi valori (ne ajuta pentru egalearea masinilor )
        return (strcmp(sofer_fc.nume,nume) == 0 && strcmp(sofer_fc.prenume,prenume) == 0);
    }
};
ostream& operator<<(ostream& os, const Sofer& altSofer) // Output : Picky Tudor
{
	os  << altSofer.nume << " " << altSofer.prenume << endl;
	return os;
}

istream& operator>>(istream& os, const Sofer& altSofer)//se citesc valorile de la tastatura
{
    cout<< "Numele: ";
    os >> altSofer.nume;
    cout<< "Prenume: ";
    os >> altSofer.prenume;
    return os;
}