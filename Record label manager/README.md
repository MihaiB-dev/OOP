# Record label app

## Elements : 
### Record Label:
- nume
- password
- lista cu Musicieni inscrisi in Record Label
### Musician:
- name
- anul nasterii
- contract formmat din record_label + " " + "start date: " when he got in
- pentru singer : cv
- pentru producer : abilties
- pentru drummer : drum
### Song
- title
- musician
- duration : minutes, seconds, time = minutes + " : " + seconds

(!observatii!)
- se poate adauga un musician daca este scris un record label curent, si este nevoie de parola
- se poate adauga o melodie la un musician existent
- atunci cand se afiseaza record label-ul, va trebui sa fie scrisa parola.

## Usage: 

### Main page:
![main page picture](/Tema_2/pictures/main_page.png)

### Add Objects:
![add page picture](/Tema_2/pictures/add_page.png)

## Example of inputs:

### Add Record Label:
![add record label](/Tema_2/pictures/record_label.png)

### Add Musician:
![add musician](/Tema_2/pictures/add_musician.png)

### Add song:
![add song](/Tema_2/pictures/add_song.png)

## Features used :

<details>
  <summary>mosteniri</summary>
  
  ```cpp
  //location: Header_Files -> musician.h
class Musician{}; //base class

class singer : public Musician {};//derived class

class producer : public Musician {};//derived class

class drummer : public Musician {};//derived class

  ```
</details>

<details>
  <summary>funcții virtuale (pure)</summary>
  
  ```cpp
  //location: Header_Files -> musician.h
  //summary of the code !
class Musician{
    public:
    virtual string citire() = 0;
    virtual string GetType()const = 0;
    virtual void afisare()const = 0;
    
};
class singer : public Musician {
    public:
    string citire();
    string GetType()const;
    void afisare()const;
};

class producer : public Musician {

    public:
    string citire();
    string GetType()const;
    void afisare()const;
};

class drummer : public Musician {

    string drum; //ce tobe foloseste.
    public:
    string citire();
    string GetType()const;
    void afisare()const;
};
  ```
</details>

<details>
  <summary>pointerii la clasa de bază + apelarea constructorului din clasa de bază</summary>
  
  ```cpp
  //location: main.cpp
vector< unique_ptr<Musician>> musicians = {};

musicians.push_back(std::move(ptr_singer));

musicians.push_back(std::move(ptr_producer));

musicians.push_back(std::move(ptr_drummer));

  ```
</details>

<details>
  <summary>smart pointers</summary>
  
  ```cpp
  //location: main.cpp

unique_ptr<singer> f1(vector<Record_label>& record_labels){
    unique_ptr<singer> ptr (new singer());
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

unique_ptr<singer> ptr_singer = f1(record_labels);
if(ptr_singer)
{musicians.push_back(std::move(ptr_singer)); break;}        
    
  ```
</details>

<details>
  <summary>dynamic cast</summary>
  
  ```cpp
  //location: Header_Files -> Record_labels.hpp

  //vector<Musician*> musicians;
vector<singer> singers;
vector<producer> producers;
vector<drummer> drummers;
    for(auto& musician : musicians)
{

    if(typeid(*musician) == typeid(singer)) singers.push_back(*dynamic_cast<singer*>(musician));
    if(typeid(*musician) == typeid(producer)) producers.push_back(*dynamic_cast<producer*>(musician));
    if(typeid(*musician) == typeid(drummer)) drummers.push_back(*dynamic_cast<drummer*>(musician));
}

  ```
</details>

<details>
  <summary>suprascris cc/op= pentru copieri/atribuiri corecte</summary>
  
  ```cpp
  //location: Header_Files -> musician.hpp
producer& producer::operator=( producer& fc_producer)
	{   
        abilities =  fc_producer.get_abilities();
		return *this;
	};

drummer& drummer::operator=( drummer& fc_drummer)
	{   
        drum =  fc_drummer.get_drum();
		return *this;
	};

    //location: Header_Files -> Record_labels.hpp

Record_label& Record_label::operator+=(singer& fc_musician){
    musicians.push_back(&fc_musician);
    nr_musicians ++;
    return *this;
};

Record_label& Record_label::operator+=(producer& fc_musician){
    musicians.push_back(&fc_musician);
    nr_musicians++;
    return *this;
};

Record_label& Record_label::operator+=(drummer& fc_musician){
    musicians.push_back(&fc_musician);
    nr_musicians++;
    return *this;
};
    //location: Header_Fiels -> song.hpp

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

  ```
</details>

<details>
  <summary>excepții: utilizare cu sens: de exemplu, throw în constructor, try/catch în main </summary>
  
  ```cpp
  //location: main.cpp

try
{
    if(cin>>add_nr) switch(add_nr)
    {   
        case 1:{cin.ignore(numeric_limits<streamsize>::max(), '\n');add_record_label(record_labels);break;}
        case 2:{cin.ignore(numeric_limits<streamsize>::max(), '\n');add_musician(musicians,record_labels);break;}
        case 3:{cin.ignore(numeric_limits<streamsize>::max(), '\n');add_song(songs,musicians);break;}
        // case 4:{
        //     // add_vinyl(vinyl)
        // }
        case 0:{meniu_add = 0;}

    } else {throw(400);break;}
    
}
catch(int n) //aici prindem toate erorile.
{
    if(n == 10) //throw(10); // the record label is incorrect. in functions f1 f2 f3
    {
        cout <<"\x1B[33mError: Invalid record_label, make sure to write properly the name of the record label, or add one.\033[0m\t \n\n";break;
    }
    else if (n == 20) //throw(20); in function add_song
    {
        cout << "\x1B[33m Error: The musician doesn't exist, make sure you write it well or create a musican\033[0m\t \n\n";break;
    }
    else if (n == 400)
    {
        cout<<"\x1B[33m Error , The input is invalid , try again\033[0m\t\n";break;
    }
}
  ```
</details>

<details>
  <summary>funcții și atribute statice</summary>
  
  ```cpp
  //location: Header_Files -> Record_labels.h
  //summary:
  class Record_label
  {
    static int nr_musicians;
  };
int Record_label::nr_musicians = 0;
  ```
</details>

<details>
  <summary>STL</summary>
  
  ```cpp
  //location: main.cpp

vector<Record_label> record_labels = {};
vector< unique_ptr<Musician>> musicians = {};
vector<Song> songs = {};
  ```
</details>

<details>
  <summary>funcții și atribute statice</summary>
  
  ```cpp
  //location: Header_Files -> Record_labels.h
  //summary:
  class Record_label
  {
    static int nr_musicians;
  };
int Record_label::nr_musicians = 0;
  ```
</details>

<details>
  <summary>funcționalități noi specifice temei</summary>
  
  ```cpp
  //location: main.cpp
  //afisarea unui record label
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

            if(typeid(*musician) == typeid(singer)) singers.push_back(*dynamic_cast<singer*>(musician));
            if(typeid(*musician) == typeid(producer)) producers.push_back(*dynamic_cast<producer*>(musician));
            if(typeid(*musician) == typeid(drummer)) drummers.push_back(*dynamic_cast<drummer*>(musician));
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
                    };
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
                    };
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
                    };
                }
                i++;
            }
        }
    }
    cout<<endl;
}

  ```
</details>