#include <iostream>

#include "nodoarbol.h"
#include "ArbolAvl.h"
#include "ArbolBB.h"

using namespace std;

int main () {

  ArbolBB<int> *demo = new ArbolBB<int>();

  demo->agregar(2);
  demo->agregar(1);
  demo->agregar(3);
  demo->agregar(3);
  demo->agregar(2);
  demo->agregar(5);
  demo->agregar(6);
  demo->agregar(4);
  demo->imprimir(2);

  cout << " load " << endl;

  return 0;
}
