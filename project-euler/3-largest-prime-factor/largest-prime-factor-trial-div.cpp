#include <iostream>
using namespace std;

int main() {
    __int64_t number = 600851475143;
    int divisor = 2;
    while (number > 1) {
        if (number % divisor == 0) {
            number /= divisor;
        } else {
            ++divisor;
        }
    }
    cout << divisor << '\n';
    return 0;
}
