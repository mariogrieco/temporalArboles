#include <iostream>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "Ready/utils/Reader.h"
#include "Ready/lib/ColaEnlazada.h"
#include "Ready/lib/PilaEnlazada.h"

using namespace std;

Reader data;
ColaEnlazada<char> *cola;
PilaEnlazada<char> *pila;


void tolowerString (char *str) {
  int contador = 0;
  while (str[contador] != '\0') {
    str[contador] = tolower(str[contador]);
    contador++;
  }
}

void poped (char *str) {
  int contador = 0;
  while (str[contador] != '\0') {
    if (str[contador] != ' ') {
      cola->push(str[contador]);
      pila->push(str[contador]);
    }
    contador++;
  }
}

int main () {
  data.open((char*)"palindromos.txt");
  char txt[256];
  char a = ' ';
  bool band = true;
  char b = ' ';

  while (data.eof()) {
    band = true;
    data.getline(txt);
    tolowerString(txt);
    pila = new PilaEnlazada<char>();
    cola = new ColaEnlazada<char>();
    poped(txt);

    do {
      a = cola->pop();
      b = pila->pop();

      cout << a << " " << b << endl;
      if ( a != b )  {
        band = false;
      }
    }while (a && b);

    if (band) {
      cout << txt << " es palindromo " << endl;
    }

    cout << " ------ " << endl;
  }
}
