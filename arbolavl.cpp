#include <iostream>
#include "arbolavl.h"
#include "nodoavl.h"

using namespace std;
ArbolAVL::ArbolAVL()
{
    this->root = nullptr;
}
void ArbolAVL::add(string elemento){
    bool b = false;
    bool* a = &b;
    this->root = this->add(this->root,elemento, *a);
}
NodoAVL *ArbolAVL::add(NodoAVL *raiz, string element, bool &scape){
    NodoAVL* n1;
    if(raiz == nullptr){
        raiz = new NodoAVL(element);
        scape = true;
    }else if(this->ascci->getSizeAscci(element) < this->ascci->getSizeAscci(raiz->getElement()) ){
        NodoAVL* izq = this->add(raiz->getLeft(),element,scape);
        raiz->setLeft(izq);
        if(scape){
            switch (raiz->getFactor()) {
            case 1:
                raiz->setFactor(0);
                scape = false;
                break;
            case 0:
                raiz->setFactor(-1);
                break;
            case -1:
                n1 = raiz->getLeft();
                if(n1->getFactor() == -1){
                    raiz = rotacionII(raiz,n1);
                }else{
                    raiz = rotacionID(raiz,n1);
                }
                scape = false;
                //break;
            }
        }
    }else if(this->ascci->getSizeAscci(element) > this->ascci->getSizeAscci(raiz->getElement())){
     NodoAVL* der = this->add(raiz->getRight(),element,scape);
     raiz->setRight(der);
     if(scape){
         switch (raiz->getFactor()) {
         case 1:
             n1 = raiz->getRight();
             if(n1->getFactor() == 1){
                 raiz = rotacionDD(raiz,n1);
             }else{
                 raiz = rotacionDI(raiz,n1);
             }
             scape = false;
             break;
         case 0:
             raiz->setFactor(1);
             break;
         case -1:
             raiz->setFactor(0);
             scape = false;
             break;
         }
     }
    }
    return raiz;
}
NodoAVL *ArbolAVL::getRoot(){
    return this->root;
}
NodoAVL* ArbolAVL::rotacionII(NodoAVL *n, NodoAVL *n1){
    n->setLeft(n1->getRight());
    n1->setRight(n);

    if (n1->getFactor() == -1){
        n->setFactor(0);
        n1->setFactor(0);
    }else{
        n->setFactor(-1);
        n1->setFactor(1);
    }
    return n1;
}
NodoAVL* ArbolAVL::rotacionDD(NodoAVL *n, NodoAVL *n1){
    n->setRight(n1->getLeft());
    n1->setLeft(n);

    if (n1->getFactor() == 1){
        n->setFactor(0);
        n1->setFactor(0);
    }else{
        n->setFactor(1);
        n1->setFactor(-1);
    }
    return n1;
}
NodoAVL* ArbolAVL::rotacionID(NodoAVL *n, NodoAVL *n1){
    NodoAVL* n2 = n1->getRight();
    n->setLeft(n2->getRight());
    n2->setRight(n);
    n1->setRight(n2->getLeft());
    n2->setLeft(n1);

    if (n2->getFactor() == 1){
        n1->setFactor(-1);
    }else{
        n1->setFactor(0);
    }

    if (n2->getFactor() == -1){
        n->setFactor(1);
    }else{
        n->setFactor(0);
    }
    n2->setFactor(0);
    return n2;
}
NodoAVL *ArbolAVL::rotacionDI(NodoAVL *n, NodoAVL *n1){
    NodoAVL* n2 = n1->getLeft();
    n->setRight(n2->getLeft());
    n2->setLeft(n);
    n1->setLeft(n2->getRight());
    n2->setRight(n1);

    if (n2->getFactor() == 1){
            n->setFactor(-1);
    }else{
        n->setFactor(0);
    }

    if (n2->getFactor() == -1){
        n1->setFactor(1);
    }else{
        n1->setFactor(0);
    }

    n2->setFactor(0);
    return n2;
}

void ArbolAVL::graficar(){
    stringstream cadena;
    cadena<< "digraph G{ \n"<<endl;
    cadena << "node[shape=\"record\"]"<<endl;
    if(this->root != nullptr){
        cadena << "node" << &(*this->root) << "[color=\"" << "" << "\",label= \"<f0>|<f1>" <<" Nombre: " <<  this->root->getElement() << " ID: " << this->ascci->getSizeAscci(this->root->getElement()) << "|<f2>\"]" << endl;
        //cadena << "node"<< &(*this->root) << "";
        this->graficar(&cadena,this->root,this->getRoot()->getLeft(),true);
        this->graficar(&cadena,this->root,this->getRoot()->getRight(),false);
    }
    cadena << "}" << endl;

    cout << cadena.str() << endl;

}
void ArbolAVL::graficar(stringstream *cadena, NodoAVL *padre, NodoAVL *actual, bool left){
    if (actual != nullptr){
        *cadena << "node" << &(*actual) << "[color=\"" <<"" <<"\",label=\"<f0>|<f1>" << "" << "\",label= \"<f0>|<f1>" << " Nombre: "<< actual->getElement() << " ID: " << this->ascci->getSizeAscci(actual->getElement()) << "|<f2>\"]" << endl;
         if (left){
                *cadena << "node" << &(*padre) << ":f0->node" << &(*actual) << ":f1" << endl;
            }else{
                *cadena << "node" << &(*padre) << ":f2->node" << &(*actual) << ":f1" << endl;
            }

            graficar(cadena, actual, actual->getLeft(), true);
            graficar(cadena, actual, actual->getRight(), false);
        }
}

