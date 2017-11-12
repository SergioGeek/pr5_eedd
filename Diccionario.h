

#ifndef PR1_DICCIONARIO_H
#define PR1_DICCIONARIO_H


#include "VDinamico.h"
#include "Palabra.h"
#include <fstream>



class Diccionario {


private:

    static const long int espacio = 80383;

    VDinamico < Palabra > hojas;



public:

    //Constructores
    Diccionario ( std::string ruta );
    Diccionario ( const Diccionario& orig );

    //Operaciones
    long int busca ( const std::string &termino );
    void insertar ( std::string &termino );
    void entrena ( const std::string& frase );
    void usacorpus ( const std::string& nom_fich_corpus );
    ListaEnlazada < std::string > sacaSucesoresDe ( const std::string& p );

    //Destructor
    virtual ~Diccionario();



};


#endif //PR1_DICCIONARIO_H
