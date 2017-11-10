#ifndef _NODO_H_
#define _NODO_H_
template <class T> class Nodo {
private:
  T data;
  Nodo<T> *next;
  Nodo<T> *back;
  
public:
  Nodo (T data) {
    this->data = data;
    this->next = NULL;
    this->back = NULL;
  }
  
  ~Nodo () {}

  Nodo<T>* getNext () {
    return this->next;
  }

  Nodo<T>* getBack () {
    return this->back;
  }

  T getData () {
    return this->data;
  }

  T* getPtrData () {
    return &this->data;
  }

  bool setData (T data) {
    this->data = data;
  }
  int setNext (Nodo<T>* nodo) {
    this->next = nodo;
  }

  int setBack (Nodo<T>* nodo) {
    this->back = nodo;
  }
};
#endif
