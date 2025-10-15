// #343838695 	Oct/15/2025 11:45UTC+2 	trintler 	546A - Soldier and Bananas 	C++23 (GCC 14-64, msys2) 	Accepted 	46 ms 	100 KB

#include <iostream>

using namespace std;

int main()
{
	int k,n,w, sum = 0;
	cin >> k >> n >> w;

	for (int i = 1; i <= w; ++i)
	{
		sum += (k*i);
	}
	if (n > sum) cout << 0 << endl;
	else cout << -n + sum << endl;
}
