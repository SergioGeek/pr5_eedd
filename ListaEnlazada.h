
#ifndef PR3_LISTAENLAZADA_H
#define PR3_LISTAENLAZADA_H

#include <iostream>

template < typename T >
class ListaEnlazada {

private:

    //CLASE NODO

    class Nodo {

    public:

        T dato;
        Nodo* siguiente;

        //Constructor
        Nodo ( const T &d, Nodo* sig = 0 ) : dato ( d ), siguiente ( sig ) {};
        //Desctructor
        virtual ~Nodo () {};
    };

    //ATRIBUTOS CLASE LISTA ENLAZADA

    Nodo* cabecera;
    Nodo* cola;


public:

    //CLASE ITERADOR
    class Iterador {

    private:

        Nodo* pNodo;

    public:

        //Constructor
        Iterador ( Nodo* nodo ) : pNodo ( nodo ) {};

        //Operaciones
        bool fin () { return pNodo == 0; };
        void siguiente() { pNodo = pNodo->siguiente; };
        T& dato () {  return pNodo->dato; };

        //Desctructor
        virtual ~Iterador() {};
    };


    //MÉTODOS CLASE LISTA ENLAZADA

    //Constructores
    ListaEnlazada ();
    ListaEnlazada ( const ListaEnlazada& orig );

    //Operadores
    ListaEnlazada < T >& operator = ( const ListaEnlazada < T >& orig );

    //Operaciones
    T& inicio ();
    T& fin ();
    Iterador iterador () const { return Iterador ( this->cabecera ); }; //Obtiene un iterador en la cabecera de la lista
    void insertarInicio ( const T& dato );
    void insertarFin ( const T& dato );
    void inserta ( Iterador& i, T& dato );
    void borraInicio ();
    void borraFinal();
    void borra ( Iterador& i );

    //Destructor
    virtual ~ListaEnlazada ();

};


//Constructor por Defecto
template < typename T >
ListaEnlazada < T > :: ListaEnlazada () : cabecera ( 0 ), cola ( 0 ) {}

//Constructor Copia
template < typename T >
ListaEnlazada < T > :: ListaEnlazada ( const ListaEnlazada &orig ) : cabecera ( 0 ), cola ( 0 ) {

    if ( orig.cabecera ) {

        Nodo *p = orig.cabecera;

        Nodo *nNodo = new Nodo(p->dato);

        this->cabecera = this->cola = nNodo;

        p = p->siguiente;

        while (p) {

            nNodo = new Nodo(p->dato);

            cola->siguiente = nNodo;
            cola = cola->siguiente;

            p = p->siguiente;
        }

    }
}


//Operador =
template<class T>
ListaEnlazada<T> &ListaEnlazada<T>::operator = (const ListaEnlazada < T >& orig ){

    if ( orig.cabecera != this->cabecera ){

        if ( this->cabecera ) {
              Nodo *borra= cabecera;

              while ( borra ){
                  cabecera = cabecera->siguiente;
                  delete borra;
                  borra=cabecera;//borro puntero a nodo
              }
              cola = 0;
        }
        Nodo *i= orig.cabecera;
        cabecera=0;
        cola=0;

        while (i){

             Nodo *nuevo;
             nuevo = new Nodo(i->dato, 0);

             if ( cola != 0 )
                 cola->siguiente = nuevo;

            if ( cabecera == 0 )
                 cabecera = nuevo;
             cola = nuevo;
             i = i->siguiente;
            }
        }
    return ( *this );

}

//Obtener el primer elemento
template < typename T >
T& ListaEnlazada < T > :: inicio () {

    if ( !this->cabecera)
        throw std::string ( "No hay datos en la lista" );

    return &this->cabecera->dato;
}

//Obtener el último elemento
template < typename T >
T& ListaEnlazada < T > :: fin () {

    if ( !this->cabecera)
        throw std::string ( "No hay datos en la lista" );

    return &this->cola->dato;
}

//Inserta un elemento al principio de la lista
template < typename T >
void ListaEnlazada < T > :: insertarInicio ( const T& dato ) {

    Nodo* nNodo = new Nodo ( dato, this->cabecera );

    if ( !this->cabecera)
        this->cola = nNodo;

    this->cabecera = nNodo;

}

//Inserta un elemento al final de la lista
template < typename T >
void ListaEnlazada < T > :: insertarFin( const T& dato ) {

    Nodo* nNodo = new Nodo ( dato );

    if ( !this->cabecera )

        this->cabecera = nNodo;
    else

        this->cola->siguiente = nNodo;


    this->cola = nNodo;
}

template < typename T >
void ListaEnlazada < T > :: inserta( Iterador& i, T& dato ) {

    if ( i.dato() == this->cabecera->dato )
        this->insertarInicio( dato );

    Nodo* p = this->cabecera->siguiente;
    Nodo* pp = this->cabecera;

    while ( p->dato != i.dato() ) {
        p = p->siguiente;
        pp = pp->siguiente;
    }

    Nodo* nNodo = new Nodo ( dato, p );

    pp->siguiente = nNodo;

}

//Borra la primera posición de la lista
template < typename T >
void ListaEnlazada < T > :: borraInicio () {

    if ( !this->cabecera)
        throw std::string ( "No hay datos en la lista" );

    if ( this->cabecera == this->cola )
        this->cola = 0;

    Nodo* p = this->cabecera->siguiente;
    delete this->cabecera;
    this->cabecera = p;
}

//Borra la última posición de la lista
template < typename T >
void ListaEnlazada < T > :: borraFinal () {

    if ( !this->cabecera)
        throw std::string ( "No hay datos en la lista" );

    if ( this->cabecera == this->cola ) {

        this->cabecera = 0;
        delete this->cola;
        this->cola = 0;

    } else {

        Nodo *p = this->cabecera;

        while (p->siguiente != this->cola)
            p = p->siguiente;

        delete this->cola;
        this->cola = p;
    }
}

template < typename T >
void ListaEnlazada < T > :: borra ( Iterador& i ) {

    if ( !this->cabecera)
        throw std::string ( "No hay datos en la lista" );

    if ( this->cabecera->dato == i.dato() )
        this->borraInicio();
    else {

        if ( this->cola->dato == i.dato() )
            this->borraFinal();

        else {

            Nodo* p = this->cabecera->siguiente;
            Nodo* pp = this->cabecera;

            while ( p->dato != i.dato() ) {
                p = p->siguiente;
                pp = pp->siguiente;
            }

            p = p->siguiente;
            delete pp->siguiente;
            pp->siguiente = p;
        }
    }

}

//Destructor
template<class T>
ListaEnlazada<T>::~ListaEnlazada(){

    if (cabecera) {

        Nodo *borra= cabecera;
        while ( borra ){
            cabecera = cabecera->siguiente;
            delete borra;
            borra = cabecera;
        }
        cola = 0;
    }
}


#endif //PR3_LISTAENLAZADA_H
