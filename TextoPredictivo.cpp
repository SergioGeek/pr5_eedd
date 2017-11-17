
#include "TextoPredictivo.h"


TextoPredictivo::TextoPredictivo( Diccionario diccIdioma ): dic ( diccIdioma ) {
}

TextoPredictivo::TextoPredictivo (  TextoPredictivo& orig ) : dic ( orig.dic ) {
}

std::list<std::string> TextoPredictivo::sugerencia(std::string &termino){


    Palabra* p = this->dic.busca(termino);
    if ( p )
    return p->sucesores();
    else
        return std::list < std::string >();
}

void TextoPredictivo::entrena(std::string &frase){
    this->dic.entrena( frase );
}

TextoPredictivo::~TextoPredictivo() {
}