// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 2: Operaciones con lenguajes
// Autor: Franco Dendi Bele
// Correo: alu0101134703@ull.edu.es
// Fecha: 19/12/2022
//
// Archivo cambioMonedas.h cabeceras de clase.
// Contiene la clase CambioMonedas, que realiza el cambio de monedas
//
//
// Referencias:
//
//
// Historial de revisiones

#include <iostream>
#include <vector>

using namespace std;

class CambioMonedas {
 private:
  int amount_;  // Cantidad a cambiar

  vector<int> candidates_;  // Monedas o billetes disponibles
  vector<int> result_;      // Resultados hasta llegar a la cantidad indicada
  vector<int> amountArr_;   // Cantidad de monedas o billetes de cada tipo

 public:
  CambioMonedas(float amount, int flag);  // Constructor de clase

  // Setters
  // modifica la cantidad de monedas o billetes
  inline void setAmountArr(const vector<int>& amount) { amountArr_ = amount; }
  // modifica los resultados tras las operaciones
  inline void setResult(const vector<int>& result) { result_ = result; }
  // modifica los tipos de moneda o billetes
  inline void setCandidates(const vector<int>& candidates) {
    candidates_ = candidates;
  }

  // Getters
  // devuelve la cantidad de monedas o billetes
  inline const vector<int> getAmountArr(void) const { return amountArr_; }
  // devuelve los resultados tras las operaciones
  inline const vector<int> getResult(void) const { return result_; }
  // devuelve los tipos de moneda o billetes
  inline const vector<int> getCandidates(void) const { return candidates_; }
  // devuelve la suma de todos los tipos de moneda o billetes seleccionados para
  // el cambio
  float getSuma(void) const;

  // Methods
  // Asigna los tipos de moneda o billete disponibles para realizar el cambio
  void PosibleCandidates(int flag);
  // Metodo Greddy selecciona las monedas o billetes
  int CandidateSelector(int& amount, int& position, int& suma);
  // Metodo Greddy mas optimo que selecciona las monedas o billetes
  int CandidateSelectorOptimized(int& newAmount, int& position);
};

// Sobrecarga
ostream& operator<<(ostream& os,
                    const CambioMonedas& amount);  // sobrecarga del operado de
                                                   // insercionde flujo