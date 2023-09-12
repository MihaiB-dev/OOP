//change live the time
void PlayList::add_song(Song& song){
    songs_playlist.push_back(&song);
    total_minutes += song.getMinutes();
    total_seconds += song.getSeconds();
    if (total_seconds > 60)
    {
        total_minutes++;
        total_seconds %=60;
    }
}

All_songs_Playlist::All_songs_Playlist(const string musician, vector<Song*> songs){
    musician_name = musician;
    tip = "All_songs_Playlist";
    for(auto& song : songs)add_song(*song);
    
}

Random_Playlist::Random_Playlist(const string musician, vector<Song*> songs){
    tip = "Random_Playlist";
    musician_name = musician;
    for(auto& song : songs){
        int b = (std::rand())%2;
        if(b)add_song(*song);
    }
}

void All_songs_Playlist::afisare(){
    cout << tip << " "<<endl;
    for(auto& song: songs_playlist)
    {
        cout << song->getTitle() << " ";
    }
    cout <<endl<<"minutes:seconds "<<total_minutes<<":"<<total_seconds<<endl;
}

void Random_Playlist::afisare(){
    cout <<"Type: "<< tip << " "<<endl<<"Songs: ";
    for(auto& song: songs_playlist)
    {
        cout << song->getTitle() << " ";
    }
    cout <<endl<<"minutes:seconds "<<total_minutes<<":"<<total_seconds<<endl;
}

string PlayList::GetName(){return musician_name;}