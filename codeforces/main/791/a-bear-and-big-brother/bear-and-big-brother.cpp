// #343774703 	Oct/14/2025 23:35UTC+2 	trintler 	791A - Bear and Big Brother 	C++23 (GCC 14-64, msys2) 	Accepted 	62 ms 	100 KB

#include <iostream>
using namespace std;

int main()
{
	int a,b, i = 0;
	cin >> a >> b;
	while (true)
	{
		if (a > b)
		{
			cout << i << endl;
			break;
		}
		else
		{
			a *= 3;
			b *= 2;
			++i;
		}
	}
	return 0;
}
