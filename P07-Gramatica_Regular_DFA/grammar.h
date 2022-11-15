#ifndef GRAMMAR_H
#define GRAMMAR_H

#include <fstream>
#include <iostream>
#include <set>

#include "alfabeto.h"
#include "cadena.h"
#include "production.h"
#include "simbolo.h"

using namespace std;

class Grammar {
 private:
  Alfabeto alf_;                   // Simbolos terminales
  set<Simbolo> noTerminalSimbol_;  // Conjunto no terminales
  Simbolo startSimbol_;            // Simbolo de inicio
  vector<Production> production_;  // Producciones

 public:
  Grammar(Alfabeto alf, Simbolo start);
  Grammar();

  // Setters
  void setAlph(Simbolo sim);
  void setNonTerminal(Simbolo sim);
  void setStartSimbol(Simbolo sim);
  void setProduction(vector<Cadena> str, Simbolo noTerminal);
  void addProductionStr(Cadena str, Simbolo noTerminal);

  // Imprimir en file
  bool printToFile(string& output);
  bool printToFileMod(string& output);
  int printToFileS(ofstream& output);

  // Metodo de busqueda
  int find(Simbolo noTerminal);

  // Getters
  Simbolo GetNoTerminalAt(int pos) const;

  inline Simbolo getStartSimbol(void) const { return startSimbol_; }
  inline Alfabeto getAlph(void) const { return alf_; }
  inline vector<Production> getProductions(void) const { return production_; }
  inline Production getProductionPos(int pos) const { return production_[pos]; }
  inline int getNoTerminalSize(void) const { return noTerminalSimbol_.size(); }
  inline int getProductionSize(void) const { return production_.size(); }
  inline int getProductionIdSize(Simbolo id);
};
// Sobrecarga
ostream& operator<<(ostream& os, const Grammar& g);

#endif