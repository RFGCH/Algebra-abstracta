#include "Vigenere_c.h"
#include <iostream>
Vigenere_c::Vigenere_c()
{
    alfabeto_NUM = "abcdefghijklmnopqrstuvwxyz -ABCDEFGHIJKLMNOPQRSTUVWXYZ,.0123456789";

    clave = "Ruben Felix Guzman Chiroque 191-10-45131";
}
string Vigenere_c::cifrado(string mensaje,string alfabeto){


    alfabeto=alfabeto_NUM;

    int aux, pos1, pos2;
    int iterador = 0;
    int tam_mens = mensaje.size();
    int tam_abc = alfabeto.size();
    int tam_codigo = clave.size()-1;

    for(int i=0;i<tam_mens;i++){

        if(iterador>tam_codigo)iterador=0;
        pos1 = alfabeto.find(clave[iterador]);
        iterador++;

        pos2 = alfabeto.find(mensaje[i]) + pos1;
        while(pos2>=tam_abc)

            pos2-=tam_abc;

        mensaje[i] = alfabeto[pos2];
    }
    return mensaje;

}
string Vigenere_c::descifrar(string mensaje, string alfabeto){

    if(alfabeto=="NUM")
        alfabeto=alfabeto_NUM;
    else if(alfabeto=="HEX")
        alfabeto=alfabeto_HEX;
    else alfabeto=alfabeto_ASCII;

    int aux, pos1,pos2;
    int iterador = 0;
    int tam_mens = mensaje.size();
    int tam_abc = alfabeto.size();
    int tam_codigo = clave.size()-1;

    for(int i=0;i<tam_mens;i++){

        if(iterador>tam_codigo)iterador=0;
        pos1 = alfabeto.find(clave[iterador]);
        iterador++;

        pos2 = alfabeto.find(mensaje[i])-pos1;

        while(pos2<0)

            pos2+=tam_abc;

        mensaje[i] = alfabeto[pos2];
    }

    return mensaje;
}