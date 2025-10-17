// #344089103 	Oct/16/2025 21:48UTC+2 	trintler 	A - Nearly Lucky Number 	C++23 (GCC 14-64, msys2) 	Accepted 	124 ms 	0 KB
#include <iostream>

using namespace std;

int main()
{
	long long n;
	cin >> n;
	string s = to_string(n);
	int c=0;
	for (char ch:s)
	{
		if (ch == '4' || ch == '7')
		{
			++c;
		}
	}
	bool t = true;
	string cn = to_string(c);
	for (char ch : cn) {
        	if (ch != '4' && ch != '7') {
			t = false;
		}
	}
	t ? cout << "YES" << endl: cout << "NO" << endl;
}
