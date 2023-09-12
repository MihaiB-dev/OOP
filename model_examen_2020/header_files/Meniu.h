class Meniu {
    vector<unique_ptr<Copil>> copii;
    vector<unique_ptr<Jucarii>> jucarii;
    Meniu() {};
    Meniu(Meniu&) {};
    Meniu& operator=(Meniu&){return *this;};
    ~Meniu();

    static Meniu* instanta;
    public:
    static Meniu* get_instanta(){
        if(instanta == nullptr){instanta =  new Meniu();}
        return instanta;
    }

    void citire_copii();
    void afisare_copii();
    void adaugare_jucarii();
    void afisare_jucarii();
    //void gaseste_dupa_nume(string& nume);
    void order_fapte();
    void order_varsta();
    vector<unique_ptr<Jucarii>> getJucarii();

     template<typename T>void adaugare_vector(){
            unique_ptr<T> element (new T());
            element->citire();
            jucarii.push_back(std::move(element));
    }

};
Meniu* Meniu::instanta = NULL;

void Meniu::citire_copii(){
    cout << "1. Citeste copil , 0. Stop";
    bool active;
    cin>>active;
    while(active){

        unique_ptr<Copil> copil(new Copil());
        copil->citire();
        //adaugam jucarii:
        for(int i = 0; i < copil->get_FB(); i++)
        {   
            int j = 1 ;
            int alegere;
            for(auto& jucarie: jucarii){
                cout << j << ". "<<jucarie->getDenumire()<<" ";
            }
            cin>>alegere;
            copil->adaugare_vector(*jucarii[alegere-1]);
        }
        copii.push_back(move(copil));
        cout << "1. Citeste copil , 0. Stop";
        cin>>active;
    }
}

void Meniu::adaugare_jucarii(){
    bool main = true;
    while(main){
        int nr;
        cout << "Alege jucaria "<< " : 1.Clasica, 2.Educativa, 3.Electronica, 4.Moderna, 0.Stop"<<endl<<"Numar: ";cin>>nr;
        switch(nr){
            case 1: {Meniu::adaugare_vector<Clasic>();break;}
            case 2: {Meniu::adaugare_vector<Educativ>();break;}
            case 3: {Meniu::adaugare_vector<Electronice>();break;}
            case 4: {Meniu::adaugare_vector<Modern>();break;}
            case 0: {main = false; break;}
        }
    }
    
}

void Meniu::afisare_copii(){
    for(auto& copil: copii){
        copil->afisare();
        cout<<endl;
    }
}

void Meniu::afisare_jucarii(){
    for(auto& jucarie: jucarii){
        jucarie->afisare();
        cout<<endl;
    }
}

// void Meniu::gaseste_dupa_nume(string& nume){
//     for(auto& copil: copii){
//         int counter = 0;
//         while()
//         if(strstr(nume, copil->getNume()))copil->afisare();
//     }
// }

void Meniu::order_fapte(){
    sort(copii.begin(), copii.end(),
     [](unique_ptr<Copil> &copil1,unique_ptr<Copil>& copil2){return copil1->getFapte() < copil2->getFapte();});
}

void Meniu::order_varsta(){
        sort(copii.begin(), copii.end(),
     [](unique_ptr<Copil> &copil1,unique_ptr<Copil>& copil2){return copil1->getVarsta() < copil2->getVarsta();});
}