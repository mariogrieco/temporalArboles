#ifndef NODOARBOL_H
#define NODOARBOL_H

#include <iostream>

template <class T>
class NodoArbol {
    T dato;
    NodoArbol<T> *HI, *HD, *P;
    int fe, nivel;

    public:
        NodoArbol() { HI = HD = NULL; }
        NodoArbol(T dato) { this->dato = dato; HI = HD = NULL; }
        void setDato(T dato) { this->dato = dato; }
        void setHI(NodoArbol<T> *HI) { this->HI = HI; }
        void setHD(NodoArbol<T> *HD) { this->HD = HD; }
        void setP(NodoArbol<T> *P) { this->P = P; }
        T getDato() { return dato; }
        NodoArbol<T> * getHI() { return HI; }
        NodoArbol<T> * getHD() { return HD; }
        NodoArbol<T> * getP() { return P; }
        int getFe(){return fe;}
        void setFe(int value){ fe = value;}
        void setNivel(int nivel){ this->nivel= nivel;}
        int getNivel(){return nivel;}

};

#endif
