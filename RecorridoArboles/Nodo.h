#pragma once
#include <iostream>

class Nodo
{
    public:
        int dato;
        Nodo* hijoIzq;
        Nodo* hijoDer;
        Nodo(int dato);
};