#include <iostream>
#include <string>
#include <memory>
#include <exception>
#include <vector>
#include <fstream>
using namespace std;

// pt proiect 3 : template, try catch, design pattern, mult STL
//today: exceptii and templates
//
// persoana - cnp, nume, tara
//  CNP Romana - 13 cifre
//             - 1, 2, 5, 6 -> prima cifra
//             - 23 - cifrele (2,3) <= 18 ; >= 6 -> elev
//             - luna = februarie si ziua 30 sau 31 sa nu fie acceptate
// exception - litera
//           - cifra
//           - prima
//           - elev
//           - februarie

//Doamne ajuta!

class Persoana {
    const string CNP;
    string nume,tara;

public:
    Persoana(string cnp, string nume, string tara): CNP(cnp), nume(nume), tara(tara) {}

    friend ostream& operator<<(ostream& os, const Persoana& rsh){
        os << "------------------"<<endl;
        os << "Nume: "<< rsh.CNP<<endl;
        os << "Tara: "<< rsh.tara<<endl;
        os << "Nume: "<< rsh.nume<<endl;
        return os;
    }

    string getCNP() const {
        return CNP;
    }

    string getTara() const {
        return tara;
    }

};


class Cifra : public exception{
    public:
     virtual const char* what(){ return "nu sunt 13 cifre la cnp roamnesc!";}
};

class PrimaCifra : public exception {
    public:
    virtual const char * what(){return "Prima cifra nu este 1,2,5,6!";}
};

class Elev : public exception {
    public:
    virtual const char* what(){return "Nu este elev";}
};

class Februarie : public exception {
    public:
    virtual const char* what(){return "februarie nu are zilele 30 si 31";}
};

class Litera : public exception {
    public:
    virtual const char* what(){return "Cnp-ul nu are litere.";}
};

class Grupa134: protected Persoana {
    private:
    const int nota_poo;
    public:
};


int main(){
    ifstream f("date.in");
    vector<shared_ptr<Persoana>> persoane, elevi;
    string cnp, nume,tara;
    int n = 5;
    for(int i = 0; i < n; i++){
        f>>cnp >> nume >> tara;
        persoane.push_back(make_shared<Persoana>(cnp,nume,tara));
    }

    for(auto j = persoane.begin(); j != persoane.end(); j++){
        auto p = *j;
        try{
            if(p->getTara() == "Romania")
            {
                if(p->getCNP().size() != 13)throw Cifra();

                auto x = p->getCNP()[0];
                if(x!='1' && x!='2' && x!='5' && x!='6')throw PrimaCifra();

                int an =int(p->getCNP()[1] - '0')*10 + int(p->getCNP()[2] - '0');
                if(23-an>18 || 23-an<6)throw Elev();

                int luna = int(p ->getCNP()[3] - '0')*10 + int(p->getCNP()[4] - '0');
                int zi = int(p->getCNP()[5] - '0')*10 + int(p->getCNP()[6] - '0');
                if (luna == 2 && (zi == 30 || zi == 31))throw Februarie();

            }
        }
        // catch(Cifra& obj){
        //     cout << *p << obj.what() << endl;
        //     persoane.erase(j);
        //     j--;
        // }catch(PrimaCifra& obj){
        //     cout << *p << obj.what() <<endl;
        //     persoane.erase(j);
        //     j--;
        // }catch(Elev& obj){
        //     cout << *p << obj.what() << endl;
        //     persoane.erase(j);
        //     j--;
        // }catch(Februarie& obj){
        //     cout << *p << obj.what() <<endl;
        //     persoane.erase(j);
        //     j--;
        // }

        catch(exception& obj){
            cout << *p << obj.what() << endl;
            persoane.erase(j);
            j--;
        }
    }
    cout<<"In vector -----------";
    for(auto p:persoane){
        cout << *p <<endl;
    }
    return 0;
}