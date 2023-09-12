class Meniu {

    vector<unique_ptr<Produse>> produse;
    Meniu(){};
    Meniu(Meniu&){};
    Meniu& operator=(Meniu&){return *this;}
    ~Meniu(){};
    static Meniu* instanta;
    public:
    static Meniu* get_instanta(){
        if(instanta == nullptr){instanta = new Meniu();}
        return instanta;
    }

    template <typename T>
    void inserare_produs(){
        unique_ptr<T> element( new T());
        element->citire();
        produse.push_back(move(element));
    }
    void inserare();
    void afisare();
    void editare();
    void Ordonare_pret();
    void celMaiMare();
};

Meniu* Meniu::instanta = NULL;

#include "Meniu.hpp"