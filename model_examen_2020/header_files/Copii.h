class Copil {
    string nume, prenume, adresa;
    int varsta;
    int ID;
    int nr_fapte_bune;
    vector<Jucarii*> jucarii_copil;

    static int increment;
public:
    Copil(){ID = increment; increment ++;}
    void citire();
    void afisare();
    string getNume(){return nume;}
    int getVarsta(){return Varsta;}
    int getFapte(){return nr_fapte_bune;}
    int get_FB(){return nr_fapte_bune;}


    template<typename T>void adaugare_vector(T jucarie){
    jucarii_copil.push_back(&jucarie);
    }
};
int Copil::increment = 1;

// template<typename T>
// void adaugare_vector(){
//     unique_ptr<T> element (new T());
//     element->citire();
//     Jucarii_copil.push_back(std::move(element));
// }
void Copil::citire() {
    cin>>nume>>prenume>>adresa>>varsta>>nr_fapte_bune;
}

void Copil::afisare(){
    cout<<"Nume: "<<nume<<endl;
    cout<<"prenume: "<<prenume<<endl;
    cout<<"adresa: "<<adresa<<endl;
    cout<<"varsta: "<<varsta<<endl;
    cout<<"Nr_fapte_bune"<<nr_fapte_bune<<endl;
}