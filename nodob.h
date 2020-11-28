#ifndef NODOB_H
#define NODOB_H
#include<iostream>
using namespace std;

class NodoB
{
private:
    string objeto;
    NodoB *parent;
    NodoB *left;
    NodoB *right;
public:
    NodoB();
    NodoB(string);
    NodoB(string,NodoB *,NodoB *,NodoB *);
    NodoB(string,NodoB *,NodoB *);
    void setElemento(string);
    void setParent(NodoB *);
    void setLeft(NodoB *);
    void setRight(NodoB *);
    NodoB *getParent();
    NodoB *getLeft();
    NodoB *getRight();
    string getElement();

};

#endif // NODOB_H
