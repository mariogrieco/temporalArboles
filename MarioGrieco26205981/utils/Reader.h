#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
// #include "typeinfo" 
#include <string>


/** 
	Para lectura de archivos de txt
	modo no binario , binary mode con FileManeger
**/

using namespace std;

class Reader
{
private:
	fstream ARCH;
	int lineCount;

public:

	Reader () {
		this->lineCount = 0;
	};

	Reader (char* dir) {
		this->open(dir);
	};

	bool open (char *dir) {
		this->lineCount = 0;
		this->lineCount = 0;
		this->ARCH.open(dir, ios::in | ios::out);
		if ( this->ARCH.fail())
		{
			cout << "error al abrir " << dir << endl;
			exit(0);
		}
	}

  void update(){
    this->ARCH.clear();
    this->ARCH.seekg(0, std::fstream::beg);
  }

	bool getline(char *where, char delim = '\n'){
		this->ARCH.getline(where, 2000, delim);
		return this->eof();
	}

	bool save (char *data) {
		this->ARCH << data << endl;
	}

	bool save (int data) {
		this->ARCH << data << endl;
	}

	bool save (bool data) {
		this->ARCH << data << endl;
	}

	bool save (double data) {
		this->ARCH << data << endl;
	}

	bool close () {
		ARCH.close();
	}
	bool nextStep(){}

	bool eof(){
		return !this->ARCH.eof();
	}

	~Reader(){
	};
	
};