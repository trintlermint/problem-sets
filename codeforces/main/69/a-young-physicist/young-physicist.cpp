// #344104163 	Oct/17/2025 01:59UTC+2 	trintler 	69A - Young Physicist 	C++23 (GCC 14-64, msys2) 	Accepted 	122 ms 	100 KB
#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int cx = 0, cy = 0, cz = 0;
	while(--n+1)
	{
		int x,y,z;
		cin >> x >> y >> z;
		cx += x;
		cy += y;
		cz += z;
	}
	cx == 0 && cx == cy && cy == cz ? cout << "YES" << endl : cout << "NO" << endl;
}
