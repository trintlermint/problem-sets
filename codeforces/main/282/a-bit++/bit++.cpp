// #343615048 	Oct/13/2025 23:58UTC+2 	trintler 	282A - Bit++ 	C++23 (GCC 14-64, msys2) 	Accepted 	62 ms 	100 KB

#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;

	int x = 0;

	for (int i = 0; i < n; ++i)
	{
		string s;
		cin >> s;
		
		if (s == "X++" || s == "++X")
		{
			x++;	
		} else
		{
			x--;	
		}
	}
	cout << x << endl;
}
