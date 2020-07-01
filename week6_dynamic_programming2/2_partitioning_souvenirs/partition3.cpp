#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#define ll long long

using std::vector;
using namespace std;

// int partition3(vector<int> &A) {
//   //write your code here

// 	ll i,j,n,total,sum;

// 	n = A.size();
// 	total = 0;

// 	sort(A.begin(), A.end());
// 	reverse(A.begin(), A.end());

// 	for(i=0; i<n; i++)
// 	{
// 		total += A[i];
// 	}

// 	if(total%3 != 0)
// 	{
// 		return 0;
// 	}

// 	total /= 3;
// 	sum = 0;

// 	ll arr[n] = {0};

// 	for(i=1; i<=3; i++)
// 	{
// 		sum = 0;
// 		for(j=0; j<n; j++)
// 		{
// 			if(arr[j] == 0 && sum + A[j] <= total)
// 			{
// 				arr[j] = i;
// 				sum += A[j];
// 			}
// 		}
// 		if(sum != total)
// 		{
// 			return 0;
// 		}
// 	}

// 	// for(j=0; j<n; j++)
// 	// {
// 	// 	cout<<A[j]<<"("<<arr[j]<<")"<<" ";
// 	// }
// 	// cout<<"\n";

// 	for(j=0; j<n; j++)
// 	{
// 		if(arr[j] == 0)
// 		{
// 			return 0;
// 		}
// 	}

// 	return 1;
// }

int subsetsum(vector<int> &A, int n, int a, int b, int c, std::map<string, int> lookup)
{
	if(a==0 && b==0 && c==0)
	{
		return 1;
	}
	if(n < 0)
	{
		return 0;
	}

	string key = to_string(a) + "|" + to_string(b) + "|" + to_string(c) + "|" + to_string(n);

	if(lookup.find(key) == lookup.end())
	{
		int x = 0;
		if(a - A[n] >= 0)
		{
			x = subsetsum(A, n-1, a - A[n], b, c, lookup);
		}

		int y = 0;
		if(!x && b - A[n] >= 0)
		{
			y = subsetsum(A, n-1, a, b - A[n], c, lookup);
		}

		int z = 0;
		if((!x && !y) && c - A[n] >= 0)
		{
			z = subsetsum(A, n-1, a, b, c - A[n], lookup);
		}

		if(x || y || z)
		{
			lookup[key] = 1;
		}
		else
		{
			lookup[key] = 0;
		}
		
	}
	
	return lookup[key];
}

int mypartition3(vector<int> &A)
{
	ll i,j,n,total,sum;

	n = A.size();
	total = 0;

	for(i=0; i<n; i++)
	{
		total += A[i];
	}

	if(total%3 != 0)
	{
		return 0;
	}

	std::map<string, int> lookup;

	return subsetsum(A, n-1, total/3, total/3, total/3, lookup);
}

int main() {
  int n;
  std::cin >> n;
  vector<int> A(n);
  for (size_t i = 0; i < A.size(); ++i) {
    std::cin >> A[i];
  }
  std::cout << mypartition3(A) << '\n';
}
