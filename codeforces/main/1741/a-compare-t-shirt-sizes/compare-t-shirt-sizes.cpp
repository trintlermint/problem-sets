// #344656320 	Oct/19/2025 16:24UTC+2 	trintler 	1741A - Compare T-Shirt Sizes 	C++23 (GCC 14-64, msys2) 	Accepted 	93 ms 	0 KB

#include <iostream>
using namespace std;

char type(const string &s) { return s.back(); }

int xs(const string &s) { return s.length() - 1; }

int main() {
	int t;
	cin >> t;
	while (t--) {
		string a, b;
		cin >> a >> b;
		char ta = type(a), tb = type(b);
		if (ta == tb) {
			if (ta == 'M') {
				cout << "=" << endl;
			} else if (ta == 'S') {
				if (xs(a) == xs(b)) cout << "=" << endl;
				else if (xs(a) > xs(b)) cout << "<" << endl;
				else cout << ">" << endl;
			} else {
				if (xs(a) == xs(b)) cout << "=" << endl;
				else if (xs(a) > xs(b)) cout << ">" << endl;
				else cout << "<" << endl;
			}
		} else {
			if (ta == 'M') {
				if (tb == 'S') cout << ">" << endl;
				else cout << "<" << endl;
			} else if (ta == 'S') { cout << "<" << endl;
			} else {
				cout << ">" << endl;
			}
		}
	}
	return 0;
}
