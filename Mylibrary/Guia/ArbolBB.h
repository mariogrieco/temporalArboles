#ifndef ARBOLBB_H
#define ARBOLBB_H

#include <iostream>
#include "nodoarbol.h"

// #include "cola.h"

using namespace std;

template <class T>
class ArbolBB		//Arbol Binario de Búsqueda
{
        NodoArbol<T> * raiz;

        public:
                ArbolBB() { raiz = NULL; }
                int agregar(T ele);
                int eliminar(T &ele);
                void imprimir(int band);
                void preOrden(NodoArbol<T> *p, int niv);
                void inOrden(NodoArbol<T> *p, int niv);
                void posOrden(NodoArbol<T> *p, int niv);
                int Altura ( NodoArbol<T> *pt);
                void Calcular_fe( NodoArbol<T> *pt);
                NodoArbol<T> *getRaiz() {return raiz;}
                int verificarAVL(NodoArbol<T> *pt);

                void imprimirNivel(NodoArbol<T> *pt, int nivel);
                void preOrdenNivel(NodoArbol<T> *p, int niv, int nivel);
                void simetria(NodoArbol<T> *p, NodoArbol<T> *q, int &aux);

                void anchura(NodoArbol<T> *nodo, int k=0);

                T eliminar(T *elem);
                T eliminarElemento(T elem, NodoArbol<T> *padre, NodoArbol<T> *nodo);

                T buscar(T elem);
                 T buscarElemento(T elem, NodoArbol<T>*nodo);

                 bool isHoja(NodoArbol<T> *nodo){
                     if(nodo->getHI() == NULL && nodo->getHD()== NULL)
                         return true;

                     return false;
                 }
};



template <class T>
int ArbolBB<T> :: agregar(T ele) {
        NodoArbol<T> *nuevo, *p, *antp;

        nuevo = new NodoArbol<T>(ele);

        if(!nuevo)
                return 0;

        if(!raiz) {
                raiz = nuevo;
                return 1;
        }

        p = raiz;

        while(p) {
                antp = p;
                if(ele < p->getDato())
                        p = p->getHI();
                else
                        p = p->getHD();
        }

        if(ele < antp->getDato())
                antp->setHI(nuevo);
        else
                antp->setHD(nuevo);

        return 1;
}



template<class T>
int ArbolBB<T>:: Altura ( NodoArbol<T> *pt)
{
    int ai, ad;
    if ( !pt ) return 0;
    ai= 1 + Altura(pt->getHI());
    ad= 1 + Altura(pt->getHD());
    if ( ai>ad ) return ai;
    return ad;
}
template <class T>
void ArbolBB<T> :: imprimir(int band) {
        if(!raiz)
                return;

        if(band == 1)			//Imprimir por Pre Orden
                preOrden(raiz, 0);
        if(band == 2)			//Imprimir por Inorden
                inOrden(raiz, 0);
        if(band == 3)			//imprimir por posOrden
                posOrden(raiz, 0);


}

template <class T>
void ArbolBB<T> :: preOrden(NodoArbol<T> *p, int niv) {
        for(int i = 0; i < niv; i++)
                cout << "  ";

        cout<<p->getDato() <<" ("<<p->getFe()<< ") "<<endl ;
        p->setNivel(niv);
        if(p->getHI())
                this->preOrden(p->getHI(), niv+1);
        if(p->getHD())
                this->preOrden(p->getHD(), niv+1);
}

template <class T>
void ArbolBB<T> :: inOrden(NodoArbol<T> *p, int niv) {
        if(p->getHI())
                this->inOrden(p->getHI(), niv+1);

        for(int i = 0; i < niv; i++)
                cout << "  ";

        cout << p->getDato() << endl;

        if(p->getHD())
                this->inOrden(p->getHD(), niv+1);
}

template <class T>
void ArbolBB<T> :: posOrden(NodoArbol<T> *p, int niv) {
        if(p->getHD())
                this->posOrden(p->getHD(), niv+1);



        for(int i = 0; i < niv; i++)
                cout << "  ";

        cout<<p->getDato() <<" ("<<p->getFe()<< ") "<<endl ;


        if(p->getHI())
                this->posOrden(p->getHI(), niv+1);

}

template<class T>
void ArbolBB<T>:: Calcular_fe( NodoArbol<T>*pt)
{

    pt->setFe( Altura(pt->getHD())-Altura(pt->getHI()));
    if ( pt->getHI()) Calcular_fe(pt->getHI());
    if ( pt->getHD()) Calcular_fe(pt->getHD());
}

template<class T>
int ArbolBB<T>:: verificarAVL(NodoArbol<T> *pt){

   if(pt->getFe()> 1 || pt->getFe()< -1){
       return 1;
   }else{
       if ( pt->getHI()) verificarAVL(pt->getHI());
       if ( pt->getHD()) verificarAVL(pt->getHD());
   }
   return 0;
}

template<class T>
void ArbolBB<T>::imprimirNivel(NodoArbol<T> *pt, int nivel){
    if(!raiz)
            return;

     preOrdenNivel(pt, 0, nivel);

}

template <class T>
void ArbolBB<T> :: preOrdenNivel(NodoArbol<T> *p, int niv, int nivel) {
       if(niv==nivel)
            cout<<p->getDato() <<" ("<<p->getFe()<< ") "<<" " ;

        if(p->getHI())
                this->preOrdenNivel(p->getHI(), niv+1, nivel);
        if(p->getHD())
                this->preOrdenNivel(p->getHD(), niv+1, nivel);
}


/*
template <class T>
int ArbolBB<T>::simetria(NodoArbol<T> *der, NodoArbol<T> *izq){


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
void ArbolBB<T> :: simetria(NodoArbol<T> *p, NodoArbol<T> *q, int &aux) {
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




template <class T>
T ArbolBB<T>::eliminar(T *elem) {
    if (!raiz) return NULL;

    if (elem == raiz->getDato()) {
        if (!raiz->getHD() && !raiz->getHI()) {
            raiz = NULL;
        }
        else if (!raiz->getHD() && raiz->getHI()) {
            raiz = raiz->getHI();
        }
        else if (raiz->getHD() && !raiz->getHI()) {
            raiz = raiz->getHD();
        }
        else if (raiz->getHD() && raiz->getHI()) {
            NodoArbol<T> *aux = raiz->getHI();
            NodoArbol<T> *aux_padre = raiz;

            while (aux->getHD()) {
                aux_padre = aux;
                aux = aux->getHD();
            }

            aux->setHijoDerecho(raiz->getHD());
            if (!aux->getHI() && aux != raiz->getHI()) aux->setHI(raiz->getHI());
            aux_padre->setHD(NULL);
            raiz = aux;

        }
        return elem;
    }

    if (elem > raiz->getDato()) elem = eliminarElemento(elem, raiz, raiz->getHI());
    if (elem < raiz->getDato()) elem = eliminarElemento(elem, raiz, raiz->getHD());

    return elem;
}



template <class T>
T ArbolBB<T>::eliminarElemento(T elem, NodoArbol<T> *padre, NodoArbol<T> *nodo) {
    if (elem == nodo->getDato()) {
        if (!nodo->getHD() && !nodo->getHI()) {
            if      (nodo == padre->getHD())   padre->setHD(NULL);
            else if (nodo == padre->getHI()) padre->setHI(NULL);
        }
        else if (!nodo->getHD() && nodo->getHI()) {
            if      (nodo == padre->getHI())   padre->setHI(nodo->getHI());
            else if (nodo == padre->getHD())     padre->setHD(nodo->getHI());
            nodo = NULL;
        }
        else if (nodo->getHD() && !nodo->getHI()) {
            if      (nodo == padre->getHI())   padre->setHI(nodo->getHD());
            else if (nodo == padre->getHD())     padre->setHD(nodo->getHD());
            nodo = NULL;
        }
        else if (nodo->getHD() && nodo->getHI()) {
            //Nodo_Arbol<T> *aux = buscarHojaDerecha(nodo->getHijoIzquierdo());
            NodoArbol<T> *aux       = nodo->getHI();
            NodoArbol<T> *aux_padre = nodo;

            while (aux->getHD()) {
                aux_padre = aux;
                aux       = aux->getHD();
            }

            aux->setHD(nodo->getHD());
            if (!aux->getHI()&& aux != nodo->getHI()) aux->setHI(nodo->getHI());
            aux_padre->setHD(NULL);

            if     (nodo == padre->getHD())    padre->setHD(aux);
            else if(nodo == padre->getHI())  padre->setHI(aux);

            nodo = NULL;

        }

        return elem;
    }

    if (elem > nodo->getDato()) return eliminarElemento(elem, nodo, nodo->getHijoIzquierdo());
    if (elem < nodo->getDato()) return eliminarElemento(elem, nodo, nodo->getHijoDerecho());
    //if (elem <  nodo->getInfo()) return eliminarElemento(elem, nodo, nodo->getHijoDerecho());
}




template <class T>
T ArbolBB<T>::buscar(T elem) {
    return buscarElemento(elem, raiz);
}

template <class T>
T ArbolBB<T>::buscarElemento(T elem, NodoArbol<T>*nodo) {
    if (!nodo) return NULL;

    if (elem == nodo->getDato())   return nodo->getDato();
    if (elem <  nodo->getDato())   return buscarElemento(elem, nodo->getHI());
    if (elem >  nodo->getDato())   return buscarElemento(elem, nodo->getHD());

    return NULL;
}


template <class T>
void ArbolBB<T>::anchura(NodoArbol<T> *nodo, int k){   //nodo->raiz



        if(nodo->getNivel()==k){

            for(int i=0; i<k; i++){
                cout<<" ";
            }


            cout<<nodo->getDato();
             cout<<endl;
        }
        k++;
        if(nodo->getHI()){
            anchura(nodo->getHI(), k);
        }

        if(nodo->getHD()){
            anchura(nodo->getHD(), k);
        }




    //cout<<"HOA";

   /* Cola<NodoArbol<T> *> cola;

    NodoArbol<T> *q;


    if(nodo!= NULL){
      //  cout<<"\nEEOEOE";
        cola.insertar(nodo);
    cout<<"\t\t"<<nodo->getDato();
        while(cola.retornarLongitud()>0){

      //      cout<<"\nXDXDD";

             q=cola.quitar();

             cout<<endl;



            if(q->getHI() != NULL){


                cola.insertar(q->getHI());

                cout<<"\t";
                cout<<q->getHI()->getDato();

            }

            if(q->getHD() != NULL){
                cola.insertar(q->getHD());
            cout<<"\t\t";

                cout<<q->getHD()->getDato();
            }



       //     cout<<endl;
        }
    }

    cout<<endl;*/
}



#endif
