#include "musician.h"
#include <ctime>
string singer::GetType()const
{
    return "singer";
}

string producer::GetType()const
{
    return "producer";
}

string drummer::GetType()const
{
    return "drummer";
}


string Musician::citire(){
    string record_label;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout<<"Nume: ";getline(cin,name);
    cout<<"Anul Nasterii: ";cin>>anul_nasterii;
    cin.ignore(1,'\n');
    cout<< "Record Label: ";getline(cin,record_label);
    
    time_t now = time(0);
    char * dt = ctime (&now);

    contract = record_label + " start date: " + dt;

    return record_label;
}

string singer::citire()
{
    string record_label = Musician::citire();
    cout<<"cv: ";getline(cin,cv);

    return record_label;
}

string producer::citire()
{
    string record_label = Musician::citire();
    cout<<"abilities: ";getline(cin,abilities);

    return record_label;
}

string drummer::citire()
{
    string record_label = Musician::citire();
    cout<<"drum: ";getline(cin,drum);

    return record_label;
}



string producer::get_abilities()
{
    return abilities;
}

string drummer::get_drum()
{
    return drum;
}

string Musician::GetName()
{
    return name;
}

//setSinger, setPrducer, setDrummer

void singer::setSinger(singer& fc_singer){ // special setter
    name = fc_singer.name;
    anul_nasterii = fc_singer.anul_nasterii;
    contract = fc_singer.contract;
    free = 0;
    cv = fc_singer.cv;
}

void producer::setproducer(producer& fc_producer){ // special setter
    name = fc_producer.name;
    anul_nasterii = fc_producer.anul_nasterii;
    contract = fc_producer.contract;
    free = 0;
    abilities = fc_producer.abilities;
}

void drummer::setdrummer(drummer& fc_drummer){ // special setter
    name = fc_drummer.name;
    anul_nasterii = fc_drummer.anul_nasterii;
    contract = fc_drummer.contract;
    free = 0;
    drum = fc_drummer.drum;
}


void Musician::afisare()const
{
    cout<<name<<":"<<endl;
    cout<<" -anul nasterii: "<<anul_nasterii<<endl;
    cout<<" -contract: "<<contract;
}

void singer::afisare()const
{
    Musician::afisare();

    cout<<" -cv: "<<cv<<endl;
}

void producer::afisare()const
{
    Musician::afisare();
    cout<<" -abilities: "<<abilities<<endl;
}

void drummer::afisare()const
{
    Musician::afisare();
    cout<<" -drum: "<<drum<<endl;
}