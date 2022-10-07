#include "lenguaje.h"

// alf_axu = " a b " value = " abb a bb "
Lenguaje::Lenguaje(Alfabeto& alf_aux, Cadena& value) {}
Lenguaje::Lenguaje(Alfabeto& alf_aux) : alf_(alf_aux) {
  /* Cadena cad_aux;
   Simbolo sim_aux;
   string aux = "{}";  // no se si esta del todo bien, comprobar
   sim_aux.addSimbolo(aux);
   cad_aux.setStringSimbolo(sim_aux);
   arr_.insert(cad_aux);*/
}
Lenguaje::Lenguaje() {}
Lenguaje::~Lenguaje() {}

Cadena Lenguaje::getStringPos(int pos) const {
  std::set<Cadena>::iterator it = arr_.begin();
  std::advance(it, pos);
  Cadena x = *it;

  return x;
}
set<Cadena> Lenguaje::getString() const { return arr_; }
Alfabeto Lenguaje::getAlfabeto() const { return alf_; }
void Lenguaje::insertString(Cadena str) { arr_.insert(str); }

ostream& operator<<(ostream& os, const Lenguaje& x) {
  os << "{ " << x.getAlfabeto() << "} ";

  for (size_t i = 0; i < x.getString().size(); i++) {
    os << x.getStringPos(i) << " ";
  }
  os << "}";
  return os;
}