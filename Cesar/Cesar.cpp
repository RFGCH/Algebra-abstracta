#include "Cesar.h"

Cesar::Cesar()
{
   alfabeto = "abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ,.";
   clave = 7;
}

string Cesar::cifrado(string mensaje){

    int aux, pos;
    int tam = mensaje.size();
    int abc = alfabeto.size();
    for(int i=0;i<tam;i++){
        pos = alfabeto.find(mensaje[i]);
        aux = pos+clave;
        while(aux>=abc)aux-=abc;//%
        mensaje[i]=alfabeto[aux];
    }
    return mensaje;
}
string Cesar::descifrar(string mensaje){

    int aux, pos;
    int tam = mensaje.size();
    int abc = alfabeto.size();
    for(int i=0;i<tam;i++){
        pos = alfabeto.find(mensaje[i]);
        aux = pos-clave;
        while(aux<0)aux+=abc;
        mensaje[i]=alfabeto[aux];
    }
    return mensaje;
}
