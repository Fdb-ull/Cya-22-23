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
// Archivo Languages.h
// Contiene las cabeceras de la clase lenguaje, encargada
// de dar forma al lenguaje y almacenar sus variables
//
// Referencias:
//
//
// Historial de revisiones
// 08/10/2022 - Creacion del primer codigo
#ifndef LENGUAJE_H
#define LENGUAJE_H

#include <iostream>
#include <set>

#include "alfabeto.h"
#include "cadena.h"
#include "simbolo.h"

// Lenguaje vacio = {}
// Lenguaje que contiene la cadena vacia = {&}

class Lenguaje {
 private:
  Alfabeto alf_;
  set<Cadena> arr_;

 public:
  Lenguaje(Alfabeto &alf_aux, Cadena &value);
  Lenguaje(Alfabeto &alf_aux);
  Lenguaje();
  ~Lenguaje();

  Alfabeto getAlfabeto() const;
  Alfabeto &setAlfabeto(void) { return alf_; }

  Cadena getStringPos(int pos) const;
  set<Cadena> getString() const;
  int getSize() const { return arr_.size(); }
  Cadena getCadenaVacia(void);

  void setLenguaje(const Lenguaje &lang);

  void insertString(Cadena str);

  void insertAlfabeto(Alfabeto alf);

  Lenguaje diferencia(const Lenguaje y);
  Lenguaje unioN(const Lenguaje y);
  Lenguaje interseccion(const Lenguaje y);

  Lenguaje concatenacion(const Lenguaje &y);
  Simbolo concatenar(const Cadena &x, const Cadena &y);

  Lenguaje inversa(void);
  Lenguaje potencia(const int n);

  bool checkCadena(Cadena &x) const;
  void generateAlfabeto(Lenguaje &value);
  void clear();

  Lenguaje &operator=(const Lenguaje &L2);
};

ostream &operator<<(ostream &os, const Lenguaje &x);

#endif