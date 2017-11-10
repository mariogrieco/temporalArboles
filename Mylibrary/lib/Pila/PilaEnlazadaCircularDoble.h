#ifndef _PILA_ENLAZADA_H_
#define _PILA_ENLAZADA_H_
// #include "Nodo.h"

using namespace std;

template <class T> class PilaEnlazadaCircularDoble {
private:
  Nodo<T> *frente;
  Nodo<T> *cola;
  int length;

public:

  PilaEnlazadaCircularDoble () {
    this->length = 0;
    this->frente = NULL;
    this->cola = NULL;
  }

  ~PilaEnlazadaCircularDoble () {}

  int push (T data) {
    if (!this->frente || this->length == 0) {
      this->frente =  new Nodo<T>(data);
      this->cola = this->frente;
      this->frente->setNext(this->cola);
      this->cola->setNext(this->frente);
      this->frente->setBack(this->cola);
      this->cola->setBack(this->frente);
    } else {
       Nodo<T> *temp = this->frente;
      this->frente = new Nodo<T>(data);
      temp->setBack(this->frente);
      this->frente->setNext(temp);
      this->cola->setNext(this->frente);
      this->frente->setBack(this->cola);
    }
    this->length++;
  }

  T pop () {
    if (this->frente == this->cola && this->frente != NULL) {
      T data = this->frente->getData();
      this->frente = NULL;
      this->cola = NULL;
      this->length--;
      return data;
    } else if (this->frente) {
      T data = this->frente->getData();
      this->frente->getBack()->setNext(this->frente->getNext());
      this->frente->getNext()->setBack(this->frente->getBack());
      this->frente = this->frente->getNext();
      this->length--;
      return data;
    }
    return -1;
  }

  bool list () {
    Nodo<T> *temp = this->frente;
    if (!this->frente || this->length <= 0) return false;
    do {
      std::cout << temp->getData() << std::endl;
      temp = temp->getNext();
    } while (temp != this->frente);
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
};
#endif
