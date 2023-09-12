class Jucarii{
protected:
    string denumire, tip;
    int dimensiune;
public:
    Jucarii() = default;
    virtual void citire();
    virtual void afisare();
    string getDenumire();
};

class Clasic : public Jucarii{
    string material, culoare;
public:
    Clasic() = default;
    void citire();
    void afisare() override;
};

class Educativ: virtual public Jucarii{
protected:
    string abilitate;
public:
    Educativ() = default;
    void citire();
    void afisare()  override;
};

class Electronice : virtual public Jucarii {
protected:
    int nr_baterii;
public:
    Electronice() = default;
    void citire();
    void afisare()  override;
};

class Modern : public Educativ, public Electronice {
    string brand, model;
public:
    Modern() = default;
    void citire();
    void afisare()  override;
};
void Jucarii::citire(){cin>>denumire;cin>>tip;cin>>dimensiune;}
void Clasic::citire(){Jucarii::citire();cin>>material;cin>>culoare;}
void Educativ::citire(){Jucarii::citire();cin>>abilitate;}
void Electronice::citire(){Jucarii::citire();cin>>nr_baterii;}
void Modern::citire(){Jucarii::citire();nr_baterii = 1;abilitate = "general";cin>>brand;cin>>model;}

void Jucarii::afisare(){cout<<"denumire/tip/dimensiune "<<denumire<<" "<<tip<<" "<<dimensiune<<" ";}
void Clasic::afisare(){Jucarii::afisare();cout<<"material: "<<material<<" culoare: "<<culoare;}
void Educativ::afisare(){Jucarii::afisare();cout<<"abilitate: "<<abilitate;}
void Electronice::afisare(){Jucarii::afisare();cout<<"nr baterii: "<<nr_baterii;}
void Modern::afisare(){Jucarii::afisare(); cout<<"nr_baterii: "<<nr_baterii<<" abilitate: "<<abilitate<<" brand: "<<brand<<" model: "<<model;}

string Jucarii::getDenumire(){return denumire;}