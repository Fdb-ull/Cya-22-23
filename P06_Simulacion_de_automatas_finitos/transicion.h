#ifndef TRANSICION_H
#define TRANSICION_H

#include "simbolo.h"

class Transicion {
 private:
  Simbolo condition_;
  int stateTo_;

 public:
  Transicion(Simbolo cond, int to);
  ~Transicion();

  inline int GetNextState(void) const { return stateTo_; }
  inline Simbolo GetCondition(void) const { return condition_; }
  Transicion& operator=(const Transicion& y);
};

ostream& operator<<(ostream& os, const Transicion& x);

#endif