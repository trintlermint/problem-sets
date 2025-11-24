// #350004263 	Nov/21/2025 01:21UTC+1 	trintler 	1944A - Destroying Bridges 	C++23 (GCC 14-64, msys2) 	Accepted 	46 ms 	0 KB 
#include <iostream>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;
        	if (k == 0)
        	{
        		cout << n << endl;
        		continue;
        	}
        	int b = n * (n - 1) / 2;
        	if (k == b)
        	{
        		cout << 1 << endl;
        		continue;
		}
        	for (int i = 1; i <= n; i++)
        	{
        		if (i * (n - i) <= k)
        		{
        			cout << i << "\n";
        			break;
			}
		}
	}
	return 0;
}
