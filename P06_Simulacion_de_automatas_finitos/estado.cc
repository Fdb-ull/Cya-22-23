#include "estado.h"

Estado::Estado(int id, bool stateFlag, int sz)
    : id_(id), sz_(sz), acceptedStateFlag_(stateFlag) {}
Estado::Estado() {}

Estado::~Estado() {}

void Estado::SetTransition(Simbolo sim, int toId) {
  Transicion aux(sim, toId);
  transitions_.push_back(aux);
}

int Estado::GetSameTransitionsSimSize(Simbolo sim) const {
  int count = 0;
  for (size_t i = 0; i < GetTransitionsSize(); i++) {
    if (sim == GetTransitions()[i].GetCondition()) count++;
  }
  return count;
}

int Estado::GetSameTransitionNext(int next) const {
  int count = 0;
  for (size_t i = 0; i < GetTransitionsSize(); i++) {
    if (next == GetTransitions()[i].GetNextState() && next != GetId()) {
      count++;
    }
  }
  return count;
}
ostream& operator<<(ostream& os, const Estado& x) {
  os << "Estado: " << x.GetId() << endl;
  if (x.IsAccepted()) os << "Es un estado de aceptacion." << endl;
  os << "numero de transiciones:" << x.GetTransitionsSize() << endl << endl;
  for (size_t i = 0; i < x.GetTransitionsSize(); i++) {
    os << "from:" << x.GetId() << endl << x.GetTransitions()[i] << endl;
  }
  return os;
}

Estado& Estado::operator=(const Estado& y) {
  this->id_ = y.GetId();
  this->transitions_ = y.GetTransitions();
  this->sz_ = y.GetTransitionsSize();
  this->acceptedStateFlag_ = y.IsAccepted();

  return *this;
}
bool Estado::operator==(const Estado& y) const {
  return this->GetId() == y.GetId();
}

bool operator<(const Estado& x, const Estado& y) {
  return x.GetId() < y.GetId();
}