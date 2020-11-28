#include "matriz.h"

Matriz::Matriz()
{
    this->horizontal = nullptr;
    this->vertical = nullptr;
    this->countEspacio = 0;
}

Header *Matriz::setHorizontal(string x){
    int xAscci = stoi(x);
    if(this->horizontal == nullptr){
        Header* nueva = new Header(x);
        this->horizontal = nueva;
        return nueva;
    }
    Header* aux = this->horizontal;
   if(xAscci <= stoi(aux->getNombre())){
       Header* nueva = new Header(x);
       nueva->setNext(aux);
       this->horizontal->setPrevious(nueva);
       this->horizontal = nueva;
       return nueva;
   }
   while (aux->getNext() != nullptr) {
        if (xAscci > stoi(aux->getNombre()) && xAscci  <= stoi(((Header*)aux->getNext())->getNombre())){
            Header* nuevo = new Header(x);
            Header* tmp = (Header*)aux->getNext();
            tmp->setPrevious(nuevo);
            nuevo->setNext(tmp);
            aux->setNext(nuevo);
            nuevo->setPrevious(aux);
            return nuevo;
        }
        aux = (Header*)aux->getNext();
   }
   Header* nuevo = new Header(x);
   aux->setNext(nuevo);
   nuevo->setPrevious(aux);
  return nuevo;

}

Header *Matriz::setVertical(string y ){
    int yAscii = stoi(y);
    if (this->vertical == nullptr){
        Header* nueva = new Header(y);
        this->vertical = nueva;
        return nueva;
    }

    Header* aux = this->vertical;
    if ( yAscii <= stoi(aux->getNombre())){
        Header* nueva = new Header(y);
        nueva->setDown(aux);
        this->vertical->setUp(nueva);
        this->vertical = nueva;
        return nueva;
    }
    while (aux->getDown() != nullptr){
        if (yAscii > stoi(aux->getNombre()) && yAscii <= stoi(((Header*)aux->getDown())->getNombre())){
            Header* nuevo = new Header(y);
            Header* tmp = (Header*)aux->getDown();
            tmp->setUp(nuevo);
            nuevo->setDown(tmp);
            aux->setDown(nuevo);
            nuevo->setUp(aux);
            return nuevo;
        }
        aux = (Header*)aux->getDown();
    }

        Header* nuevo = new Header(y);
        aux->setDown(nuevo);
        nuevo->setUp(aux);
        return nuevo;
}

NodoM *Matriz::getUltimoH(Header *cabecera, string x){
    int xAscii = stoi(x);
    if(cabecera->getNext() == nullptr){return cabecera;}
    NodoM* aux = cabecera->getNext();
    if(xAscii <= stoi(((Object*)aux)->getX())){
        return cabecera;
    }
    while (aux->getNext() != nullptr) {
        if(xAscii > stoi(((Object*)aux)->getX()) && xAscii <= stoi(((Object*)aux->getNext())->getX())){
            return aux;
        }
        aux = aux->getNext();
    }
    return aux;

}
NodoM *Matriz::getUltimoV(Header *cabecera, string y){
    int yAscii = stoi(y);
    if(cabecera->getDown() == nullptr){return cabecera;}
    NodoM* aux = cabecera->getDown();
    if(yAscii <= stoi(((Object*)aux)->getY())){return cabecera;}
    while (aux->getDown() != nullptr) {
        if(yAscii > stoi(((Object*)aux)->getY()) && yAscii <= stoi(((Object*)aux->getDown())->getY())){
            return aux;
        }
        aux = aux->getDown();
    }
    return aux;

}
Header* Matriz::getHorizontal(string x)
{
    if (this->horizontal == nullptr)
    {
        return nullptr;
    }
    Header* aux = this->horizontal;
    while (aux != nullptr)
    {
        if (((string)aux->getNombre()) == x)
        {
            return aux;
        }
        aux = (Header*)aux->getNext();
    }
    return nullptr;

}
Header* Matriz::getVertical(string y)
{
    if (this->vertical == nullptr){return nullptr;}
    Header* aux = this->vertical;
    while (aux != nullptr)
    {
        if (((string)aux->getNombre()) == y){
            return aux;
        }
        aux = (Header*)aux->getDown();
    }
    return nullptr;
}
bool Matriz::existPosicion(string x, string y){
    if(x == "" || y ==""){}
   return true;
}

void Matriz::setPointEmpty(){
    //Maxima posicion en x
    int x = 0;
    //Maxima posicion en y
    int y = 0;

    Header* auxV = this->vertical;
    while (auxV != nullptr){
            y = y + 1;
            auxV = (Header*)auxV->getDown();
    }

    Header* auxH = this->horizontal;
    while (auxH != nullptr){
            x = x + 1;
            auxH = (Header*)auxH->getNext();
    }

    for (int i = 0; i < y; i++){
        for (int j = 0; j < x; j++){
            this->coutEspacio++;
                //cout << "X max: " << j << " Y max: " << i  << endl;
                // j = x ; i = y
                this->add(-1000000, "",to_string(j), to_string(i));
        }

    }
}
void Matriz::add(int id,string element, string x, string y){
    if(stoi(x)>= 0 && stoi(y) >= 0){
        if(!this->listaPuntos->existPunto(x,y)){
            Object* newObject = new Object(id,element,x,y);
            add(newObject,x,y);
            Puntos* punto = new Puntos(x,y);
            this->listaPuntos->add(punto);
        }
    }
}
void Matriz::add(Object *objeto, string x, string y){
    Header* vertical = this->getVertical(y);
    Header* horizontal = this->getHorizontal(x);

    if(vertical == nullptr){vertical = setVertical(y);}
    if(horizontal == nullptr){horizontal = setHorizontal(x);}

    NodoM* left = getUltimoH(vertical,x);
    NodoM* up = getUltimoV(horizontal,y);

    if(left->getNext() == nullptr){
        left->setNext(objeto);
        objeto->setPrevious(left);
    }else{
        NodoM* temp = left->getNext();
        left->setNext(objeto);
        objeto->setPrevious(left);
        temp->setPrevious(objeto);
        objeto->setNext(temp);
    }

    if(up->getDown() == nullptr){
        up->setDown(objeto);
        objeto->setUp(up);
    }else{
        NodoM* temp = up->getDown();
        up->setDown(objeto);
        objeto->setUp(up);
        temp->setUp(objeto);
        objeto->setDown(temp);
    }
}
void Matriz::graficar(){
    this->setPointEmpty();
    int grupos = 0;
    NodoM* vertical;
    NodoM* horizontal;
    ostringstream cadena;
    cadena << "digraph G{" << endl << "node[shape=\"box\"];\n graph[splines=\"ortho\"];" << endl;
    cadena << "nodo[label=\"Nivel " << "1" <<"\"; group=0];\n";
    vertical = this->vertical;

    while (vertical != nullptr) {
        cadena << "node" << &(*vertical) << "[label=\"" << ((Header*)vertical)->getNombre() << "\", group=" << grupos << "];\n";
        vertical = vertical->getDown();
    }
    grupos++;
    horizontal = this->horizontal;
    int temp = grupos;
    while (horizontal != nullptr) {
        cadena << "node" << &(*horizontal) << "[label=\"" << ((Header*)horizontal)->getNombre() << "\", group=" << grupos << "];\n";
        horizontal = horizontal->getNext();
        grupos++;
    }
    grupos = temp;

    vertical = this->vertical;
    while (vertical->getDown() != nullptr) {
        cadena << "node" << &(*vertical) << "->node" << &(*vertical->getDown()) << ";\n";
        cadena << "node" << &(*vertical->getDown()) << "->node" << &(*vertical) << ";\n";
        vertical = vertical->getDown();
    }

    horizontal = this->horizontal;
    while (horizontal->getNext() != nullptr) {
        cadena << "node" << &(*horizontal) << "->node" << &(*horizontal->getNext()) << ";\n";
        cadena << "node" << &(*horizontal->getNext()) << "->node" << &(*horizontal) << ";\n";
        horizontal = horizontal->getNext();
    }

    horizontal = this->horizontal;
    while (horizontal != nullptr) {
        NodoM* aux = horizontal->getDown();
        while (aux != nullptr) {
            if(((Object*)aux)->getId() == -1000000){
                cadena << "node" << &(*aux) << "[shape=\"point\", width = 0, fontcolor=\"white\", color=\"" << "" << "\", style=\"filled\", label=\"" << ((Object*)aux)->getData() << "\"" << ", group = " << grupos << "];\n";
            }else{
                cadena << "node" << &(*aux) << "[shape=\"circle\", fontcolor=\"white\", color=\"" << "" << "\", style=\"filled\", label=\"" << ((Object*)aux)->getData() << "\"" << ", group = " << grupos << "];\n";
            }
            aux = aux->getDown();
        }
        grupos++;
        horizontal = horizontal->getNext();
    }
    horizontal = this->horizontal;
    while (horizontal != nullptr) {
        NodoM* aux = horizontal;
        while (aux->getDown() != nullptr) {
            if(((Object*)aux)->getId() != -1000000 && ((Object*)aux->getDown())->getId() == -1000000){
                cadena << "node" << &(*aux->getDown()) << "->node" << &(*aux) << ";\n";
            }else if(((Object*)aux)->getId() == -1000000 && ((Object*)aux->getDown())->getId() != -1000000){
                cadena << "node" << &(*aux) << "->node" << &(*aux->getDown()) << ";\n";
            }else if(((Object*)aux)->getId() == -1000000 && ((Object*)aux->getDown())->getId() == -1000000){
                cadena << "node" << &(*aux) << "->node" << &(*aux->getDown()) << "[ dir = none ];\n";
            }else{
                cadena << "node" << &(*aux) << "->node" << &(*aux->getDown()) << ";\n";
                cadena << "node" << &(*aux->getDown()) << "->node" << &(*aux) << ";\n";
            }
            aux = aux->getDown();
        }
        horizontal = horizontal->getNext();
    }
    vertical = this->vertical;
    while (vertical != nullptr) {
        NodoM* aux = vertical;
        while (aux->getNext() != nullptr) {
            if(((Object*)aux)->getId() != -1000000 &&((Object*)aux->getNext())->getId() == -1000000){
                cadena << "node" << &(*aux->getNext()) << "->node" << &(*aux) << ";\n";
            }else if(((Object*)aux)->getId() == -1000000 && ((Object*)aux->getNext())->getId() != -1000000){
                cadena << "node" << &(*aux) << "->node" << &(*aux->getNext()) << ";\n";
            }else if(((Object*)aux)->getId() == -1000000 && ((Object*)aux->getNext())->getId() == -1000000){
                cadena << "node" << &(*aux) << "->node" << &(*aux->getNext()) << "[ dir = none ];\n";
            }else{
                cadena << "node" << &(*aux) << "->node" << &(*aux->getNext()) << ";\n";
                cadena << "node" << &(*aux->getNext()) << "->node" << &(*aux) << ";\n";
            }
            aux = aux->getNext();
        }
        vertical = vertical->getDown();
    }
    if(this->vertical != nullptr){
        cadena << "nodo->node" << &(*this->vertical) << "\n";
        cadena << "nodo->node" << &(*this->horizontal) << "\n";
        cadena << "{rank=\"same\";nodo;node" << &(*this->horizontal);
        horizontal = this->horizontal;
        while (horizontal != nullptr) {
            cadena << ";node" << &(*horizontal);
            horizontal = horizontal->getNext();
        }
        cadena << "};" << endl;
    }
    vertical = this->vertical;
    while (vertical != nullptr) {
        NodoM* aux = vertical->getNext();
        cadena << "{rank=\"same\";node" << &(*vertical);
        while (aux != nullptr) {
            cadena << ";node" << &(*aux);
            aux = aux->getNext();
        }
        cadena << "};" << endl;
        vertical = vertical->getDown();
    }
    cadena << "}" << endl;
    cout << cadena.str() << endl;

}
