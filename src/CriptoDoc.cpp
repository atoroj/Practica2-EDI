#include <iostream>
#include <fstream>
#include <string>
#include "string.h"
#include "CriptoDoc.h"

bool CriptoDoc::leer(char fichero[]){
    bool abierto = false;
    linea cadena;
    int cont = 1;
    ifstream fich(fichero);
    if(!fich.fail()){
        if(!texto.esvacia()){
            vaciar();
        }
            getline(fich, cadena); //SI PONGO ESTO LA ULTIMA LINEA NO LA COGE, YA QUE LEE Y PIENSA QUE ESTÁ EN FINAL DE FICHERO
            //texto.insertar(cont,cadena);
            while(!fich.eof()){
                texto.insertar(cont,cadena);
                getline(fich, cadena);
                cont++;
            }
            texto.insertar(cont,cadena);
        abierto = true;
        fich.close();
    }
    return abierto;
}

bool CriptoDoc::escribir(char fichero[]){
    bool abierto = false;
    linea cadena;
    ofstream fich(fichero);
    if(!fich.fail()){
        if(!texto.esvacia()){
            for(int i = 1; i<texto.longitud(); i++){
                cadena = texto.observar(i);
                fich << cadena << endl;
            }
        }
        abierto = true;
        fich.close();
    }
    return abierto;
}

void CriptoDoc::cifrar(int codigo){
    linea l;
    if(!texto.esvacia()){
        for(int i = 1; i<=texto.longitud(); i++){
            l = texto.observar(i);
                for(int j = 0; j<l.length(); j++){
                    l[j]=l[j]+codigo;
                        if(l[j]>255){
                            l[j]=l[j]-256;
                        }
                }
                texto.modificar(i,l);
        }
    }
}

void CriptoDoc::descifrar(int codigo){
    linea l;
    if(!texto.esvacia()){
        for(int i = 1; i<=numlineas(); i++){
            l = texto.observar(i);
                    for(int j = 0; j<l.length(); j++){
                            //cout << l.length() << endl;
                            if((l[j]-codigo) < 0){
                                l[j] = (l[j]-codigo) + 256;
                            }else{
                                l[j] = (l[j]-codigo);
                            }
                    }
                texto.modificar(i,l);
        }
    }
}

void CriptoDoc::vaciar(){
    if(!texto.esvacia()){
        for(int i = 1; i<texto.longitud(); i++){
            texto.eliminar(i);
        }
    }
}

int CriptoDoc::numlineas(){
    return texto.longitud();
}

linea CriptoDoc::observar(int i){
    return texto.observar(i);
}

void CriptoDoc::concatenar(CriptoDoc &doc){
    //texto.concatenar(doc.texto);
    for(int i = 1; i<doc.texto.longitud(); i++){
        texto.insertar(texto.longitud()+1, doc.texto.observar(i));
    }
}

//EXAMEN MODIFICACION 2
void CriptoDoc::insertarlinea(linea l){
        texto.anadirDch(l);
}
