#ifndef NODOPUNTOS_H
#define NODOPUNTOS_H
#include "puntos.h"
class NodoPuntos
{
public:
    NodoPuntos(Puntos *,NodoPuntos *);
    void setSiguiente(NodoPuntos *);
    void setElemento(Puntos *);
    NodoPuntos *getSiguiente();
    Puntos *getElemento();
    ~NodoPuntos();
private:
    Puntos *elemento;
    NodoPuntos *siguiente;
};

#endif // NODOPUNTOS_H
