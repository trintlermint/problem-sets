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
