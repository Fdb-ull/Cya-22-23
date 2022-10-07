#include "alfabeto.h"

Alfabeto::Alfabeto(Simbolo value) {
  value_.push_back(value);
  sz_++;
}

Alfabeto::Alfabeto() {}

Alfabeto::~Alfabeto() { value_.clear(); }

vector<Simbolo> Alfabeto::getAlfabeto() const { return value_; }

Simbolo Alfabeto::getSimbolo(int pos) const { return value_[pos]; }

void Alfabeto::setSimbolo(Simbolo value) {
  for (int i = 0; i < value_.size(); i++) {
    value_.resize(value_.size() + 1);
    value_[value_.size() - 1] = value;
    sz_++;
  }
}

bool Alfabeto::isSimbolo(Simbolo value) {
  for (int i = 0; i < getSize(); i++) {
    if (value.getSimbolo() == value_[i].getSimbolo()) {
      return true;
    }
  }
  return false;
}

void Alfabeto::addSimbolo(Simbolo value) {
  // if (isSimbolo(value) != true) {
  value_.push_back(value);
  //}
}

ostream& operator<<(ostream& os, const Alfabeto& x) {
  for (int i = 0; i < x.getAlfabeto().size(); i++) {
    os << x.getAlfabeto()[i] << ",";
  }
  return os;
}