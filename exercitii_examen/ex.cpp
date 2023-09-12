#include<iostream>
#include<typeinfo>
using namespace std;

// int main()
// {
//     // int **p;
//     // int x = 5;
//     // **p = x;
//     // cout <<p;

//     // int x = 5;
// 	// int y = 3;
// 	// auto compute = [x, &y](int z){
// 	// 		y++;
// 	// 		return x + y + z;
// 	// };
//     // cout << compute;
//     return 0;
// }


// class A{
//     long i;
// };
// class B : public A{
//     char p;
//     long i;
// };
// int main(){
// cout << sizeof(A)<<endl<<sizeof(B);
// // f();
// return 0;
   
// }

// class A {
//     private:
//     A(){};
//     A(A& a){};
// };
// class B : public A{};

// int main(){
//     B b;
//     return 0;
// }
//-----------------------
// class A { int i; 
// public: 
//     A(int ii) : i(ii) {cout<<"A";} 
//     ~A() {cout<<" DA";} 
//     void f() const {} 
// }; 

// class B { int i; 
// public: 
//     B(int ii) : i(ii) {cout<<"B";} 
//     ~B() {cout<<" DB";} 
//     void f() const {} 
// };

// class C : public B { 
//     A a; 
// public: 
//     C(int ii) : B(ii), a(ii) {cout<<"C";} 
//     ~C() {cout<<" DC";} // Calls ~A() and ~B() 
//     void f() const 
//           { // Redefinition 
//                 a.f(); 
//                 B::f(); 
//           } 
// }; 
// int main() { 
//     C c(47); 
// } 
//---------------------
// class Baza {
// public:
//     void afis( )    {        cout<<"Baza\n";    }
// };

// class Derivata : public Baza {
// public:
//     void afis (int x)     {
//         Baza::afis();
//         cout<<"si Derivata\n";    }
// };

// int main( ) {
//     Derivata d;
//     d.afis(); //nu exista Derivata::afis( )
//     d.afis(3); }
//------------------------------------------------
// class Base {
// public:
//   int f() const { cout << "Base::f()\n";  return 1;  }
//   int f(string) const { return 1; }
//   void g() { }
// };
// class Derived3 : public Base {
// public:
//   // Change return type:
//   void f() const { cout << "Derived3::f()\n"; }
// };
// class Derived4 : public Base {
// public:
//   // Change argument list:
//   int f(int) const { 
//     cout << "Derived4::f()\n"; 
//     return 4; 
//   }
// };

// int main() {

//   Derived3 d3;
//   int x = d3.f(); // return int version hidden

//   Derived4 d4;
// //!  x = d4.f(); // f() version hidden
//   x = d4.f(1);
// }
//-----------------------------------
// class A {
//     public:
//     virtual void f(){cout<<"1";}

// };
// class B : public A {
//     public:
//     void f(){cout << "2";}

// };
// int main(){

//     A* p = new B();
//     p->f();

//     return 0;
// }
//-----------------------------
// enum note { middleC, Csharp, Eflat }; // Etc.

// class Instrument {  public:
//   virtual void play(note) const {
//     cout << "Instrument::play" << endl;  }
// };

// class Wind : public Instrument {
// public:  // Redefine interface funcţion:
//   void play(note) const {
//     cout << "Wind::play" << endl;  }
// };

// void tune(Instrument& i) {  i.play(middleC);  }

// int main() {
//   Wind flute;
//   tune(flute); // se afiseaza Wind::play
// }
//--------------
// class NoVirtual {  int a;
// public:
//   void x() const {}
//   int i() const { return 1; } };

// class OneVirtual {  int a;
// public:
//   virtual void x() const {}
//   int i() const { return 1; } };

// class TwoVirtuals {  int a;
// public:
//   virtual void x() const {}
//   virtual int i() const { return 1; } };
// int main() {
//   cout << "int: " << sizeof(int) << endl;
//   cout << "NoVirtual: "
//        << sizeof(NoVirtual) << endl;
//   cout << "void* : " << sizeof(void*) << endl;
//   cout << "OneVirtual: "
//        << sizeof(OneVirtual) << endl;
//   cout << "TwoVirtuals: "
//        << sizeof(TwoVirtuals) << endl;
// }
//----------------------------------------------------
// #include <iostream>
// using namespace std;

// int main()
// {
//     int* p = new int(65);
//     char* ch = reinterpret_cast<char*>(p);
//     cout << *p << endl;
//     cout << *ch << endl;
//     cout << p << endl;
//     cout << ch << endl;
//     return 0;
// }
//-----------------------------------------------------
// void Test(int x)
// {
//      cout << "In functie x = " << x <<"\n";
//      if (x < 0) throw x;
// }
// class TestTry {    
// public:    
//         void Test_Throw_Functie() {
//                try {            
//                     Test(5);
//                     Test(200);
//                     Test(-300);
//                     Test(22); 
//               }        
//               catch (int x)         {           
//                     cout << "Exceptie pe valoarea " << x <<"\n"; 
//               }        
//         }
// };


// int main() {
// TestTry T;
// T.Test_Throw_Functie();
// } 
//-----------------------------------------
// const int TABWIDTH = 8; 
// // Display data at specified tab position. 
// template<class X> void tabOut(X data, int tab) { 
// 	for(; tab; tab--) 
// 	   for(int i=0; i<TABWIDTH; i++) cout << ' '; 
//     	cout << data << "\n"; 
// } 

// int main()
// { 
// 	tabOut("This is a test", 0); 
// 	tabOut(100, 1); 
// 	tabOut('X', 2); 
// 	tabOut(10/3, 3); 
// 	return 0; 
// } 
//-------------------------------------------
// template <class T> // sau template <typename T>
// class Nume { 
// 	T x;
// public: 
// 	void set_x(T a){x = a;} 
// 	void afis(){cout<<x;} 
// }; 

// template <> 
// class Nume<unsigned> { 
// 	unsigned x;
// public: 
// 	void set_x(unsigned a){x = a;} 
// 	void afis(){cout<<"\nUnsigned "<<x<< " "<<(typeid(&x)==typeid(unsigned int));} 
// }; 
// int main() 
// { 
// 	Nume<int> m;
// 	m.set_x(7);
// 	m.afis();
// 	Nume<unsigned> n;
// 	n.set_x(100); 
// 	n.afis(); 
// 	return 0; 
// } 
//--------------------------
// template <class T> class myclass{
//       T a;
//       public:
//       myclass(T u){u = a;}
//  }; 

// int main() 
// { 
// 	myclass<int> o1(10), o2(9); 
// 	myclass<double> o3(7.2); 

// 	cout << "Type of o1 is " << typeid(o1).name() << endl; 
// 	cout << "Type of o2 is " << typeid(o2).name() << endl; 
// 	cout << "Type of o3 is " << typeid(o3).name() << endl; 

// 	if(typeid(o1) == typeid(o2)) cout << "o1 and o2 are the same type\n"; 
// 	if(typeid(o1) == typeid(o3)) cout << "Error\n"; 
// 	else cout << "o1 and o3 are different types\n"; 

// 	return 0; 
// } 
//--------------------------
// #include <iostream>
// using namespace std;

// class base {
//    int i;
// public:
//    void set_i(int num) { i=num; }
//    int get_i() { return i; }
// };

// class derived: public base {
//    int j;
// public:
//    void set_j(int num) {j=num;}
//    int get_j() {return j;}
// };
// int main()
// {
//    base *bp;
//    derived d[2];
//    bp = d;
//    d[0].set_i(1);
//    d[1].set_i(2);
// //    for( auto& bp = d.begin(); bp != d.end(); bp ++){
// //       ....
// //    }
//    cout << bp->get_i() << " ";
//    bp++; // relative to base, not derived
//    cout << bp->get_i(); // garbage value displayed
//    return 0;
// }
//------------------------------
// #include <iostream>
// using namespace std;
// class cl {
// public:
//    cl(int i) { val=i; }
//    int val;
//    int double_val() { return val+val; }
// };

// int main()
// {
//    int cl::*data; // data member pointer
//    int (cl::*func)(); // function member pointer
//    cl ob1(1), ob2(2); // create objects
//    data = &cl::val; // get offset of val
//    func = &cl::double_val; // get offset of 				 //double_val()
//    cout << "Here are values: ";
//    cout << ob1.*data << " " << ob2.*data << "\n";
//    cout << "Here they are doubled: ";
//    cout << (ob1.*func)() << " ";
//    cout << (ob2.*func)() << "\n";
//    return 0;
// }
//------------------------------------
// #include <iostream>
// using namespace std;

// class X {
//   int i;
// public:
//   X(int ii = 0) : i(ii) {} // Default
//   ~X() { cout << "X::~X()" << endl; }
// };

// void f() {
//   static X x1(47);
//   static X x2; // Default constructor required
// }

// int main() {
//   f();
// } 
//----------------------------------------
// #include <iostream>
// using namespace std;

// int x = 100;

// class WithStatic {
//   static int x;
//   static int y;
// public:
//   void print() const {
//     cout << "WithStatic::x = " << x << endl;
//     cout << "WithStatic::y = " << y << endl;
//   }
// };

// int WithStatic::x = 1;
// int WithStatic::y = x + 1;
// // WithStatic::x NOT ::x

// int main() {
//   WithStatic ws;
//   ws.print();
// }
//--------------------

// class problema
// {  int i;
//    public: problema(int j=5){i=j;}
// 	      void schimba(){i++;}
// 	      void afiseaza(){cout<<"starea curenta "<<i<<"\n";}
//             ~problema(){cout<<"destructor\n";}
// };
// problema mister1() { return problema(6);}
// void mister2(problema o)
// {  o.afiseaza(); //look at the error and solve the problem

//    o.schimba(); 
//    o.afiseaza();
// }
// int main()
// {  mister2(mister1()); 
//    return 0;
// }
//---------------------

// #include <typeinfo>
// class B
// { int i;
//   public: B() { i=1; }
//           int get_i() { return i; }
// };
// class D: public B
// { int j;
//   public: D() { j=2; }
//           int get_j() {return j; }
// };
// int main()
// { B *p=new D; 
//   cout<<p->get_i();
//   if (typeid((B*)p).name()=="D*") cout<<((D*)p)->get_j();
//   return 0;
// }

//------------------------
// class cls1 
// {   protected: int x; 
//      public:      cls1(){ x=13;cout<<"Constructor cls1"; } }; 
// class cls2: public cls1 
// {   protected: int y; 
//      public:     cls2(){ y=15; cout<<"Constructor cls2";} }; 
// class cls3: public cls2 
// {   protected: int z; 
//     public:      cls3(){ z=17; cout<<"Constructor cls3";} 
// int f(cls3 ob){ return ob.x+ob.y+ob.z; } }; 
// int main() 
// {   cls3 ob; 
//      cout<<ob.f(ob); 
//      return 0; 
// } 
// class cls 
// {              int x; 
//   public: cls(int i=0) { x=i; } 
//                cls(cls& ob) { x=ob.x; } 
//                ~cls() { cout<<"Destructor cls\n"; }
//                }; 

// cls& f(cls& c)  { return c; } 
 
// int main() 
// {   cls r; 
//     cls s=r; 
//     f(f(f(s))); 
// } 
//-------------------------

// class B
// { protected: int x;
//   public: B(int i=28) { x=i; } 
//           virtual B f(B ob) { return x+ob.x+1; }
//           void afisare(){ cout<<x; } };
// class D: public B
// { public: D(int i=-32):B(i) {}
//           B f(B ob) { return x+ob.x-1; } };
// int main()
// { B *p1=new D, *p2=new B, *p3=new B(p1->f(*p2));
//   p3->afisare();  
//   return 0;
// }

//--------------------------
// class B
// { int i;
// public: B() { i=1; }
//           int get_i() { return i; }
// };

// class D:public B
// { int j;
// public: D() { j=2; }
//           int get_j() {return j; }
// };

// int main()
// { B *p=new D(); 
//   cout<<p->get_i();
//   if (typeid((B*)p)==typeid("D*")) cout<<((D*)p)->get_j();
//   return 0;
// }
//----------------------------
// template<class T, class U>
// T f(T x, U y)
// { return x+y;
// }
// int main()
// { int b(2);
// const char a[4] = "Abc";
// cout<<*f(a,b);
//   return 0;
// }

//------------
// class A{
//   public:
//   A(){cout<<"constructor"<<endl;}
//   A(const A& a){cout<<"copiere"<<endl;}
// };
// void function(A& b){
//   cout<<"function";

// }
// int main(){
//   A a;
//   function(a);
//   return 0;
// }
//----
// class Base
// {
// protected:
//     int x;
// public:
//     Base(int i) { x = i; }
// };
// class Derived : public Base
// {
// public:
//     Derived(int i) :  Base(i){}
//     void print() { cout << x; }
// };
// int main()
// {
//     Derived d(10);
//     d.print();
// }
///--------------------
// class Cls
// {
//     int x;
// public:
//     Cls(int i) : x(i) {}
//     int &f()
//     {
//         return x;
//     }
// };
// int main()
// {
//     Cls a(14);
//     auto b = [&a](){return a.f()++;};
//     cout <<b()<< '\n';
//     return 0;
// }
//---------------
// int& f(){
//     static int a = 10;
//     static int b = 15;
//     return b;

// }
// int main(){
//     int& x = f();
//     x++;
//     cout<<f();
// }
//---------------
// class A
// {
//     int id;
//     static int count;
// public:
//     A()
//     {
//         count++;
//         id = count;
//         cout << "constructor called " << id << endl;
//     }
//     ~A()
//     {
//         cout << "destructor called " << id << endl;
//     }
// };
// int A::count = 0;
// int main()
// {
//     A a[2];
//     return 0;
// }
//---------------
// class Test
// {
// private:
//     int x;
//     static int count;
// public:
//     Test(int i = 0) : x(i) {}
//     Test(const Test &rhs) : x(rhs.x) { ++count; }
//     static int getCount() { return count; }
// };
// int Test::count = 0;
// Test fun()
// {
//     return Test();
// }
// int main()
// {
//     Test a = fun(); 
   
//     cout << Test::getCount(); 
//     return 0;
// }
//---------------
// int a = 2;
// class Test
// {
//     int &t = a;
// public:
//     Test(int& t) t(t) {}
//     int getT() { return t; }
// };
// int main()
// {
//     int x = 20;
//     int &ref = x;
//     int b = 10;
//     ref = b;
//     Test t1(x);
//     cout << t1.getT() << endl;
//     x = 30;
//     cout << t1.getT() << endl;
//     return 0;
// }
//-----------------
// class B
// {
// protected:
//     int x;
// public:
//     B(int i = 16) { x = i; }
//     B f(B ob) { return x + ob.x; }
//     void afisare() { cout << x; }
// };
// class D : public B
// {
//     // protected: x
//     //public:  toti membrii public din B
// public:
//     B f(B ob)
//     {
//         return x+1;
//     }
// };
// int main()
// {
//     B *p1 = new D; //upcasting
//     B *p2 = new B;
//     B *p3 = new B(p1->f(*p2));
//     p3->afisare(); //32
//     return 0;
// }
//-------------------
// class A
// {
// public:
//     int x;
//     A(int i = 13) { x = i;cout<<"A"<<x<<endl; }
// };
// class B : virtual public A
// {
// public:
//     B(int i = 15) { x = i; cout<<"B"<<x<<endl;}
// };
// class C : virtual public A
// {
// public:
//     C(int i = 17) { x = i; cout<<"C"<<x<<endl;}
// };
// class D : virtual public A
// {
// public:
//     D(int i = 19){x = i;cout<<"D"<<x<<endl;}
// };
// class E : public B, public C, public D
// {
// public:
//     int y;
//     E(int i, int j) : D(i), B(j){y = x + i + j;}
//     E(E &e) { y = -e.y; }
// };
// int main()
// {
//     E e1(1, 2), e2 = e1;
//     cout << e2.y; // -4
//     return 0;
// }
//--------------------------------
// class Base
// {
// public:
//     Base()
//     {
//         fun();
//     }
//     virtual void fun()
//     {
//         cout << "\nBase Function";
//     }
// };
// class Derived : public Base
// {
// public:
//     Derived() {}
//     virtual void fun()
//     {
//         cout << "\nDerived Function";
//     }
// };
// int main()
// {
//     Base *pBase = new Derived();
//     delete pBase;
//     return 0;
// }
//------------------------
// class A
// {
// protected:
//     static int x;
// public:
//     A(int i = 0) { x = i; }
//     virtual A schimb() { return (7 - x); }
// };
// class B : public A
// {
// public:
//     B(int i = 0) { x = i; }
//     void afisare() { cout << x; }
//     A schimb(){return 1;}
// };
// int A::x = 5;
// int main()
// {
//     A *p1 = new B(18);
//     *p1 = p1->schimb();
//     ((B *)p1)->afisare();
//     return 0;
// }
//------------
// class Base {};
// class Derived : public Base {};
// int main(){

// Base *b = new Derived();
// Derived *d = (Derived*) b;
// }
//-----------------
// #include <iostream>
// using namespace std;


// class A
// {
// 	int x;
// public: A(int i = 17) { x = i; }
// 	  int get_x() { return x; }
// };
// class B
// {
// 	int x;
// public: B(int i = -16) { x = i; }
// 	  operator A() { return x; }
// 	  int get_x() { return x; }
// };
// int main()
// {
// 	B a;
// 	A b(a);
// 	cout << b.get_x();
// 	return 0;
// }
//------------------------
// class C{
// int c;
// public:  C(int p=1){c=p;}
// const int & get()const{return c;}
// };
// int f(const C & op){return op.get();}
// int main(){
// C o1;
// int x=f(o1);
// return 0;
// }
//------------------------
// class B{
// 	protected:
// 	static int x;
// public: virtual B * fv(){return this;}
//         int adun(int p){return p+1;}
// 		virtual int* ceva(){return &x;}
// };
// int B::x = 1;
// class D:public B{
// public: 
//         D * fv(){cout<<"UIte!!";return this; }
//         int adun (int p){return p+2;}
// 		double* ceva(){ return &x;}
// };
// int main(){
// B *p =new D;
// // int x=p->fv()->adun(1);
// // cout<<x;
// int* x = p->ceva();
// cout<<*x;
// return 0;
// }
//-----
// class B{
// public: virtual B * fv(){return this;}
//         virtual int adun(int p){return p+1;}
// };
// class D:public B{
// public: virtual D * fv(){return this;}
//         virtual int adun (int p){return p+2;}
// };
// int main(){
// B *p =new D;
// int x=p->fv()->adun(1);
// return 0;
// }
//------------------
// class B {
// protected:
//     static int x;
//     int offset;
// public:
//     B()
//     {x++; offset = 100;}
//     ~B() { x--; }
//     static int get_x() { return x; }
//     int get_offset() { return offset; }
//     int f() { return (x + offset) / 2; }
// };
// int B::x = 0;

// class D : public B {
// public:
//     D() { x++; }
//     ~D() { x--; }
//     int f() { return ( (x + offset) / 2 + 1); }
// };

// void func(B* q, int n) {cout << q->get_x() << " ";
//     for(int i = 0; i < n; i++) cout << q[i].f() << " ";
//     cout<<"\n";
// }

// int main()
// {
//     B* p = new B[2];
// 	 func(p, 2); 
// 	 delete[] p;
//     p = new D; 
// 	func(p, 1); 
// 	delete p;
//     cout << D::get_x();    return 0;
// }
//------------------
// class B {protected:
//     static int x;
//     int offset;
// public:
//     B()    { x++;offset = 100; }
//     ~B() { x--; }
//     static int get_x() { return x; }
//     int get_offset() { return offset; }
//      int f() { return (x + offset) / 2; }
// };
// int B::x = 0;

// class D : public B {public:
//     D() { x++; }
//     ~D() { x--; }
//     int f() { return (x + offset) / 2 + 1; }
// };

// void func(B* q, int n){cout << q->get_x() << " ";
//     for(int i = 0; i < n; i++) cout << q[i].f() << " ";
//     cout<<"\n";}

// int main()
// {
//     B* p = new B[2];func(p, 2);delete[] p;
//     p = new D;func(p, 1); delete p;
//     cout << D::get_x();
// }
//-------------------
// #include <iostream>
// using namespace std;

// class A
// {
//     int *x;
// public:
//     A(int i = 25){ x = new int(i); }
//     int& get_x() const  { return *x;  }
//     void set_x(int i) { x = new int(i); }
//     A& operator=(A a1)
//     {
//         set_x(a1.get_x());
//         return *this;
//     }
// };

// int main()
// {
//     A a(18), b(7);
//     (b=a).set_x(27);
//     int i;
//     i=b.get_x();
//     return 0;
// }
//-------------------
// class A {
//     int *x;
// public:
//     A() {  x = new int(0);  }
//     A(int i) { x = new int(i); }
//     int& get_x() const { return *x; }
//     void set_x(int i) { x = new int(i); }
//     A operator=(A a1) { set_x(a1.get_x());cout<<"POO :( ";return a1;}
// };

// class B : public A {
//     int *y;
// public:
//     B() : A() { y = new int(0); }
//     B(int i) : A(i){ y = new int(i);}
// 	void afisare() const { cout << *y; }
// };

// int main()
// {
//     B a(112), b, *c;
// 	b=a;
//     (c = &b)->afisare();


//     return 0;
// }
//----
// class X{
// 	static int x;
// 	class Y{
// 		int y;
// 		public:
// 		Y(int b = 2){y = b; cout<<y<<" ";}
// 		void afis(){cout<<x<<" "<<y;}
// 	}ob1;
// 	public:
// 	X(int a = 1){x = a; cout <<x<<" ";}
// 	void afis(){ob1.afis();}
// };
// int X::x = 0;
// int main(){
// 	X ob2;
// 	ob2.afis();
// }
//-------------------

class C {
    int *p;
    public:
        C (int *q) : p(q) {}
        void reload () {  p = new int;}
        void set (int q) const { *p = q; }
};
int main () {
    int x = 20210614;
    C ob(&x);
    ob.reload(); ob.set(x);
    return 0;
}
