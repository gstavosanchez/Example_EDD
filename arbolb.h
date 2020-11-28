#ifndef ARBOLB_H
#define ARBOLB_H
#include "nodob.h"
#include "asccitranslate.h"
#include<sstream>
class ArbolB
{
private:
    NodoB *root;
    ascciTranslate* ascci = new ascciTranslate();
public:
    ArbolB();
    NodoB *getRoot();
    NodoB *add(string);
    void preOrden(NodoB *);
    bool isEmpty();
    bool isRoot(NodoB *);
    bool isLeaf(NodoB *);
    bool isInternal(NodoB *);
    void graficar();
    void graficar(stringstream *,NodoB *,NodoB *,bool);
    void remove(NodoB * nodo);
    void removeLeaf(NodoB* nodo);
};

#endif // ARBOLB_H
