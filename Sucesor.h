
#ifndef PR3_SUCESOR_H
#define PR3_SUCESOR_H

#include <iostream>

class Sucesor {

private:

    std::string termino;
    int numOcurrencias;

public:

    //Cosntructor
    Sucesor ();
    Sucesor ( const std::string& term );

    const std::string& getTermino () const;

    void incrementar ();

};


#endif //PR3_SUCESOR_H
