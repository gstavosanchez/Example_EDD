#ifndef HEADER_H
#define HEADER_H
#include "nodom.h"
#include <iostream>
using namespace std;
class Header:public NodoM
{
private:
    string nombre;
public:
    Header(string name);
    void setNombre(string name);
    string getNombre();
};

#endif // HEADER_H
