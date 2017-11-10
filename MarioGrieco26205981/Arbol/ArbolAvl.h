#ifndef ARBOLAVL_H
#define ARBOLAVL_H
#include <iostream>
#include "NodoArbol.h"
#include "Cola.h" // CIRCULAR

using namespace std;
template <class T>
class ArbolAvl
{
	NodoArbol<T> * raiz;
    bool tipo=true;
    int ifeTree;

    public:
        // ES NECESARIO REINICIAR EN CADA BUSQUEDA!!! LOS STEPS
        Cola< NodoArbol<T> > *steps;  // cola de busqueda ( un recorrido hasta encontrar )
        
		ArbolAvl() { 
            raiz = NULL; 
            ifeTree = 0; 
            this->steps = new Cola< NodoArbol<T> >();
        }

		void push(NodoArbol<T> *r, T ele);
		void Rota_SD(NodoArbol<T> *abu, NodoArbol<T> *pad, NodoArbol<T> *hoj);
		void Rota_SI(NodoArbol<T> *abu, NodoArbol<T> *pad, NodoArbol<T> *hoj);
		void Rota_CD(NodoArbol<T> *abu, NodoArbol<T> *pad, NodoArbol<T> *hoj);
        void Rota_CI(NodoArbol<T> *abu, NodoArbol<T> *pad, NodoArbol<T> *hoj);
        int Altura(NodoArbol<T> * pt);
        //buscar
        int get (NodoArbol<T> *pt, T dato);
		void Calcular_fe(NodoArbol<T> *pt);
		void imprimir(int band);
		void preOrden(NodoArbol<T> *p, int niv);
		void inOrden(NodoArbol<T> *p, int niv);
		void posOrden(NodoArbol<T> *p, int niv);
        NodoArbol<T> *getRaiz(){return raiz;};
        bool isHoja(NodoArbol<T> *nodo);
		void *setRaiz(NodoArbol<T> *p){ raiz=p;}
		bool getTipo(){ return tipo; }
		int simetria(NodoArbol<T> *der, NodoArbol<T> *izq);
};

template <class T>
bool isHoja(NodoArbol<T> *nodo){
    if(nodo->getHI() == NULL && nodo->getHD()== NULL) return true;
    return false;
}

template <class T>
void ArbolAvl<T> :: imprimir(int band) {
	if(!raiz)
		return;
	
    if(band == 1){			//Imprimir por Pre Orden
        cout << "preorden" << endl;
        preOrden(raiz, 0);
    }
    if(band == 2){			//Imprimir por Inorden
        cout << "inorden" << endl;
        inOrden(raiz, 0);
    }
    if(band == 3)	{		//imprimir por posOrden
        cout << "postOrden" << endl;
        posOrden(raiz, 0);
    }
	//Programar Pos Orden
	//Programar Anchura
}

template <class T>
void ArbolAvl<T> :: preOrden(NodoArbol<T> *p, int niv) {
	for(int i = 0; i < niv; i++)
		cout << "  ";
	
    cout << p->getDato();
	cout <<" ("<< p->getFe()<<")"<<endl;
	
	if(p->getFe()>1 || p->getFe() <-1)
		tipo=false;
	
	p->setNivel(niv);
	
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
	
	cout << p->getDato();
    cout<<"(" << p->getFe()<<") " << endl;
	if(p->getHD())
		this->inOrden(p->getHD(), niv+1);
}

template <class T>
void ArbolAvl<T> :: posOrden(NodoArbol<T> *p, int niv) {
  if ( p != NULL ) { 
    posOrden( p->getHI(), niv + 1);
    posOrden( p->getHD() , niv + 1);
    for ( int i = 0; i < niv; i++ ) {
        cout << " ";
    }
    cout <<  p->getDato() << "(" << p->getFe() << ")"<< endl;
  }
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


// Slo retorna si encontro mas nada aun ...
// retornar elm
// restaurar
// quedar uno antes segun bool
// buscar
template <class T>
int ArbolAvl<T>::get (NodoArbol<T> *pt, T dato)
{
    int ai = 0;
    int ad = 0;
    if ( !pt ) return 0;
    
    steps->push(pt);

    if (pt->getDato() == dato) {
        cout << " -> ";
        cout << " Fue Encontrado! Fuera de lista\n camino(nodos):" << endl;
        // cout << 
        cout << endl;
        steps->list();
        cout << "\n";
        return 1;
    }
    else {
        // get (buscar) en propiedad 
        // interna del nodo del arbos aca..
    }

    ai= get(pt->getHI(), dato);
    ad= get(pt->getHD(), dato);
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
template <class T>
void ArbolAvl<T>::Rota_SD(NodoArbol<T> *abu, NodoArbol<T> *pad, NodoArbol<T> *hoj){

    //abu->abuelo, pad->padre, hoj->hoja

    NodoArbol<T> *p;
    p= new NodoArbol<T>();

    abu->setHD(p);
    p->setData(abu->getDato());
    abu->setData(pad->getDato());
    pad->setData(hoj->getDato());

    pad->setHI(NULL);
    delete hoj;
}

template <class T>
void ArbolAvl<T>::Rota_SI(NodoArbol<T> *abu, NodoArbol<T> *pad, NodoArbol<T> *hoj){

    //abu->abuelo, pad->padre, hoj->hoja

    NodoArbol<T> *p;
    p= new NodoArbol<T>();

    abu->setHI(p);
    p->setData(abu->getDato());
    abu->setData(pad->getDato());
    pad->setData(hoj->getDato());

    pad->setHD(NULL);
    delete hoj;
}
template <class T>
void ArbolAvl<T>::Rota_CD(NodoArbol<T> *abu, NodoArbol<T> *pad, NodoArbol<T> *hoj){

    NodoArbol<T> *p;
    p= new NodoArbol<T>();
    abu->setHD(p);
    p->setData(abu->getDato());
    abu->setData(hoj->getDato());

    pad->setHD(NULL);
    delete hoj;
}
template <class T>
void ArbolAvl<T>::Rota_CI(NodoArbol<T> *abu, NodoArbol<T> *pad, NodoArbol<T> *hoj){

    NodoArbol<T> *p;
    p= new NodoArbol<T>();
    abu->setHI(p);
    p->setData(abu->getDato());
    abu->setData(hoj->getDato());

    pad->setHI(NULL);
    delete hoj;
}

	template <class T>
	void ArbolAvl<T>::push ( NodoArbol<T> *r, T ele)
	{
		NodoArbol<T> *p,*q,*pnue;
    	p= new NodoArbol<T>();
    	p=r;
		q= new NodoArbol<T>();
    	pnue= new NodoArbol<T>(ele);
    while (true)
    {
        if ( ele < p->getDato())
        {
            if ( !p->getHI() ) {
                p->setHI(pnue);
                break;
            }
            q= p;
            p= p->getHI();
        }
        else
        {
            if ( !p->getHD() )
            {
                p->setHD(pnue);
                break;
            }
            q= p;
            p= p->getHD();
        }
    }// fin while
    if (q)
    {
      Calcular_fe(q);
      if (q->getFe()==2  && p->getFe()==1 )  Rota_SI(q,p,pnue);
      if (q->getFe()==-2 && p->getFe()==-1)  Rota_SD(q,p,pnue);
      if (q->getFe()==2  && p->getFe()==-1)  Rota_CI(q,p,pnue);
      if (q->getFe()==-2 && p->getFe()==1 )  Rota_CD(q,p,pnue);
    }
    Calcular_fe(q);
} // Fin de push

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



#endif
