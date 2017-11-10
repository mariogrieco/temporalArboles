#ifndef ARBOLAVL_H
#define ARBOLAVL_H
#include <iostream>
#include "nodoarbol.h"

using namespace std;

#define IZQUIERDO 1
#define DERECHO 0

template <class T>
class ArbolAvl
{
        NodoArbol<T> * raiz;
        bool tipo=true;
        public:

                ArbolAvl() { raiz = NULL; }


                int agregar(T elem);

                void eliminar(T elem);


                void RSD(NodoArbol<T>* nodo);
                void RSI(NodoArbol<T>* nodo);
                void RCD(NodoArbol<T>* nodo);
                void RCI(NodoArbol<T>* nodo);

                void balancear(NodoArbol<T> *nodo, int rama, bool nuevo);


                int Altura(NodoArbol<T> * pt);
                void Calcular_fe(NodoArbol<T> *pt);
                void imprimir(int band);
                void preOrden(NodoArbol<T> *p, int niv);
                void inOrden(NodoArbol<T> *p, int niv);
                void posOrden(NodoArbol<T> *p, int niv);
                NodoArbol<T> *getRaiz(){return raiz;}
                void *setRaiz(NodoArbol<T> *p){ raiz=p;}
                bool getTipo(){return tipo;	}
                int verificarAVL(NodoArbol<T> *pt);
                void simetria(NodoArbol<T> *p, NodoArbol<T> *q, int &aux);

                bool isHoja(NodoArbol<T> *nodo){
                    if(nodo->getHI() == NULL && nodo->getHD()== NULL)
                        return true;

                    return false;
                }
};

template <class T>
void ArbolAvl<T> :: imprimir(int band) {
        if(!raiz)
                return;

        if(band == 1)			//Imprimir por Pre Orden
                preOrden(raiz, 0);
        if(band == 2)			//Imprimir por Inorden
                inOrden(raiz, 0);
        if(band == 3)			//imprimir por posOrden
                posOrden(raiz, 0);
        //Programar Pos Orden
        //Programar Anchura
}
template <class T>
void ArbolAvl<T> :: preOrden(NodoArbol<T> *p, int niv) {
        for(int i = 0; i < niv; i++)
                cout << "  ";

        cout << p->getDato();
        cout <<"("<< p->getFe()<<")"<<endl;

        if(p->getFe()>1 || p->getFe() <-1)
                tipo=false;

        //p->setNivel(niv);

        if(p->getHI())
                this->preOrden(p->getHI(), niv+1);
        if(p->getHD())
                this->preOrden(p->getHD(), niv+1);
}

template <class T>
void ArbolAvl<T> :: inOrden(NodoArbol<T> *p, int niv) {
        if(p->getHI())
                this->inOrden(p->getHI(), niv+1);

        for(int i = 0; i < niv; i++)
                cout << "  ";

        cout << p->getDato() << endl;

        if(p->getHD())
                this->inOrden(p->getHD(), niv+1);
}

template <class T>
void ArbolAvl<T> :: posOrden(NodoArbol<T> *p, int niv) {
        if(p->getHD())
                this->inOrden(p->getHD(), niv+1);

        for(int i = 0; i < niv; i++)
                cout << "  ";

        cout << p->getDato() << endl;

        if(p->getHD())
                this->inOrden(p->getHD(), niv+1);
}


template <class T>
int ArbolAvl<T>::Altura ( NodoArbol<T> *pt)
{
    int ai, ad;
    if ( !pt ) return 0;
    ai= 1 + Altura(pt->getHI());
    ad= 1 + Altura(pt->getHD());
    if ( ai>ad ) return ai;
    return ad;
}
template <class T>
void ArbolAvl<T>::Calcular_fe( NodoArbol<T> *pt)
{
    pt->setFe(Altura(pt->getHD())-Altura(pt->getHI()));
    if ( pt->getHI()) Calcular_fe(pt->getHI());
    if ( pt->getHD()) Calcular_fe(pt->getHD());
}

template<class T>
int ArbolAvl<T>:: verificarAVL(NodoArbol<T> *pt){

   if(pt->getFe()> 1 || pt->getFe()< -1){
       return 1;
   }else{
       if ( pt->getHI()) verificarAVL(pt->getHI());
       if ( pt->getHD()) verificarAVL(pt->getHD());
   }
   return 0;
}

/////////////////////


template<class T>
void ArbolAvl<T>::balancear(NodoArbol<T> *nodo, int rama, bool nuevo) {
    bool salir = false;

    while (nodo && !salir) {
        if (nuevo)
            if (rama == IZQUIERDO)
                nodo->setFe(nodo->getFe() + 1);
            else
                nodo->setFe(nodo->getFe() - 1);
        else if (rama == IZQUIERDO)
            nodo->setFe(nodo->getFe() - 1);
        else
            nodo->setFe(nodo->getFe() + 1);

        if (nodo->getFe() == 0)
            salir = true;
        else if (nodo->getFe() == -2) {
            if (nodo->getHD()->getFe() == 1)
                RCI(nodo);
            else
                RSI(nodo);
            salir = true;
        } else if (nodo->getFe() == 2) {
            if (nodo->getHI()->getFe() == -1)
                RCD(nodo);
            else
                RSD(nodo);
            salir = true;
        }
        if (nodo->getP())
            if (nodo->getP()->getHD() == nodo)
                rama = DERECHO;
            else
                rama = IZQUIERDO;
        nodo = nodo->getP();
    }
}





template<class T>
void ArbolAvl<T>::RCD(NodoArbol<T>* nodo) {
//	cout << "RCD" << endl;
    NodoArbol<T> *Padre = nodo->getP();
    NodoArbol<T> *P = nodo;
    NodoArbol<T> *Q = P->getHI();
    NodoArbol<T> *R = Q->getHD();
    NodoArbol<T> *B = R->getHI();
    NodoArbol<T> *C = R->getHD();

    if (Padre)
        if (Padre->getHD() == nodo)
            Padre->setHD(R);
        else
            Padre->setHI(R);
    else
        raiz = R;

    Q->setHD(B);
    P->setHI(C);
    R->setHI(Q);
    R->setHD(P);

    R->setP(Padre);
    P->setP(R);
    Q->setP(R);
    if(B)
        B->setP(Q);
    if(C)
        C->setP(P);

    switch(R->getFe()) {
        case -1: Q->setFe(0);  P->setFe(1); break;
        case 0:  Q->setFe(0) ;  P->setFe(0); break;
        case 1:  Q->setFe(-1) ; P->setFe(0); break;
    }
    R->setFe(0);
}

template<class T>
void ArbolAvl<T>::RCI(NodoArbol<T>* nodo) {
//	cout << "RCI" << endl;
    NodoArbol<T> *Padre = nodo->getP();
    NodoArbol<T> *P = nodo;
    NodoArbol<T> *Q = P->getHD();
    NodoArbol<T> *R = Q->getHI();
    NodoArbol<T> *B = R->getHI();
    NodoArbol<T> *C = R->getHD();

    if (Padre)
        if(Padre->getHD() == nodo)
            Padre->setHD(R);
    else
        Padre->setHI(R);
    else
        raiz = R;

    P->setHD(B);
    Q->setHI(C);
    R->setHI(P);
    R->setHD(Q);

    R->setP(Padre);
    P->setP(R);
    Q->setP(R);

    if (B)
        B->setP(P);
    if (C)
        C->setP(Q);

    switch(R->getFe()) {
        case -1: P->setFe(0); Q->setFe(1) ; break;
        case 0:  P->setFe(0); Q->setFe(0) ; break;
        case 1:  P->setFe(-1) ; Q->setFe(0); break;
    }
    R->setFe(0);
}

template<class T>
void ArbolAvl<T>::RSD(NodoArbol<T>* nodo) {
//	cout << "RSD" << endl;
    NodoArbol<T> *Padre = nodo->getP();
    NodoArbol<T> *P = nodo;
    NodoArbol<T> *Q = P->getHI();
    NodoArbol<T> *B = Q->getHD();

    if (Padre)
        if (Padre->getHD() == P)
            Padre->setHD(Q);
        else
            Padre->setHI(Q);
    else
        raiz = Q;

    P->setHI(B);
    Q->setHD(P);

    P->setP(Q);
    if (B)
        B->setP(P);
    Q->setP(P);

    P->setFe(0);
    Q->setFe(0);
}

template<class T>
void ArbolAvl<T>::RSI(NodoArbol<T>* nodo) {
//	cout << "RSI" << endl;
    NodoArbol<T> *Padre = nodo->getP();
    NodoArbol<T> *P = nodo;
    NodoArbol<T> *Q = P->getHD();
    NodoArbol<T> *B = Q->getHI();

    if (Padre)
        if (Padre->getHD() == P)
            Padre->setHD(Q);
        else
            Padre->setHI(Q);
    else
        raiz = Q;

    P->setHD(B);
    Q->setHI(P);

   P->setP(Q);
    if (B)
        B->setP(P);
    Q->setP(Padre);


    P->setFe(0);
    Q->setFe(0);
}





template <class T>
int ArbolAvl<T>::agregar(T elem) {
    NodoArbol<T> *nuevo = new NodoArbol<T>(elem);
    NodoArbol<T> *puntero       = raiz;
    NodoArbol<T> *padre         = NULL;
    NodoArbol<T> *abuelo        = NULL;

    if (!nuevo) return 0;

    if (raiz == NULL) {
        raiz = nuevo;
        Calcular_fe(raiz);
        return 1;
    }

    while (puntero) {
        abuelo     = padre;
        padre      = puntero;

        if (elem > puntero->getDato()) {
            puntero = puntero->getHI();
        }
        else {
            puntero = puntero->getHD();
        }
    }

    if (elem > padre->getDato()) {
        nuevo->setP(padre);
        padre->setHI(nuevo);
        balancear(padre, IZQUIERDO, true);
    }
    else {
        nuevo->setP(padre);
        padre->setHD(nuevo);
        balancear(padre, DERECHO, true);
    }
    Calcular_fe(raiz);
    return 1;
}

template<class T>
void ArbolAvl<T>::eliminar(T elem) {
    NodoArbol<T> *padre = NULL;
    NodoArbol<T> *nodo;
    NodoArbol<T> *p = raiz;
    T aux;

    Calcular_fe(raiz);
    while (p != NULL) {
        if (elem == p->getDato()) {
            if (!p->getHD() && !p->getHI()) {
                if (padre) {
                    if (padre->getHD() == p)
                        padre->setHD(NULL);
                    else if (padre->getHI() == p)
                        padre->setHI(NULL);
                }
                delete p;
                p = NULL;

                if ((padre->getHD()   && padre->getFe() == -1) ||
                    (padre->getHI() && padre->getFe() == -1)) {

                    balancear(padre, IZQUIERDO, false);
                    padre->setFe(0);
                    p = padre;
                    padre = p->getP();
                }

                if (padre)
                    if (padre->getHD() == p)
                        balancear(padre, DERECHO, false);
                    else
                        balancear(padre, IZQUIERDO, false);
                //actual = p;
                Calcular_fe(raiz);
                return;
            }
            else {
                padre = p;
                if (p->getHD()) {
                    nodo = p->getHD();
                    while (nodo->getHI()) {
                        padre = nodo;
                        nodo = nodo->getHI();
                    }
                }
                else {
                    nodo = p->getHI();
                    while (nodo->getHD()) {
                        padre = nodo;
                        nodo = nodo->getHD();
                    }
                }
                aux = p->getDato();
                p->setDato(nodo->getDato());
                nodo->setDato(aux);
                p = nodo;
            }
        }
        else {
            padre = p;
            if (elem < p->getDato())
                p = p->getHD();
            else if (elem > p->getDato())
                p = p->getHI();
        }
    }
    Calcular_fe(raiz);
}

 /*
 template <class T>
 int ArbolAvl<T>::simetria(NodoArbol<T> *der, NodoArbol<T> *izq){


     if((der->getHD() && der->getHI()) && (izq->getHD() && izq->getHI())){
         simetria(der->getHD(), der->getHI());
         simetria(izq->getHD(), izq->getHI());
     }
     else if((der->getHD() && der->getHI()==NULL ) && (izq->getHI() && izq->getHD()==NULL )){
         simetria(der->getHD(), izq->getHD());
     }
     else if(( der->getHI() && der->getHD()==NULL )&& (izq->getHD() && izq->getHI()==NULL)){
         simetria(der->getHI(), izq->getHI());
     }
     else{
         return 0;
     }

     return 1;

 }
*/
template <class T>
void ArbolAvl<T> :: simetria(NodoArbol<T> *p, NodoArbol<T> *q, int &aux) {
    if( p && q ) {
        if(this->isHoja(p) && this->isHoja(q))
            aux = 1;
        else if(!this->isHoja(p) && !this->isHoja(q)) {
            if(p->getHI() && q->getHD()) {
                aux = 1;
                this->simetria(p->getHI(), q->getHD(), aux);
            } else if(!p->getHI() && !q->getHD()){
                aux = 1;
            } else {
                aux = 0;
            }

            if(p->getHD() && q->getHI()) {
                aux = 1;
                this->simetria(p->getHD(), q->getHI(), aux);
            } else if(!p->getHD() && !q->getHI()){
                aux = 1;
            } else {
                aux = 0;
            }
        } else
            aux = 0;
    }
}


#endif
