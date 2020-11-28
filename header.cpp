#include "header.h"

Header::Header(string name)
{
    this->nombre =name;
}

void Header::setNombre(string name){
    this->nombre = name;
}
string Header::getNombre(){
    return this->nombre;
}
