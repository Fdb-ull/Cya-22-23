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
// Archivo Lenguaje.cc:
// Contiene los metodos de la clase Lenguaje
//
// Referencias:
//
//
// Historial de revisiones
// 08/10/2022 - Creacion del primer codigo

#include "lenguaje.h"

// alf_axu = " a b " value = " abb a bb "
Lenguaje::Lenguaje(Alfabeto &alf_aux, Cadena &value) {}
Lenguaje::Lenguaje(Alfabeto &alf_aux) : alf_(alf_aux) {
  /* Cadena cad_aux;
   Simbolo sim_aux;
   string aux = "{}";  // no se si esta del todo bien, comprobar
   sim_aux.addSimbolo(aux);
   cad_aux.setStringSimbolo(sim_aux);
   arr_.insert(cad_aux);*/
}
Lenguaje::Lenguaje() {}
Lenguaje::~Lenguaje() {}

void Lenguaje::clear() {
  arr_.clear();
  alf_.clear();
}

Cadena Lenguaje::getStringPos(int pos) const {
  std::set<Cadena>::iterator it = arr_.begin();
  std::advance(it, pos);
  Cadena x = *it;

  return x;
}

set<Cadena> Lenguaje::getString() const { return arr_; }

Alfabeto Lenguaje::getAlfabeto() const { return alf_; }

Cadena Lenguaje::getCadenaVacia(void) {
  string x = "&";
  Simbolo sim;
  sim.addSimbolo(x);
  Cadena aux;
  aux.setStringSimbolo(sim);
  return aux;
}

void Lenguaje::insertString(Cadena str) { arr_.insert(str); }

void Lenguaje::insertAlfabeto(Alfabeto alf) {
  alf_.setAlfabeto(alf.getAlfabeto());
}

void Lenguaje::setLenguaje(const Lenguaje &lang) {
  arr_.clear();
  for (int i = 0; i < lang.getSize(); i++) arr_.insert(lang.getStringPos(i));
}
// works =)
Lenguaje Lenguaje::diferencia(const Lenguaje y) {
  Lenguaje aux;
  int count = 0;
  if (getSize() == y.getSize()) {
    for (int i = 0; i < getSize(); i++) {
      count = 0;
      for (int j = 0; j < y.getSize(); j++)
        if (getStringPos(i) == y.getStringPos(j)) count++;

      if (count == 0) aux.insertString(getStringPos(i));
    }
  }
  if (aux.getSize() < 1) {
    aux.insertString(getCadenaVacia());
  }

  Alfabeto alf_aux;
  Cadena string_aux;
  for (int i = 0; i < aux.getSize(); i++) {
    string_aux.setString(aux.getStringPos(i));
    for (int j = 0; j < string_aux.getSize(); j++)
      if (string_aux.getStringSimbolo(i) != getCadenaVacia())
        alf_aux.addSimbolo(string_aux.getStringSimbolo(j));
  }
  alf_.setAlfabeto(alf_aux.getAlfabeto());
  return aux;
}
bool Lenguaje::checkCadena(Cadena &x) const {
  for (int i = 0; i < getSize(); i++) {
    if (getStringPos(i) == x) return true;
  }

  return false;
}

void Lenguaje::generateAlfabeto(Lenguaje &value) {
  Alfabeto alf;

  for (size_t i = 0; i < value.getSize(); i++) {
    Simbolo aux;
    for (size_t j = 0; j < value.getStringPos(i).getSize(); j++) {
      string x;
      for (int z = 0; z < value.getStringPos(i).getStringSimbolo(j).getSize();
           z++) {
        if (value.getStringPos(i).getStringSimbolo(j).getSimboloAt(z) != '&') {
          x.push_back(
              value.getStringPos(i).getStringSimbolo(j).getSimboloAt(z));
          aux.addSimbolo(x);
          alf.addSimbolo(aux);
        }
        x.clear();
      }
    }

    value.insertAlfabeto(alf);
  }
}
// works =)
Lenguaje Lenguaje::interseccion(const Lenguaje y) {
  Lenguaje aux;

  for (int i = 0; i < getSize(); i++)
    for (int j = 0; j < y.getSize(); j++)
      if (getStringPos(i) == y.getStringPos(j))
        aux.insertString(getStringPos(i));

  generateAlfabeto(aux);
  return aux;
}
// works =´)
Lenguaje Lenguaje::concatenacion(const Lenguaje &y) {
  Lenguaje aux;
  Cadena string_aux;
  Simbolo sim_aux;

  for (int i = 0; i < y.getSize(); i++)
    for (int j = 0; j < getString().size(); j++) {
      string_aux.clear();
      if (y.getStringPos(i) ==
          getCadenaVacia())  // Comprobamos que no se encuentre la cadena vacia
      {
        if (getStringPos(j) == getCadenaVacia())
          aux.insertString(getCadenaVacia());
        else {
          string_aux.setString(getStringPos(j));
          aux.insertString(string_aux);
        }
      } else if (getStringPos(j) == getCadenaVacia()) {
        string_aux.setString(y.getStringPos(i));
        aux.insertString(string_aux);

      } else {
        string_aux = y.getStringPos(i) + getStringPos(j);
        aux.insertString(string_aux);
      }
    }

  alf_ = alf_.unionAlfabeto(y.getAlfabeto());
  aux.alf_ = alf_;

  return aux;
}

// Works =)
Lenguaje Lenguaje::unioN(const Lenguaje y) {
  Lenguaje aux;

  for (int i = 0; i < this->getSize(); i++) {
    aux.insertString(this->getStringPos(i));
  }
  for (int i = 0; i < y.getSize(); i++) {
    aux.insertString(y.getStringPos(i));
  }
  aux.alf_ = alf_.unionAlfabeto(y.getAlfabeto());
  return aux;
}

// al ser ordenado por set, no se aprecia del todo la inversa, but works =)
Lenguaje Lenguaje::inversa(void) {
  Lenguaje inv;

  for (int i = 0; i < this->getSize(); i++) {
    inv.insertString(this->getStringPos(i).inversa());
  }
  inv.insertAlfabeto(this->getAlfabeto());
  return inv;
}

Lenguaje Lenguaje::potencia(const int n) {
  Lenguaje aux;
  if (n > 0) {
    aux.setLenguaje(*this);
    Lenguaje aux2;
    aux2.setLenguaje(*this);
    for (int i = 0; i < n; i++) {
      aux.setLenguaje(aux.concatenacion(aux2));
    }
  } else {  // si n = 0 el lenguaje contiene la cadena vacia
    Simbolo vacio("&");
    Cadena str(vacio);
    aux.insertString(str);
  }
  aux.insertAlfabeto(this->getAlfabeto());
  return aux;
}

ostream &operator<<(ostream &os, const Lenguaje &x) {
  os << "{ ";
  for (int i = 0; i < x.getString().size(); i++) {
    os << x.getStringPos(i);
  }
  os << "} ";
  return os;
}
Lenguaje &Lenguaje::operator=(const Lenguaje &L2) {
  if (this != &L2) {
    this->alf_ = L2.alf_;
    this->arr_ = L2.arr_;
  }
  return *this;
}