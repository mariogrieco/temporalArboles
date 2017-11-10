#ifndef _Multilistas_H
#define _Multilistas_H

/**
  Lista Nv 1 ( ascendente o decendente, [true, false])
  outher lv -> ListaEnlazadaCircularDoble ( type, [true, false] )
  outherList -> ListaEnlazadaCircularDoble ( type, [true, false] )
**/

  #include <iostream>
    using namespace std;
  #include "Lista.h"

  template <class K, class T> class NodoLista {
  private:
    K categoria;
    Lista<T> data;
    NodoLista<K, T> *next;

  public:
    NodoLista () {
      this->next = NULL;
    };

    NodoLista (K categoria) {
      this->categoria = categoria;
      this->next = NULL;
    };

    ~ NodoLista () {};

    K getCategoria () {
      return this->categoria;
    }

    Lista<T>* getData () {
      return &this->data;
    }

    bool setData (T data) {
      this->data.push(data);
    }

    void setNext (NodoLista<K, T> *next) {
      this->next = next;
    }

    NodoLista<K, T>* getNext() {
      return this->next;
    }
  };

template <class K, class T> class Multilista {
private:
  int length;
  NodoLista<K, T> *frente;

public:
  Multilista () {
    this->length = 0;
    this->frente = NULL;
  };

  void registrar (K categoria) {
    this->length++;
    if (this->frente == NULL) {
      this->frente = new NodoLista<K, T>(categoria);
    }
    else {
      NodoLista<K, T> *temp = this->frente;
      while (temp->getNext()) {
        temp = temp->getNext();
      }
      temp->setNext(new NodoLista<K,T>(categoria));
    }
  }

  void push (K categoria, T data) {
    NodoLista<K, T> *temp = this->frente;
    while (temp) { 
      if (temp->getCategoria() == categoria) {
        temp->setData(data);
        break;
      }
      temp = temp->getNext();
    }
  }

  Nodo<T>* pop (K categoria, T code) {
    NodoLista<K, T> *temp = this->frente;
    while (temp) { 

      if (temp->getCategoria() == categoria) {
        Lista<T> *d = temp->getData();
        if (d) {
          T *item = d->get(code);
            if (item) {
              int cantidad = item->getCantidad();
              if (cantidad-1 >0) {
                item->setCantidad(cantidad-1);
              }else {
                d->pop(code);
              }
            }
            else { 
              return NULL;
            }
        } else {
          return NULL;
        }
  
      }
      temp = temp->getNext();
    }
  }

  T* modListItems (K categoria, T code) {
    NodoLista<K, T> *temp = this->frente;
    while (temp != NULL) { 
      if (temp->getCategoria() == categoria) {
        Lista<T> *d = temp->getData();
        if (d) {
          T *item = d->get(code);
            if (item) {
              return item;
            }
            else { 
              return NULL;
            }
        } else {
          return NULL;
        }
      }
      temp = temp->getNext();
    }
    return NULL;
  }

  NodoLista<K, T>* getFrente () {
    return this->frente;
  }
  
  void list () {
    NodoLista<K, T> *temp = this->frente;
    while (temp) { 
      cout << temp->getCategoria() << endl;
      temp->getData()->list();
      cout << "\n";
      temp = temp->getNext();
    }
  }

  ~Multilista () {};
};

#endif
