#include "transicion.h"
Transicion::Transicion(Simbolo cond, int to) : condition_(cond), stateTo_(to) {}

Transicion& Transicion::operator=(const Transicion& y) {
  this->condition_ = y.GetCondition();
  this->stateTo_ = y.GetNextState();
  return *this;
}

ostream& operator<<(ostream& os, const Transicion& x) {
  os << "condition:" << x.GetCondition() << endl
     << "to:" << x.GetNextState() << endl;
  return os;
}