#include <iostream>
#include "Nodo.h"

Nodo::Nodo(int dato)
{
    this->dato = dato;
    this->hijoIzq = nullptr;
    this->hijoDer = nullptr;
}