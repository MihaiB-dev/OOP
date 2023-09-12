#include <iostream>
#include <string>
using namespace std;

class Jucarie {
protected:
    string denumire;
    int dimensiune;
    string tip;
public:

 Jucarie(string& denumire_fc, int& dimensiune_fc, string& tip_fc ) :denumire(denumire_fc), dimensiune(dimensiune_fc), tip(tip_fc) {};

 virtual ~Jucarie();
};

class Clasica : public Jucarie {

    string material, culoare;
    public:
    Clasica(string & mat, string& cul, string& denumire, int dim, string& tip)
};

class Educative : virtual public Jucarie {
    protected:
    string abilitate;
}

class Electronice : virtual public Jucarie {
    protected:
    int nr_b;

}

class Moderne : public Educative, public Electronice {
    string brand,model;
}
class 
int main(){

}