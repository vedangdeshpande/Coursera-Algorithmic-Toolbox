#include <algorithm>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#define ll long long

using std::vector;
using namespace std;

map<ll, ll> m;

// int get_majority_element(vector<int> &a, int left, int right) {
//   if (left == right) return -1;
//   if (left + 1 == right) return a[left];
//   //write your code here

// }

int get_majority_element(int n) {
  
  n = n/2;

  map<ll, ll>::iterator it;

  for(it=m.begin(); it!=m.end(); it++)
  {
    int x = it->second;
    if(x > n)
    {
      return 1;
    }
  }

  return 0;
}

int main() {
  int n, x;
  std::cin >> n;

  for(int i=0; i<n; i++)
  {
    cin >> x;
    m[x]++;
  }
  // vector<int> a(n);
  // for (size_t i = 0; i < a.size(); ++i) {
  //   std::cin >> a[i];
  // }
  // std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';

  std::cout << get_majority_element(n) << '\n';
}
