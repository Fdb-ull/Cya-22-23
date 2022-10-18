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
// Archivo Cadena.cc: .
// Contiene los metodos de la clase Cadena
//
// Referencias:
//
//
// Historial de revisiones
// 08/10/2022 - Creacion del primer codigo

#include "cadena.h"

Cadena::Cadena(vector<Simbolo> string_t) : string_(string_t) {}
Cadena::Cadena(const Simbolo &string_t) { string_.push_back(string_t); }
Cadena::Cadena() {}

void Cadena::WriteCadena()
{
  for (int i = 0; i < string_.size(); i++)
  {
    cout << string_[i];
  }
}

Cadena::~Cadena() { string_.clear(); }

void Cadena::setStringSimbolo(Simbolo value) { string_.push_back(value); }

void Cadena::setString(const Cadena &value)
{
  string_.clear();
  for (int i = 0; i < value.getSize(); i++)
  {
    string_.push_back(value.getStringSimbolo(i));
  }
}

Simbolo Cadena::getStringSimbolo(int pos) const
{
  string aux;
  for (int i = 0; i < string_[pos].getSize(); i++)
  {
    aux.push_back(string_[pos].getSimboloAt(i));
  }
  Simbolo sim(aux);
  return sim;
}
Cadena Cadena::inversa(void)
{
  Cadena aux;
  for (int i = string_.size() - 1; i >= 0; --i)
  {
    aux.setStringSimbolo(string_[i]);
  }
  return aux;
}
bool Cadena::checkVectorCadenas(vector<Cadena> vec, Cadena str)
{
  for (int i = 0; i < vec.size(); i++)
  {
    if (vec[i].checkCadena(str) == true)
      return true;
  }
  return false;
}

bool Cadena::checkCadena(const Cadena value)
{
  if (value.getSize() != this->getSize())
  {
    return false;
  }
  else
  {
    for (int i = 0; i < string_.size(); i++)
    {
      if (value.getStringSimbolo(i) != this->getStringSimbolo(i))
        return false;
    }
  }
  return true;
}

void Cadena::clear() { string_.clear(); }

ostream &operator<<(ostream &os, const Cadena &x)
{
  if (x.getSize() == 0)
  {
    os << "&";
  }
  else
  {
    for (int i = 0; i < x.getString().size(); i++)
    {
      os << x.getString()[i] << ", ";
    }
  }

  return os;
}

Cadena &Cadena::operator=(const Cadena &x)
{
  this->string_ = x.getString();

  return *this;
}

Cadena &Cadena::operator+(const Cadena &x)
{
  Simbolo sim_aux;
  Cadena aux;
  for (size_t i = 0; i < this->getSize(); i++)
  {
    for (size_t j = 0; j < x.getSize(); j++)
    {
      sim_aux = x.getStringSimbolo(j) + this->getStringSimbolo(i);
      aux.setStringSimbolo(sim_aux);
    }
  }
  this->setString(aux);

  return *this;
}

bool operator==(const Cadena &x, const Cadena &y)
{
  if (x.getSize() == y.getSize())
  {
    for (int i = 0; i < x.getSize(); i++)
      if (x.getStringSimbolo(i) != y.getStringSimbolo(i))
        return false;
  }
  else
    return false;

  return true;
}

bool operator!=(const Cadena &x, const Cadena &y)
{
  if (x.getSize() == y.getSize())
  {
    for (int i = 0; i < x.getSize(); i++)
      if (x.getStringSimbolo(i) != y.getStringSimbolo(i))
        return true;
  }
  else
    return true;

  return false;
}
bool operator<(const Cadena &x, const Cadena &y)
{
  if (x.getSize() != y.getSize())
  {
    return x.getSize() < y.getSize();
  }
  else
  {
    for (int i = 0; i < x.getSize(); i++)
    {
      if (x.getStringSimbolo(i).getSize() != y.getStringSimbolo(i).getSize())
      {
        return x.getStringSimbolo(i).getSize() <
               y.getStringSimbolo(i).getSize();
      }
      else
      {
        for (int i = 0; i < x.getSize(); i++)
        {
          if (x.getStringSimbolo(i).getSimbolo() !=
              y.getStringSimbolo(i).getSimbolo())
            return x.getStringSimbolo(i).getSimbolo() <
                   y.getStringSimbolo(i).getSimbolo();
        }
      }
    }
  }
  return false;
}