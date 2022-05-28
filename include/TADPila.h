#ifndef TADPILA_H
#define TADPILA_H

// FICHERO TADPila.h
#include <iostream>
#define INCREMENTO 4

using namespace std;

class pila
{
    int* elementos; // elementos de la pila
    int Tope; // tope de la pila
    int Tama; // tamaño máximo de la tabla
public:
    pila(); // constructor de la clase
    ~pila(); // destructor de la clase
    void apilar(int e);
    void desapilar();
    bool esvacia();
    int cima() ;
    int longitud();
};
#endif // TADPILA_H
