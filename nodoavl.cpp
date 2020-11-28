#include "nodoavl.h"

NodoAVL::NodoAVL(string elemento){
    this->elemento = elemento;
    this->right = nullptr;
    this->left = nullptr;
    this->factorE = 0;
}


void NodoAVL::setLeft(NodoAVL* left)
{
    this->left = left;
}

NodoAVL* NodoAVL::getLeft()
{
    return this->left;
}

void NodoAVL::setRight(NodoAVL *right)
{
    this->right = right;
}

NodoAVL* NodoAVL::getRight()
{
    return this->right;
}

void NodoAVL::setFactor(int factor)
{
    this->factorE = factor;
}

int NodoAVL::getFactor()
{
    return this->factorE;
}

void NodoAVL::setElement(string elemento)
{
    this->elemento = elemento;
}
string NodoAVL::getElement(){
    return this->elemento;
}
