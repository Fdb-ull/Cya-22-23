#include <iostream>
#include <sstream>

#include "cambioMonedas.h"

int main(int argc, char *argv[]) {
  if (argc != 2 && argc != 3) {
    cerr << "ERROR, Numero de argumentos incorrecto" << endl;
    exit(EXIT_FAILURE);
  }
  string argv1 = argv[1];
  if (argv1 != "-o" && argv1 != "-b" && argc == 3) {
    cerr << "ERROR, comando incorrecto." << endl
         << "Para usar el algoritmo mas optimo se debe introducir el comando -o"
         << endl;
    exit(EXIT_FAILURE);
  }

  float amount;
  int flag;
  if (argv1 == "-o") {
    istringstream cinx(argv[2]);
    cinx >> amount;
    flag = 0;
  } else if (argv1 == "-b") {
    istringstream cinx(argv[2]);
    cinx >> amount;
    flag = 1;
  } else {
    istringstream cinx(argv[1]);
    cinx >> amount;
    flag = 2;
  }

  if (0 <= amount) {
    CambioMonedas cambio(amount, flag);
    cout << cambio << endl;
  }
}