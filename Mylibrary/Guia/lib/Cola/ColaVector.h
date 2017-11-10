#ifndef _ColaVector_H_
#define _ColaVector_H_

using namespace std;

template <class T> class ColaVector {
private:
  T *vector;
  unsigned int cursor;  // no usado aun
  unsigned int dim;
  unsigned int length;

public:

  // ColaVector () {};

  ColaVector (int dim) {
    this->vector = new T[dim];
    this->dim = dim;
    this->length = 0;
    this->cursor = 0;

    if (!this->vector) {
      cout << " error creando Dato T en cola vector" << endl;
    }
  };


  ~ColaVector () {};

  bool push (T data) {
    if (this->length < dim) {
      this->vector[this->length] = data;
      this->length++;
      return true;
    }
    return false;
  }

  T pop () {
    if (this->length > 0) { 
      T data = this->vector[0];

      for (int i = 0; i < length-1; i++) {
        this->vector[i] = this->vector[i+1];
      }

      this->length--;

      return data;
    }
    else {
      return -1;
    }
  }

  bool list () {
    unsigned int temp = 0;

    while (temp < this->length) {
      cout << this->vector[temp] << endl;
      temp++;
    }
  }

  // bool cheeckIntegrity ()
};

#endif
