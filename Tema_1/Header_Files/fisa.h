#include <iostream>
#include "masina.h"
using namespace std;

class Fisa{
    int id;
    Masina masina;

    public:
        Fisa(const int id_fc, const Masina masina_fc)
        {
            id = id_fc;
            masina = masina_fc;
        }
        // ~Fisa();
        Fisa(const int id_fc, const string nr, const int NrSoferi, const char* nume, const char* prenume)
        {   
            id = id_fc;

            Sofer sofer(nume,prenume),sofer_array[1];
            sofer_array[0] = sofer;
            Masina masina1(nr,NrSoferi,sofer_array);
            
            masina = masina1;
            
        }

        Fisa& operator+=(const Sofer& sofer_fc)
        {   
            masina += sofer_fc;
            return *this;
        }

        bool operator>(const Fisa& fisa_fc) 
        {
            return masina.getSize() > fisa_fc.masina.getSize();
        }

        friend ostream& operator<<(ostream& os, const Fisa& f1);
};

ostream& operator<<(ostream& os, const Fisa& f1)
{
    os << f1.id << " : " << f1.masina;
    return os;
}