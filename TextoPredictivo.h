
#ifndef PR5_EEDD_TEXTOPREDICTIVO_H
#define PR5_EEDD_TEXTOPREDICTIVO_H


#include "Diccionario.h"
#include <list>

class TextoPredictivo {

private:

    Diccionario* dic;

public:

    TextoPredictivo( Diccionario *diccIdioma );
    TextoPredictivo( const TextoPredictivo& orig);

    std::list<std::string> sugerencia(std::string &termino);
    void entrena ( std::string& frase );

    virtual ~TextoPredictivo();

};


#endif //PR5_EEDD_TEXTOPREDICTIVO_H
