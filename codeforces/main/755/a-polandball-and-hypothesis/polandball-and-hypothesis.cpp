#include <iostream>
using namespace std;

bool isprime(int num) {
    if (num < 2) return false;
    if (num == 2) return true;
    if (num % 2 == 0) return false;
    for (int i = 3; i * i <= num; i += 2)
    {
        if (num % i == 0) return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    for (int m = 1; m <= 1000; m++) {
        int value = n * m + 1;
        if (!isprime(value)) {
            cout << m << endl;
            return 0;
        }
    }
    return 0;
}
