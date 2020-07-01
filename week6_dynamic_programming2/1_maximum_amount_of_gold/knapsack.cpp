#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#define ll long long

using std::vector;
using namespace std;


int optimal_weight(int W, vector<int> &w) {
  //write your code here
  int current_weight = 0;
  for (size_t i = 0; i < w.size(); ++i) {
    if (current_weight + w[i] <= W) {
      current_weight += w[i];
    }
  }
  return current_weight;

}

int myfunc(int W, vector<int> &w)
{
  ll i,j,n,wt;

  n = w.size();
  vector<int> v(n);

  for(i=0; i<n; i++)
  {
    v[i] = 0;
  }

  sort(w.begin(), w.end());

  for(i=n-1; i>=0; i--)
  {
    if(v[i] != 0)
    {
      continue;
    }
    j = i;
    wt = 0;
    while(j >= 0)
    {
      if(v[j] != 0)
      {
        j--;
        continue;
      }
      if(wt + w[j] <= W)
      {
        v[j] = wt + w[j];
        wt += w[j];
      }
      j--;
    }
  }

  sort(v.begin(), v.end());

  return v[n-1];
}

int myfunc2(int W, vector<int> &w)
{

  ll i,j,n,wt;

  n = w.size();
  vector<int> v(n);

  for(i=0; i<n; i++)
  {
    v[i] = 0;
  }

  sort(w.begin(), w.end());

  for(i=n-1; i>=0; i--)
  {
    j = i;
    wt = 0;
    while(j >= 0)
    {
      if(wt + w[j] <= W)
      {
        wt += w[j];
      }
      j--;
    }
    v[i] = wt;
  }

  sort(v.begin(), v.end());

  return v[n-1];
}

int knapsackrec(int W, vector<int> &w, int i, vector<vector<int>> &dp)
{
  if(i < 0)
  {
    return 0;
  }

  if(dp[i][W] != -1)
  {
    return dp[i][W];
  }

  if(w[i] > W)
  {
    dp[i][W] = knapsackrec(W, w, i-1, dp);
    return dp[i][W];
  }
  else
  {
    dp[i][W] = max( w[i]+knapsackrec(W-w[i], w, i-1, dp), knapsackrec(W, w, i-1, dp));
    return dp[i][W];
  }
}

int myfunc4(int W, vector<int> &w, int n)
{
  vector<vector<int>> dp(n, vector<int>(W+1));
  int i,j;

  for(i=0; i<n; i++)
  {
    for(j=0; j<=W; j++)
    {
      dp[i][j] = -1;
    }
  }

  return knapsackrec(W, w, n-1, dp);
}

int myfunc3(int W, vector<int> &w, int n)
{
  if(n == 0 || W == 0)
  {
    return 0;
  }

  if(w[n-1] > W)
    return myfunc3(W, w, n-1);
  else
    return max( w[n-1]+myfunc3(W-w[n-1], w, n-1), myfunc3(W, w, n-1));

}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }

  // std::cout << optimal_weight(W, w) << '\n';

  // std::cout << myfunc(W, w) << '\n';

  // std::cout << myfunc2(W, w) << '\n';

  // std::cout << myfunc3(W, w, n) << '\n';

  std::cout << myfunc4(W, w, n) << '\n';
}
