#ifndef NODOM_H
#define NODOM_H


class NodoM
{
private:
    NodoM *next;
    NodoM *previous;
    NodoM *up;
    NodoM *down;
public:
    NodoM();
    void setNext(NodoM *next);
    void setPrevious(NodoM *previous);
    void setUp(NodoM *up);
    void setDown(NodoM *down);
    NodoM *getNext();
    NodoM *getPrevious();
    NodoM *getUp();
    NodoM *getDown();
};

#endif // NODOM_H
