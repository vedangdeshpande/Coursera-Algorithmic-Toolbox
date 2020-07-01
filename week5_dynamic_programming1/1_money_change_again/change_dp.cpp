#include <iostream>

int get_change(int m) {
  //write your code here
  
  int n,x,money;
  n = x = 0;
  money = m;

  if(money >= 4)
  {
  	if(money % 4 == 0)
  	{
  		return money/4;
  	}
  	x = money % 4;

	if(x == 2)
	{
		n = (money / 4) - 1;
		money = (money % 4) + 4;

		return n+2;
	}
	else
	{
		n = (money / 4);
		money = (money % 4);
	}

	return n+1;
  }
  else
  {
  	if(m == 1 || m == 2)
  		return m;
  	else if(m == 3)
  		return 1;
  }

}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
