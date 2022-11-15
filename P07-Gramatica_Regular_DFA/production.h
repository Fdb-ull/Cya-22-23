#ifndef PRODUCTION_H
#define PRODUCTION_H

#include <iostream>
#include <vector>

#include "cadena.h"
#include "simbolo.h"

using namespace std;

class Production {
 private:
  Simbolo noTerminal_;   // Simbolo que realiza la produccion
  Cadena productionTo_;  // resultado de la produccion

 public:
  Production(Simbolo noTerminal);
  Production();

  // Getters
  inline Simbolo getNoTerminal(void) const { return noTerminal_; }
  inline Cadena getProductionTo(void) const { return productionTo_; }

  // Setters
  inline void setNoTerminal(Simbolo noTerminal) { noTerminal_ = noTerminal; }
  inline void addProduction(Cadena str) { productionTo_.setString(str); }

  // Sobrecarga
  Production& operator=(const Production& y);
};
ostream& operator<<(ostream& os, const Production& g);

#endif