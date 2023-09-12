class Bilet{
string statia_de_plecare;
string statia_de_sosire;

string data;
string ora;

int cod_tren;

int durata;
int distanta;
double pret; //calculat automat
static int ID const;
public:

void eliberare();
};
ID = 1;

void Bilet::eliberare(){
    cout << "statia de plecare: ";
    fin >> statia_de_plecare;
    cout << "statia_de_sosire: ";
    fin >> statia_de_sosire;
    cout << "Data: ";
    fin >> data;
    cout << "Ora: ";
    fin >> ora;
    cout << "Durata: ";
    fin >> durata;
    cout << "cod_tren: ";
    fin >> cod_tren;
    cout <<"durata: ";
    fin >> durata;
    cout <<"distanta: ";
    fin >> distanta;

    cout <<"Tren regio = 1; Tren inter-regio = 2";
    short tip_tren;
    fin >> tip_tren;
    if(tip_tren == 1){
        
    }

    ID ++;
}

