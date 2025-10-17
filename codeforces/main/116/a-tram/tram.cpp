// #344406427 	Oct/17/2025 23:41UTC+2 	trintler 	116A - Tram 	C++23 (GCC 14-64, msys2) 	Accepted 	124 ms 	100 KB
// worked together on this, with +1mbalance && Valyn.
#include <iostream>

using namespace std;

int v[1000];

int main() {
  int n;
  cin >> n;

  int sum = 0;
  int max = 0;

  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;

    sum += b;
    sum -= a;

    if (sum > max) {
      max = sum;
    }
  }

  cout << max << endl;

  return 0;
}
