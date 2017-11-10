
#ifndef _Palabra_
#define _Palabra_

class Palabra {
  char palabra[256]; 
  int claveNumerica;

public: 
  Palabra () {};

  Palabra (char *palabra, int claveNumerica) {
    strcpy(this->palabra, palabra);
    this->claveNumerica = claveNumerica;
  };

  int getClaveNumerica () {
    return this->claveNumerica;
  }

  void setClaveNumerica (int claveNumerica) {
    this->claveNumerica = claveNumerica;
  }

  char* getPalabra () {
    return this->palabra;
  }

  void setPalabra (char* palabra) {
    strcpy(this->palabra, palabra);
  }

  friend ostream& operator<<(ostream& os, const Palabra dt)
  {  
      os << dt.palabra << "[keyCode " << dt.claveNumerica << "]";  
      return os;  
  }
  
  bool operator==(const Palabra dt)
  {  
    return this->claveNumerica == dt.claveNumerica;
  } 

  bool operator=(const Palabra dt)
  {  
    strcpy(this->palabra, dt.palabra);
    this->claveNumerica = dt.claveNumerica;
  } 

  bool operator<(const Palabra dt)
  {  
    return this->claveNumerica < dt.claveNumerica;
  } 


  bool operator>(const Palabra dt)
  {  
    return this->claveNumerica > dt.claveNumerica;
  } 
};


class PalabraToList {
public:

  char palabra[256]; 
  int claveNumerica;

  PalabraToList () {}

  PalabraToList (Palabra in) {
    strcpy(this->palabra, in.getPalabra());
    this->claveNumerica = in.getClaveNumerica();
  }

  char* getPalabra () {
    return this->palabra;
  }
  
  friend ostream& operator<<(ostream& os, const PalabraToList dt)
  {  
      os << dt.palabra << "[keyCode " << dt.claveNumerica << "]";  
      return os;  
  }
  
  bool operator==(const PalabraToList dt)
  {  
    return ((int)this->palabra[0]) == ((int)dt.palabra[0]);
  } 

  bool operator=(const PalabraToList dt)
  {  
    strcpy(this->palabra, dt.palabra);
    this->claveNumerica = dt.claveNumerica;
  } 

  bool operator=(const PalabraToList *dt)
  {  
    strcpy(this->palabra, dt->palabra);
    this->claveNumerica = dt->claveNumerica;
  } 

  bool operator<(const PalabraToList dt)
  {  
    return ((int)this->palabra[0]) < ((int)dt.palabra[0]);
  } 


  bool operator>(const PalabraToList dt)
  {  
    return ((int)this->palabra[0]) > ((int)dt.palabra[0]);
  } 
};

#endif
