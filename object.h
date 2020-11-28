#ifndef OBJECT_H
#define OBJECT_H
#include "nodom.h"
#include <iostream>
using namespace std;
class Object: public NodoM
{
private:
    int id;
    string data;
    string x;
    string y;
    //void privateMethod();
public:
    Object(int,string,string,string);
    void setData(string data);
    void setX(string x);
    void setY(string y);
    void setId(int id);
    string getX();
    string getY();
    string getData();
    int getId();
};

#endif // OBJECT_H
