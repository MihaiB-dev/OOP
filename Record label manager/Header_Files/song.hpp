#include "song.h"

istream& operator>>(istream& os, Duration& duration)
{
    cout<<"Duration:\n minutes: ";os>>duration.minutes;
    cout<<" seconds: ";os>>duration.seconds;

    duration.time = duration.minutes + " : " + duration.seconds;

    return os;
}
ostream& operator<<(ostream& os, Duration& duration){
    os<<duration.time;
    return os;
}
string Song::citire()
{
    cout<<"Add a title: ";getline(cin,title);
    cout<<"Add the main musician: ";getline(cin,main_musician);
    cin>>duration;

    return main_musician;
}

string Song::getMusician(){
    return main_musician;
}


void Song::afisare()
{
    cout<<title<<endl;
    cout<<"   -duration: "<<duration;
}