#ifndef _COLA_CIRCULAR_H_
#define _COLA_CIRCULAR_H_

template <class T> class ColaCircular {
private:
  T *data;
  int TAM;
  int cursor; // CON %
  int contador;
  
public:
  ColaCircular (int length) {
    this->data = new T[length];
    this->TAM = length;
    this->cursor = 0;
    this->contador = 0;
  }

  int push (T data) {
    if (this->contador == this->TAM) {
      this->contador--;
      this->cursor = ++this->cursor % this->TAM;
    }
    this->data[((this->contador++)+this->cursor) % this->TAM] = data;
  }

  T pop () {
    if (this->contador > 0 && this->cursor >= 0) {
      T data = this->data[this->cursor];
      this->data[this->cursor] = -1;
      this->cursor = ++this->cursor % this->TAM;
      this->contador--;  
      return data;
    } else {
      return (T)-1;
    }
  }

 int getLength () {
   return this->contador;
 }

  void list () {
    int i = this->cursor;
    while (this->cursor < i % this->TAM) {
      std::cout << data[i] << "\n";
      i++;
    }
  }
};

#endif