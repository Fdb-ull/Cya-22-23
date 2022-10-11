// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 2: Operaciones con lenguajes
// Autor: Franco Dendi Bele
// Correo: alu0101134703@ull.edu.es
// Fecha: 10/10/2022
//
// Archivo Simbolo.cc:
// Contiene los metodos de la clase Simbolo
//
// Referencias:
//
//
// Historial de revisiones
// 08/10/2022 - Creacion del primer codigo
#include "simbolo.h"

Simbolo::Simbolo(const string &value) : value_(value) {}

Simbolo::~Simbolo() { value_.erase(); }

void Simbolo::replaceSimbolo(string value) {
  value_.resize(value.length() - 1);
  for (int i = 0; i < value.length(); i++) {
    value_[i] = value[i];
  }
}

Simbolo toSimbol(string value) {
  Simbolo aux;
  for (int i = 0; i < value.length(); i++) {
    aux.addAnotherSimbolo(value[i]);
  }
  return aux;
}
void Simbolo::addAnotherSimbolo(char sim) { value_.push_back(sim); }

void Simbolo::setSimbolo(char sim) {
  value_.clear();
  value_.push_back(sim);
}

string Simbolo::getSimbolo() const { return value_; }

char Simbolo::getSimboloAt(int pos) const { return value_[pos]; }
void Simbolo::addSimbolo(string sim) { value_ = sim; }

int Simbolo::getSize() const { return value_.length(); }
void Simbolo::clear() { value_.erase(); }

ostream &operator<<(ostream &os, const Simbolo &x) {
  os << x.getSimbolo();
  return os;
}

Simbolo &Simbolo::operator=(const Simbolo &x) {
  this->value_ = x.getSimbolo();

  return *this;
}

bool operator==(const Simbolo &x, const Simbolo &y) {
  return x.getSimbolo() == y.getSimbolo();
}

bool operator!=(const Simbolo &x, const Simbolo &y) {
  return x.getSimbolo() != y.getSimbolo();
}

ostream &Simbolo::writeSimbolo(ostream &os) {
  for (int i = 0; i < getSize(); i++) {
    os << value_[i];
  }
  return os;
}
bool operator<(const Simbolo &x, const Simbolo &y) {
  if (x.getSize() != y.getSize()) {
    return x.getSize() < y.getSize();
  } else {
    for (int i = 0; i < x.getSize(); i++) {
      if (x.getSimbolo()[i] != y.getSimbolo()[i]) {
        return x.getSimboloAt(i) < y.getSimboloAt(i);
      }
    }
  }
  return false;
}