#ifndef _ASCII_
#define _ASCII_

   int get_ascii_length (char*);

   int get_ascii_length (char* input) {
    int i = 0;
    int contador = 0;

    while ( input[i] != '\0' ) {
      contador+= ((int)input[i]);
      i++;
    }

      return contador;
   }

#endif