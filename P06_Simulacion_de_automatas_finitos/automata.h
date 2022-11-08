#ifndef AUTOMATA_H
#define AUTOMATA_H

#include <iostream>

#include "alfabeto.h"
#include "cadena.h"
#include "estado.h"
#include "simbolo.h"

const Simbolo EPSILON("&");

class Automata {
 private:
  Alfabeto alf_;
  set<Estado> states_;
  vector<Estado> currentState_;
  int startState_;

 public:
  Automata(Alfabeto alf, int start);
  ~Automata();

  Estado GetState(int pos) const;
  void SetState(Estado state);

  bool TestString(Cadena str);

  void CheckSimbol(Simbolo sim);
  Estado Find(int id);

  bool IsAnyAccepted(vector<Estado> states) const;
  void RemoveState(int pos);

  inline set<Estado> GetSetStates(void) const { return states_; }
  inline int GetNumStates(void) const { return states_.size(); }
};

ostream& operator<<(ostream& os, const Automata& x);

#endif