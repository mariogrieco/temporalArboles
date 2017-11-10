int length(char *);   //Tamano del char
int length(int);      // digitos int
int getAt(int, int ); // pos del int (cual,pos)

// indexado a 1
int length (char *cadena_t) {
  int count = 0;

  while ( cadena_t[count] != '\0' ) {
    count++;
  }
  return count;
}

// indexado a 1
int length (int numbers_t) {
  int count = 0;
    while ( numbers_t != 0 ) {
      count++;
      numbers_t /= 10;
    }
  return (count);
}

// indexado a 0
int indexOf (int entero, int pos) {
    int i = 0;

    while ( i < pos) {
      entero /= 10;
      i++;
    }
    return (entero%10);
}

 void filter (int arr[], int data, int length) {
   int c = 0;
   while (c < length) {
      if (data == arr[c]) {
        arr[c] = -1;
      }
      else {
        c++;
      }
   }
 }



void map (int data[], int largo) {
  int i = 0;
  int x;
  while (i < largo) {
     x = 0;
     while (x < largo) {
       if (x == i) x++;
       if (x >= largo) break;
      if (data[x] == data[i]) {
        data[x] = -1;
      }
       x++;
     }
     cout << "\n";
    i++;
  }
} 

void map (char data[], int largo) {
  int i = 0;
  int x;
  while (i < largo) {
     x = 0;
     while (x < largo) {
       if (x == i) x++;
       if (x >= largo) break;
      if (data[x] == data[i]) {
        data[x] = ' ';
      }
       x++;
     }
     cout << "\n";
    i++;
  }
} 

void tolowerString (char *str) {
  int contador = 0;
  while (str[contador] != '\0') {
    str[contador] = tolower(str[contador]);
    contador++;
  }
}

// primos 
// pares