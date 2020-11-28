#include <iostream>
#include "asccitranslate.h"
using namespace std;

ascciTranslate::ascciTranslate(){}
int ascciTranslate::getSizeAscci(string cadena){
    int size = 0;
    if(cadena != ""){
        if(cadena.length() == 1){
           size = this->translateAscci(cadena.at(0));
        }else{
            int lengthCadena = cadena.length();
            for(int x = 0;x < lengthCadena ;x++){
                size += this->translateAscci(cadena.at(x));
            }
        }
    }
    return size;
}

int ascciTranslate::translateAscci(char caracter){
    int value = caracter;
    return value;
}
