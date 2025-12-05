#include <iostream>
using namespace std;
using ll = long long;

ll largest_prime_factor(ll n) {
    ll maxp = -1;
    while (n % 2 == 0) {
        maxp = 2;
        n /= 2;
    }
    for (ll i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            maxp = i;
            n /= i;
        }
    }
    if (n > 2) maxp = n;

    return maxp;
}

int main() {
    ll n = 600851475143LL;
    ll res = largest_prime_factor(n);
    cout << res << '\n';
    return 0;
}
