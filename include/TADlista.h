#ifndef TADLISTA_H
#define TADLISTA_H

#include <iostream>
#define INCREMENTO 4

using namespace std;

typedef string linea;

class lista
{
    linea *elementos;  // elementos de la lista
    int  n;            // nº de elementos que tiene la lista
    int Tama;          // tamaño de la tabla en cada momento
public:
    lista();  // constructor de la clase
    ~lista(); // destructor de la clase
    lista(linea e);
    bool esvacia();
    int longitud();
    void anadirIzq(linea e);
    void anadirDch(linea e);
    void eliminarIzq();
    void eliminarDch();
    linea observarIzq();
    linea observarDch();
    void concatenar(lista l);
    bool pertenece(linea e);
    void insertar(int i, linea e);
    void eliminar(int i);
    void modificar(int i, linea e);
    linea observar(int i);
    int posicion(linea e);
};
#endif // TADLISTA_H
