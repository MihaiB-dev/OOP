#include <iostream>
#include <exception>
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Litera : public exception {
public:
    const char* what() const throw(){
        return "\x1B[33m\nTrebuie sa tastati un numar intre 1 si 4\033[0m\t\n";
    }
};

int main(){


    bool main = true;
    string optiune;
    // while(main){
        
    //     cout << "1. 2. 3. 4. 0. "<<endl<<"Number: ";
    //     cin>>optiune;
        
    //     try{
    //         for(auto& litera : optiune){
    //             if(litera < '0' || litera > '4')throw Litera();
    //         }
    //         int optiune_int = stoi(optiune);
    //         switch(optiune_int){
    //             case 1: {cout<<"yuppy"<<endl;break;}
    //             case 2: {cout<<"yuppy"<<endl;break;}
    //             case 3: {cout<<"yuppy"<<endl;break;}
    //             case 4: {cout<<"yuppy"<<endl;break;}
    //             case 0: {main = false;break;}
    //         }
            
    //     }
    //     catch(exception &obj){
    //         cout << obj.what()<<endl;
    //     }
    // }

    //ordonez crescator un vector folosind lambda functions
    vector<int> vector{1,9,2,3,7,4,6,5,8};
    auto sort_function = [](int& a, int&b){return a < b;};
    sort(vector.begin(), vector.end(), sort_function);
    for(auto& el : vector){
        cout << el << " ";
    }
}