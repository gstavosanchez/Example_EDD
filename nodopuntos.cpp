#include "nodopuntos.h"

NodoPuntos::NodoPuntos(Puntos *elemento,NodoPuntos *siguiente)
{
    this->elemento = elemento;
    this->siguiente = siguiente;
}
void NodoPuntos::setElemento(Puntos *_elemento)
{
    this->elemento = _elemento;
}

void NodoPuntos::setSiguiente(NodoPuntos *_siguiente)
{
    this->siguiente = _siguiente;
}

Puntos *NodoPuntos::getElemento()
{
    return this->elemento;
}

NodoPuntos *NodoPuntos::getSiguiente()
{
    return this->siguiente;
}
NodoPuntos::~NodoPuntos(){}
