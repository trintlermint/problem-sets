#include <iostream>
using namespace std;

int f[41];

int fib(int n)
{
    return f[n] ? f[n] : f[n] = (n <= 2 ? 1 : fib(n - 1) + fib(n - 2));
}

int main()
{
    int k, s = 0;
    cin >> k;
    for (int i = 1; i <= k; i++) s += fib(i);
    cout << s << '\n';
    return 0;
}
