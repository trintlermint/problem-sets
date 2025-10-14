// #343617410 	Oct/14/2025 00:59UTC+2 	trintler 	158A - Next Round 	C++23 (GCC 14-64, msys2) 	Accepted 	124 ms 	100 KB

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n, k, sum = 0;
	cin >> n >> k;
	vector<int> as(n);
	for(int i = 0; i < n; ++i)
	{
		cin >> as[i];
	}
	for (int i = 0; i < n; ++i)
	{
		if (as[i] >= as[k-1] && as[i] != 0)
		{
			sum += 1;
		}
		else { continue; }
		
	}
	cout << sum << endl;
	return 0;
}
