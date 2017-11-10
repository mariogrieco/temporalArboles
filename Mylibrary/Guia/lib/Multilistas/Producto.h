#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>   
#include <ctype.h>

  using namespace std;

class Producto {
  private:
    int codigo; // 10, 20, 30 + surifijo
    char descripcion[25]; 
    double precio;
    int cantidad;

  public:
    Producto () {};

    Producto (int codigo,char descripcion[25],double  precio, int cantidad) {
      this->setCodigo(codigo);
      this->setDescripcion(descripcion);
      this->setPrecio(precio);
      this->setCantidad(cantidad);
    };

    void setDescripcion (char descripcion[25]) {
      strcpy(this->descripcion, descripcion);
    }

    void setCantidad (int cantidad) {
      this->cantidad = cantidad;
    }

    int getCantidad () {
      return this->cantidad;
    }

    char* getDescripcion () {
      return this->descripcion;
    }

    void setCodigo (int codigo) {
      this->codigo = codigo;
    }

    void setPrecio (double precio)
    {
      this->precio = precio;
    }

    double getPrecio () {
      return this->precio;
    }

    int getCodigo () {
      return this->codigo;
    }
    
    bool operator>(Producto i) {
      return (this->codigo > i.getCodigo());
    }

    bool operator>=(Producto i) {
      return (this->codigo >= i.getCodigo());
    }

    bool operator<=(Producto i) {
      return (this->codigo <= i.getCodigo());
    }

    bool operator<(Producto i) {
      return (this->codigo < i.getCodigo());
    }

    bool operator==(Producto i) {
      return (this->codigo == i.getCodigo());
    }
    
    friend ostream& operator<<(ostream& os, const Producto& dt)
    {  
        os << "Codigo: " << dt.codigo << " Producto: " << dt.descripcion  << " Precio: " << dt.precio << " (X" <<dt.cantidad << ")";  
        return os;  
    } 

    ~Producto () {};
};
