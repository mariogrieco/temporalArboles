#ifndef _BiEstructura_H_
#define _BiEstructura_H_

#include "Nodo.h"

// TRABAJA COMO BI-COLA O BI-PILA 
// done!

template <class T> class BiEstructura {
private:
  Nodo<T> *cola;
  Nodo<T> *frente;
  int length;

public:

  BiEstructura () {
    this->cola = NULL;
    this->frente = NULL;
    this->length = 0;
  }

  int push (T data, bool way = true) { 
    // add back || add front 
   Nodo<T> *temp;
   this->length++;
   Nodo<T> *d = new Nodo<T>(data);

    if (way) {
      d->setNext(this->frente);
      if (this->frente) {
        this->frente->setBack(d);
      } else {
        this->frente = d;
        this->cola = this->frente;
      }
      this->frente = d;
    } else {
      d->setBack(this->cola);
      if (this->cola) {
        this->cola->setNext(d);
      } else {
        this->cola = d;
        this->frente = this->cola;
      }
      this->cola = d;
    }
  }

  void list (bool way = true) {
    if (way) {
      Nodo<T> *temp = this->frente;
      while (temp) {
        std::cout << temp->getData() << " \n"; 
        temp = temp->getNext();
      }
    } else {
      Nodo<T> *temp = this->cola;
      while (temp) {
        std::cout << temp->getData() << " \n"; 
        temp = temp->getBack();
      }
    }
  }

  T pop (bool way = true) {
    Nodo<T> *temp = this->frente;
    T data;
    if (this->frente != NULL) {
      this->length--;
      if (this->frente == this->cola) {
        data = this->frente->getData();
        this->frente = this->cola = NULL;
        return data;
      }
  
      if (way) {
        Nodo<T> *t = this->frente->getNext();
        data = this->frente->getData();
        t->setBack(NULL);
        this->frente = t;
      } else {
        Nodo<T> *t = this->cola->getBack();
        data = this->cola->getData();
        t->setNext(NULL);
        this->cola = t;
      }
  
      return data;
    }
    else {
      std::cout << "poping from empty emtity" << std::endl;
      return NULL;
    }
  }

  ~BiEstructura () {}
};
#endif
