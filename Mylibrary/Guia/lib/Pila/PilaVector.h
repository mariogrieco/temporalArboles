#ifndef _PilaVector_H_
#define _PilaVector_H_

using namespace std;

template <class T> class PilaVector {
private:
  T *vector;
  unsigned int cursor;  // no usado aun
  unsigned int dim;
  unsigned int length;

public:

  // PilaVector () {};

  PilaVector (int dim) {
    this->vector = new T[dim];
    this->dim = dim;
    this->length = 0;
    this->cursor = 0;

    if (!this->vector) {
      cout << " error creando Dato T en PilaVector vector" << endl;
    }
  };


  ~PilaVector () {};

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
      T data = this->vector[this->length-1];
      this->length--;
      return data;
    }
    else {
      return -1;
    }
  }

  bool list () {
    unsigned int temp = this->length;

    while (temp-- > 0) {
      cout << this->vector[temp] << endl;
    }
  }

  // bool cheeckIntegrity ()
};

#endif
