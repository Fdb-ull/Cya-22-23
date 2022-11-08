#include "automata.h"

Automata::Automata(Alfabeto alf, int start) : alf_(alf), startState_(start) {}
Automata::~Automata() {}

void Automata::SetState(Estado state) { states_.insert(state); }

Estado Automata::GetState(int pos) const {
  std::set<Estado>::iterator it = states_.begin();
  std::advance(it, pos);
  Estado x = *it;

  return x;
}
void Automata::RemoveState(int pos) {
  vector<Estado>::iterator it = currentState_.begin();
  advance(it, pos);
  currentState_.erase(it);
}
bool Automata::IsAnyAccepted(vector<Estado> states) const {
  for (auto state : states) {
    if (state.IsAccepted()) return true;
  }

  return false;
}

Estado Automata::Find(int id) {
  set<Estado>::iterator it;

  for (auto state : states_) {
    if (state.GetId() == id) return state;
  }
}

bool Automata::TestString(Cadena str) {
  for (auto state : states_) {
    if (state.GetId() == startState_) {
      currentState_.push_back(state);
    }
  }

  for (size_t i = 0; i < str.getSize(); i++) {
    CheckSimbol(str.getStringSimbolo(i));
  }

  vector<Estado> aux = currentState_;
  currentState_.clear();
  return IsAnyAccepted(aux);
}

// Realiza la transicion
void Automata::CheckSimbol(Simbolo sim) {
  // Eliminamos los estados que no transitan

  for (size_t k = 0; k < currentState_.size(); k++) {
    if (currentState_[k].GetTransitionsSize() < 1) {
      RemoveState(k);
    }
  }

  Estado aux_state;
  int count, i = 0, sz = currentState_.size();

  while (i < sz) {
    count = 0;
    for (auto aux_transt : currentState_[i].GetTransitions()) {
      if (sim == aux_transt.GetCondition() ||
          aux_transt.GetCondition() == EPSILON) {
        // Comprobar si el estado tiene e-transiciones
        if (aux_transt.GetCondition() == EPSILON) {
          if (currentState_[i].GetSameTransitionNext(
                  aux_transt.GetNextState()) == 1) {
            count++;
            if (count > 1) {
              currentState_.push_back(Find(aux_transt.GetNextState()));
            } else {
              currentState_[i] = Find(aux_transt.GetNextState());
            }
          }
        }

        if (currentState_[i].GetSameTransitionsSimSize(sim) > 1) {
          // Comprueba si ya se realizo la primera transicion
          count++;
          if (count > 1) {
            currentState_.push_back(Find(aux_transt.GetNextState()));
          } else {
            currentState_[i] = Find(aux_transt.GetNextState());
          }

        } else {
          currentState_[i] = Find(aux_transt.GetNextState());
        }
      }
    }
    // Comprobamos que el simbolo sea igual a la condicio

    i++;
  }
}

ostream& operator<<(ostream& os, const Automata& x) {
  for (size_t i = 0; i < x.GetNumStates(); i++) {
    os << x.GetState(i) << endl;
  }
  return os;
}