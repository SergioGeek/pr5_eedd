
#ifndef PR2_VDINAMICO_H
#define PR2_VDINAMICO_H


#include <stdexcept>
#include <climits>
#include <algorithm>
#include <iostream>

template < typename T >
class VDinamico {

private:

    T* mem;
    unsigned tamal, tamaf;

    //Operaciones
    void aumentarTamaF ();
    void disminuirTamaF ();

public:

    //Constructores
    VDinamico ();
    VDinamico ( unsigned tam );
    VDinamico ( const VDinamico < T >& orig );
    VDinamico ( const VDinamico < T >& orig, unsigned inicio, unsigned num );

    //Operadores
    VDinamico < T >& operator = ( const VDinamico < T >& orig );
    T& operator [] ( unsigned pos );

    //Operaciones
    void insertar ( const T& dato, unsigned pos = UINT_MAX );
    T borrar ( unsigned pos = UINT_MAX );
    unsigned tam ();
    long int busquedaBin ( T p );
    void ordenar ();
    long int tamaBase2 ( long int tam );

    //Destructor
    virtual ~VDinamico ();


};


//Constructor por Defecto
template < typename T >
VDinamico < T >::VDinamico () : mem ( new T [ tamaf = 1 ] ), tamal ( 0 ) {}

//Constructor parametrizado
template < typename T >
VDinamico < T >::VDinamico ( unsigned tam ) : mem ( new T [ tamaf = tamaBase2(tam) ] ), tamal ( 0 ) {

    if ( this->tamaf < 1 )
        throw std::out_of_range ( "El tamaño del vector debe de ser mayor que 0" );
}

//Constructor copia
template  < typename T >
VDinamico < T >::VDinamico ( const VDinamico < T >& orig ) : mem ( new T [ tamaf = orig.tamaf ] ), tamal ( orig.tamal ){

    if ( orig.tamal < 1 )
        throw std::out_of_range ( "El tamaño del vector debe de ser mayor que 0" );


    for ( long int i = 0; i < this->tamal; ++i ) {

        this->mem[ i ] = orig.mem[ i ];
    }
}

//Constructor segmentado
template  < typename T >
VDinamico < T >::VDinamico ( const VDinamico < T > &orig, unsigned inicio, unsigned num ) : mem ( new T [ tamaf = orig.tamaf ] ) {


    for ( long int i = 0; i < num - 1; ++i ) {

        this->mem [ i ] = orig [ inicio + i ];
        ++this->tamal;
    }

}

//Operador "="
template < typename T >
VDinamico < T >& VDinamico < T >::operator = ( const VDinamico < T >& orig ) {

    delete[] this->mem;
    this->tamal = orig.tamal;
    this->mem = new T [ this->tamaf = orig.tamaf ];

    for ( long int i = 0; i < this->tamal; ++i ) {
        this->mem [ i ] = orig.mem [ i ];
    }

}

//Operador []
template < typename T >
T& VDinamico < T >::operator [] ( unsigned pos ) {

    if ( pos > tamal - 1 )
        throw std::out_of_range ( "Ha intenado acceder a una posición sin dato" );

    return mem[pos];
}

//Insertar
template < typename T >
void VDinamico < T >::insertar ( const T &dato, unsigned pos )  {

    if ( pos == UINT_MAX ) {

        this->mem [ this->tamal ] = dato;

    }else {

        this->mem [ pos ] = dato;
    }

    ++this->tamal;

    if ( this->tamal == this->tamaf )
        this->aumentarTamaF();
    }

//Aumentar Tamaño Físico
template < typename T >
void VDinamico < T >::aumentarTamaF () {

    T* aux = new T [ this->tamaf * 2 ];

    for ( int i = 0; i < this->tamaf; ++i )
        aux[ i ] = this->mem [ i ];

    delete[] this->mem;

    this->mem = aux;
    this->tamaf = this->tamaf * 2;
}

template < typename T >
T VDinamico < T >::borrar ( unsigned pos ) {

    T aux;

    if ( this->tamal ) {

        if ( pos == UINT_MAX ) {

            aux = this->mem [ this->tamal - 1 ];

        }else {
            aux = this->mem [ pos ];
            for ( unsigned i = pos; i < tamal-1; ++i )
                this->mem [ i ] = this->mem [ i + 1 ];
        }

        --this->tamal;
        if ( this->tamal * 3 < this->tamaf )
            this->disminuirTamaF();

    }else throw std::string ( " No puedes borrar algo que no exite" );

    return aux;
}

//Disminuir Tamaño Físico
template < typename T >
void VDinamico < T >::disminuirTamaF () {

    T* aux = new T [ this->tamaf / 2 ];

    for ( int i = 0; i < this->tamaf; ++i )
        aux[i] = this->mem [ i ];

    delete[] this->mem;

    this->mem = aux;
}

//Get Tamaño Lógico
template < typename T >
unsigned VDinamico < T >::tam () { return this->tamal; }

//BUSQUEDA_BINARIA
template < typename T >
long int VDinamico < T >::busquedaBin ( T p ) {

    bool flag = true;

    long int  pos, pos0 = 0, pos1 = this->tamal-1;

    while ( flag ) {

        pos = ( pos0 + pos1 ) / 2;

        if ( p == this->mem[ pos ] )
            return pos;

        else {

            if ( ( pos1 - pos0 ) <= 0 )
                flag = false;

            else {

                if ( p < this->mem[ pos ] ) {

                    pos1 = pos - 1;

                } else {

                    pos0 = pos + 1;
                }
            }
        }
    }
    return -1;
}

template < typename T >
void VDinamico < T >::ordenar () {
    std::sort ( this->mem, this->mem + this->tamal );
}

template < typename T >
long int VDinamico < T >::tamaBase2 ( long int tam ) {

    return pow ( 2, ceil ( log2(tam)));
}


//Destructor
template < typename T >
VDinamico < T >::~VDinamico () { delete[] mem; }





#endif //PR2_VDINAMICO_H
