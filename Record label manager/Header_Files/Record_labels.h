//example of object pool pattern

class Record_label{
    string nume;
    vector<Musician*> musicians;
    string password;
    // vector<Vinyl*> vinyls_created;
    static int nr_musicians;
    static const int max_musicians = 2; //o sa facem object pool
    int musicians_in_Record_label = 0;
    public:
    Record_label();
    
    //singer, producer, drummer
    template <class T>Record_label& operator+=(T& fc);

    void afisare(vector<Song>& songs);
    void afisare()const;

    ~Record_label(){}
    bool operator==(char*&fc_password);
    string getName();

    template <class T> void add_musician_in_record_label(T& fc);
    
    // Record_label& operator+=(const Vinyl& fc_vinyl);
};
int Record_label::nr_musicians = 0;