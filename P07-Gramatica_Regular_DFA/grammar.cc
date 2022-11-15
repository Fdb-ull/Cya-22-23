#include "grammar.h"

Grammar::Grammar(Alfabeto alf, Simbolo start)
    : alf_(alf), startSimbol_(start) {}
Grammar::Grammar() {}

// Metodo de busqueda
int Grammar::find(Simbolo noTerminal) {
  for (size_t i = 0; i < getNoTerminalSize(); i++) {
    if (GetNoTerminalAt(i) == noTerminal) {
      return i;
    }
  }
}

Simbolo Grammar::GetNoTerminalAt(int pos) const {
  set<Simbolo>::iterator it = noTerminalSimbol_.begin();
  advance(it, pos);
  return *it;
}

void Grammar::setAlph(Simbolo sim) { alf_.setSimbolo(sim); }

void Grammar::setNonTerminal(Simbolo sim) { noTerminalSimbol_.insert(sim); }

void Grammar::setStartSimbol(Simbolo sim) { startSimbol_.setSimbolo(sim); }

void Grammar::setProduction(vector<Cadena> str, Simbolo noTerminal) {
  Production aux_production;
  aux_production.setNoTerminal(noTerminal);
  for (size_t i = 0; i < str.size(); i++) {
    aux_production.addProduction(str[i]);
    production_.push_back(aux_production);
  }
}

inline int Grammar::getProductionIdSize(Simbolo id) {
  int count = 0;
  for (size_t i = 0; i < production_.size(); i++) {
    if (production_[i].getNoTerminal() == id) {
      count++;
    }
  }
  return count;
}

void Grammar::addProductionStr(Cadena str, Simbolo noTerminal) {
  Production x;
  x.setNoTerminal(noTerminal);
  x.addProduction(str);
  production_.push_back(x);
}

bool Grammar::printToFile(string& output) {
  ofstream file(output);
  if (!file.is_open()) {
    cerr << "Error, no se pudo abrir el archivo:" << output << endl;
    exit(EXIT_FAILURE);
    return false;
  }

  file << getAlph().getSize() << endl;
  for (size_t i = 0; i < getAlph().getSize(); i++) {
    file << getAlph().getSimbolo(i) << endl;
  }
  file << getNoTerminalSize() << endl;

  file << getStartSimbol() << endl;
  if (getNoTerminalSize() > 18)
    for (size_t i = 0; i < getNoTerminalSize(); i++) {
      if (i != 18) file << GetNoTerminalAt(i) << endl;
    }
  else
    for (size_t i = 0; i < getNoTerminalSize() - 1; i++) {
      file << GetNoTerminalAt(i) << endl;
    }

  file << getStartSimbol() << endl << getProductionSize() << endl;

  int sPosition = printToFileS(file);
  for (size_t i = 0; i < getNoTerminalSize() - 1; i++) {
    if (i != sPosition) {
      file << GetNoTerminalAt(i) << " -> ";
      for (size_t j = 0; j < getProductionSize(); j++) {
        if (getProductionPos(j).getNoTerminal() == GetNoTerminalAt(i))
          file << getProductionPos(j);
      }
      if (getProductionIdSize(GetNoTerminalAt(i)) == 0) file << "&";
      file << endl;
    }
  }
  return true;
}

bool Grammar::printToFileMod(string& output) {
  ofstream file(output);
  if (!file.is_open()) {
    cerr << "Error, no se pudo abrir el archivo:" << output << endl;
    exit(EXIT_FAILURE);
    return false;
  }

  file << "Alfabeto = " << getAlph() << endl;

  file << "V = { " << getStartSimbol() << ", ";
  if (getNoTerminalSize() > 18)
    for (size_t i = 0; i < getNoTerminalSize(); i++) {
      if (i != 18) file << GetNoTerminalAt(i) << ", ";
    }
  else
    for (size_t i = 0; i < getNoTerminalSize() - 1; i++) {
      file << GetNoTerminalAt(i) << ", ";
    }
  file << "}" << endl;

  file << "Simbolo de Arranque: " << getStartSimbol() << endl;
  file << "Producciones: " << endl;

  int sPosition = printToFileS(file);
  for (size_t i = 0; i < getNoTerminalSize() - 1; i++) {
    if (i != sPosition) {
      file << GetNoTerminalAt(i) << " -> ";
      for (size_t j = 0; j < getProductionSize(); j++) {
        if (getProductionPos(j).getNoTerminal() == GetNoTerminalAt(i))
          file << getProductionPos(j);
      }
      if (getProductionIdSize(GetNoTerminalAt(i)) == 0) file << "&";
      file << endl;
    }
  }
  return true;
}

int Grammar::printToFileS(ofstream& file) {
  // print first noTerminal = S
  Simbolo aux;
  aux.addAnotherSimbolo('S');
  file << GetNoTerminalAt(find(aux)) << " -> ";

  for (size_t i = 0; i < getProductionSize(); i++) {
    if (getProductionPos(i).getNoTerminal() == GetNoTerminalAt(find(aux)))
      file << getProductionPos(i);
  }
  file << endl;
  return find(aux);
}

// NUMERO ASCCI A = 65
// MOSTRAR CADA ID DEL ESTADO COMO UN SIMBOLO DE ALFABETO A-Z
ostream& operator<<(ostream& os, const Grammar& g) {
  os << g.getAlph().getSize() << endl;
  for (size_t i = 0; i < g.getAlph().getSize(); i++) {
    os << g.getAlph().getSimbolo(i) << endl;
  }
  os << g.getNoTerminalSize() << endl;

  for (size_t i = 0; i < g.getNoTerminalSize(); i++) {
    os << g.GetNoTerminalAt(i) << endl;
  }

  os << g.getStartSimbol() << endl << g.getProductionSize() << endl;

  for (size_t i = 0; i < g.getNoTerminalSize(); i++) {
    os << g.GetNoTerminalAt(i) << " -> ";
    os << g.getProductionPos(i);
    os << endl;
  }
  return os;
}