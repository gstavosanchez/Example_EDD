#ifndef NODOAVL_H
#define NODOAVL_H
#include<iostream>
using namespace std;

class NodoAVL
{
private:
    string elemento;
    NodoAVL* left;
    NodoAVL* right;
    int factorE;
public:
    NodoAVL(string elemento);
    void setLeft(NodoAVL *left);
    void setRight(NodoAVL *right);
    void setElement(string elemento);
    void setFactor(int factor);
    NodoAVL *getLeft();
    NodoAVL *getRight();
    string getElement();
    int getFactor();
};

#endif // NODOAVL_H
