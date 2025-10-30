// #346745172 	Oct/30/2025 23:05UTC+1 	trintler 	58A - Chat room 	C++23 (GCC 14-64, msys2) 	Accepted 	62 ms 	0 KB
#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	cin >> s;
	string t = "hello";
	int i = 0;
	for (char c : s) {
		if (c == t[i]) {
			++i;
			if (i== t.size()) break;
		}
	}
	i == t.size() ? cout << "YES" << endl : cout << "NO" << endl;
}
