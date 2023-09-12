class Musician{
    protected:
    string name;
    int anul_nasterii;
    string contract; //record_label + " " + "start date: " when he got in.
    bool free;
    public:
    // Musician(){name = ""; anul_nasterii = 0; contract = ""; free = 1;}
    // bool iffree(){if(free == true)return true; return false;}
    virtual string citire() = 0;
    virtual string GetType()const = 0;
    virtual void afisare()const = 0;
    string GetName();
    virtual ~Musician(){};  
};

class singer : public Musician {
    string cv; // a link to a cv.
    public:
    string citire();
    string GetType()const;
    void afisare()const;
    void setSinger(singer& fc_singer);
};

class producer : public Musician {

    string abilities; // cu ce e special acest producer fata de restul.
    public:
    string citire();
    string GetType()const;
    string get_abilities();
    void afisare()const;
    void setproducer(producer& fc_producer);
};

class drummer : public Musician {

    string drum; //ce tobe foloseste.
    public:
    string citire();
    string GetType()const;
    string get_drum();
    void afisare()const;
    void setdrummer(drummer& fc_drummer);
};