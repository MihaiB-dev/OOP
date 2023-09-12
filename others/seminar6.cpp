#include <iostream>
using namespace std;



class Test {
    int x;
    mutable int y;
    public:
        Test():x(1){}
        void function() const {
            x++;
        }
        //pot fi acceptate amandoua deaorece nu pot sa fie convertite 
        //void f(int *i) {}
        //void f(const int* i ){}
        //--------------------------

        //nu pot fi acceptate amandoua in acelas timp, va fi ambiguitate
        //void f(const int i){}
        void f1()const{y = 7;}
        //--------------------------

};
int main(){
    Test ob;
    // ob.f1();
    ob.function();
    //int x = 7; 
    //cosnt int * p = &x;
    //const int *p = &x; pointeaza acum spre o zona de memorie constanta.
    //*p = 70; merge
    //*q = 1000; NU MERGE (nu merge sa schimba valoarea lui x prin q, dar putem sa schimba x)

    //int * const p = &x; (acum pointer-ul este unul constant)
    //p = &y; NU MERGE

    // Test ob;
    // ob.f1(1); 
    //ob.f1(p); nu merge
    //ob.f1(pc); nu merge
    
    return 0;
}