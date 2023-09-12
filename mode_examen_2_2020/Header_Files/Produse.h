class Produse {
protected:
    int pret;
    int cantitate;
    int ID;
    static int incrementare;
public:
    Produse(){ID = incrementare; incrementare++;}
    virtual void citire() = 0;
    virtual void afisare() = 0;
    int getPrice(){return pret;}
    int getCantitate(){return cantitate;}
    int getID(){return ID;}

};
int Produse::incrementare = 1;

class Carti : public Produse{
    string titlu;
    vector<string> actori;
public:
    void citire();
    void afisare();
};

class DVD : public Produse {
protected:
    int nr_minute;
public:
    void citire();
    void afisare();
};

class DVD_muzica : public DVD {
    string nume_album;
    vector<string> interpreti;
public:
    void citire();
    void afisare();
};

class DVD_filme : public DVD {
    string nume, gen;
public:
    void citire();
    void afisare();
};

class ob_de_colectie : public Produse {
protected:
    string denumire;
public:
    void citire();
    void afisare();
};

class figurina : public ob_de_colectie {
    string categorie, brand, material;
public:
    void citire();
    void afisare();
};

class poster : public ob_de_colectie {
    string format; //A3 A4
public:
    void citire();
    void afisare();
};

#include "Produse.hpp"