//FICHERO TADPila.cpp
#include "TADPila.h"
pila::pila()
{
    elementos=new int[INCREMENTO];
    Tama=(elementos!=NULL ? INCREMENTO : -1);
    Tope=-1;
}
pila::~pila()
{
    if (elementos!=NULL)
        delete [] elementos;
    elementos=NULL;
    Tope=-1;
    Tama=0;
}
void pila::apilar(int e)
{
    if (Tope+1==Tama)
    {
        int *NuevaZona=new int[Tama+INCREMENTO];
        if (NuevaZona!=NULL)
        {
            for (int i=0; i<Tama; i++)
                NuevaZona[i]=elementos[i];
            Tama+=INCREMENTO;
            delete [] elementos;
            elementos=NuevaZona;
        }
    };
    if (Tope+1<Tama)
        elementos[++Tope]=e;
}
void pila::desapilar()
{
    Tope--;
    if (Tama-Tope>INCREMENTO && Tama>INCREMENTO)
    {
        int *NuevaZona=new int[Tama-INCREMENTO];
        if (NuevaZona!=NULL)
        {
            Tama-=INCREMENTO;
            for (int i=0; i<Tama; i++)
                NuevaZona[i]=elementos[i];
            delete [] elementos;
            elementos=NuevaZona;
        };
    };
}
int pila::cima()
{
    return elementos[Tope];
}
bool pila::esvacia()
{
    return (Tope == -1);
}
int pila::longitud()
{
    return (Tope+1);
}
