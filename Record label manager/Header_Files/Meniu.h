//example of singleton pattern

class Meniu {

    vector<Record_label> record_labels = {};
    vector<unique_ptr<Musician>> musicians = {};
    vector<Song> songs = {};
    vector<PlayList*> playList= {};

    Meniu () {};
    Meniu(Meniu&) {};
    Meniu& operator= (Meniu&) {return *this;};
    ~Meniu() {};
    static Meniu* instanta ;
public:
    static Meniu* get_instanta() {
        if(instanta == NULL){instanta = new Meniu();}
        return instanta;
    }
    //punem toate functiile care le folosim in main aici.
    void add_record_label();

    template<class T> unique_ptr<T> f(); //example of function template
    void add_musician();
    void add_song();
    void add_function();
    void see_record_label();
    void create_playlist();
    void see_playlist();

};
Meniu* Meniu::instanta = NULL;
#include "Meniu.hpp"