
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
    int altura, nElmentos;

    void recorreYCopia ( Nodo < T >*& pn, Nodo < T >*& po );
    void limpiaAVL ( Nodo < T >*& r );
    void rotDer ( Nodo < T >*& p );
    void rotIzq ( Nodo < T >*& p );
    bool insertaDato( Nodo<T>*& p, const T& dato, int& h );



public:

    AVL ();
    AVL ( const AVL < T >& orig );
    AVL < T >& operator = (const AVL < T >& orig );
    bool insertar ( const T& dato );
};


//Constructor por defecto
template < typename T >
AVL < T >::AVL () : raiz ( 0 ), altura ( 0 ), nElmentos ( 0 ) {}

//Constructor copia
template < typename T >
AVL < T >::AVL ( const AVL<T>& orig ) : altura ( orig.altura ), nElmentos ( nElmentos ) {

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
bool AVL < T >::insertar( const T& dato ) {

    int h = 0;
    if ( this->insertaDato ( this->raiz, dato, h ) ) {

        if ( this->altura < h )
            this->altura = h;
        ++this->nElmentos;
        return true;
    }

    return false;
}

template < typename T >
bool AVL < T >::insertaDato( Nodo < T >*& o, const T& dato, int &h ) {

    bool sol = false;

    Nodo < T > *p = o;

    if ( !p ){
        p = new Nodo < T > ( dato );
        o = p; sol=1;
    }else if ( dato > p->dato ){
        if (insertaDato( p->der, dato, h ) ){
            p->bal--;
            if ( p->bal == -1 ) sol = true;
            else if ( p->bal == -2 ) {
                if ( p->der->bal == 1) rotDer ( p->der );
                rotIzq ( o );
            }
        }
    }
    else if ( dato < p->dato ){
        if ( insertaDato ( p->izq, dato, h ) ){
            p->bal++;
            if ( p->bal == 1 ) sol = true;
            else if ( p->bal == 2 ){
                if ( p->izq->bal == -1) rotIzq ( p->izq );
                rotDer ( o );
            }
        }
    }
    ++h;
    return sol;
}


#endif //PR5_EEDD_AVL_H
