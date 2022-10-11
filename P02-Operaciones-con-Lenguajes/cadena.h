#ifndef CADENA_H
#define CADENA_H

#include <iostream>
#include <vector>

#include "simbolo.h"
#include "stdio.h"
#include "string"

using namespace std;

class Cadena
{
private:
  vector<Simbolo> string_;

public:
  Cadena(vector<Simbolo> string_t);
  Cadena(const Simbolo &string_t);
  Cadena();

  ~Cadena();

  int getSize(void) const { return string_.size(); }
  vector<Simbolo> const getString(void) const { return string_; }
  Simbolo getStringSimbolo(int pos) const;

  void setStringSimbolo(Simbolo value);
  void setString(const Cadena &value);

  void WriteCadena();

  const int longitud(void) { return string_.size(); };

  Cadena inversa();

  bool checkCadena(const Cadena value);
  bool checkVectorCadenas(vector<Cadena> vec, Cadena str);

  friend bool operator<(const Cadena &x, const Cadena &y);
  void clear();

  Cadena &operator=(const Cadena &x);
};

ostream &operator<<(ostream &os, const Cadena &x);
bool operator==(const Cadena &x, const Cadena &y);
bool operator!=(const Cadena &x, const Cadena &y);

#endif