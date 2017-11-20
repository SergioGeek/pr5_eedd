
#include <iostream>
#include <sstream>
#include "Diccionario.h"



Diccionario::Diccionario() {}

Diccionario::Diccionario( std::string ruta ) {


    std::ifstream fe;
    std::string linea;

    Palabra* pp = 0;

    fe.open( ruta );

    if ( fe.good() ) {

        while ( !fe.eof() ) {

            getline( fe, linea );

            if ( linea != "") {

                Palabra p ( linea );
                this->hojas.insertar( p, pp );
            }
        }

        fe.close();

    } else {

        throw std::string ( "El archivo no se ha podido abrir correctamente" );

    }
}


Diccionario::Diccionario( Diccionario &orig) : hojas ( orig.hojas ) {}


//BUSCA
Palabra* Diccionario::busca ( const std::string &termino ) {

    Palabra p(termino);
    return this->hojas.busca ( p );

}




void Diccionario::insertar(std::string &termino) {


    Palabra p ( termino );
    Palabra* pp = 0;
    this->hojas.insertar( p, pp );
}


void Diccionario::entrena ( const std::string& frase ) {

    std::string palabra = "", predecesor = "";
    std::stringstream ss;
    Palabra* pos = 0;
    ss << frase;	//enviamos la cadena al stream
    while (!ss.eof()) {
        ss >> palabra;	//leemos la siguiente palabra
        if (palabra!="") {

            Palabra termino ( palabra );
            this->hojas.insertar( termino, pos );

            if ( predecesor != "") {
                pos->nuevoSucesor( predecesor );
            }
        }

        predecesor = palabra;
    }

}


void Diccionario::usacorpus ( const std::string &nom_fich_corpus ) {

    std::ifstream fe;
    std::string linea;

    fe.open( nom_fich_corpus );

    if ( fe.good() ) {

        while ( !fe.eof() ) {

            getline( fe, linea );

            if ( linea != "") {

                this->entrena( linea );
            }
        }

        fe.close();

    } else {

        throw std::string ( "El archivo no se ha podido abrir correctamente" );

    }
    std::cout << "Fin de corpus" <<std::endl;

}

std::list < std::string > Diccionario::sacaSucesoresDe(const std::string &p) {

    Palabra termino ( p );

    Palabra* pp = this->hojas.busca( termino );

    if ( !pp )
        throw std::string ( "La palabra no tiene sucesores porque no está en el diccionario" );

    return pp->sucesores();
}

void Diccionario::muestra() {
    this->hojas.muestraAVL();
}

Diccionario::~Diccionario() {}