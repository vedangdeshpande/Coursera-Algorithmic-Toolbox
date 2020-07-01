#include <iostream>

int get_change(int m) {
  //write your code here
	int ch = 0;
	if(m >= 10)
	{
		ch += m/10;
		m = m%10;
	}
	if(m >= 5)
	{
		ch += m/5;
		m %= 5;
	}

	ch += m;

  return ch;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
