#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <bits/stdc++.h>

using std::vector;
using std::string;
using std::max;
using std::min;
using namespace std;

#define ll long long

long long eval(long long a, long long b, char op) {
  if (op == '*') {
    return a * b;
  } else if (op == '+') {
    return a + b;
  } else if (op == '-') {
    return a - b;
  } else {
    assert(0);
  }
}

long long get_maximum_value(const string &exp) {
  //write your code here
  
  int Len = exp.size();
  int NumOfOperands = (Len + 1) / 2;

  ll Mini[NumOfOperands][NumOfOperands];
  ll Maxi[NumOfOperands][NumOfOperands];

  memset(Mini, 0, sizeof(Mini)); 
  memset(Maxi, 0, sizeof(Maxi)); 
  for (int i = 0; i < NumOfOperands; i++) {

    Mini[i][i] = stoll(exp.substr(2 * i, 1));
    Maxi[i][i] = stoll(exp.substr(2 * i, 1));
  }

  for (int s = 0; s < NumOfOperands - 1; s++) {
    for (int i = 0; i < NumOfOperands - s - 1; i++) {
      int j = i + s + 1;
      ll MinValue = LLONG_MAX;
      ll MaxValue = LLONG_MIN;

      for (int k = i; k < j; k++) {
        ll a = eval(Mini[i][k], Mini[k + 1][j], exp[2 * k + 1]);
        ll b = eval(Mini[i][k], Maxi[k + 1][j], exp[2 * k + 1]);
        ll c = eval(Maxi[i][k], Mini[k + 1][j], exp[2 * k + 1]);
        ll d = eval(Maxi[i][k], Maxi[k + 1][j], exp[2 * k + 1]);

        MinValue = min(MinValue, min(a, min(b, min(c, d))));
        MaxValue = max(MaxValue, max(a, max(b, max(c, d))));

      }
      Mini[i][j] = MinValue;
      Maxi[i][j] = MaxValue;
    }
  }

  return Maxi[0][NumOfOperands - 1];
}

int main() {
  string s;
  std::cin >> s;
  std::cout << get_maximum_value(s) << '\n';
}
