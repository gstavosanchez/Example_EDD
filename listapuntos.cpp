#include "listapuntos.h"

ListaPuntos::ListaPuntos()
{
    this->cabeza = nullptr;
    this->size = 0;
}
void ListaPuntos::add(Puntos *_elemento)
{
    NodoPuntos *nuevo = new NodoPuntos(_elemento, nullptr);
    if (this->isEmpty())
    {
        this->cabeza = nuevo;
        this->cabeza->setSiguiente(nullptr);
    }
    else
    {
        NodoPuntos *aux = this->cabeza;
        while (aux->getSiguiente() != nullptr)
        {
            aux = aux->getSiguiente();
        }
        aux->setSiguiente(nuevo);
    }
    this->size++;
}
string ListaPuntos::toString()
{
    NodoPuntos *aux = this->cabeza;
    string obj;
    while (aux != nullptr)
    {
        obj += "X:" + aux->getElemento()->getX() + "Y:" + aux->getElemento()->getY() + "\n";
        aux = aux->getSiguiente();
    }
    return obj;
}

bool ListaPuntos::isEmpty()
{
    return this->size == 0;
}
int ListaPuntos::getSize()
{
    return this->size;
}
Puntos *ListaPuntos::getElemento(string x, string y)
{
    if (this->isEmpty())
    {
        return nullptr;
    }
    else
    {
        NodoPuntos *aux = this->cabeza;
        int contador = 0;
        while (contador < this->getSize())
        {
            if (x == aux->getElemento()->getX() && y == aux->getElemento()->getY())
            {
                return aux->getElemento();
            }
            contador++;
            aux = aux->getSiguiente();
        }
        return nullptr;
    }
}
bool ListaPuntos::existPunto(string x, string y){
    if (this->isEmpty())
    {
        return false;
    }
    else
    {
        NodoPuntos *aux = this->cabeza;
        int contador = 0;
        while (contador < this->getSize())
        {
            if (x == aux->getElemento()->getX() && y == aux->getElemento()->getY())
            {
                return true;
            }
            contador++;
            aux = aux->getSiguiente();
        }
        return false;
    }
}
int ListaPuntos::indexOf(string x, string y)
{
    if (this->isEmpty())
    {
        return -1;
    }
    else
    {
        NodoPuntos *aux = this->cabeza;
        int contador = 0;
        int posicion = 0;
        while (contador < this->getSize())
        {
            if (x == aux->getElemento()->getX() && y == aux->getElemento()->getY())
            {
                return posicion;
            }
            contador++;
            posicion++;
            aux = aux->getSiguiente();
        }
        return -1;
    }
}

NodoPuntos *ListaPuntos::getNodo(int index)
{
    if (isEmpty())
    {
        return NULL;
    }
    else
    {
        NodoPuntos *buscado = this->cabeza;
        int contador = 0;
        while (contador < index)
        {
            contador++;
            buscado = buscado->getSiguiente();
        }
        return buscado;
    }
}
void ListaPuntos::remove(string x, string y)
{
    int buscado = indexOf(x, y);
    if (buscado != -1)
    {
        if (buscado == 0)
        {
            NodoPuntos *aux = cabeza->getSiguiente();
            cabeza = NULL;
            cabeza->~NodoPuntos();
            cabeza = aux;
            size--;
        }
        else if (buscado == getSize() - 1)
        {
            NodoPuntos *nodo_anterior = getNodo(buscado - 1);
            NodoPuntos *nodo_actual = getNodo(buscado);
            nodo_actual = NULL;
            nodo_actual->~NodoPuntos();
            nodo_anterior->setSiguiente(NULL);

            size--;
        }
        else
        {
            NodoPuntos *nodo_anterior = getNodo(buscado - 1);
            NodoPuntos *nodo_actual = getNodo(buscado);
            NodoPuntos *nodo_siguiente = nodo_actual->getSiguiente();
            nodo_actual = NULL;
            nodo_actual->~NodoPuntos();
            nodo_anterior->setSiguiente(nodo_siguiente);
            size--;
        }
    }
    else
    {
        cout << "No se encontro el punto,"
             << "X:" << x << "Y:" << y << endl;
    }
}
