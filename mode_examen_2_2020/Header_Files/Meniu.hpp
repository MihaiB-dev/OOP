void Meniu::inserare(){
    int numar;
    cout<<"Carte = 1, DVD = 2, DVD muzica = 3, DVD_filme = 4, Obiecte de colectie = 5, figurina = 6, poster = 7"<<endl<<"NUmar: ";
    cin>>numar;
    switch(numar){
        case 1: {inserare_produs<Carti>();break;}
        case 2: {inserare_produs<DVD>();break;}
        case 3: {inserare_produs<DVD_muzica>();break;}
        case 4: {inserare_produs<DVD_filme>();break;}
        case 5: {inserare_produs<ob_de_colectie>();break;}
        case 6: {inserare_produs<figurina>();break;}
        case 7: {inserare_produs<poster>();break;}
    }
}

void Meniu::afisare(){
    cout<<endl;
    for(auto& produs : produse){
        produs->afisare();
        cout<<endl;
    }
}

void Meniu::editare(){
    //afisam toate id-urile si sa aleaga unul din ele;
    int id;
    cout<<"Alege din urmatoarele produse (ID) : ";
    for(int i = 1; i <= produse.size(); i++){
        cout<<i<<", ";
    }
    cin>>id;
    for(auto& produs: produse){
        if(id == produs->getID()){
            produs->afisare();
            cout<<endl;
            produs->citire();
        }
    }
}
void Meniu::Ordonare_pret(){
    sort(produse.begin(), produse.end(),[](unique_ptr<Produse>& el1, unique_ptr<Produse>& el2){return el1->getPrice() < el2->getPrice();});
}

void Meniu::celMaiMare(){
    int cantitate = 0;
    for(auto& produs: produse){
        if(produs->getCantitate() > cantitate){
            cantitate = produs->getCantitate();
        }
    }
    for(auto& produs: produse){
        if(produs->getCantitate() == cantitate){
            produs->afisare();
            cout<<endl;
        }
    }
}