#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>   
#include <ctype.h>
#include "../Ready/lib/Nodo.h"
#include "../Ready/utils/Reader.h"
#include "../Ready/lib/ColaPilaPrioridad.h"

class Miliciano {
private:
  char name[45];
  char rango[4];

public:
  Miliciano () {};
  Miliciano (char* name, char* rango) {
    strcpy(this->name, name);
    strcpy(this->rango, rango);
  };

  char* getRango () {
    return this->rango;
  }

  char* getName () {
    return this->name;
  }
  
  bool operator>(Miliciano d) {
    return ((int)this->rango[1] > d.rango[1]);
  }

  bool operator<(Miliciano d) {
    return ((int)this->rango[1] < d.rango[1]);
  }

  friend ostream& operator<<(ostream& os, const Miliciano& dt)
  {  
      os << dt.name << " " << dt.rango;  
      return os;  
  } 
  
  friend ostream& operator<<(ostream& os, const Miliciano *dt)
  {  
      os << dt->name <<  " " << dt->rango;  
      return os;  
  } 

  ~Miliciano () {};
};

Reader milicia;
Reader jugada;
ColaPilaPrioridad<Miliciano> data;
Nodo<Miliciano> *oput;
Nodo<Miliciano> *Cursor;

// bool singleTown = false;
using namespace std;

void loadMilitians (char *name, char* rango) {
  data.push(new Miliciano(name, rango));
}

Nodo<Miliciano>* searchMilitianByName (char* name, int way = 1) {
  Nodo<Miliciano> *frenteMem = data.getFrente();
  if (!frenteMem) return NULL;
  
  if (way) {
    do {
      if ( strcmp(frenteMem->getData().getName(), name) == 0) {
        return frenteMem;
      }
      frenteMem = frenteMem->getNext();
    } while (frenteMem != data.getFrente());
  } else {
    do {
      if ( strcmp(frenteMem->getData().getName(), name) == 0) {
        return frenteMem;
      }
      frenteMem = frenteMem->getBack();
  } while (frenteMem != data.getFrente());
  }
}

Nodo<Miliciano>* searchMilitianByMinor (Nodo<Miliciano>* cursor, int way = 1) {
  if (way) {
  } else {
  }
}

Nodo<Miliciano>* popOrMove (Nodo<Miliciano>* cursor) {
  if (!cursor) return NULL;
  if (data.getFrente() == cursor || data.getFrente()->getData()> cursor->getData() ) {
    if (data.getFrente() == data.getCola()) {
      data.pop();
      return cursor;
    }else {
      cursor->getBack()->setNext(cursor->getNext());
      cursor->getNext()->setBack(cursor->getBack());
      if (cursor == data.getFrente()) {
        data.setFrente(cursor->getNext());
      }
      if (cursor == data.getCola()) {
        data.setCola(cursor->getBack());
      }
      return cursor;
    }
  }
  return NULL;
}

void getJugada (char *a, char* b) {
    a[0] = '\0';
    b[0] = '\0';
    strcpy(a, "");
    strcpy(b, "");
    jugada.getline(a, ',');
    jugada.getline(b, '\n');
}

int main () {
  char a[256];
  char b[256];
  int num; 
  // bool band = false;
  cout << "Josephus quiz..." << endl;
  milicia.open((char*)"milicia.txt");
  jugada.open((char*)"jugada.txt");
  
  while (milicia.eof()) {
    a[0] = '\0';
    b[0] = '\0';
    strcpy(a, "");
    strcpy(b, "");
    milicia.getline(a, ',');
    milicia.getline(b, '\n');
    if (strcmp(a, "") != 0 && strcmp(b, "") != 0) {
      loadMilitians(a,b);
    }
  }

  getJugada(a, b);
  num = atoi(b);

  Cursor = searchMilitianByName(a);
  if (!Cursor) {
    cout << " error no encontrado primer miliciano!" << endl;
  }
  while (num--) {
    Cursor = Cursor->getNext();
  }

  data.list();
  cout << num+1 << " para: " << Cursor->getData() << endl;
  oput = popOrMove(Cursor);
  if (!oput) {

  }

  data.list();
  data.cheeckIntegrity();
}


/**
  3 rangos 
    R0, R1, R2 -> MAYOR
  
  primer nombre sentido horario
   despues:

  de la jugada sacar siempre y cuando no se 
  encuentren menor rango en la lista
  de lo contrario cambiar el sentido del
  recorrido y buscar el militar

  Realizar la operación de recorrido, según lo indicado, imprimiendo en cada momento:
    a. Nombre del MILITAR desde donde se partió el recorrido.
    b. Nombre y rango del MILITAR que sale del juego.
    c. Nombre y rango del MILITAR que fue reemplazado por su rango (SI LO HAY).
    d. Numero de conteo.
    e. Sentido del recorrido.
**/
