#include <iostream>
using namespace std;

long long gen(int n) {
    n--;
    auto divby = [](int k, int n) -> long long {
        long long p = n / k;
        return k * p * (p + 1) / 2;
    };
    return divby(3, n) + divby(5, n) - divby(15, n);
}

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        cout << gen(n) << '\n';
    }
    return 0;
}
