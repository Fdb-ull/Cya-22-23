#include "production.h"

Production::Production(Simbolo noTerminal) : noTerminal_(noTerminal) {}
Production::Production() {}

Production& Production::operator=(const Production& y) {
  this->noTerminal_ = y.noTerminal_;
  this->productionTo_ = y.productionTo_;
  return *this;
}

ostream& operator<<(ostream& os, const Production& g) {
  os << g.getProductionTo();
  return os;
}