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
// Contiene las cabeceras de la clase Alfabeto, encargada de
// almacenar y operar con un alfabeto
//
// Referencias:
//
//
// Historial de revisiones
// 08/10/2022 - Creacion del primer codigo

#ifndef ALFABETO_H
#define ALFABETO_H

#include <iostream>
#include <set>

#include "cadena.h"
#include "simbolo.h"

using namespace std;

class Alfabeto {
 private:
  set<Simbolo> value_;  // Conjunto de simbolos del alfabeto

 public:
  Alfabeto(Simbolo value);
  Alfabeto();

  // Getters
  set<Simbolo> getAlfabeto() const;
  Simbolo getSimbolo(int pos) const;
  Simbolo getSimboloVacio(void);
  int getSize(void) const { return value_.size(); };

  // Setters
  void setAlfabeto(const set<Simbolo> value);
  void setSimbolo(Simbolo value);
  void addSimbolo(Simbolo value);

  // sobrecarga del operador de asignacion
  Alfabeto &operator=(const Alfabeto &y);

  void clear();
};
// sobrecarga del operador de insercion de flujo
ostream &operator<<(ostream &os, const Alfabeto &x);

#endif