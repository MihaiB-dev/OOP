#include <iostream>
#include <string>
#include <utility>

class student {
    std::string nume;
public:
    student(std::string nume_) : nume(std::move(nume_)) { std::cout << "8 constructor student: " << nume << "\n"; }
    student(const student& other) : nume(other.nume) { std::cout << "9 cc student: " << nume << "\n"; }
    student& operator=(const student& other) { nume = other.nume; std::cout << "10 op= student: " << nume << "\n"; return *this; }
    ~student() { std::cout << "11 destructor student: " << nume << "\n"; }
    friend std::ostream& operator<<(std::ostream& os, const student& st) { os << "12 st: " << st.nume << "\n"; return os; }
};

class profesor {
    std::string nume;
public:
    profesor(std::string nume_) : nume(std::move(nume_)) { std::cout << "18 constructor profesor: " << nume << "\n"; }
    profesor(const profesor& other) : nume(other.nume) { std::cout << "19 cc profesor: " << nume << "\n"; }
    profesor& operator=(const profesor& other) { nume = other.nume; std::cout << "20 op= profesor: " << nume << "\n"; return *this; }
    ~profesor() { std::cout << "21 destructor profesor: " << nume << "\n"; }
    friend std::ostream& operator<<(std::ostream& os, const profesor& p) { os << "22 prof: " << p.nume << "\n"; return os; }
};

class curs {
    profesor prof;
public:
    curs() : prof("prof") { std::cout << "28 constructor implicit curs\n"; }
    curs(const profesor& prof_) : prof(prof_) { std::cout << "29 constructor curs: " << prof << "\n"; }
    curs(const curs& other) : prof(other.prof) { std::cout << "30 cc curs: " << prof << "\n"; }
    curs& operator=(const curs& other) { prof = other.prof; std::cout << "31 op= curs: " << prof << "\n"; return *this; }
    ~curs() { std::cout << "32 destructor curs: " << prof << "\n"; }
    friend std::ostream& operator<<(std::ostream& os, const curs& c) { os << "33 curs: " << c.prof << "\n"; return os; }
};

class curs_obligatoriu : public curs {
    student st;
public:
    curs_obligatoriu(const student& st_) : st(st_) { std::cout << "39 constructor curs_obligatoriu: " << st << "\n"; }
    curs_obligatoriu(const curs_obligatoriu& other) : st(other.st) { std::cout << "40 cc curs_obligatoriu: " << st << "\n"; }
    curs_obligatoriu& operator=(const curs_obligatoriu& other) { st = other.st; std::cout << "41 op= curs_obligatoriu: " << st << "\n"; return *this; }
    ~curs_obligatoriu() { std::cout << "42 destructor curs_obligatoriu: " << st << "\n"; }
    friend std::ostream& operator<<(std::ostream& os, const curs_obligatoriu& c) { os << "43 curs_obligatoriu: " << c.st << "\n"; return os; }
};

int main() {
    student s{"a"};
    profesor p{"b"};
    curs_obligatoriu co{s};
}