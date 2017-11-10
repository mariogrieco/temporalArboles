#ifndef _COLA_ENLAZADA_H_
#define _COLA_ENLAZADA_H_
#include "Nodo.h"
//NOTA! es circular

using namespace std;

template <class T> class Cola {
private:
  Nodo<T> *cola;
  Nodo<T> *end;
  int length;

public:

  Cola () {
    this->length = 0;
    this->cola = NULL;
  };

  ~Cola () {
  };

  int push (T *data) { 
    this->push(*data);
  }

  int push (T data) {
    this->length++;
    Nodo<T> *entry = new Nodo<T>(data);

    if (this->cola == NULL)  {
      this->cola = entry;
      this->end = entry;
      this->cola->setNext(end);
      this->cola->setBack(cola);
    }
    else {
      entry->setNext(this->cola);
      this->cola->setBack(entry);
      entry->setBack(this->end);
      this->end->setNext(entry);
      this->end = entry;
    }
  }

  Nodo<T>* get (T dato) {
    Nodo<T> *frente = this->cola;
    while(frente) {
      if (frente->getData() == dato) {
        return frente;
      }
      frente = frente->getNext();
      if (this->cola == frente) {
        break;
      }
    }

    return NULL;
  }

  void list () {
    Nodo<T> *frente = this->cola;
    while(frente) {
      cout << frente->getData() << endl;
      frente = frente->getNext();
      if (this->cola == frente) {
        break;
      }
    }
  }

  T pop () {
    if (this->cola == this->end && this->cola != NULL) {
      T t = this->cola->getData();
      this->cola = NULL;
      this->end = NULL; 
      this->length--;
      return t;
    }
    else if (this->cola) {
      T t = this->cola->getData();
      this->cola->getBack()->setNext(this->cola->getNext());
      this->cola->getNext()->setBack(this->cola->getBack());
      this->cola = this->cola->getNext();
      this->length--;

      return t;
    } else {
      // CUIDADO!
      return -1;
    }
  }

  bool cheeckIntegrity () {
    Nodo<T> *temp = this->cola;
    Nodo<T> *mem = NULL;
    Nodo<T> *mem2 = NULL;
    if (!temp) return false;

    do {
      mem = temp;
      if (temp->getNext()->getBack() != mem && temp->getBack()->getNext() != mem) {
        std::cout << " warinig!!!!" << std::endl;
      }
      temp = temp->getNext();
    } while(temp != this->cola);

    if (this->cola->getBack() != this->end) {
      std::cout << " warinig!!!!" << std::endl;
    }
    if (this->end->getNext() != this->cola) {
      std::cout << " warinig!!!!" << std::endl;
    }
  }
};
#endif