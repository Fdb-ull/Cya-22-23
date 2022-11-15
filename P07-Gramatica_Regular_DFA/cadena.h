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
// Archivo cya-P02-Languages.cc: programa cliente.
// Contiene las cabeceras de la clase Cadena, se encarga
// de alamcenar y gestionar operaciones con Cadenas
//
// Referencias:
//
//
// Historial de revisiones
// 08/10/2022 - Creacion del primer codigo

#ifndef CADENA_H
#define CADENA_H

#include <iostream>
#include <vector>

#include "simbolo.h"
#include "stdio.h"
#include "string"

using namespace std;

class Cadena {
 private:
  vector<Simbolo> string_;

 public:
  Cadena(vector<Simbolo> string_t);
  Cadena(const Simbolo &string_t);
  Cadena();

  int getSize(void) const { return string_.size(); }
  vector<Simbolo> const getString(void) const { return string_; }
  Simbolo getStringSimbolo(int pos) const;

  void setStringSimbolo(Simbolo value);
  void setString(const Cadena &value);

  const int longitud(void) { return string_.size(); };

  Cadena inversa();

  bool checkCadena(const Cadena value);
  bool checkVectorCadenas(vector<Cadena> vec, Cadena str);

  friend bool operator<(const Cadena &x, const Cadena &y);
  void clear();

  Cadena &operator=(const Cadena &x);
  Cadena &operator+(const Cadena &x);
};

ostream &operator<<(ostream &os, const Cadena &x);
bool operator==(const Cadena &x, const Cadena &y);
bool operator!=(const Cadena &x, const Cadena &y);

#endif