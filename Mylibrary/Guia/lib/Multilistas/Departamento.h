class Departamento {
private:
  int codigo; // 10, 20 o 30
  char nombre[25];
  // 10 Ropa
  // 20 Hogar y lenceria
  // Ferreteria

public:
  Departamento () {}

  Departamento (int codigo, char* nombre) {
    this->setCodigo(codigo);
    this->setName(nombre);
  }

  int getCodigo () {
    return this->codigo;
  }

  void setCodigo (int codigo) {
    this->codigo = codigo;
  }

  void setName(char* name) {
    strcpy(this->nombre, name);
  }

  char* getName () {
    return this->nombre;
  }

  bool operator>(Departamento i) {
    return (this->codigo > i.getCodigo());
  }

  bool operator>=(Departamento i) {
    return (this->codigo >= i.getCodigo());
  }

  bool operator<=(Departamento i) {
    return (this->codigo <= i.getCodigo());
  }


  bool operator!=(Departamento i) {
    return (this->codigo != i.getCodigo());
  }

  bool operator<(Departamento i) {
    return (this->codigo < i.getCodigo());
  }

  bool operator==(Departamento i) {
    return (this->codigo == i.getCodigo());
  }
  
  friend ostream& operator<<(ostream& os, const Departamento& dt)
  {  
      os << "Departamento de:" << dt.nombre << ", Codigo " << dt.codigo;  
      return os;  
  } 


  ~ Departamento () {}
};