// #344103154 	Oct/17/2025 01:25UTC+2 	trintler 	41A - Translation 	C++23 (GCC 14-64, msys2) 	Accepted 	46 ms 	100 KB

#include <iostream>
using namespace std;
#include <string>
int main()
{
	string s,t;
	cin >> s;
	cin >> t;
	string r = string(t.rbegin(), t.rend());
	r == s ? cout << "YES" << endl : cout << "NO" << endl;
}
