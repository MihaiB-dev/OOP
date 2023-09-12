#include "Record_labels.h"
Record_label::Record_label(){
    cout << "Nume: ";
    getline(cin,nume);
    musicians.resize(max_musicians);
    char *tmp_password = getpass("\033[34mCreate password: \033[00m");
    password = tmp_password;
    cout<<"\033[1;32mSuccesfully created the record label : "<<nume<<"\033[00m"<<endl;
    // vinyls_created = {};
}

template <class T>
void Record_label::add_musician_in_record_label(T& fc){
    bool ok = 0;
    for(auto& muzician : musicians)
    {
        if(muzician == nullptr){
            muzician = &fc;
            musicians_in_Record_label ++;
            nr_musicians ++;
            ok = 1;
            break;
            }
    }
    if(ok == 0){throw(999);}
}  

template <class T>
Record_label& Record_label::operator+=(T& fc){

    //add a function to add a musician in record label.
    add_musician_in_record_label(fc);
    //musicians_in_Record_label ++;
    //musicians.push_back(&fc);
    //nr_musicians ++;
    return *this;
};

void Record_label::afisare()const{
    for(auto p = musicians.begin(); p != musicians.end();p++ )
    {
        cout << (*p)->GetType();
    }
}

bool Record_label::operator==(char*& fc_password){
    string fc_tmp_password = fc_password;

    if(password == fc_tmp_password){
        return true;
    } else {return false;}
}

// ostream& operator<<(ostream& os, Record_label& record_label)
void Record_label::afisare(vector<Song>& songs){
    cout<<endl<<"Record label -> "<<nume<<endl;
    if(nr_musicians > 0)
    {
        cout<<"Total musicians:"<<nr_musicians<<endl;
    }else {cout<<"There are no musicians yet."<<endl;}
    if(musicians.size() > 0)
    {   
        
        vector<singer> singers;
        vector<producer> producers;
        vector<drummer> drummers;
        for(auto& musician : musicians)
        {
            if(musician != nullptr)
            {
                if(typeid(*musician) == typeid(singer)) singers.push_back(*dynamic_cast<singer*>(musician));
                if(typeid(*musician) == typeid(producer)) producers.push_back(*dynamic_cast<producer*>(musician));
                if(typeid(*musician) == typeid(drummer)) drummers.push_back(*dynamic_cast<drummer*>(musician));
            }  
        }
        if(singers.size() > 0)
        {   
            cout<<endl<<"Singers:"<<endl<<endl;
            int i = 1;
            for(auto& singer : singers)
            {
                cout<<i<<". ";
                singer.afisare();

                int nr_songs = 1;
                for(auto& song : songs)
                {
                    if(song.getMusician() == singer.GetName()){
                        cout<<"  "<<nr_songs<<". ";
                        song.afisare(); 
                        nr_songs++;
                        cout<<endl;
                    }
                }
                i++;
            }
        }
        if(producers.size() > 0)
        {
            cout<<endl<<"Producers:"<<endl<<endl;
            int i = 1;
            for(auto& producer : producers)
            {
                cout<<i<<". ";
                producer.afisare();
                int nr_songs = 1;
                for(auto& song : songs)
                {
                    if(song.getMusician() == producer.GetName()){
                        cout<<"  "<<nr_songs<<". ";
                        song.afisare();
                        nr_songs++;
                        cout<<endl;
                    }
                    
                }
                i++;
            }
        }
        if(drummers.size() > 0)
        {   
            cout<<endl<<"Drummers:"<<endl<<endl;
            int i = 1;
            for(auto& drummer : drummers)
            {
                cout<<i<<". ";
                drummer.afisare();
                int nr_songs = 1;
                for(auto& song : songs)
                {
                    if(song.getMusician() == drummer.GetName()){
                        cout<<"  "<<nr_songs<<". ";
                        song.afisare(); 
                        nr_songs++;
                        cout<<endl;
                    }
                    
                }
                i++;
            }
        }
    }
    cout<<endl;
}

string Record_label::getName(){
    return nume;
}