#include "Vigenere_c.h"
#include <iostream>
Vigenere_c::Vigenere_c()
{
    alfabeto = "abcdefghijklmnopqrstuvwxyz(espacio)ABCDEFGHIJKLMNOPQRSTUVWXYZ,."
    clave = "PERO CASI";
}
string Vigenere_c::cifrado(string mensaje,string
                           {

    int aux, pos1, pos2;
    int iterador = 0;
    int tam_mens = mensaje.size();
    int tam_abc = alfabeto.size();
    int tam_codigo = clave.size();

    for(int i=0;i<tam_mens;i++){

        if(iterador>tam_codigo)iterador=0;
        pos1 = alfabeto.find(clave[iterador]);

        pos2 = alfabeto.find(mensaje[i]) + pos1;
        while(pos2>=tam_abc)

            pos2-=tam_abc;

        mensaje[i] = alfabeto[pos2];
    }
    return mensaje;

}
string Vigenere_c::descifrar(string mensaje){

    int aux, pos1,pos2;
    int iterador = 0;
    int tam_mens = mensaje.size();
    int tam_abc = alfabeto.size();
    int tam_codigo = clave.size();

    for(int i=0;i<tam_mens;i++){

        if(iterador>tam_codigo)iterador=0;
        pos1 = alfabeto.find(clave[iterador]);

        pos2 = alfabeto.find(mensaje[i])-pos1;

        while(pos2<0)

            pos2+=tam_abc;

        mensaje[i] = alfabeto[pos2];
    }

    return mensaje;
}
