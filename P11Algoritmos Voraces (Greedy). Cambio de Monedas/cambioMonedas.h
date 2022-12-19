#include <iostream>
#include <vector>

using namespace std;

class CambioMonedas {
 private:
  int amount_;

  vector<int> candidates_;
  vector<int> result_;
  vector<int> amountArr_;

 public:
  CambioMonedas(float amount, int flag);

  // Setters
  inline void setAmountArr(const vector<int>& amount) { amountArr_ = amount; }
  inline void setResult(const vector<int>& result) { result_ = result; }
  inline void setCandidates(const vector<int>& candidates) {
    candidates_ = candidates;
  }

  // Getters
  inline const vector<int> getAmountArr(void) const { return amountArr_; }
  inline const vector<int> getResult(void) const { return result_; }
  inline const vector<int> getCandidates(void) const { return candidates_; }
  float getSuma(void) const;

  // Methods
  void PosibleCandidates(int flag);
  int CandidateSelector(int& amount, int& position, int& suma);
  int CandidateSelectorOptimized(int& newAmount, int& position);
};
// Sobrecarga

ostream& operator<<(ostream& os, const CambioMonedas& amount);
