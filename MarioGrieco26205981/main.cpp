#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "Arbol/Nodo.h"
#include "Arbol/ArbolAvl.h"
#include "Arbol/NodoArbol.h"
#include "Arbol/Cola.h" // CIRCULAR
#include "Arbol/Lista.h" // SUPER LISTA
// TODO PILA

ArbolAvl<int> *arbol = new ArbolAvl<int>();
NodoArbol<int> *raiz = new NodoArbol<int>();
Cola<int> *cola = new Cola<int>();
Lista<int> *lista = new Lista<int>();


// int items[20] = {2, 4, 2, 8, 4, 2, 6, 2, 2, 0, 0, 0, 8, 0, 4, 0, 6, 4, 8, 4};
int items[2] = {4, 3};
  using namespace std;

int main () {

  srand(time(NULL));
  raiz->setData(2);
  arbol->setRaiz(raiz);
  for ( int i = 0; i < 2; i++) {
    arbol->push(arbol->getRaiz(), items[i]);
  }

  // cout << arbol->get(arbol->getRaiz(), 'c');

  cout << "\n";
  arbol->imprimir(3);
  return 0;
}
