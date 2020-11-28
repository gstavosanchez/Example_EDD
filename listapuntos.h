#ifndef LISTAPUNTOS_H
#define LISTAPUNTOS_H
#include "puntos.h"
#include "nodopuntos.h"

class ListaPuntos
{
private:
   int size;
   NodoPuntos *cabeza;
public:
    ListaPuntos();
    void add(Puntos *);
    bool isEmpty();
    int getSize();
    Puntos *getElemento(string,string);
    bool existPunto(string x,string y);
    void remove(string,string);
    int indexOf(string,string);
    NodoPuntos *getNodo(int);
    string toString();
};

#endif // LISTAPUNTOS_H
