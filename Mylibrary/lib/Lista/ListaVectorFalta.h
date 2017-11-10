#ifndef _LISTA_VECTOR_H_
#define _LISTA_VECTOR_H_

using namespace std;

template <class T> class ListaVector {
private:
  // unsigned int *index;
  T *vector;
  unsigned int length;
  unsigned int cursor; // no usado
  unsigned int dim;

public:
  // ListaVector () {};

  ListaVector (int dim) {
    // this->index = new unsigned int[dim];
    this->vector = new T[dim];
    this->length = 0;
    this->cursor = 0;
    this->dim = dim;
  };

  bool push (T data) {
   if (this->length == 0) {
     this->vector[0] = data;
     this->length++;

     return true;
   }
   else if (this->length < this->dim) {
    unsigned int temp = 0;
    bool band = false;

     while (data > this->vector[temp]) {
       temp++;
       if( temp >= this->length) {
        band = true;
        break;
       }
     }
     if (temp < this->dim && band) {
        this->vector[temp] = data;
     }
     else if (temp < this->dim) {
      int t = temp;
      // arreglar...
      while (t < this->dim && t > 0 ) {
        this->vector[t] = this->vector[t-1];
        t++;
      }
      this->vector[temp] = data;
     }

     this->length++;
   } else {
    return false;
   }
  }

  bool list () {
    if (this->length > 0) {
      unsigned int t = 0;
      while (t < this->length) {
        cout << this->vector[t] << endl;
        t++;
      }
    }
  }

  T pop () {}

  ~ListaVector () {};
};
#endif
