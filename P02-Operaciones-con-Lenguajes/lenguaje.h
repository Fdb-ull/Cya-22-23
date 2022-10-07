#ifndef LENGUAJE_H
#define LENGUAJE_H

#include <iostream>
#include <set>

#include "alfabeto.h"
#include "cadena.h"
#include "simbolo.h"

class Lenguaje {
 private:
  Alfabeto alf_;
  set<Cadena> arr_;

 public:
  Lenguaje(Alfabeto& alf_aux, Cadena& value);
  Lenguaje(Alfabeto& alf_aux);
  Lenguaje();
  ~Lenguaje();

  Alfabeto getAlfabeto() const;
  Cadena getStringPos(int pos) const;
  set<Cadena> getString() const;

  void insertString(Cadena str);
};

ostream& operator<<(ostream& os, const Lenguaje& x);

#endif