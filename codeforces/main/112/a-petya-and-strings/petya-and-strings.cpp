// #343620541 	Oct/14/2025 02:38UTC+2 	trintler 	112A - Petya and Strings 	C++23 (GCC 14-64, msys2) 	Accepted 	154 ms 	100 KB

#include <iostream>
#include <string>
using namespace std;

int main() {
	string s, t;
	cin >> s >> t;
	for (int i = 0; i < s.length(); ++i)
	{
		s[i] = (s[i] >= 'A' && s[i] <= 'Z') ? s[i] + ('a' - 'A') : s[i];
		t[i] = (t[i] >= 'A' && t[i] <= 'Z') ? t[i] + ('a' - 'A') : t[i];
	}
        if (s < t)
	{
            	cout << -1 << endl;
            	return 0;
        } else if (s > t) {
            	cout << 1 << endl;
            	return 0;
        } else {
		cout << 0 << endl;
		return 0;
	}
	
}
