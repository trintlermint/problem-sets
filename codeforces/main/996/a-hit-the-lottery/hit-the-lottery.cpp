// #351754108 	Dec/03/2025 17:27UTC+1 	trintler 	996A - Hit the Lottery 	C++23 (GCC 14-64, msys2) 	Accepted 	46 ms 	100 KB
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, res = 0; cin >> n;
	int bills[] = {100, 20, 10, 5, 1};

	for (int b : bills) {
		res += n / b;
		n %= b;
	}
	cout << res << endl;
	return 0;
}
