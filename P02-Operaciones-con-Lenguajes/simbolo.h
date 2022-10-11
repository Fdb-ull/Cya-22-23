
#ifndef SIMBOLO_H
#define SIMBOLO_H

#include <iostream>
#include <string>

using namespace std;

class Simbolo
{
private:
  string value_;

public:
  Simbolo(const string &value = "");
  ~Simbolo();

  string getSimbolo() const;
  char getSimboloAt(int pos) const;
  int getSize() const;

  void addSimbolo(string sim);
  void setSimbolo(char sim);
  void addAnotherSimbolo(char sim);
  void replaceSimbolo(string value);

  friend Simbolo toSimbol(string value);

  ostream &writeSimbolo(ostream &os);
  void clear();

  Simbolo &operator=(const Simbolo &x);
};

ostream &operator<<(ostream &os, const Simbolo &x);
bool operator==(const Simbolo &x, const Simbolo &y);
bool operator!=(const Simbolo &x, const Simbolo &y);
Simbolo toSimbol(string value);

#endif