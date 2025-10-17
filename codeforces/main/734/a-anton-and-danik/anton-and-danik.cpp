// #344102960 	Oct/17/2025 01:20UTC+2 	trintler 	734A - Anton and Danik 	C++23 (GCC 14-64, msys2) 	Accepted 	77 ms 	0 KB
#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	int ca = 0, cd = 0;
	for (char c:s) c == 'A' ? ++ca : ++cd;
	(ca == cd) ? cout << "Friendship" << endl: (ca > cd ? cout << "Anton" << endl: cout << "Danik" << endl);
}
