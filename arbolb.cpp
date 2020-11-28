#include<iostream>
#include "arbolb.h"
#include "nodob.h"

using namespace std;
ArbolB::ArbolB(){
    this->root = nullptr;
}

bool ArbolB::isEmpty(){
    return this->root == nullptr;
}

NodoB* ArbolB::getRoot(){
    return this->root;
}
bool ArbolB::isRoot(NodoB *nodo){
    return this->root == nodo;
}

bool ArbolB::isLeaf(NodoB *nodo){
    return nodo->getRight() == nullptr && nodo->getLeft() == nullptr;
}

bool ArbolB::isInternal(NodoB *nodo){
    return !isLeaf(nodo);
}
NodoB* ArbolB::add(string element){

    NodoB* nodo = nullptr;
        if(this->root == nullptr){
            this->root = new NodoB(element);
        }else{
            NodoB* aux = this->root;
            bool insertado = false;
            while (!insertado){
                if(this->ascci->getSizeAscci(element) < this->ascci->getSizeAscci(aux->getElement())){
                    if(aux->getLeft() != nullptr){
                        aux = aux->getLeft();
                    }else{
                        nodo = new NodoB(element);
                        nodo->setParent(aux);
                        aux->setLeft(nodo);
                        insertado = true;
                    }
                }else {
                    if(aux->getRight() != nullptr){
                        aux = aux->getRight();
                    }else{
                        nodo = new NodoB(element);
                        nodo->setParent(aux);
                        aux->setRight(nodo);
                        insertado = true;
                    }
                }
            }
        }
        return nodo;
}
void ArbolB::preOrden(NodoB * nodo){
    cout<<"Size: "<< this->ascci->getSizeAscci(nodo->getElement()) <<" Value: " <<nodo->getElement()<<endl;
    if(nodo->getLeft() != nullptr){
        this->preOrden(nodo->getLeft());
    }
    if(nodo->getRight() != nullptr){
        this->preOrden(nodo->getRight());
    }

}

void ArbolB::graficar(){
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
void ArbolB::graficar(stringstream *cadena, NodoB *padre, NodoB *actual, bool left){
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
