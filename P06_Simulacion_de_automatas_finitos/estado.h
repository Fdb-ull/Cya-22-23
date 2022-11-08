#ifndef ESTADO_H
#define ESTADO_H

#include <iostream>
#include <vector>

#include "simbolo.h"
#include "transicion.h"

class Estado {
 private:
  // identificador
  int id_;
  // transciciones
  vector<Transicion> transitions_;
  // numero de transiciones
  int sz_;
  // estado de aceptacion
  bool acceptedStateFlag_;

 public:
  Estado(int id, bool stateFlag, int sz);
  Estado();
  ~Estado();

  void SetTransition(Simbolo sim, int toId);

  inline int GetId(void) const { return id_; }
  inline int GetTransitionsSize(void) const { return sz_; }
  inline vector<Transicion> GetTransitions(void) const { return transitions_; }
  int GetSameTransitionsSimSize(Simbolo sim) const;
  int GetSameTransitionNext(int next) const;

  inline bool IsAccepted(void) const { return acceptedStateFlag_; }
  Estado& operator=(const Estado& y);
  bool operator==(const Estado& y) const;
};

ostream& operator<<(ostream& os, const Estado& x);
bool operator<(const Estado& x, const Estado& y);

#endif