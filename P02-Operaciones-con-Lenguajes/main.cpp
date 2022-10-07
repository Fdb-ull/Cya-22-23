#include <cstring>
#include <fstream>
#include <iostream>
#include <string>

#include "alfabeto.h"
#include "cadena.h"
#include "lenguaje.h"
#include "simbolo.h"

using namespace std;

void build(const string line, Alfabeto& alf, Cadena& str);

int main() {
  ifstream file("prueba.txt");
  if (!file.is_open()) {
    cout << "Error al abrir ejemplo.dat\n";
    exit(EXIT_FAILURE);
  }
  string line;  // = "a b abbab";

  // ofstream out("salida.txt");

  while (getline(file, line, '\n')) {
    Alfabeto alf;
    Cadena str;
    Simbolo sim_aux;
    string aux;

    size_t last_alf =
        line.find_first_of('}');  // posicion de donde acaba el alfabeto
    size_t last_str =
        line.find_last_of('}');  // posicion donde empiza el lenguaje
    for (size_t i = 2; i < last_alf; i++) {
      if (line[i] != ' ') {
        sim_aux.addAnotherSimbolo(line[i]);
      } else {
        alf.addSimbolo(sim_aux);  // Añadimos el simbolo al alfabeto
        sim_aux.clear();          // limpiamos el simbolo auxiliar
      }
    }

    for (size_t i = line.find_last_of('{') + 2; i < last_str; i++) {
      if (line[i] != ' ') {
        sim_aux.addAnotherSimbolo(line[i]);
      } else {
        str.setStringSimbolo(sim_aux);
        // lang.insertString(str);
      }
    }

    // build(line, alf, str);
    //  out << "Alfabeto:" << alf << " Cadena:" << str << endl;
    // cout << "Alfabeto:" << alf << " Cadena:" << str << endl;
  }

  file.close();
  // out.close();
}