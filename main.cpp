#include <iostream>
#include "AVL.h"
#include "Palabra.h"
#include "Diccionario.h"

int main() {


    Diccionario d ( "/home/anonymous/Documents/eedd_practice/pr5_eedd/listado-sin-acentos_v2.txt");

    Diccionario z;

    z = d;

    //Diccionario p ( z );


    std::string termino = "zuzon";

    if(d.busca(termino))
        std::cout << "Vamooooooooooooooos";


    return 0;
}



