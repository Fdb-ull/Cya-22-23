#ifndef LENGUAJE_H
#define LENGUAJE_H

#include <iostream>
#include <set>

#include "alfabeto.h"
#include "cadena.h"
#include "simbolo.h"

// Lenguaje vacio = {}
// Lenguaje que contiene la cadena vacia = {&}

class Lenguaje
{
private:
  Alfabeto alf_;
  set<Cadena> arr_;

public:
  Lenguaje(Alfabeto &alf_aux, Cadena &value);
  Lenguaje(Alfabeto &alf_aux);
  Lenguaje();
  ~Lenguaje();

  Alfabeto getAlfabeto() const;
  Alfabeto &setAlfabeto(void) { return alf_; }

  Cadena getStringPos(int pos) const;
  set<Cadena> getString() const;
  int getSize() const { return arr_.size(); }
  Cadena getCadenaVacia(void);

  void setLenguaje(const Lenguaje &lang);

  void insertString(Cadena str);

  void insertAlfabeto(Alfabeto alf);

  Lenguaje diferencia(const Lenguaje y);
  Lenguaje unioN(const Lenguaje y);
  Lenguaje interseccion(const Lenguaje y);

  Lenguaje concatenacion(const Lenguaje &y);

  Lenguaje inversa(void);
  Lenguaje potencia(const int n);

  bool checkCadena(Cadena &x) const;
};

ostream &operator<<(ostream &os, const Lenguaje &x);

#endif