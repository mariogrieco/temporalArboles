#include <fstream>
#include <iostream>
#include <string.h>

/** 
  Manejador de Archivos del tipo Class
  solo binario...
**/

  using namespace std;

template <class T> class FileManager {
private:
  unsigned int seekg;
  unsigned int lineSize;
  unsigned int length;
  unsigned int lines;
  fstream *f;
  char f_name[25];

public:
  FileManager () {
    this->seekg = 0;
    this->lineSize = sizeof(T);
    this->f = new fstream();
    this->length = 0;
    this->lines = 0;
  }

  FileManager (char* name) {
    std::cerr << "FILE IS LOADING...\n";
    strcpy(this->f_name, name);
    this->seekg = 0;
    this->lineSize = sizeof(T);
    this->f = new fstream();
    this->f->open(this->f_name, std::ios::in | std::ios::out | std::ios::binary );
    if ( this->f->fail() ) 
    {
      std::cerr << "fail while opening file " << this->f_name << " FileManager exit(0)\n" ;
      exit(0);
    }
    else{
      std::cerr << "file has been load!\n";
      this->f->seekg(0,std::ios::end); // para leer la cantidad de lineas
      this->lines = (this->f->tellg()/sizeof(T));
      std::cerr << "lines: " << this->lines << '\n';
    } 
    // restauro el cursor despues de leer lineas
    update();
  }
  
  void open (char *name) {
    std::cerr << "FILE IS LOADING...\n";
    strcpy(this->f_name, name);
    this->seekg = 0;
    this->lineSize = sizeof(T);
    this->f = new fstream();
    this->f->open(this->f_name, std::ios::in | std::ios::out | std::ios::binary );
    if ( this->f->fail() ) 
    {
      std::cerr << "fail while opening file " << this->f_name << " FileManager exit(0)\n" ;
      exit(0);
    }
    else{
      std::cerr << "file has been load!\n";
      this->f->seekg(0,std::ios::end); // para leer la cantidad de lineas
      this->lines = (this->f->tellg()/sizeof(T));
      std::cerr << "lines: " << this->lines << '\n';
    } 
    // restauro el cursor despues de leer lineas
    update();
  }
  void gotoline (unsigned int pos) {
    this->f->seekg(pos*this->lineSize);
    this->seekg = pos;
  }
    
  void write(T *buf){ // ptr al la memoria del objeto
    this->f->write(reinterpret_cast<char*>(buf),sizeof(T));
  }

  void read(T *data){ // ptr a un objeto nuevo
    this->f->read(reinterpret_cast<char*>(data),sizeof(T));
  }

  void update(){
    this->f->clear();
    this->f->seekg(0, std::fstream::beg);
  }
  
  void close(){
    if ( this->f->is_open() )
    {
      this->f->close();
    }
  }

  bool eof(){
    return this->f->eof();
  }

  bool createFile(char *filename = (char*)"FILE.HEX" ){
    std::fstream output(filename, std::ios::out | std::ios::binary);
    if (  output.fail() )
    {
       std::cerr << "ERROR AL CREAR ARCHIVO " << filename << " \n";
       output.close();
    }else{
      std::cerr << "ARCHIVO " << filename << " CREADO \n";
      output.close();
    }
  }

  ~ FileManager () {
  }
};
