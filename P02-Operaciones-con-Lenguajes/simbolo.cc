#include "simbolo.h"

Simbolo::Simbolo(const string &value) : value_(value) {}

Simbolo::~Simbolo() { value_.erase(); }

void Simbolo::replaceSimbolo(string value)
{
  value_.resize(value.length() - 1);
  for (int i = 0; i < value.length(); i++)
  {
    value_[i] = value[i];
  }
}

Simbolo toSimbol(string value)
{
  Simbolo aux;
  for (int i = 0; i < value.length(); i++)
  {
    aux.addAnotherSimbolo(value[i]);
  }
  return aux;
}
void Simbolo::addAnotherSimbolo(char sim) { value_.push_back(sim); }

void Simbolo::setSimbolo(char sim)
{
  value_.clear();
  value_.push_back(sim);
}

string Simbolo::getSimbolo() const { return value_; }

char Simbolo::getSimboloAt(int pos) const { return value_[pos]; }
void Simbolo::addSimbolo(string sim) { value_ = sim; }

int Simbolo::getSize() const { return value_.length(); }
void Simbolo::clear() { value_.erase(); }

ostream &operator<<(ostream &os, const Simbolo &x)
{
  os << x.getSimbolo();
  return os;
}

Simbolo &Simbolo::operator=(const Simbolo &x)
{
  this->value_ = x.getSimbolo();

  return *this;
}

bool operator==(const Simbolo &x, const Simbolo &y)
{
  return x.getSimbolo() == y.getSimbolo();
}

bool operator!=(const Simbolo &x, const Simbolo &y)
{
  return x.getSimbolo() != y.getSimbolo();
}

ostream &Simbolo::writeSimbolo(ostream &os)
{
  for (int i = 0; i < getSize(); i++)
  {
    os << value_[i];
  }
  return os;
}