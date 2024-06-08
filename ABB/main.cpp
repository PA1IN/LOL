#include <iostream>
#include "Nodo.h"
#include <stack>

using namespace std;

Nodo* busquedaRec(Nodo* &raiz, int datoABuscar)
{
    if(!raiz)
    {
        return nullptr;
    }

    if(raiz->dato == datoABuscar)
    {
        return raiz;
    }

    if(raiz->dato > datoABuscar)
    {
        return busquedaRec(raiz->hijoIzq,datoABuscar);
    }
    return busquedaRec(raiz->hijoDer,datoABuscar);
}

Nodo* insertarNodoRec(Nodo* &raiz, int dato)
{
    if(raiz == nullptr)
    {
        return new Nodo(dato);
    }

    Nodo* existe = busquedaRec(raiz,dato);

    if(existe == nullptr)
    {
        if(raiz->dato > dato)
        {
            raiz->hijoIzq = insertarNodoRec(raiz->hijoIzq,dato);
        }
        else
        {
            raiz->hijoDer = insertarNodoRec(raiz->hijoDer,dato);
        }
    }
    else
    {
        cout<<"Número repetido."<<endl;
    }
    return raiz;
}

void inOrdenRecursivo(Nodo* &raiz)
{
    if(raiz == nullptr){
        return;
    }
    
    inOrdenRecursivo(raiz->hijoIzq);
    cout<<raiz->dato<<"";
    inOrdenRecursivo(raiz->hijoDer);
}

Nodo* menorDeLosMayores(Nodo* raiz)
{
    Nodo* actual = raiz;

    while(actual != nullptr)
    {
        actual = actual->hijoIzq;
    }
    return actual;
}

void eliminar(Nodo* &raiz, int datoAEliminar)
{
    if(raiz == nullptr)
    {
        return;
    }

    if(datoAEliminar > raiz->dato)
    {
        eliminar(raiz->hijoDer, datoAEliminar);
    }else if(datoAEliminar < raiz->dato)
    {
        eliminar(raiz->hijoIzq, datoAEliminar);
    }else
    {
        if(raiz->hijoDer == nullptr)
        {
            Nodo* temp = raiz->hijoIzq;
            delete raiz;
            raiz = temp;
        }
        else if(raiz->hijoIzq == nullptr)
        {
            Nodo* temp = raiz->hijoDer;
            delete raiz;
            raiz = temp;
        }
        else
        {
            Nodo* temp = menorDeLosMayores(raiz->hijoDer);   
            raiz->dato = temp->dato;
            eliminar(raiz->hijoDer,temp->dato);
        }
    }
}


int main()
{
    Nodo* raiz = nullptr;
    raiz = insertarNodoRec(raiz, 5);
    insertarNodoRec(raiz,3);
    insertarNodoRec(raiz,8);
    insertarNodoRec(raiz,2);
    insertarNodoRec(raiz,4);
    insertarNodoRec(raiz,7);
    insertarNodoRec(raiz,9);
    insertarNodoRec(raiz,3); //Repetido para confirmar la Busqueda y revisión.

    cout<<"comprobar que se armó correctamente:"<<endl;
    inOrdenRecursivo(raiz);

    eliminar(raiz,raiz->dato);
    cout<<"comprobar que se eliminó correctamente:"<<endl;
    inOrdenRecursivo(raiz);
}