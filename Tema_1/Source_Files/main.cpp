
#include "../Header_Files/fisa.h"

int main(){
    Sofer s1("Zugravu","Alexandra"),s2("Dobrin","Ionut"),s3("Stoica","Cristian"),s4("Payam","Erdeem"); //initializarea soferilor cu valori num, prenume
    Sofer list_soferi[5];

    Masina m4;
    cout << "Creati-va masina:"<<endl;
    cin >> m4; //se citeste doar numarul masinii, restul fiind initializate null

    cout<<endl;

    cout<< "Creati-va soferul:"<<endl;
    cin>>list_soferi[0];  //citirea unui sofer
    
    list_soferi[1] = s1; //supraincarcarea operatorului de egal
    list_soferi[2] = s2;
    list_soferi[3] = s3;
    list_soferi[4] = s4;
    
    // cout << "Succes: Soferul "<< s2[0] << "a fost salvat"<<endl;

    m4 += list_soferi[0]; //adaguarea soferului create la masina creata
    cout<< endl << "Ati creat cu succes masina: "<< m4<<endl;

    for( int x=0; x<5; x++) cout<<"Soferul "<<x+1<<" este: "<< list_soferi[x]; //se afiseaza toti soferii

    Masina m1("B 23 ABC"),m2("B 10 DEF",2,list_soferi),m3(m1);
    m3 += s1;
    m3 += list_soferi[0];

    cout << endl;

    if (m2 == m3) // cele 2 masini sunt egale desi ordinea soferilor este diferita.
    {
        cout<< "masinile: " << m2.getNr() << " si "<< m3.getNr()<<" sunt conduse de acceasi soferi."<<endl; // afiseaza mesaj “masinile” m1 “si” m2 sunt conduse de aceiasi soferi.
    }
    cout << endl;

    cout<< m2 <<endl << m3<<endl; //se afiseaza masina

    Fisa f1(1,m4), f(2,"B 59 XYZ",1,"Popescu","George"); //soferii pot fi initializati in 2 moduri
    f1+=s1; f1+=s2; f1+=s3; f1+=s4; //adauga soferul s1,s2,s3,s4 masinei din fisa f1
    if (f1 > f) cout << "Masina de pe fisa 1 are mai multi soferi asignati"<<endl;
    cout << "Fisa " << f1<<endl; //se afiseaza fisa
    cout<< "Fisa " << f << endl;

    return 0;
}