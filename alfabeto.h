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
  set<Simbolo> value_;

 public:
  Alfabeto(Simbolo value);
  Alfabeto();

  ~Alfabeto();

  void writeAlfabeto();
  int getSize(void) const { return value_.size(); };
  set<Simbolo> getAlfabeto() const;
  Simbolo getSimbolo(int pos) const;

  void setSimbolo(Simbolo value);
  void addSimbolo(Simbolo value);
  void setAlfabeto(const set<Simbolo> value);

  Simbolo getSimboloVacio(void);

  Alfabeto unionAlfabeto(const Alfabeto &alf);
  // Alfabeto diferenciaAlfabeto(const Alfabeto &alf);
};

ostream &operator<<(ostream &os, const Alfabeto &x);

#endif