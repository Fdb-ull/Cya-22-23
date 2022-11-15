#ifndef ESTADO_H
#define ESTADO_H

#include <iostream>
#include <vector>

#include "simbolo.h"
#include "transicion.h"

class Estado {
 private:
  int id_;                          // identificador
  int sz_;                          // numero de transiciones
  vector<Transicion> transitions_;  // transciciones

 public:
  Estado(int id, int sz);
  Estado();

  void SetTransition(Simbolo sim, int toId);

  inline int GetId(void) const { return id_; }
  inline int GetTransitionsSize(void) const { return sz_; }
  inline vector<Transicion> GetTransitions(void) const { return transitions_; }

  int GetSameTransitionsSimSize(Simbolo sim) const;
  int GetSameTransitionNext(int next) const;

  inline Transicion GetTransitionAt(int pos) const { return transitions_[pos]; }
  Estado& operator=(const Estado& y);
  bool operator==(const Estado& y) const;
};

ostream& operator<<(ostream& os, const Estado& x);
bool operator<(const Estado& x, const Estado& y);

#endif