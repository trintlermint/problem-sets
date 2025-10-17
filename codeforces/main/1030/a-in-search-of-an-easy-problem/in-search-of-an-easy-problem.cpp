// #344407762 	Oct/18/2025 00:04UTC+2 	trintler 	1030A - In Search of an Easy Problem 	C++23 (GCC 14-64, msys2) 	Accepted 	46 ms 	0 KB
#include <iostream>
using namespace std;

int main()
{
	int n,e;
	cin >> n;
	int hard = 0;
	while(n-- && cin >> e)
	{
		if (e == 1) hard = 1;
	}
	hard == 1 ? cout << "HARD" << endl : cout << "EASY" << endl;
}
