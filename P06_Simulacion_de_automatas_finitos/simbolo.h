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
// Archivo simbolo.h:
// Contiene las cabeceras de la clase Simbolo, se encarga
// de alamcenar y gestionar operaciones con Simbolos
//
// Referencias:
//
//
// Historial de revisiones
// 08/10/2022 - Creacion del primer codigo
#ifndef SIMBOLO_H
#define SIMBOLO_H

#include <iostream>
#include <string>

using namespace std;

class Simbolo {
 private:
  string value_;

 public:
  Simbolo(const string &value = "");
  ~Simbolo();

  string getSimbolo() const;
  char getSimboloAt(int pos) const;
  int getSize() const;

  void addSimbolo(string sim);
  void addSimbolo(char sim);
  void setSimbolo(Simbolo sim);
  void addAnotherSimbolo(char sim);
  void replaceSimbolo(string value);

  ostream &writeSimbolo(ostream &os);
  void clear();

  Simbolo &operator=(const Simbolo &x);
  Simbolo &operator+(const Simbolo &x);
};

ostream &operator<<(ostream &os, const Simbolo &x);
bool operator==(const Simbolo &x, const Simbolo &y);
bool operator!=(const Simbolo &x, const Simbolo &y);
bool operator<(const Simbolo &x, const Simbolo &y);
Simbolo toSimbol(string value);

#endif