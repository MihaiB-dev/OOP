class Duration{
    string time;
    string minutes;
    string seconds;
    public:
    friend istream& operator>>(istream& os, Duration& duration);
    friend ostream& operator<<(ostream& os, Duration& duration);
    int getMinutes(){return stoi(minutes);}
    int getSeconds(){return stoi(seconds);}
    ~Duration(){};

};

class Song{
    string title;
    string main_musician;
    // vector<Musician*> other_musicians;
    Duration duration;
    public:
    string citire();
    // friend istream& operator>>(istream& os, Song& song);
    string getMusician();
    string getTitle(){return title;}
    void afisare();
    ~Song(){};
    int getMinutes(){return duration.getMinutes();}
    int getSeconds(){return duration.getSeconds();}
};