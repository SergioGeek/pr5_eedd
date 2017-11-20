
#ifndef PR5_EEDD_AVL_H
#define PR5_EEDD_AVL_H

#include <iostream>

template <typename T>
class Nodo
{
public:
    Nodo<T> *izq;
    Nodo<T> *der;
    char bal;
    T dato;

    Nodo(const T &ele): izq(0), der(0), bal(0), dato(ele){}
    Nodo(const Nodo<T> *orig): izq(0), der(0), bal(orig->bal), dato(orig->dato){}
};

template < typename T >
class AVL {

private:

    Nodo < T >* raiz;
    int altura, nElmentos;

    void recorreYCopia ( Nodo < T >* &pn, Nodo < T >* po );
    void limpiaAVL ( Nodo < T >*& r );
    void rotDer ( Nodo < T >*& p );
    void rotIzq ( Nodo < T >*& p );
    bool insertaDato( Nodo<T>*& o, T& dato, int& h, bool& sol, T*& r );
    void inorden ( Nodo < T >* r );



public:

    AVL ();
    AVL (  AVL < T >& orig );
    AVL < T >& operator = ( const AVL < T >& orig );
    bool insertar ( T& dato, T*& r );
    T* busca ( T& dato );
    void muestraAVL ();
    unsigned int numElementos() { return this->nElmentos; };
    unsigned int alturaH() { return this->altura; };

    virtual ~AVL();
};


//Constructor por defecto
template < typename T >
AVL < T >::AVL () : raiz ( 0 ), altura ( 0 ), nElmentos ( 0 ) {}


//Constructor copia
template < typename T >
AVL < T >::AVL (  AVL<T>& orig ) : altura ( orig.altura ), nElmentos ( orig.nElmentos ) {

    recorreYCopia( raiz, orig.raiz );
}


template < typename T >
void AVL < T >::recorreYCopia ( Nodo < T >* &pn, Nodo < T >* po ) {

    if ( po ) {

        pn = new Nodo < T > ( po );

        recorreYCopia( pn->izq, po->izq );
        recorreYCopia( pn->der, po->der );

    } else

        pn = 0;
}

template  < typename T >
AVL < T >& AVL < T >::operator = ( const AVL < T > &orig ) {

    //preguntar si son iguales que pasa
    if ( this->raiz )
        this->limpiaAVL( this->raiz );

    this->recorreYCopia( this->raiz, orig.raiz );

    this->nElmentos = orig.nElmentos;
    this->altura = orig.altura;

    return *this;
}

template  < typename T >
void AVL < T >::limpiaAVL ( Nodo < T >*& r ) {

    if ( r ) {

        limpiaAVL( r->izq );
        limpiaAVL( r->der );
        delete r;
        r = 0;
    }
}


template < typename T >
void AVL < T >::rotDer (Nodo < T >*& p){

    Nodo<T> *q = p, *l;
    p = l = q->izq;
    q->izq = l->der;
    l->der = q;
    q->bal--;
    if (l->bal > 0)
        q->bal -= l->bal;
    l->bal--;
    if(q->bal < 0)
        l->bal -= -q->bal;
}

template < typename T >
void AVL < T >::rotIzq ( Nodo < T >*& p){

    Nodo<T> *q = p, *r;
    p = r = q->der;
    q->der = r->izq;
    r->izq = q;
    q->bal++;
    if (r->bal < 0) q->bal += -r->bal;
    r->bal++;
    if(q->bal > 0) r->bal += q->bal;
}


template  < typename T >
bool AVL < T >::insertar(  T& dato, T*& r) {

    bool sol = false;
    int h = 0;
    if ( this->insertaDato ( this->raiz, dato, h, sol, r ) ) {

        if ( this->altura < h )
            this->altura = h;
        ++this->nElmentos;
        return true;
    }

    return false;
}

template < typename T >
bool AVL < T >::insertaDato( Nodo < T >*& o, T& dato, int& h, bool& sol, T*& r ) {

    Nodo < T > *p = o;

    if ( !p ){

        p = new Nodo < T > ( dato );
        r = &p->dato;
        o = p; sol= true;

    }else if ( dato > p->dato ){
        ++h;
        if (insertaDato( p->der, dato, h, sol, r ) ){
            p->bal--;
            if ( p->bal == -2 ) {
                --h;
                if ( p->der->bal == 1)
                    rotDer ( p->der );
                rotIzq ( o );
            }
        }
    }
    else if ( dato < p->dato ){
        ++h;
        if ( insertaDato ( p->izq, dato, h, sol, r ) ){
            p->bal++;
            if ( p->bal == 2 ){
                --h;
                if ( p->izq->bal == -1)
                    rotIzq ( p->izq );
                rotDer ( o );
            }
        }
    } else if ( dato == p->dato)
        r = &p->dato;
    ++h;
    return sol;
}

template < typename T >
T* AVL < T >::busca ( T& dato  ) {

    Nodo < T >* p = this->raiz;

    while ( p ) {
        if ( dato == p->dato) {
            return &p->dato;
        }
        if ( dato < p->dato )
            p = p->izq;
        else
            p = p->der;
    }
    T* nulo = 0;
    return nulo;
}

template < typename T >
void AVL < T >::inorden ( Nodo<T>* r ) {

    if (r) {

        inorden(r->izq);

        std::cout << r->dato << std::endl;

        inorden(r->der);
    }
}

template < typename T >
void AVL < T >::muestraAVL () { if (this->raiz ) this->inorden( this->raiz ); }

template < typename T >
AVL < T >::~AVL() {
    limpiaAVL( this->raiz );
}

#endif //PR5_EEDD_AVL_H
