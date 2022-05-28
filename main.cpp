#include <iostream>
#include "CriptoDoc.h"
#include "TADLista.h"
#include "TADPila.h"
#include <fstream>
#include "string.h"

const int TAM_CADENA = 30;

typedef char cadena[TAM_CADENA];

using namespace std;

int opc;
CriptoDoc c;
cadena docCifrar, docDestino;
int cod;
int main()
{
    do
    {

        cout<< "CriptoDoc \n";
        cout<< "-------------------------------"<<endl;

        cout<<"1- Cifrar documento."<<endl;
        cout<<"2- Descifrar documento."<<endl;
        cout<<"3- Descifrar varios documentos."<<endl;
        cout<<"4- Invertir dichero de codigos."<<endl;
        cout<<"5- Salir"<<endl;
        cout<<"\nIndique la opcion deseada:";
        cin>>opc;
        switch(opc)
        {
        case 1:
        {
            cout<<"Nombre del documento a cifrar: ";
            cin >> docCifrar;
            cout<<"Nombre del documento destino: ";
            cin >> docDestino;
            do
            {
                cout<<"Codigo del 100 al 200: ";
                cin >> cod;
            }
            while(cod <= 100 && cod >= 200);

            if(c.leer(docCifrar))
            {
                c.cifrar(cod);
                //EXAMEN MODIFICACION 2 *SEGUNDO EJERCICIO*
                fstream fichLog;
                fichLog.open("log", ios::in | ios::out | ios::app);
                if(fichLog.fail()){
                    fichLog.close();
                    fichLog.clear();
                    fichLog.open("log", ios::out |ios::binary);
                    fichLog.close();
                    fichLog.clear();
                    fichLog.open("log", ios::in | ios::out);
                }if(fichLog){
                    fichLog << docDestino << " " << cod << endl;
                }
                cout << "Completado" << endl;
                if(!c.escribir(docDestino))
                {
                    cout << "No se ha podido abrir el fichero destino" << endl;
                }
            }
            else
            {
                cout << "No se ha podido abrir el fichero origen" << endl;
            }
            system("pause");
            break;
        }
        case 2:
        {


            int cod;
            cout<<"Nombre del documento a cifrar: ";
            cin >> docCifrar;
            cout<<"Nombre del documento destino: ";
            cin >> docDestino;
            do
            {
                cout<<"Codigo del 100 al 200: ";
                cin >> cod;
            }
            while(cod <= 100 && cod >= 200);

            if(c.leer(docCifrar))
            {
                c.descifrar(cod);
                cout << "Completado" << endl;
                if(!c.escribir(docDestino))
                {
                    cout << "No se ha podido abrir el fichero destino" << endl;
                }
            }
            else
            {
                cout << "No se ha podido abrir el fichero origen" << endl;
            }
            system("pause");
            break;
        }
        case 3:
        {
            CriptoDoc d;
            CriptoDoc docFinal;
            int cont = 0;
            cadena text;
            strcpy(text, "doc-");
            if(c.leer("fichCodigos"))
            {
                c.descifrar(123);
                for(int i = 1; i<c.numlineas(); i++)
                {
                    text[4]=i+'0';
                    if(d.leer(text))
                    {
                        d.descifrar(stoi(c.observar(i)));
                        docFinal.concatenar(d);
                        cont++;
                        d.vaciar();
                    }
                }
                docFinal.escribir("docDescifrado.txt");
                cout << "\nSe han descifrado: " << cont << endl;
                docFinal.vaciar();
                c.vaciar();
                cout << "Completado" << endl;
            }
            system("pause");
            break;
        }
        case 4:
        {
            linea y;
            pila p;
            CriptoDoc d;
            CriptoDoc nuevo;
            int x;
            if(c.leer("fichCodigos"))
            {
                c.descifrar(123);
                for(int i = 1; i<c.numlineas(); i++)
                {
                    x = stoi(c.observar(i));
                    p.apilar(stoi(c.observar(i)));
                }
                //ofstream fich("fichCodigos");
                for(int j = p.longitud(); j >= 0; j--)
                {
                    int x = p.cima();
                    y = to_string(x);
                    //USO DE NUEVO METODO
                    nuevo.insertarlinea(y);
                    //fich << y << endl;
                    p.desapilar();
                }
                nuevo.cifrar(123);
                nuevo.escribir("fichCodigos");
                /*if(d.leer("fichCodigos"))
                {
                    d.cifrar(123);
                    d.escribir("fichCodigos");
                }*/
                d.vaciar();
                c.vaciar();
                nuevo.vaciar();
                cout << "Completado" << endl;
            }
            system("pause");
            break;
        }
        case 5:
            opc = 0;
            break;

        }
    }
    while(opc != 0);
}
