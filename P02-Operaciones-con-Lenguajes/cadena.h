#ifndef CADENA_H
#define CADENA_H

#include <iostream>
#include <vector>

#include "simbolo.h"
#include "stdio.h"
#include "string"

using namespace std;

class Cadena {
 private:
  vector<Simbolo> string_;

 public:
  Cadena(vector<Simbolo> string_t);
  Cadena(const Simbolo& string_t);
  Cadena();

  ~Cadena();

  int getSize(void) const { return string_.size(); }
  void setStringSimbolo(Simbolo value);
  vector<Simbolo> const getString(void) const { return string_; }
  Simbolo getStringSimbolo(int pos) const;

  void WriteCadena();

  const int longitud(void) { return string_.size(); };

  ostream& inversa(ostream& os);
  ostream& sufijo(ostream& os);
  ostream& prefijo(ostream& os);
  ostream& subcadenas(ostream& os);
  Cadena subcadenas_aux(int ini, int fin);

  Cadena& operator=(const Cadena& x);
  bool checkCadena(const Cadena value);
  bool checkVectorCadenas(vector<Cadena> vec, Cadena str);

  void clear();
};

ostream& operator<<(ostream& os, const Cadena& x);

#endif