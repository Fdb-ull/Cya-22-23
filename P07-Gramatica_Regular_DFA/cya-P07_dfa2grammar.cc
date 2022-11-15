// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 2: Operaciones con lenguajes
// Autor: Franco Dendi Bele
// Correo: alu0101134703@ull.edu.es
// Fecha: 10/10/2022
//
// Archivo cya-P02-Languages.cc: programa cliente.
// Contiene las cabeceras de la clase Alfabeto, encargada de
// almacenar y operar con un alfabeto
//
// Referencias:
//
//
// Historial de revisiones
// 02/11/2022 - Creacion del primer codigo, se introducen correctamente
// las variables correspondientes al estado, junto a sus transiciones y el
// automata se genera correctamente
// 03/11/2022 - Creacion del metodo que comprueba cadenas haciendo uso del
// automata

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>

#include "alfabeto.h"
#include "automata.h"
#include "cadena.h"
#include "estado.h"
#include "grammar.h"
#include "simbolo.h"
#include "transicion.h"

using namespace std;

int main(int argc, char *argv[]) {
  if (argc < 3)
    if (string(argv[1]) == "--help") {
      cerr << "\nPara iniciar el programa se debera ejecutar siguiendo la "
              "siguiente sintaxis: ./main FICHERO_AUTOMATA.fa "
              "FICHERO_CADENAS.txt\n"
           << endl
           << "El formato del fichero que especifica el automata debera ser el "
              "siguiente:"
           << endl
           << " Linea 1: Simbolos del alfabeto separados por espacios.\n"
              " Linea 2: Numero total de estados del automata.\n"
              " Linea 3: Estado de arranque del automata.\n"
              "\nA continuacion las siguientes lineas contendran la "
              " especificacion de cada estado, separada por espacios:\n"
              "---1º Numero identificador del estado.\n"
              "---2º Un 1 se se trata de un estado de aceptacion, un 0 en caso "
              "contrario.\n"
              "---3º Numero de transiciones que posee el estado.\n"
              "\nA continuacion para cada una de las transiciones y utilizando "
              " espacios en blanco como separadores, se detallara la "
              " informacion siguiente:\n"
              "---1º Simbolo de entrada necesario para la transicion.\n"
              "---2º Estado destino de la transicion.\n"
              "\n\n El formato del fichero que especifica las cadenas a probar "
              "en el automata sera el siguiente:\n"
              "---1º En cada linea vendra especificada la cadena\n"
              "---2º La cadena no debe contener espacios en blanco\n"
              "\n\n***IMPORTANTE, EL SIMBOLO & SERA UTILIZADO PARA REPRESENTAR "
              "LA CADENA VACIA***\n\n"
           << endl;
      exit(EXIT_FAILURE);
    } else {
      cerr << "Error, numero de argumentos incorreto." << endl
           << "Si necesita ayuda, introduzca el comando --help y se desplegara "
              "el modo de ejecucion."
           << endl;
      exit(EXIT_FAILURE);
    }

  string line;
  Automata automat(argv[1], argv[2]);
}