// #343214567 	Oct/12/2025 04:03UTC+2 	trintler 	4A - Watermelon 	C++17 (GCC 7-32) 	Accepted 	92 ms 	0 KB

#include <iostream>
using namespace std;

int main()
{
	int w;
	cin >> w;

	if (w % 2 == 0 && w > 2)
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}
}
