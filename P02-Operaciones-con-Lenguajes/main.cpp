#include <cstring>
#include <fstream>
#include <iostream>
#include <string>

#include "alfabeto.h"
#include "cadena.h"
#include "lenguaje.h"
#include "simbolo.h"

using namespace std;

void build(const string line, Lenguaje &lang, Alfabeto &alf, Cadena &str);
ofstream &writeLenguaje(ofstream &out, const Lenguaje &value);

int main(int argc, char *argv[])
{
  if (argc > 4)
  {
    int n;
    int opcode = atoi(argv[4]);
    if (opcode == 6)
    {
      cout << "\nIntroduzca el valor de n: ";

      cin >> n;
    }

    ifstream file(argv[1]);
    if (!file.is_open())
    {
      cout << "Error al abrir prueba.txt\n";
      exit(EXIT_FAILURE);
    }
    string line;

    ifstream file2(argv[2]);
    if (!file2.is_open())
    {
      cout << "Error al abrir prueba2.txt\n";
      exit(EXIT_FAILURE);
    }

    ofstream out(argv[3]);

    while (getline(file, line, '\n'))
    {
      Alfabeto alf, alf2;
      Lenguaje lang, lang2;
      Cadena str, str2;

      build(line, lang, alf, str);
      out << "\nAlfabeto:" << alf << " Cadena:" << lang << endl;

      if (opcode < 5) // distinguimos operaciones binarias y unitarias
      {
        getline(file2, line, '\n');

        build(line, lang2, alf2, str2);
        out << "Alfabeto:" << alf2 << " Cadena:" << lang2 << endl;
      }

      switch (opcode)
      {
      case 1:
        out << "\nConcatenacion: ";
        writeLenguaje(out, lang.concatenacion(lang2));
        break;
      case 2:
        out << "\nUnion: ";
        writeLenguaje(out, lang.unioN(lang2));
        break;
      case 3:
        out << "\nInterseccion: ";
        writeLenguaje(out, lang.interseccion(lang2));
        break;
      case 4:
        out << "\nDiferencia: ";
        writeLenguaje(out, lang.diferencia(lang2));
        break;
      case 5:
        out << "\nInversa: ";
        writeLenguaje(out, lang.inversa());
        break;
      case 6:
        out << "\nPotencia: ";
        writeLenguaje(out, lang.potencia(n));
        break;

      default:
        cerr << "ERROR, opcion no valida\n";
        break;
      }
    }

    file.close();
    file2.close();
    out.close();
  }
  else
  {
    cerr << "ERROR, numero de argumentos incorrecto" << endl;
  }
}

void build(const string line, Lenguaje &lang, Alfabeto &alf, Cadena &str)
{

  Simbolo sim_aux;

  size_t last_alf =
      line.find_first_of('}'); // posicion de donde acaba el alfabeto
  size_t last_str =
      line.find_last_of('}'); // posicion donde empiza el lenguaje
  for (size_t i = 2; i < last_alf; i++)
  {
    if (line[i] != ' ')
    {
      sim_aux.addAnotherSimbolo(line[i]);
    }
    else
    {
      alf.addSimbolo(sim_aux); // Añadimos el simbolo al alfabeto
      sim_aux.clear();         // limpiamos el simbolo auxiliar
    }
  }
  lang.insertAlfabeto(alf);
  for (size_t i = line.find_last_of('{') + 2; i < last_str; i++)
  {
    if (line[i] != ' ')
    {
      sim_aux.setSimbolo(line[i]);
      str.setStringSimbolo(sim_aux);
    }
    else
    {
      lang.insertString(str);
      str.clear();
    }
  }
}

ofstream &writeLenguaje(ofstream &out, const Lenguaje &value)
{
  out << value << endl;
  return out;
}