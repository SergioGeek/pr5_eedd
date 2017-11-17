#include <iostream>
#include "Palabra.h"
#include "Diccionario.h"
#include "TextoPredictivo.h"

int main() {



    //Primer programa de prueba
    AVL < int > arbol;

    int* p = 0;

    int cinco = 5, dos = 2, ocho = 8, siete = 7, seis = 6, nueve = 9;

    arbol.muestraAVL();
    arbol.insertar(cinco, p);
    arbol.muestraAVL();
    std::cout << " ============================ " << std::endl;
    arbol.insertar(dos, p);
    arbol.muestraAVL();
    std::cout << " ============================ " << std::endl;
    arbol.insertar(ocho, p);
    arbol.muestraAVL();
    std::cout << " ============================ " << std::endl;
    arbol.insertar(siete, p);
    arbol.muestraAVL();
    std::cout << " ============================ " << std::endl;
    arbol.insertar(seis, p);
    arbol.muestraAVL();
    std::cout << " ============================ " << std::endl;
    arbol.insertar(nueve, p);
    arbol.muestraAVL();
    std::cout << " ============================ " << std::endl;




    //Segundo programa de prueba



    Diccionario d ( "/home/administrador/Escritorio/pr5_eedd/listado-sin-acentos_v2.txt" );


    d.usacorpus( "/home/administrador/Escritorio/pr5_eedd/corpus_spanish.txt" );


    TextoPredictivo tp ( d );

    std::string frase = "escriba su frase";

    tp.entrena( frase );

    std::string termino = "frase";

    auto lista = tp.sugerencia( termino );

    std::list < std::string >::iterator it = lista.begin();

    std::cout << "Palabra recomendada" << std::endl;

    std::cout << *it << std::endl;





   //d.muestra();

    return 0;
}



