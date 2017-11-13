

#ifndef PR1_DICCIONARIO_H
#define PR1_DICCIONARIO_H


#include "Palabra.h"
#include "AVL.h"
#include <fstream>



class Diccionario {


private:


    AVL < Palabra > hojas;



public:

    //Constructores
    Diccionario();
    Diccionario ( std::string ruta );
    //Diccionario ( const Diccionario& orig );

    //Operaciones
    Palabra* busca ( const std::string &termino );
    void insertar ( std::string &termino );
    //void entrena ( const std::string& frase );
    void usacorpus ( const std::string& nom_fich_corpus );
    std::list < std::string > sacaSucesoresDe ( const std::string& p );

    //Destructor
    virtual ~Diccionario();



};


#endif //PR1_DICCIONARIO_H
