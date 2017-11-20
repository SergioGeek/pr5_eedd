#include <iostream>
#include <chrono>
#include "Palabra.h"
#include "Diccionario.h"
#include "TextoPredictivo.h"

int main() {


    try {

        //Primer programa de prueba
        AVL<int> arbol;

        int *p = 0;

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



        auto start = std::chrono::system_clock::now();

        Diccionario d("/home/anonymous/Documents/eedd_practice/pr5_eedd/listado-sin-acentos_v2.txt");


        d.usacorpus("/home/anonymous/Documents/eedd_practice/pr5_eedd/corpus_spanish.txt");

        auto end = std::chrono::system_clock::now();

        auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count();

        std::cout << "Time spent (ms): " << elapsed_ms << std::endl;

        TextoPredictivo tp(d);

        std::string frase, palabra;

        std::cout << "Introduzca una frase para entrenar: " << std::endl;
        std::getline(std::cin, frase);
        std::cout << "Introduzca la palabra de la que quiere saber sus sucesores: " << std::endl;
        std::cin >> palabra;

        tp.entrena( frase );

        std::cout << "Lista de sucesores: " << std::endl;
        std::list<std::string> l = tp.sugerencia(palabra);
        std::list<std::string>::iterator it = l.begin();

        while (it != l.end()) {
            std::cout << *it << std::endl;
            ++it;
        }






    }catch ( std::string &e ) {
        std::cout << e << std::endl;
    }
    return 0;
}



