#include <stdio.h>
#include <unistd.h>
#include<ios> //used to get stream size
#include<limits> //used to get numeric limits
void Meniu::add_record_label()
{
    record_labels.push_back(Record_label());
}


//should add the passwords.
template <class T>
unique_ptr<T> Meniu::f(){
    unique_ptr<T> ptr (new T());
    string record_label = ptr->citire();
    for(auto &p : record_labels)if(p.getName() == record_label)
    {   
        char* password;
        password = getpass("\033[34mEnter record labels password: \033[00m");

        if(p == password)
        {
            p+=*(ptr);
            return ptr;
        } else {throw(111);} //the password is incorrect

    }
    //nu a fost gasit un record label deci nu va fi returnat nimic, atunci nu se va pune in vector.
    throw(10); // the record label is incorrect.
    return nullptr;
    }


void Meniu::add_musician()
{   
    int musician_number;
    cout << "---------------------------------------------\n";
    cout << "|Locatie: meniu_principal -> add -> musician|\n";
    cout << "---------------------------------------------\n";
    cout << "singer = 1, producer = 2, drummer = 3, close = 0 : ";
    cin>>musician_number;
    switch(musician_number)
    {
        case 1: {//verifica daca exista un record label in care sa fie cantaretul, daca nu va da eroare si se va relua procesul.
            unique_ptr<singer> ptr_singer = Meniu::f<singer>();
            if(ptr_singer)
            {musicians.push_back(std::move(ptr_singer)); break;}        
            }
        case 2: {
            unique_ptr<producer> ptr_producer = Meniu::f<producer>();
            if(ptr_producer)
            {musicians.push_back(std::move(ptr_producer)); break;}    
            }
        case 3: {
            unique_ptr<drummer> ptr_drummer = Meniu::f<drummer>();
            if(ptr_drummer)
            {musicians.push_back(std::move(ptr_drummer)); break;}
        }
        case 0: {
            break;
        }
    }   
}

void Meniu::add_song(){

    Song song;
    string main_musician = song.citire();
    bool ok = false;
    for(auto p = musicians.begin(); p != musicians.end(); p++)if(main_musician == (*p)->GetName()){songs.push_back(song); ok = true;}

    if(ok == false)throw(20);
}

void Meniu::create_playlist(){
    if(musicians.size() == 0)throw(902);
    cout << "---------------------------------------------\n";
    cout << "|Locatie: meniu_principal -> add -> playlist|\n";
    cout << "---------------------------------------------\n";
    cout << "Choose one of the musicians: ";
    int x = 1;
    for(auto& musician : musicians)
    {
        cout << musician->GetName() << " = " << x << ", ";
        x++;
    }
    cout<<endl<<"Close = 0"<<endl<<"Numar: ";
    cin>>x;
    if(x == 0){return;}
    //get the songs from the musician
    vector<Song*> musician_songs;
    for(auto &song : songs)
    {
        if(song.getMusician() == musicians[x-1]->GetName()){
            musician_songs.push_back(&song);
        };
    }
    bool type_playlist;
    cout <<endl<< "All_songs_Playlist = 0 or Random_Playlist = 1 ? ";cin >>type_playlist;
    if(!type_playlist)
    {
        playList.push_back(new All_songs_Playlist(musicians[x-1]->GetName(), musician_songs));
    } else 
    {
        playList.push_back(new Random_Playlist(musicians[x-1]->GetName(), musician_songs));
    }
    cout<<endl<<"\033[1;32m Playlistul a fost creat cu succes\033[00m"<<endl;
    //facem design pattern de factory.
}
void Meniu::add_function(){
    int meniu_add = 1;
    while(meniu_add)
    {   
        int add_nr;
        cout<<"---------------------------------\n";
        cout<<"|Locatie: meniu_principal -> add|\n";
        cout<<"---------------------------------\n";
        cout<<"Add Record Label = 1\nAdd musician = 2\nAdd a song = 3\nCreate a playlist = 4 \033[1;32m(New)\033[00m\nback = 0\n";
        cout<<"Numar: ";

        try
        {
            if(cin>>add_nr) switch(add_nr)
            {   
                case 1:{cin.ignore(numeric_limits<streamsize>::max(), '\n');Meniu::add_record_label();break;}
                case 2:{cin.ignore(numeric_limits<streamsize>::max(), '\n');Meniu::add_musician();break;}
                case 3:{cin.ignore(numeric_limits<streamsize>::max(), '\n');Meniu::add_song();break;}
                case 4:{cin.ignore(numeric_limits<streamsize>::max(), '\n');Meniu::create_playlist();break;}
                // case 4:{
                //     // add_vinyl(vinyl)
                // }
                case 0:{meniu_add = 0;}

            } else {throw(400);break;}
            
        }
        catch(int n) //aici prindem toate erorile.
        {
            if(n == 10)
            {
                cout <<"\x1B[33mError: Invalid record_label, make sure to write properly the name of the record label, or add one.\033[0m\t \n\n";break;
            }
            else if (n == 20)
            {
                cout << "\x1B[33m Error: The musician doesn't exist, make sure you write it well or create a musican\033[0m\t \n\n";break;
            }
            else if (n == 400)
            {
                cout<<"\x1B[33m Error , The input is invalid , try again\033[0m\t\n";break;
            }
            else if (n == 111)
            {
                cout<<"\x1B[33m The passowrd is incorrect.\033[0m\t\n";
            }
            else if(n == 999)
            {
                cout<<"\x1B[33m A Record Label can has a maxim number of muscians of 2.\033[0m\t\n";
            }
            else if(n == 902)
            {
                cout<<"\x1B[33m Nu exista cantareti, creati unul.\033[0m\t\n";
            }
            

        }
    }
}

void Meniu::see_record_label(){
    if(record_labels.size() == 0)throw(900);

    cout<<"--------------------------------------------------------\n";
    cout<<"|Locatie: meniu principal->details about a record label|\n";
    cout<<"--------------------------------------------------------\n";
    cout<<"alegeti unul din urmatoarele Record labels:\n";
    int x = 1;
    for(auto p = record_labels.begin(); p != record_labels.end(); p++)
    {
        cout << (*p).getName() << " = "<< x<<", ";
        x ++;
    }
    cout<<"\nNumar: ";
    cin>>x;

    char* password;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    password = getpass("\033[34mEnter record labels password: \033[00m");
    if(record_labels[x-1] == password)
    {
        record_labels[x-1].afisare(songs);
    }else {throw(111);}
}

void Meniu::see_playlist(){
    if(playList.size() == 0)throw(901);
    cout<<"-----------------------------------------\n";
    cout<<"|Locatie: meniu principal->see playlists|\n";
    cout<<"-----------------------------------------\n";
    cout<<"alegeti unul din urmatorii muzicieni:\n";
    int x = 1;
    for(auto& playlist_local : playList)
    {
        cout << playlist_local->GetName() << " = " << x << ", ";
        x++;
    }
    cout<<endl<<"Numar: ";
    cin>>x;
    playList[x-1]->afisare();
}