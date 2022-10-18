// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 2: Operaciones con lenguajes
// Autor: Franco Dendi Bele
// Correo: alu0101134703@ull.edu.es
// Fecha: 10/10/2022
//
// Archivo cya-P02-main.cc: programa cliente.
// Contiene la Funcion main que se encarga de gestionar
// los ficheros de entrada y salida, ademas de identificar los alfabetos
// y conjuntos de cadenas mediante un metodo auxiliar
//
// Referencias:
//
//
// Historial de revisiones
// 08/10/2022 - Creacion del primer codigo

#include <cstring>
#include <fstream>
#include <iostream>
#include <stack>
#include <string>

#include "alfabeto.h"
#include "cadena.h"
#include "lenguaje.h"
#include "simbolo.h"

using namespace std;

pair<Lenguaje, string> BuildLang(const string line);
Lenguaje OperationRpn(const string line,
                      const vector<pair<Lenguaje, string>> lang_r);

ofstream &writeLenguaje(ofstream &out, const Lenguaje &value);

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    cerr << "ERROR, numero de argumentos incorrecto" << endl;
    exit(EXIT_FAILURE);
  }
  ifstream file("prueba.txt");

  if (!file.is_open())
  {
    cerr << "Error, no se ha podido abrir el archivo" << endl;
    return 1;
  }

  string line;
  vector<pair<Lenguaje, string>>
      arr_lang;    // contiene los lenguajes a operar e identificadores
  Lenguaje lang_r; // Lenguaje resultante de las operaciones

  int i = 0;
  while (getline(file, line, '\n'))
  {
    if (line[3] == '=')
    {
      arr_lang.push_back(BuildLang(line));
      cout << "Alfabeto: " << arr_lang[i].first.getAlfabeto()
           << arr_lang[i].second << " = " << arr_lang[i].first << endl;
    }
    else
    {
      lang_r = OperationRpn(line, arr_lang);
      cout << "Alfabeto: " << lang_r.getAlfabeto() << "result: " << lang_r
           << endl;
    }

    i++;
  }
}

// Works =)
pair<Lenguaje, string> BuildLang(const string line)
{
  size_t start_lang =
      line.find_first_of('{'); // posicion donde empieza el lenguaje
  size_t end_lang =
      line.find_last_of('}'); // posicion donde termina el lenguaje

  pair<Lenguaje, string> lang;
  Lenguaje lang_aux;
  Alfabeto alf_aux;
  Cadena str_aux;
  Simbolo sim_aux, sim_aux2;

  int i = 0;

  while (line[i] != ' ')
  {
    lang.second.push_back(line[i]);
    i++;
  }
  for (size_t i = start_lang + 1; i < end_lang; i++)
  {
    if (line[i] != ' ' && line[i] != ',')
    {
      sim_aux.addAnotherSimbolo(line[i]);
      if (line[i] != '&')
      {
        sim_aux2.addAnotherSimbolo(line[i]);
        alf_aux.addSimbolo(sim_aux2);
      }
      sim_aux2.clear();
    }
    else
    {
      if (line[i] != ',')
      {
        str_aux.setStringSimbolo(sim_aux);
        lang.first.insertString(str_aux);
        str_aux.clear();
        sim_aux.clear();
      }
    }
  }
  // introducimos el ultimo elemento

  str_aux.setStringSimbolo(sim_aux);
  lang.first.insertString(str_aux);
  lang.first.insertAlfabeto(alf_aux);

  return lang;
}

Lenguaje OperationRpn(const string line,
                      const vector<pair<Lenguaje, string>> lang_r)

{ // Guardamos la operacion dentro de la pila
  vector<string> arrstr_;
  string id;
  Lenguaje aux;

  for (auto i : line)
  { // check line length some caracter not saving well
    if (i != ' ' && i != '\n' && i != '\r')
    {
      // comprobamos que es un elemento identificador u operador
      id.push_back(i);
    }
    else
    {
      if (i != '\n' && i != '\r')
      {
        arrstr_.push_back(id);
        id.clear();
      }
    }
  }
  arrstr_.push_back(id);

  stack<Lenguaje> stacklang_;
  // stack contiene una expresion postfija
  int count = 0;
  int n = 0;
  while (arrstr_.size() > count)
  {
    string str = arrstr_[count]; // leemos el primer elemento

    if (str.size() > 1)
    { // comprobamos si es un operando
      for (size_t i = 0; i < lang_r.size(); i++)
      { // Lo asignamos a la pila
        if (arrstr_[count] == lang_r[i].second)
          stacklang_.push(lang_r[i].first);
      }
    }
    else
    {
      if (str[0] != '!' && str[0] != '*' && str[0] != '-' && str[0] != '+' &&
          str[0] != '|' && str[0] != '^')
      {
        char st = (char)str[0];
        n = atoi(&st);
      }
      else if (str[0] != '!' &&
               str[0] != '*')
      {                            // si el operador tomas n operandos
        if (stacklang_.size() < 2) // comprobamos que hayan 2 operandos
        {
          cerr << "Error, operandos insuficientes en la expresion" << endl;
          cout << stacklang_.top() << endl;
        }
        else
        {
          aux = stacklang_.top(); // tomamos el primer operando
          stacklang_.pop();       // posicionamos la pila en el segundo operando
          Lenguaje x;
          switch (str[0])
          { // realizamos la operacion
          case '+':
            aux = aux.concatenacion(stacklang_.top());
            stacklang_.pop();
            stacklang_.push(aux);
            aux.clear();
            break;
          case '-':
            aux = aux.diferencia(stacklang_.top());
            stacklang_.pop();
            stacklang_.push(aux);
            aux.clear();
            break;
          case '^':
            aux = aux.interseccion(stacklang_.top());
            stacklang_.pop();
            stacklang_.push(aux);
            aux.clear();
            break;
          case '|':
            aux = aux.unioN(stacklang_.top());
            stacklang_.pop();
            stacklang_.push(aux);
            aux.clear();
            break;
          default:
            break;
          }
        }
      }
      else
      {
        switch (str[0])
        {
        case '*':
          aux = stacklang_.top().potencia(n);
          stacklang_.pop();
          stacklang_.push(aux);
          aux.clear();
          break;

        case '!':
          aux = stacklang_.top().inversa();
          stacklang_.pop();
          stacklang_.push(aux);
          aux.clear();
          break;
        default:
          break;
        }
      }
    }
    count++;
  }

  if (stacklang_.size() != 1)
  {
    cerr << "Error, hay mas/menos de un elemento en la pila" << endl;
    exit(EXIT_FAILURE);
  }

  return stacklang_.top();
}

ofstream &writeLenguaje(ofstream &out, const Lenguaje &value)
{
  out << value << endl;
  return out;
}
