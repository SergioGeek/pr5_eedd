
#ifndef PR5_EEDD_AVL_H
#define PR5_EEDD_AVL_H

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

    void recorreYCopia ( Nodo < T >*& pn, Nodo < T >*& po );
    void limpiaAVL ( Nodo < T >*& r );
    void rotDer ( Nodo < T >*& p );
    void rotIzq ( Nodo < T >*& p );


public:

    AVL ();
    AVL ( const AVL < T >& orig );
    AVL < T >& operator = (const AVL < T >& orig );
};


//Constructor por defecto
template < typename T >
AVL < T >::AVL () : raiz ( 0 ) {}

//Constructor copia
template < typename T >
AVL < T >::AVL ( const AVL<T>& orig ) {

    this->recorreYCopia( this->raiz, orig.raiz );
}

template < typename T >
void AVL < T >::recorreYCopia ( Nodo < T >*& pn, Nodo < T >*& po ) {

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


template<typename T>
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

template<typename T>
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

#endif //PR5_EEDD_AVL_H
