#include "nodom.h"

NodoM::NodoM()
{
    this->up = nullptr;
    this->down = nullptr;
    this->next = nullptr;
    this->previous = nullptr;
}

void NodoM::setNext(NodoM* next) {
    this->next = next;
}
void NodoM::setUp(NodoM* up) {
    this->up = up;
}
void NodoM::setDown(NodoM* down)
{
    this->down = down;
}
void NodoM::setPrevious(NodoM* previous)
{
    this->previous = previous;
}
NodoM *NodoM::getNext()
{
    return this->next;
}
NodoM* NodoM::getUp()
{
    return this->up;
}
NodoM* NodoM::getDown()
{
    return this->down;
}
NodoM* NodoM::getPrevious()
{
    return this->previous;
}
