#include <iostream>
#include <vector>
#include <bits/stdc++.h>

// using std::cin;
// using std::cout;
// using std::vector;
// using std::max;
using namespace std;


int compute_min_refills(int dist, int tank, vector<int> & stops) {
    // write your code here

    if(dist <= tank )
    {
        return 0;
    }
    int start = 0;
    int d = 0;
    int i = 0;
    int nextmax = tank;
    int n = stops.size();
    int ans = 0;
    while(nextmax<=dist && i<n)
    {
        if(stops[i] > nextmax)
        {
            return -1;
        }
        while(stops[i]<=nextmax && i+1<n)
        {
            if(stops[i+1]<=nextmax)
            {
                i++;
            }
            else
            {
                break;
            }
        }
        d = stops[i];
        ans++;
        nextmax = d+tank;
        i++;
    }

    if(nextmax < dist)
    {
        return -1;
    }
    return ans;
}


int main() {
    int d = 0;
    int m = 0;
    int n = 0;
    cin >> d >> m >> n;

    // cout<<d<<m<<n;
    int x;
    vector<int> stops(n);
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        stops[i] = x;
    }

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
