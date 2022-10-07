#ifndef ALFABETO_H
#define ALFABETO_H

#include <iostream>
#include <vector>

#include "simbolo.h"

using namespace std;

class Alfabeto {
 private:
  vector<Simbolo> value_;
  int sz_ = 0;

 public:
  Alfabeto(Simbolo value);
  Alfabeto();

  ~Alfabeto();

  void writeAlfabeto();
  int getSize(void) const { return sz_; };
  vector<Simbolo> getAlfabeto() const;
  Simbolo getSimbolo(int pos) const;

  void setSimbolo(Simbolo value);
  bool isSimbolo(Simbolo value);
  void addSimbolo(Simbolo value);
};

ostream& operator<<(ostream& os, const Alfabeto& x);

#endif