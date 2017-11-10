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

	Reader (char* dir, bool remove = false) {
		this->open(dir, remove);
	};

	void create (char* filename) {
		this->ARCH.open(filename, ios::out);
		this->ARCH << "\n" << endl;
		this->close();
	}

	bool open (char *dir, bool remove = false) {
		this->lineCount = 0;
		this->lineCount = 0;
		this->ARCH.open(dir, ios::in | ios::out);
		if (this->ARCH.fail())
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
		this->ARCH << data;
	}

	bool save (char data) {
		this->ARCH << data;
	}

	bool save (int data) {
		this->ARCH << data;
	}

	bool save (float data) {
		this->ARCH << data;
	}

	bool save (bool data) {
		this->ARCH << data;
	}

	bool save (double data) {
		this->ARCH << data;
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