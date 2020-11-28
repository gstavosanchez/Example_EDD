#ifndef MATRIZ_H
#define MATRIZ_H
#include <iostream>
#include <ostream>
#include <sstream>
#include "header.h"
#include "object.h"
#include "listapuntos.h"
using namespace std;
class Matriz
{
private:
    Header *horizontal;
    Header *vertical;
    int coutEspacio;
    ListaPuntos* listaPuntos = new ListaPuntos();

public:
    Matriz();
    void add(int id,string element,string x,string y);
    void graficar();
    Header *setHorizontal(string x);
    Header *setVertical(string y);
    Header *getHorizontal(string x);
    Header *getVertical(string y);
    NodoM *getUltimoV(Header *cabezera,string y);
    NodoM *getUltimoH(Header *cabezera,string x);
    void add(Object *objeto,string x,string y);
    int countEspacio;
    bool existPosicion(string x,string y);
    void setPointEmpty();
};

#endif // MATRIZ_H
