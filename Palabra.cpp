
#include "Palabra.h"

Palabra::Palabra () : termino ( "" ), siguientes () {}

Palabra::Palabra ( const std::string &t ) : termino ( t ), siguientes () {}

Palabra::Palabra ( const Palabra &orig ) : termino ( orig.termino ), siguientes ( orig.siguientes ) {}

//OPERATOR ==
bool Palabra::operator == ( const Palabra &orig ) {

    if ( this->termino == orig.termino )
        return true;

    return false;
}

bool Palabra::operator < ( const Palabra &orig ) {

    if ( this->termino < orig.termino )
        return true;

    return false;
}

std::string Palabra::getPalabra () {
    return this->termino;
}

void Palabra::nuevoSucesor( const std::string& termino ) {

    bool encontrado = false;
    ListaEnlazada < Sucesor >::Iterador it = this->siguientes.iterador();

    while ( !it.fin() && !encontrado  ) {

        if ( it.dato().getTermino() == termino ) {

            it.dato().incrementar();
            encontrado = true;
        }

        it.siguiente();
    }

    if ( !encontrado ) {
        Sucesor s ( termino );
        this->siguientes.insertarFin ( s );
    }
}

ListaEnlazada < std::string > Palabra::sucesores() {

    ListaEnlazada < std::string > lstr;

    ListaEnlazada < Sucesor >::Iterador it = this->siguientes.iterador();

    while ( !it.fin() ){
        lstr.insertarFin( it.dato().getTermino() );
        it.siguiente();
    }

    return lstr;
}


Palabra::~Palabra() {}