#include "automata.h"

Automata::Automata(string input, string output) { Build(input, output); }

Automata::Automata() {}

void Automata::Build(string input, string output) {
  ifstream file(input);
  if (!file.is_open()) {
    cerr << "Error, no se pudo abrir el archivo:" << input << endl;
    exit(EXIT_FAILURE);
  }

  Alfabeto alf;
  string line;
  // leemos la primera linea que contiene el alfabeto
  getline(file, line, '\n');
  // eliminamos los espacios en blanco
  line.erase(remove_if(line.begin(), line.end(), ::isspace), line.end());

  for (int i = 0; i < line.length(); i++) {
    Simbolo sim;
    sim.addSimbolo(line[i]);
    alf.addSimbolo(sim);
  }
  alf_ = alf;
  // Leemos el numero total de estados
  getline(file, line, '\n');
  int nStates = stoi(line);
  // Leemos cual es el estado inicial
  getline(file, line, '\n');
  int ini_state = stoi(line);

  int count = 0;
  // Leemos los estados correspondientes y los introducimos en el automata

  while (nStates > count) {
    getline(file, line, '\n');
    vector<string> id;
    string auxStr;

    string::iterator it = line.begin();
    while (it != line.end()) {
      if (*it != ' ') {
        auxStr.push_back(*it);
      } else {
        id.push_back(auxStr);
        auxStr.clear();
      }
      it++;
    }
    id.push_back(auxStr);

    Estado state(stoi(id[0]), stoi(id[2]));  // inicializamos identificador y
                                             // numero de transiciones
    if (stoi(id[1]) == 1)
      setAcceptedState(state);  // asignamos si se trata de
                                // un estado de aceptacion

    for (size_t i = 3; i < id.size(); i = i + 2) {
      Simbolo sim;
      for (size_t j = 0; j < id[i].size(); j++) {
        sim.addAnotherSimbolo(id[i][j]);  // Asignamos la condicion
      }
      state.SetTransition(sim,
                          stoi(id[i + 1]));  // asignamos hacia donde transita
    }

    if (state.GetId() == ini_state)
      setStartState(state);  // Comprueba si es el estado incial
    SetState(state);         // Guarda en el conjunto el estado actual
    count++;
  }

  file.close();

  // Comprubea si es un DFA
  if (!IsDfa()) {
    cerr << "ERROR, no es posible convertir un nfa" << endl;
    exit(EXIT_FAILURE);
  }

  Grammar regularGrammar;
  regularGrammar = ConvertToGrammar();  // Convierte el Dfa en Gramatica

  // Imprime la gramatica
  if (!regularGrammar.printToFile(output))
    cout << "El fichero NO se ha escrito correctamente, intentelo de nuevo.\n";
  else
    cout << "El fichero se a escrito correctamente.\n";
}

Grammar Automata::ConvertToGrammar(void) {
  Simbolo grammarId;
  string f;

  f += char(83);
  grammarId.addAnotherSimbolo(f[0]);

  Grammar regularGrammar(
      alf_, grammarId);  // Asignamos el primer no terminal junto al alfabeto
  grammarId.clear();

  for (size_t i = 0; i < GetNumStates(); i++) {
    string f;

    // Asigna el no terminal
    if (i == 0)
      f += char(i + 83);
    else
      f += char(i + 64);

    grammarId.addAnotherSimbolo(f[0]);
    regularGrammar.setNonTerminal(grammarId);

    Cadena auxStr;
    // Convierte las transiciones

    for (size_t j = 0; j < GetState(i).GetTransitionsSize(); j++) {
      Simbolo auxSim;
      string f;
      auxSim.setSimbolo(GetState(i)
                            .GetTransitionAt(j)
                            .GetCondition());  // Asignamos el terminal

      // Asignamos el no terminal dependiendo si es el primero o no
      if (i == 0 &&
          GetState(i).GetTransitionAt(j).GetNextState() == GetState(i).GetId())
        f += char(GetState(i).GetTransitionAt(j).GetNextState() + 83);
      else
        f += char(GetState(i).GetTransitionAt(j).GetNextState() + 64);

      auxSim.addAnotherSimbolo(f[0]);
      auxStr.setStringSimbolo(auxSim);

      // Añade la nueva produccion a al gramtica
      regularGrammar.addProductionStr(auxStr, grammarId);

      auxStr.clear();
    }
    // Comprueba si el estado es de aceptacion
    if (IsAccepted(GetState(i))) {
      auxStr.setStringSimbolo(EPSILON);  // Asigna epsilon como aceptacion
      regularGrammar.addProductionStr(auxStr,
                                      grammarId);  // Añade la produccion
      auxStr.clear();
    }

    grammarId.clear();
  }

  return regularGrammar;
}

void Automata::SetState(Estado state) { states_.insert(state); }

void Automata::setStartState(Estado startState) { startState_ = startState; }

void Automata::setAcceptedState(Estado accepted) {
  acceptedStates_.insert(accepted);
}

Estado Automata::GetState(int pos) const {
  std::set<Estado>::iterator it = states_.begin();
  std::advance(it, pos);
  Estado x = *it;

  return x;
}

bool Automata::IsAccepted(Estado state) const {
  for (auto accepted : acceptedStates_)
    if (state == accepted) return true;

  return false;
}

bool Automata::IsDfa(void) const {
  if (acceptedStates_.size() < 1) return false;

  for (size_t i = 0; i < GetNumStates(); i++)
    if (GetState(i).GetTransitionsSize() != GetAlfabeto().getSize())
      return false;
  return true;
}

ostream& operator<<(ostream& os, const Automata& x) {
  for (size_t i = 0; i < x.GetNumStates(); i++) {
    os << x.GetState(i) << endl;
  }
  return os;
}