#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>

using std::vector;
using namespace std;

// vector<int> optimal_sequence(int n) {
//   std::vector<int> sequence;
//   while(n >= 1) 
//   {

//     while(n%3==0 || n%2==0)
//     {
//       while(n % 3 == 0) 
//       {
//         // cout<<n<<" ";
//         sequence.push_back(n);
//         n /= 3;
//       }
//       while(n % 2 == 0) 
//       {
//         // cout<<n<<" ";
//         sequence.push_back(n);
//         n /= 2;
//       } 
//     }

//     // cout<<"\nin n-1 for n = "<<n<<endl;

//     sequence.push_back(n);
//     n = n - 1;

//     // cout<<" log of "<<n-1<<" "<< ( log(n-1) / log(3) ) <<"  "<<(int)( log(n-1) / log(3) )<<endl;

//     if((int)( log(n-1) / log(3) ) == ( log(n-1) / log(3) ) )
//     {
//       sequence.push_back(n);
//       n = n - 1;
//     }
    
//   }

//   reverse(sequence.begin(), sequence.end());
//   return sequence;
// }

std::vector<int> sequence;
std::vector<int> counts;

void optimal_sequence(int n) {

  sequence.push_back(0);
  counts.push_back(0);
  sequence.push_back(1);
  counts.push_back(0);
  int i;
  for(i=2; i<=n; i++)
  {

    if(i%3 == 0)
    {
      if(counts[i-1] < counts[i/3])
      {
        sequence.push_back(i-1);
        counts.push_back(counts[i-1]+1);
      }
      else
      {
        sequence.push_back(i/3);
        counts.push_back(counts[i/3]+1);
      }
    }
    else if(i%2 == 0)
    {
      if(counts[i-1] < counts[i/2])
      {
        sequence.push_back(i-1);
        counts.push_back(counts[i-1]+1);
      }
      else
      {
        sequence.push_back(i/2);
        counts.push_back(counts[i/2]+1);
      }
    }
    else
    {
      sequence.push_back(i-1);
      counts.push_back(counts[i-1]+1);
    }
  }
}


int main() {
  int n;
  std::cin >> n;
  // vector<int> sequence = optimal_sequence(n);
  // std::cout << sequence.size() - 1 << std::endl;
  // for (size_t i = 0; i < sequence.size(); ++i) {
  //   std::cout << sequence[i] << " ";
  // }

  std::vector<int> v;

  optimal_sequence(n);
  cout<<counts[n]<<endl;
  int i = n;
  // cout<<n<<" ";
  v.push_back(n);
  while(i!=1)
  {
    // cout<<sequence[i]<<" ";
    v.push_back(sequence[i]);
    i = sequence[i];
  }
  // cout<<endl;

  reverse(v.begin(), v.end());
  for(i=0; i<v.size(); i++)
  {
    cout<< v[i] <<" ";
  }
  cout<<"\n";
}
