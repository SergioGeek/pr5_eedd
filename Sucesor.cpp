
#include "Sucesor.h"


Sucesor::Sucesor () : termino ( "" ), numOcurrencias ( 0 ){}

Sucesor::Sucesor ( const std::string& term ) : termino ( term ), numOcurrencias ( 1 ) {}

const std::string& Sucesor::getTermino () const { return this->termino; }

bool Sucesor::operator < ( const Sucesor& orig ) const{
    return numOcurrencias < orig.numOcurrencias;
}

void Sucesor::incrementar() { ++this->numOcurrencias; }