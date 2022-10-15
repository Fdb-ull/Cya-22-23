#include "alfabeto.h"

Alfabeto::Alfabeto(Simbolo value) { value_.insert(value); }

Alfabeto::Alfabeto() {}

Alfabeto::~Alfabeto() { value_.clear(); }

set<Simbolo> Alfabeto::getAlfabeto() const { return value_; }

Simbolo Alfabeto::getSimbolo(int pos) const {
  std::set<Simbolo>::iterator it = value_.begin();
  std::advance(it, pos);
  Simbolo x = *it;

  return x;
}
void Alfabeto::setAlfabeto(const set<Simbolo> value) {
  value_.clear();
  value_ = value;
}

void Alfabeto::setSimbolo(Simbolo value) { value_.insert(value); }

void Alfabeto::addSimbolo(Simbolo value) { value_.insert(value); }
Simbolo Alfabeto::getSimboloVacio(void) {
  string x = "&";
  Simbolo sim;
  sim.addSimbolo(x);

  return sim;
}
Alfabeto Alfabeto::unionAlfabeto(const Alfabeto &alf) {
  this->clear();
  for (int i = 0; i < getSize(); i++) this->addSimbolo(getSimbolo(i));
  for (int i = 0; i < alf.getSize(); i++) this->addSimbolo(alf.getSimbolo(i));

  return *this;
}
/*
Alfabeto Alfabeto::diferenciaAlfabeto(const Alfabeto &alf)
{
  Alfabeto alf_aux;
  Cadena string_aux;
  for (int i = 0; i < alf.getSize(); i++)
  {
    string_aux.setStringSimbolo(alf.getSimbolo(i));
    for (int j = 0; j < string_aux.getSize(); j++)
      if (string_aux.getStringSimbolo(i) != getSimboloVacio())
        alf_aux.addSimbolo(string_aux.getStringSimbolo(j));
  }
  return alf_aux;
}
*/
ostream &operator<<(ostream &os, const Alfabeto &x) {
  os << "{ ";
  for (int i = 0; i < x.getSize(); i++) {
    os << x.getSimbolo(i) << " ";
  }
  os << "} ";
  return os;
}

Alfabeto &Alfabeto::operator=(const Alfabeto &y) {
  if (this != &y) {
    this->value_ = y.value_;
  }
  return *this;
}

void Alfabeto::clear() { value_.clear(); }