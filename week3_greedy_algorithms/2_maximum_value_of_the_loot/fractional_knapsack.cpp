#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using std::vector;
using namespace std;

double get_optimal_value(int capacity, vector<double> weights, vector<double> values) {
  double value = 0.0000;

  // write your code here
  int n = values.size();
  int valueperweight[2][n];

  std::vector<pair<double, double>> vec;

  int i,x;
  for(i=0; i<n; i++)
  {
    // valueperweight[0][i] = i;
    // valueperweight[1][i] = values[i] / weights[i];

    vec.push_back(make_pair((values[i]/weights[i]),i));
  }

  std::sort(std::begin(vec), std::end(vec), [](pair<double, double>& first, pair<double, double>& second)->bool { return first.first < second.first; });

  // for(i=0; i<n; i++)
  // {
  //   cout<<vec[i].first<<"  "<<vec[i].second<<"\n";
  // }

  int sack = 0;
  for(i=n-1; i>=0; i--)
  {
    if(sack >= capacity)
    {
      break;
    }
    x = vec[i].second;
    if(weights[x] <= (capacity - sack))
    {
      sack += weights[x];
      value += (double)values[x];
    }
    else if(sack < capacity)
    {
      value += ((values[x]/weights[x])) * (capacity-sack);
      sack = capacity;
    }       
  }
  
  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<double> values(n);
  vector<double> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  // std::cout.precision(10);
  std::cout << std::fixed;
  std::cout << std::setprecision(4) << optimal_value << std::endl;
  return 0;
}
