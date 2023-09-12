//example of factory design pattern.
class PlayList{
protected:
    string musician_name;
    vector<Song*> songs_playlist;
    int total_minutes = 0;
    int total_seconds = 0;
public:
    virtual void afisare() = 0;
    void add_song(Song& song);
    string GetName();

};

class All_songs_Playlist : public PlayList{
    string tip;
    public:
        All_songs_Playlist(const string musician, vector<Song*> songs);
        void afisare();
};

class Random_Playlist : public PlayList {
    string tip;
    public:
        Random_Playlist(const string musician, vector<Song*> songs);
        void afisare();
};

#include "Playlist.hpp"