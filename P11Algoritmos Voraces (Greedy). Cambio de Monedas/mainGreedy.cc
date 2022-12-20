// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 2: Operaciones con lenguajes
// Autor: Franco Dendi Bele
// Correo: alu0101134703@ull.edu.es
// Fecha: 19/12/2022
//
// Archivo mainGreddy.cc: programa cliente.
// Programa encargado de gestionar las operaciones de E/S
// y las diferentes opciones que maneja el programa
//
// Referencias:
//
//
// Historial de revisiones

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
  if (argv1 == "-o") {  // Metodo optimizado
    istringstream cinx(argv[2]);
    cinx >> amount;
    flag = 0;
  } else if (argv1 == "-b") {  // Cambio con billetes y monedas
    istringstream cinx(argv[2]);
    cinx >> amount;
    flag = 1;
  } else {  // Metodo por defecto
    istringstream cinx(argv[1]);
    cinx >> amount;
    flag = 2;
  }

  if (0 < amount) {
    CambioMonedas cambio(amount, flag);
    cout << cambio << endl;
  } else {
    cerr << "ERROR, Cantidad incorrecta, la cantidad debe ser > 0.\n";
    exit(EXIT_FAILURE);
  }
}