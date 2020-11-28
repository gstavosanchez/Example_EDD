#ifndef ARBOLAVL_H
#define ARBOLAVL_H
#include <iostream>
#include <sstream>
#include "nodoavl.h"
#include "asccitranslate.h"
using namespace std;
class ArbolAVL
{
private:
    NodoAVL *root;
    ascciTranslate* ascci = new ascciTranslate();
public:
    ArbolAVL();
    void add(string elemento);
    NodoAVL *getRoot();
    void graficar();
    void inOrden();
    // Metod Privados
    NodoAVL *add(NodoAVL *raiz, string element,bool& scape);
    NodoAVL* rotacionII(NodoAVL *n,NodoAVL *n1);
    NodoAVL* rotacionDD(NodoAVL *n,NodoAVL *n1);
    NodoAVL* rotacionID(NodoAVL *n,NodoAVL *n1);
    NodoAVL* rotacionDI(NodoAVL *n,NodoAVL *n1);
    void graficar(stringstream *cadena,NodoAVL *padre, NodoAVL *actual, bool left);
};

#endif // ARBOLAVL_H
