#ifndef _ColaPilaPrioridad_H_
#define _ColaPilaPrioridad_H_
  #include <iostream>
  #include "Nodo.h"


/**
	Cola de prioridad con modelo 1
	( modelo 2 listas de colas )

	- no es una etructura FIFO
	en la totalidad de sus elementos
	que la componen.

	- se eliminan ( procesan ). de acuerdo a una prioridad

**/

  using namespace std;

template <class T, int ascendente = true> class ColaPilaPrioridad {
private:
  Nodo<T> *frente;
  Nodo<T> *cola;
  Nodo<T> *cursor;
  Nodo<T> *ptr_h;
  int length;

public:
  ColaPilaPrioridad () {
    this->frente = NULL;
    this->cola = NULL;
    this->ptr_h = 0;
    this->length = 0;
  }

  bool push (T *data) {
    this->push((*data));
  }

  bool push (T data) {
    this->length++;

    if (this->frente == NULL) {
      this->frente = this->cola = new Nodo<T>(data);
      this->frente->setNext(this->frente);
      this->frente->setBack(this->frente);
    }
    else {
      Nodo<T> *toAdd = new Nodo<T>(data);
      this->ptr_h = this->frente;
      do {
        if (ascendente ? data < this->ptr_h->getData() : data > this->ptr_h->getData() ) break;
        this->ptr_h = this->ptr_h->getNext();
      } while (this->ptr_h != this->frente);
      toAdd->setNext(this->ptr_h);
      toAdd->setBack(this->ptr_h->getBack());
      this->ptr_h->getBack()->setNext(toAdd);
      this->ptr_h->setBack(toAdd);

      if (ascendente? this->frente->getData() > data : this->frente->getData() < data) {
        this->frente = toAdd;
      }

      this->cola = this->frente->getBack();
    }
  }

  void setFrente (Nodo<T> *frente) {
    this->frente = frente;
  }

  void setCola (Nodo<T> *cola) {
    this->cola = cola;
  }

  T pop () {
  	 T data;
  	  if (this->frente == this->cola && this->frente != NULL)  {
  	  	 data = this->frente->getData();
  	 		 this->frente = NULL;
  	 		 this->cola = NULL;
  	 		return data;
  	 }
  	 else if (this->frente != this->cola){
  	 	  Nodo<T> *pop = this->frente;
  	 	  T data = pop->getData();
  	 		this->frente = this->frente->getNext();
  	 		this->frente->setBack(pop->getBack());
  	 		this->frente->getBack()->setNext(this->frente);
  		 
  		 return data;
  	 }

  }

  void list (bool ascend = true) {
  	if (this->frente) {
  		cout << "Frente: " << this->frente->getData() << "\n";
    	cout << "Cola: " << this->cola->getData() << "\n";
  	}

     if (ascend) {
       this->ptr_h = this->frente;
       do {
         if (!this->ptr_h) break;
         cout << this->ptr_h->getData() << endl;
         this->ptr_h = this->ptr_h->getNext();
       } while (this->ptr_h != this->frente);  
     }
     else {
       this->ptr_h = this->cola;
       do {
         if (!this->ptr_h) break;
         cout << this->ptr_h->getData() << endl;
         this->ptr_h = this->ptr_h->getBack();
       } while (this->ptr_h != this->cola);  
     }
  }

  bool cheeckIntegrity () {
    Nodo<T> *temp = this->frente;
    Nodo<T> *mem = NULL;
    Nodo<T> *mem2 = NULL;
   if (temp != NULL) {
   	 do {
      mem = temp;
     
      if ( temp->getNext() ) {
        if (temp->getNext()->getBack() != mem && temp->getBack()->getNext() != mem) {
          std::cout << " warinig!!!!" << std::endl;
        }
      }
      temp = temp->getNext();
    } while(temp != this->frente);

    if (this->frente->getBack() != this->cola) {
      cout << "warning!" << endl;
    }

    if (this->cola->getNext() != this->frente) {
      cout << "warning!" << endl;
    }
   }
  }

  Nodo<T>* getFrente () {
    return this->frente;
  }

  Nodo<T>* getCola () {
    return this->cola;
  }

  ~ ColaPilaPrioridad () { }
};
#endif

