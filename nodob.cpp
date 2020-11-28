#include <iostream>
#include "nodob.h"
using namespace std;
NodoB::NodoB(){
    this->objeto = nullptr;
    this->right = nullptr;
    this->left = nullptr;
    this->parent = nullptr;
}
NodoB::NodoB(string value){
    this->objeto = value;
    this->parent = nullptr;
    this->right = nullptr;
    this->left = nullptr;
}
NodoB::NodoB(string dato,NodoB *dercha,NodoB *izquierda){
    this->objeto = dato;
    this->left = izquierda;
    this->right = dercha;
    this->parent = nullptr;
}
NodoB::NodoB(string dato,NodoB *parent,NodoB *derecha,NodoB *izquierda){
    this->objeto = dato;
    this->parent = parent;
    this->right = derecha;
    this->left = izquierda;
}
void NodoB::setElemento(string _dato){
    this->objeto =_dato;
}
void NodoB::setRight(NodoB *_derecha){
    this->right = _derecha;
}
void NodoB::setLeft(NodoB *_izquierda){
    this->left = _izquierda;
}
void NodoB::setParent(NodoB *_parent){
    this->parent = _parent;
}

string NodoB::getElement(){
    return this->objeto;
}
NodoB *NodoB::getRight(){
    return this->right;
}
NodoB *NodoB::getLeft(){
    return this->left;
}
