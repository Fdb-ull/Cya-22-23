#ifndef AUTOMATA_H
#define AUTOMATA_H

#include <algorithm>
#include <fstream>
#include <iostream>
#include <unordered_set>
#include <vector>

#include "alfabeto.h"
#include "cadena.h"
#include "estado.h"
#include "grammar.h"
#include "simbolo.h"

const Simbolo EPSILON("&");

class Automata {
 private:
  Alfabeto alf_;                         // Alfabeto
  set<Estado> states_, acceptedStates_;  // Conjunto de estados
                                         // y estados de aceptacion
  Estado startState_;                    // Estado de inicio

  Grammar ConvertToGrammar(void);  // Convierte un DFA en una gramatica

 public:
  Automata(string intput, string output = "output.gra");
  Automata();

  void Build(string input, string output);  // construye el automata

  // Setters
  void SetState(Estado state);
  void setStartState(Estado startState);
  void setAcceptedState(Estado accepted);

  bool IsAccepted(
      Estado state) const;  // Comprueba si el estado es de aceptacion
  bool IsDfa(void) const;   // Comprueba si el automata es un DFA

  // Getters
  Estado GetState(int pos) const;

  inline Alfabeto GetAlfabeto(void) const { return alf_; }
  inline set<Estado> GetSetStates(void) const { return states_; }
  inline int GetNumStates(void) const { return states_.size(); }

  bool printToFile(Grammar print);  // Imprime en el fichero de salida la
                                    // gramatica resultante

  bool printToFileMod(Grammar print);
};

// Sobrecarga operador <<
ostream& operator<<(ostream& os, const Automata& x);

#endif