#include <cstring>
#include <fstream>
#include <iostream>
#include <string>

#include "alfabeto.h"
#include "cadena.h"
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
    Cadena str, inversa, sufijo, prefijo, subcadenas;
    build(line, alf, str);
    // out << "Alfabeto:" << alf << " Cadena:" << str << endl;
    cout << "Alfabeto:" << alf << " Cadena:" << str << endl;

    // str.inversa(cout);
    // str.sufijo(cout);
    // str.prefijo(cout);
    str.subcadenas(cout);
  }

  file.close();
  // out.close();
}

void build(const string line, Alfabeto& alf, Cadena& str) {
  Cadena arr_;
  Simbolo aux;
  string line_aux;
  int count = 0;

  for (int i = 0; i < line.length(); i++) {
    if (line[i] != ' ') {
      aux.addAnotherSimbolo(line[i]);
    } else {
      arr_.setStringSimbolo(aux);
      count++;
      aux.clear();
    }
  }
  int last = arr_.getSize();
  arr_.setStringSimbolo(aux);
  string sim_aux;

  if (count > 0) {
    for (int i = 1; i <= count; i++) {
      aux = arr_.getStringSimbolo(i);
      alf.addSimbolo(aux);
    }

    for (int i = 0; i < arr_.getStringSimbolo(last).getSize() - 1; i++) {
      sim_aux = arr_.getStringSimbolo(last).getSimboloAt(
          i);  // string para convertir a simbolo
      aux = toSimbol(sim_aux);
      str.setStringSimbolo(aux);
      aux.clear();
      sim_aux.clear();
    }
  } else {
    for (int i = 0; i < arr_.getStringSimbolo(last).getSize(); i++) {
      sim_aux = arr_.getStringSimbolo(last).getSimboloAt(
          i);  // string para convertir a simbolo
      aux = toSimbol(sim_aux);
      alf.addSimbolo(aux);
      str.setStringSimbolo(aux);
      sim_aux.clear();
    }
  }
}