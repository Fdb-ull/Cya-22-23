#include "cadena.h"

Cadena::Cadena(vector<Simbolo> string_t) : string_(string_t) {}
Cadena::Cadena(const Simbolo& string_t) { string_.push_back(string_t); }
Cadena::Cadena() { string_.push_back(Simbolo("")); }

void Cadena::WriteCadena() {
  for (int i = 0; i < string_.size(); i++) {
    cout << string_[i];
  }
}

Cadena::~Cadena() { string_.clear(); }

void Cadena::setStringSimbolo(Simbolo value) { string_.push_back(value); }

Simbolo Cadena::getStringSimbolo(int pos) const {
  string aux;
  for (int i = 0; i < string_[pos].getSize(); i++) {
    aux.push_back(string_[pos].getSimboloAt(i));
  }
  Simbolo sim(aux);
  return sim;
}
ostream& Cadena::inversa(ostream& os) {
  Cadena aux;
  for (int i = string_.size() - 1; i > 0; --i) os << string_[i];

  os << endl;
  return os;
}
ostream& Cadena::sufijo(ostream& os) {
  Cadena aux, vacia;
  vector<Simbolo> str;

  os << "&";  // mostramos la cadena vacia
  for (int i = string_.size() - 1; 0 <= i; i--) {
    for (int j = string_.size() - 1; i < j; j--) {
      os << string_[j];
    }
    os << " ";
  }
  os << endl;
  return os;
}
ostream& Cadena::prefijo(ostream& os) {
  Cadena aux, vacia;
  vector<Simbolo> str;
  os << "&";  // mostramos la cadena vacia
  for (int i = 1; i < string_.size(); i++) {
    for (int j = 1; j <= i; j++) {
      os << string_[j];
    }
    os << " ";
  }
  os << endl;
  return os;
}

// comprobar esto
ostream& Cadena::subcadenas(ostream& os) {
  vector<Cadena> vec;
  Cadena aux;
  int count = 0;

  for (int i = 0; i < getSize(); i++) {
    for (int j = i + 1; j < getSize(); j++) {
      aux.setStringSimbolo(string_[j]);
      if (checkVectorCadenas(vec, aux) == false) vec.push_back(aux);
    }
    aux.clear();
  }
  for (int i = 0; i < vec.size(); i++) {
    os << vec[i] << " ";
  }

  return os;
}

bool Cadena::checkVectorCadenas(vector<Cadena> vec, Cadena str) {
  for (int i = 0; i < vec.size(); i++) {
    if (vec[i].checkCadena(str) == true) return true;
  }
  return false;
}
Cadena Cadena::subcadenas_aux(int ini, int fin) {
  Cadena aux;

  for (int i = ini; i < fin; i++) {
    aux.setStringSimbolo(string_[i]);
  }
  return aux;
}

bool Cadena::checkCadena(const Cadena value) {
  if (value.getSize() != this->getSize()) {
    return false;
  } else {
    for (int i = 0; i < string_.size(); i++) {
      if (value.getStringSimbolo(i) != this->getStringSimbolo(i)) return false;
    }
  }
  return true;
}

void Cadena::clear() { string_.clear(); }

ostream& operator<<(ostream& os, const Cadena& x) {
  if (x.getSize() == 0) {
    os << "&";
  } else {
    for (int i = 0; i < x.getString().size(); i++) {
      os << x.getString()[i];
    }
  }

  return os;
}

Cadena& Cadena::operator=(const Cadena& x) {
  this->string_ = x.getString();

  return *this;
}