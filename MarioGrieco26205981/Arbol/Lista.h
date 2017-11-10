#ifndef _Lista_H_
#define _Lista_H_
  #include <iostream>
  #include "Nodo.h"

  using namespace std;

template <class T, int ascendente = true> class Lista {
private:
  Nodo<T> *frente;
  Nodo<T> *cola;
  Nodo<T> *cursor;
  Nodo<T> *ptr_h;
  int length;
public:
  Lista () {
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

  // T pop (T data) {} 
  
  // T pop (bool orient = false) {
  // false -> izquierda
  // true  -> derecha
  //} 

  Nodo<T>* get (T dato) {
    this->ptr_h = this->frente;
    do {
      if (!this->ptr_h) break;
      if (this->ptr_h->getData() == dato) {
        return this->ptr_h;
      }
      this->ptr_h = this->ptr_h->getNext();
    } while (this->ptr_h != this->frente);  
  }
  
  void list (bool ascend = true) {
    // cout << "Frente: " << this->frente->getData() << "\n";
    // cout << "Cola: " << this->cola->getData() << "\n";
    if (ascend) {
      this->ptr_h = this->frente;
      do {
        if (!this->ptr_h) break;
        cout << this->ptr_h->getData() << "\n";
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

  bool sort (bool ascend = ascendente) {
    bool band = false;
    Nodo<T> *iterator = this->frente;
    Nodo<T> *item = iterator->getNext();

    do {
      band = false;
      iterator = this->frente;
      item = iterator->getNext();

      do {
        if ( ascend ? iterator->getData() > item->getData() : iterator->getData() < item->getData()) {
          this->swaNodes(iterator, item);
          band = true;
        }
  
        iterator = iterator->getNext(); 
        item = iterator->getNext();
  
      } while (this->frente != item);
    }while (band);
  }

  Nodo<T>* pop(T data) {
    Nodo<T> *ref = this->frente;
    Nodo<T>* temp;
    if (this->frente != NULL) {
      do { 
        if (ref->getData() == data) {
  
          temp = ref;
          if (this->frente == this->cola) {
            this->frente = this->cola = NULL;
            this->length = 0;
          }else { 
                      
            if (ref == this->cola) {
              this->cola = this->cola->getBack();
            }
            
            if (ref == this->frente) {
              this->frente = this->frente->getNext();
            }
          
            ref->getBack()->setNext(ref->getNext());
            ref->getNext()->setBack(ref->getBack());
            this->length--;
          }

          return temp;
        }
        ref = ref->getNext();
      } while (ref != this->frente);
    }
    //Cuidado!

    return NULL;
  }

  void swaNodes(Nodo<T> *a, Nodo<T> *b) {
    T Aux;
    Aux = a->getData();

    a->setData(b->getData());
    b->setData(Aux);
  }

  Nodo<T>* getFrente () {
    return this->frente;
  }

  int getLength () {
    return this->length;
  }

  ~ Lista () { }
};
#endif
