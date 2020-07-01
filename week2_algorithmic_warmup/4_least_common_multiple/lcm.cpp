#include <iostream>
#define ll long long

int gcd_naive(ll a, ll b) {
  // int current_gcd = 1;
  // for (int d = 2; d <= a && d <= b; d++) {
  //   if (a % d == 0 && b % d == 0) {
  //     if (d > current_gcd) {
  //       current_gcd = d;
  //     }
  //   }
  // }
  // return current_gcd;

  if(a == 0)
    return b;
  if(b == 0)
    return a;

  if(a > b)
  {
    return gcd_naive(a%b, b);
  }

  return gcd_naive(b%a, a);
}

long long lcm_naive(ll a, ll b) {
  // for (long l = 1; l <= (long long) a * b; ++l)
  //   if (l % a == 0 && l % b == 0)
  //     return l;

  // return (long long) a * b;

	return (a*b)/gcd_naive(a,b);
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << lcm_naive(a, b) << std::endl;
  return 0;
}
