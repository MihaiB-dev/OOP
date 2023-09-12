void Produse::citire(){
    cout<<"Pret: ";cin>>pret;
    cout<<"cantitate: ";cin>>cantitate;
    
}
void Carti::citire(){
    Produse::citire();
    cout<<"Titlu: ";cin>>titlu;
    string actor;
    
    bool alegere = true;
    
    while(alegere){
        cout<<"Actor: ";
        cin>>actor;
        actori.push_back(actor);
        cout<<endl<<"Mai vreu unul? Da 1, NU 0"<<endl;cin>>alegere;
    }
}
void DVD::citire(){
    Produse::citire();
    cout<<"Minute: ";cin>>nr_minute;
}
void DVD_muzica::citire(){
    DVD::citire();
    cin>>nume_album;
    bool alegere = true;
    string interpret;
    
    while(alegere){
        cout<<"interpret: ";
        cin>>interpret;
        interpreti.push_back(interpret);
        cout<<endl<<"Mai vreu unul? Da 1, NU 0"<<endl;cin>>alegere;
    }
}

void DVD_filme::citire(){
    DVD::citire();
    cout<<"Nume: ";cin>>nume;
    cout<<"Gen: ";cin>>gen;
}

void ob_de_colectie::citire(){
    Produse::citire();
    cout<<"Denumire";cin>>denumire;
}

void figurina::citire(){
    ob_de_colectie::citire();
    cout<<"Categorie: ";cin>>categorie;
    cout<<"brand: ";cin>>brand;
    cout<<"material: ";cin>>material;
}

void poster::citire(){
    ob_de_colectie::citire();
    cout<<"Format: ";cin>>format;

}

void Produse::afisare(){
    cout<<"ID"<<ID<<" Pret: "<<pret<<" "<<"Cantitate: "<<cantitate<<" ";
}
void Carti::afisare(){
    Produse::afisare();
    cout<<"Titlu: "<<titlu<<" Autor(i): ";
    for(auto& actor:actori){cout<<actor<<" ";}
}
void DVD::afisare(){
    Produse::afisare();
    cout<<"Minute: "<<nr_minute;
}
void DVD_muzica::afisare(){
    DVD::afisare();
    cout<<"nume_album: "<<nume_album<<" Interpret(i): ";
    for(auto& interpret:interpreti){cout<<interpret<<" ";}
}
void DVD_filme::afisare(){
    DVD::afisare();
    cout<<"nume: "<<nume<<" Gen: "<<gen;
}
void ob_de_colectie::afisare(){
    Produse::afisare();
    cout<<"Denumire: "<<denumire;

}

void figurina::afisare(){
    ob_de_colectie::afisare();
    cout<<"Categorie: "<<categorie<<" Brand: "<<brand<<" Material: "<<material;
}

void poster::afisare(){
    ob_de_colectie::afisare();
    cout<<"Format: "<<format;
}