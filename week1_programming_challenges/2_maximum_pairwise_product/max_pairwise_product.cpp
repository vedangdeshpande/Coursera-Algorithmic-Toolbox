#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long

ll MaxPairwiseProduct(const std::vector<ll>& numbers) {
    ll max_product = 0;
    ll n = numbers.size();

    // for (ll first = 0; first < n; ++first) {
    //     for (ll second = first + 1; second < n; ++second) {
    //         max_product = std::max(max_product,
    //             numbers[first] * numbers[second]);
    //     }
    // }

    ll max = -1;
    ll maxind1 = 0;

    for (ll first = 0; first < n; ++first) {
            if(max < numbers[first])
            {
                max = numbers[first];
                maxind1 = first;
            }
        }

    max = -1;
    ll maxind2 = 0;
    for (ll first = 0; first < n; ++first) {
            if(max < numbers[first] && maxind1!=first)
            {
                max = numbers[first];
                maxind2 = first;
            }
        }

    max_product = numbers[maxind1] * numbers[maxind2];

    return max_product;
}

int main() {
    ll n;
    std::cin >> n;
    std::vector<ll> numbers(n);
    for (ll i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    std::cout << MaxPairwiseProduct(numbers)<< "\n";
    return 0;
}
