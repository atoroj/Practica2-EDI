#include "TADlista.h"

lista::lista()
{
    elementos=new linea[INCREMENTO];
    if (elementos!=NULL)
    {
        Tama=INCREMENTO;
        n=0;
    }
    else
    {
        Tama=n=-1;
    }
}
lista::~lista()
{
    if (elementos!=NULL)
        delete [] elementos;
    elementos=NULL;
    Tama=n=0;
}

void lista::insertar(int i, linea e)
{
    int pos;
    if (n==Tama)
    {
        linea *NuevaZona=new linea[Tama+INCREMENTO];
        if (NuevaZona!=NULL)
        {
            for (int i=0; i<n; i++)
                NuevaZona[i]=elementos[i];
            Tama+=INCREMENTO;
            delete [] elementos;
            elementos=NuevaZona;
        }
    };

    if (n<Tama)
    {
        for (pos=n-1; pos>=i-1; pos--){
            elementos[pos+1]=elementos[pos];  // Desplazamiento
        }
        elementos[i-1]=e;
        n++;
    }
}

void lista::modificar(int i, linea e)
{
    elementos[i-1]=e;
}

linea lista::observar(int i)
{
    return(elementos[i-1]);
}

bool lista::esvacia()
{
    return (n == 0);
}
void lista::eliminar(int i)
{
    while (i<n)
    {
        elementos[i-1]=elementos[i]; // Desplazamiento
        i++;
    }
    n--;
    if (Tama-n>=INCREMENTO && Tama>INCREMENTO)
    {
        linea *NuevaZona=new linea[Tama-INCREMENTO];
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

int lista::posicion(linea e)
{
    int i=0;
    while (elementos[i]!=e && i < n)
        i++;
    return (i == n ? -1 : i+1);
}

int lista::longitud()
{
    return n;
}

lista::lista(linea e)
{
    elementos=new linea[INCREMENTO];
    if (elementos!=NULL)
    {
        Tama=INCREMENTO;
        n=1;
        elementos[0]=e;
    }
    else
    {
        Tama=n=-1;
    }
}
void lista::anadirIzq(linea e)
{
    insertar(1, e);
}

void lista::anadirDch(linea e)
{
    insertar(n+1, e);
}

void lista::eliminarIzq()
{
    eliminar(1);
}

void lista::eliminarDch()
{
    eliminar(n);
}

linea lista::observarIzq()
{
    return(observar(1));
}

linea lista::observarDch()
{
    return(observar(n));
}

void lista::concatenar(lista l)
{
    int lon = l.longitud();
    for (int i=1; i<=lon; i++)
        insertar(n+1, l.observar(i));
}

bool lista::pertenece(linea e)
{
    return (posicion(e) != -1);
}
