/***
candidatii au nume, serie buletin

300 locuri la Info IF, 100 locuri la CTI, 150 locuri la Mate si 75 locuri la Info ID
- La Mate - 2 subiecte de mate
- La Info - 1 subiect mate si 1 subiect info
- LA CTI - 1 subiect fizica si 1 subiect mate
- la Info ID - INTERVIU

Media = 80%examen + 20%bac (IF)
Media ID = 60% interviu + 40%bac

nr de inregistrare candidat, creste automat si exista un cod, de forma Mate_x, Info_IF_x, CTI_x sau ID_x trecut pentru fiecare dosar
un candidat poate depune dosar de inscriere la toate cele 4 forme de invatamant / sectiuni de admitere

se cere:
- exportul listelor de inscriere, in ordinea completarii dosarelor
- listele de inscrisi - pe fiecare sectiune in parte
- listele de admisi pe fiecare sectiune
- a afiaa toti candidatii care s-au inscris la ambele forme de invatamant (IF si ID) si au fost declarati admisi macar la una
*/
#include <iostream>
#include <vector>
#include <string>
#include <memory>
using namespace std;
class Candidat {
protected:
    string nume;
    string serie_buletin;
    string cod;
    double bac;
    double mate1;
    static int nr_candidati;
public:
    virtual void citire() = 0;
    virtual void afisare() = 0;

};

int Candidat::nr_candidati = 0;

class IF : public Candidat {
    double info;
public:
    void citire();
    void afisare();
    IF(){cod = "Info_IF_" + to_string(nr_candidati); nr_candidati++;};
};
class Mate : public Candidat {
    double mate2;
public:
    void citire();
    void afisare();
    Mate(){cod = "Mate_" + to_string(nr_candidati); nr_candidati++;};
};
class CTI : public Candidat {
    double fizica;
public:
    void citire();
    void afisare();
    CTI(){cod = "CTI_" + to_string(nr_candidati); nr_candidati++;};
};
class ID : public Candidat {
    double interviu;
public:
    void citire();
    void afisare();
    ID(){cod = "ID_" + to_string(nr_candidati); nr_candidati++;};
};
void Candidat::citire(){
    cout<<"Nume: "; cin>>nume;
    cout<<"Serie buletin: "; cin>>serie_buletin;
    cout<<"Bac: "; cin>>bac;
    cout<<"Mate 1: "; cin>>mate1;
}
void IF::citire(){
    Candidat::citire();
    cout<<"Info: "; cin>>info;
}
void Mate::citire(){
    Candidat::citire();
    cout<<"Mate 2: "; cin>>mate2;
}
void CTI::citire(){
    Candidat::citire();
    cout<<"Fizica: "; cin>>fizica;
}
void ID::citire(){
    Candidat::citire();
    cout<<"Interviu: "; cin>>interviu;
}

void Candidat::afisare(){
    cout<<"Nume: "<<nume<<endl;
    cout<<"Serie buletin: "<<serie_buletin<<endl;
    cout<<"Bac: "<<bac<<endl;
    cout<<"Mate 1: "<<mate1<<endl;
}
void IF::afisare(){
    Candidat::afisare();
    cout<<"Info: "<<info<<endl;
}
void Mate::afisare(){
    Candidat::afisare();
    cout<<"Mate 2: "<<mate2<<endl;
}
void CTI::afisare(){
    Candidat::afisare();
    cout<<"Fizica: "<<fizica<<endl;
}
void ID::afisare(){
    Candidat::afisare();
    cout<<"Interviu: "<<interviu<<endl;
}


class Meniu {
    vector<unique_ptr<Candidat>> candidati;
    Meniu() {};
    Meniu(Meniu&) {};
    Meniu& operator= (Meniu&) {return *this;};
    ~Meniu() {};
    static Meniu* instanta;
public:
    static Meniu* get_instanta() {
        if(instanta == NULL){instanta = new Meniu();}
        return instanta;
    }
    void citire();
    void afisare();
};
Meniu* Meniu::instanta = NULL;

void Meniu::citire(){
    cout<<"1. IF, 2. Mate, 3. CTI, 4. ID"<<endl;
    int  optiune;
    cin>>optiune;
    switch (optiune)
    {
        case 1: { 
            unique_ptr<Candidat> new_IF(new IF());
            candidati.push_back(move(new_IF)); break;}
        case 2: { 
            unique_ptr<Candidat> new_Mate(new Mate());
            candidati.push_back(move(new_Mate)); break;}
        case 3: { unique_ptr<Candidat> new_CTI(new CTI());
            candidati.push_back(move(new_CTI)); break;
            }
        case 4: { unique_ptr<Candidat> new_ID(new ID());
            candidati.push_back(move(new_ID)); break;
            }
    }
    candidati.back()->citire();
}

void Meniu::afisare(){
    for(auto& candidat : candidati){
        candidat->afisare();
    }
}


int main(){
    cout<<"Bine ai venit pe aplicatie"<<endl<<endl;
    Meniu* meniu = Meniu::get_instanta();
    
    bool nr_citire = true;
    while(nr_citire){
        cout<<"1. Citire date, 2. Afisare date, 0.Oprire"<<endl;
        int optiune;
        cin>>optiune;
        switch (optiune)
        {
        case 1:{ meniu->citire(); break;}
        case 2: { meniu->afisare(); break;}
        case 0 : {nr_citire = false; break;}
        }
    }
}