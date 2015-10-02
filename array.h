#ifndef ARRAY_H
#define ARRAY_H
#include <iostream>


using namespace std;
class Dato{
public:
    int a;
public:
     friend ostream&operator<<(ostream& os,const Dato &d);
    bool operator==(const Dato &d);
    bool operator<(const Dato &d);
    bool operator<=(const Dato &d);
    };
 bool Dato::operator==(const Dato &d){

    return a==d.a;

    }
bool Dato::operator<(const Dato &d){
     return a<d.a;
    }
bool Dato::operator<=(const Dato &d){
    return a<=d.a;
    }


ostream& operator<<(ostream& os,Dato &d){
       os<<d.a;
    return os;
    }
#endif // ARRAY_H
