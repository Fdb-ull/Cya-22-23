#include "cambioMonedas.h"

CambioMonedas::CambioMonedas(float amount, int flag) {
  amount_ = 0.00f;
  PosibleCandidates(flag);
  amount = amount * 100;
  amount_ = (int)amount;  // Convert to cents
  int position = 0;
  int temp = amount;
  if (flag == 0)
    while (temp != 0) {
      int temp_ammount = CandidateSelectorOptimized(temp, position);
      if (temp_ammount != 0)
        result_.push_back(temp_ammount);
      else
        temp = 0;
    }
  else {
    int suma = 0;
    while (suma != temp) {
      int temp_sum = CandidateSelector(temp, position, suma);
      if (temp_sum != 0)
        result_.push_back(temp_sum);
      else
        suma = temp;
    }
  }
}
int CambioMonedas::CandidateSelector(int& amount, int& position, int& suma) {
  int candidate = 0, count = 0, i = position;
  while (i < candidates_.size()) {
    if (count > 0 && position != i) {
      i = candidates_.size();
    } else if (suma + candidates_[i] <= amount) {
      candidate = candidates_[i];
      suma += candidate;
      position = i;
      count++;
    } else
      i++;
  }
  amountArr_.push_back(count);
  return candidate;
}

float CambioMonedas::getSuma(void) const {
  float amount = 0;
  for (int i = 0; i < result_.size(); i++) {
    amount += result_[i] * 0.01 * amountArr_[i];
  }
  return amount;
}

void CambioMonedas::PosibleCandidates(int flag) {
  if (flag == 1) {
    int m[] = {50000, 20000, 10000, 5000, 2000, 1000, 500, 200,
               100,   50,    20,    10,   5,    2,    1};
    std::vector<int> v(m, m + sizeof(m) / sizeof(*m));
    setCandidates(v);
  } else {
    int m[] = {200, 100, 50, 20, 10, 5, 2, 1};
    std::vector<int> v(m, m + sizeof(m) / sizeof(*m));
    setCandidates(v);
  }
}

int CambioMonedas::CandidateSelectorOptimized(int& newAmount, int& position) {
  int divide = 0;
  int candidate = 0;
  for (int i = position; i < candidates_.size(); i++) {
    divide = newAmount / candidates_[i];
    if (divide > 0) {
      candidate = candidates_[i];
      newAmount -= candidate * divide;
      position = i + 1;
      amountArr_.push_back(divide);
      return candidate;
    }
  }
  return candidate;
}

ostream& operator<<(ostream& os, const CambioMonedas& amount) {
  vector<int> result = amount.getResult();
  vector<int> amountArr = amount.getAmountArr();

  int billetes = 0, monedas = 0;
  cout << "\nMonedas: " << amount.getSuma() << "€" << endl;
  cout << "Solucion: {";
  for (int i = 0; i < result.size() - 1; i++) {
    if (result[i] >= 100) {
      cout << amountArr[i] << "x" << (result[i] * 0.01) << "€, ";
      billetes += amountArr[i];
    } else {
      cout << amountArr[i] << "x" << (result[i]) << "¢, ";
      monedas += amountArr[i];
    }
  }

  // por estetica comprobamos la ultima cantidad fuera del bucle
  if (result[result.size() - 1] >= 100) {
    cout << amountArr[result.size() - 1] << "x"
         << (result[result.size() - 1] * 0.01) << "€";
    billetes += amountArr[result.size() - 1];
  } else {
    cout << amountArr[result.size() - 1] << "x" << (result[result.size() - 1])
         << "¢";
    monedas += amountArr[result.size() - 1];
  }
  cout << "}" << endl;
  if (amount.getCandidates().size() > 8)
    cout << "Total biletes o monedas: ";
  else
    cout << "Total monedas: ";

  cout << billetes + monedas << endl;
  return os;
}