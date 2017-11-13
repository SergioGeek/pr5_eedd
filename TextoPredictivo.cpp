
#include "TextoPredictivo.h"


TextoPredictivo::TextoPredictivo( Diccionario* diccIdioma ): dic ( diccIdioma ) {
}

TextoPredictivo::TextoPredictivo ( const TextoPredictivo& orig ) : dic ( orig.dic ) {
}

std::list<std::string> TextoPredictivo::sugerencia(std::string &termino){

    return this->dic->busca ( termino )->sucesores ();
}

void TextoPredictivo::entrena(std::string &frase){
    //dic->entrena(frase);
}

TextoPredictivo::~TextoPredictivo() {
}