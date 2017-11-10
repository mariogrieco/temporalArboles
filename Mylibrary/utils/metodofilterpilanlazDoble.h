#ifndef _LISTA_E_H_
#define _LISTA_E_H_
#include "Nodo.h"

template <class T, bool ascend = true> class ListaEnlazada {
private:
  Nodo<T> *frente;
  int length;

public:
  ListaEnlazada () {
    this->frente = NULL;
    this->length = 0;
  }

  bool push (T data) {
   Nodo<T> *temp = this->frente;
   Nodo<T> *before = NULL;
   bool band = true;

    while (temp && band) {
      before = temp;
      temp = temp->getNext();
      band = ascend ? (before->getData() < data) : (before->getData() > data);      
    }

    if (this->length == 0) {
      this->frente = new Nodo<T>(data);
    }
    else if (!temp && band) {
      before->setNext(new Nodo<T>(data));
      before->getNext()->setBack(before);
    }
    else {
      before->setNext(new Nodo<T>(before->getData()));
      before->getNext()->setBack(before);
      before->getNext()->setNext(temp);
      if (temp) {
        temp->setBack(before->getNext());
      }
      before->setData(data);
    }
    this->length++;
  }

  T filter (T data) {
    Nodo<T> *temp = this->frente;
    // To-Do Borrar Nodos de salidas
    // falta verificar si funciona

    while (temp) {
      if (temp->getData() == data) {
        Nodo<T> *before = temp->getBack();
        Nodo<T> *next = temp->getNext();
        if (before) {
          before->setNext(next);
        }else {
          this->frente = NULL;
        }

        if (next) {
          next->setBack(before);
          if (!before) {
            this->frente = next;
          }
        }
        this->length--;
      }
      temp = temp->getNext();
    }
  }

  bool cheeckIntegrity () {
    Nodo<T> *temp = this->frente;
    Nodo<T> *mem = NULL;
    Nodo<T> *mem2 = NULL;
    while (temp) {
      mem = temp;
     
      if ( temp->getNext() ) {
        if (temp->getNext()->getBack() != mem) {
          std::cout << " warinig!!!!" << std::endl;
        }
      }
      temp = temp->getNext();
    }
  }

  int getLength () {
   return this->length;
  }

  // void operator>(ListaEnlazada<T> *data){// }

  // int indexOf (T data) {// }

  // void map
  // filter
  // reduce
  // forEach
  // sort

  void list () {
    Nodo<T> *temp = this->frente;
    while (temp) {
     std::cout << temp->getBack() << " " << temp->getData() << " " << temp->getNext()  << std::endl;
     temp = temp->getNext();
    }
  }

  ~ListaEnlazada () {

  }
};
#endif
