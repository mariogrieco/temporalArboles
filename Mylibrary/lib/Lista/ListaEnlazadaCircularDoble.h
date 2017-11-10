#ifndef _ListaEnlazadaCircularDoble_H_
#define _ListaEnlazadaCircularDoble_H_
  #include <iostream>
  // #include "Nodo.h"

  using namespace std;

template <class T, int ascendente = true> class ListaEnlazadaCircularDoble {
private:
  Nodo<T> *frente;
  Nodo<T> *cola;
  Nodo<T> *cursor;
  Nodo<T> *ptr_h;
  int length;
public:
  ListaEnlazadaCircularDoble () {
    this->frente = NULL;
    this->cola = NULL;
    this->ptr_h = 0;
    this->length = 0;
  }
  
  bool push (T *data) {
    this->push(*data);
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

  T pop (T data) {
    
  } 
  
  void list (bool ascend = true) {
    cout << "Frente: " << this->frente->getData() << "\n";
    cout << "Cola: " << this->cola->getData() << "\n";
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
    if (!temp) return false;

    do {
      mem = temp;
      if (temp->getNext()->getBack() != mem && temp->getBack()->getNext() != mem) {
        std::cout << " warinig!!!!" << std::endl;
      }
      temp = temp->getNext();
    } while(temp != this->frente);

    if (this->cola->getNext() != this->frente) {
      std::cout << " warinig!!!!" << std::endl;
    }
    if (this->frente->getBack() != this->cola) {
      std::cout << " warinig!!!!" << std::endl;
    }
  }

  ~ ListaEnlazadaCircularDoble () { }
};
#endif
