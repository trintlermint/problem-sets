// #344410499 	Oct/18/2025 00:56UTC+2 	trintler 	467A - George and Accommodation 	C++23 (GCC 14-64, msys2) 	Accepted 	62 ms 	0 KB
#include <iostream>
using namespace std;

int main()
{
	int n,c=0;
	cin >> n;
	while(n--)
	{
		int p,q;
		cin >> p >> q;
		2 <= q-p ? ++c : 0;
	}
	cout << c << endl;
}
