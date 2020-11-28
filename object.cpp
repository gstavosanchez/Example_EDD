#include "object.h"

Object::Object(int id,string data,string x,string y)
{
    this->data = data;
    this->x = x;
    this->y = y;
    this->id = id;
}

void Object::setData(string data){
    this->data = data;
}
void Object::setX(string x){
    this->x = x;
}
void Object::setY(string y){
    this->y = y;
}
void Object::setId(int id){
    this->id = id;
}
string Object::getData(){
    return this->data;
}
string Object::getX(){
    return this->x;
}
string Object::getY(){
    return  this->y;
}
int Object::getId(){
    return this->id;
}
