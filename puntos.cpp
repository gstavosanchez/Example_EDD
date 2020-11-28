#include "puntos.h"

Puntos::Puntos(string x,string y)
{
    this->x = x;
    this->y = y;
}

void Puntos::setX(string x){
    this->x = x;
}

void Puntos::setY(string y){
    this->y = y;
}

string Puntos::getX(){
    return this->x;
}
string Puntos::getY(){
    return this->y;
}
