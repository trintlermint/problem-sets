// #351648942 	Dec/02/2025 20:08UTC+1 	trintler 	469A - I Wanna Be the Guy 	C++23 (GCC 14-64, msys2) 	Accepted 	46 ms 	100 KB
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	set<int> levels;
	int p; cin >> p;
	for (int i = 0; i < p; ++i) {
		int a;
		cin >> a;
		levels.insert(a);
	}
	int q; cin >> q;
	for (int i = 0; i < q; ++i) {
		int a;
		cin >> a;
		levels.insert(a);
	}
	(int)levels.size() == n
		? cout << "I become the guy.\n"
		: cout << "Oh, my keyboard!\n"
	;
	return 0;
}
