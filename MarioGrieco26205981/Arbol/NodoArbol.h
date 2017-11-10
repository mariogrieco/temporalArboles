#ifndef NODOARBOL_H
#define NODOARBOL_H

#include <iostream>

using namespace std;

template <class T>	
class NodoArbol {
	T dato;
	int fe, nivel;
	NodoArbol<T> *HI, *HD;
	
	public:
		// Lista<PalabraToList> memPalabras;
		NodoArbol() { HI = HD = NULL; }
		NodoArbol(T dato) { this->dato = dato; HI = HD = NULL; }
		void setData(T dato) { this->dato = dato; }
		void setHI(NodoArbol<T> *HI) { this->HI = HI; }
		void setHD(NodoArbol<T> *HD) { this->HD = HD; }
		void setFe(int valor){this->fe=valor;}
		void setNivel(int valor){this->nivel=valor;}
		int getFe(){ return fe;}
		int getNivel(){return nivel;}
		T getDato() { return dato; }
		NodoArbol<T> * getHI() { return HI; }
		NodoArbol<T> * getHD() { return HD; }

		// bool operator==(const Template& dt) 
		// {
		// 	return this->id == dt.id;
		// }
	
		// bool operator>(const Template& dt)
		// {  
		// 	return this->id > dt.id;
		// } 
	
	
		// bool operator<(const Template& dt)
		// {  
		// 	return this->id < dt.id;
		// } 
		
		friend ostream& operator<<(ostream& os, const NodoArbol<T>& dt)
		{  
				os << dt.dato;  
				return os;  
		} 
};

#endif
