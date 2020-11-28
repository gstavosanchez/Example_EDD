#ifndef PUNTOS_H
#define PUNTOS_H
#include <iostream>
using namespace std;
class Puntos
{
public:
    Puntos(string x,string y);
    void setX(string x);
    void setY(string y);
    string getX();
    string getY();
private:
    string x;
    string y;

};

#endif // PUNTOS_H
