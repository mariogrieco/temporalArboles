#include <iostream>
#include "Multilista.h"
#include "Producto.h"
#include "Reader.h"
#include "Departamento.h"

  using namespace std;
  char *departamento_name_file = "DEPARTAMENTO.TXT";
  char *productos_name_file = "PRODUCTOS.TXT";
  
  Multilista<Departamento, Producto> data;
  Reader departamento(departamento_name_file);
  Reader productos(productos_name_file);
  Reader temp, temp2;

void registrarDepartamentos () {
  while (departamento.eof()) {
    char codigo[25];
    char name[25];
    departamento.getline(codigo, ',');
    departamento.getline(name);
    
    data.registrar(Departamento(atoi(codigo), name));
  }

  departamento.close();
}

void registrarProductos () {
  while (productos.eof()) {
    char codigo[25];
    char des[25];
    char price[25];
    char cantidad[25];
    int i = 0;

    productos.getline(codigo, ',');
    productos.getline(des, ',');
    productos.getline(price, ',');
    productos.getline(cantidad);

    data.push(Departamento((atoi(codigo)/100), "mio"), Producto(atoi(codigo), des, strtod(price, NULL), atoi(cantidad)));
  }

  productos.close();
}

void save () {
  Nodo<Producto> *productos;
  Nodo<Producto> *it;
  NodoLista<Departamento, Producto> *nodos;
  Departamento cat;
  Producto pro;
  temp.create(departamento_name_file);
  temp.open(departamento_name_file);

  temp2.create(productos_name_file);
  temp2.open(productos_name_file);

  nodos = data.getFrente();

  while (nodos) {
    char str[80];
    cat = nodos->getCategoria();

   if (cat.getCodigo() && cat.getName()) {
      temp.save(cat.getCodigo());
      temp.save(',');
      temp.save(cat.getName());
      temp.save('\n');
   }

    productos = nodos->getData()->getFrente();
    it = productos;

    do {
      if (productos) {
        if (productos->getData().getCodigo() && productos->getData().getDescripcion()) {
          temp2.save(productos->getData().getCodigo());
          temp2.save(',');
          temp2.save(productos->getData().getDescripcion());
          temp2.save(',');
          temp2.save(productos->getData().getPrecio());
          temp2.save(',');
          temp2.save(productos->getData().getCantidad());
          temp2.save('\n');
        }
        productos = productos->getNext();
      }
    } while (productos != it);
    
    nodos = nodos->getNext();
  }

  temp.close();
  temp2.close();
}

int main () {

  registrarDepartamentos();
  registrarProductos();
  Nodo<Producto> *item;
  Producto *items = NULL;
  int code;
  int cantidad;
  bool opt = 1;

  cout << "INVENTARIO INICIAL!" << endl;
  // system("clear");
  system("cls");
  while (opt) {
    data.list(); 
    cout << "Ingresa el Codigo del Producto!" << endl;
    cin >> code;
    items = data.modListItems(Departamento(code/100, ""), Producto(code, "", 0, 0)); 
    if (items) {
      cout << " Encontrado " << (*items) << endl;
      cout << "Ingresa la cantidad de productos que quieres comprar: ";
      cin >> cantidad;
      if (cantidad <= items->getCantidad()) {
        items->setCantidad(items->getCantidad()-cantidad);
        cout << " Su factura por la compra de ";
        cout << items->getDescripcion() << "\n";
        cout << "Codigo" << items->getCodigo() << "\n";
        cout << "Precio x unidad " << items->getPrecio() << "\n";
        cout << "Compra de " << cantidad << " U\n";
        cout << "Total Compra : " << items->getPrecio()*cantidad << endl;
        cout << "...";
        cout << " \n " << endl;
        // departamento_name_file, productos_name_file
        save();
      }else {
        cout << "El inventario no tiene "  << cantidad << " unidades " << endl;
        cout << "No se puede realizar la Operacion\n " << endl;
      }
    }
    else {
      cout << code << " no se encuentra~!" << endl;
    }
    cout << "Ingresa... \n1] Otra operacion \n0] Salir\n" << endl;
    cin>>opt;

    // system("clear");
    system("cls");
  }

  cout << " Inventario Restante ...\n";
  data.list();

  return 0;
}
