#include <iostream>
using namespace std;
int main()
{
	int n,x,y;
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			cin >> n;
			if (n == 1)
			{
				x = j, y = i;
				break;
			}
		}
	}
	n = ((2 - x) < 0 ? -(2 - x) : (2 - x)) + ((2 - y) < 0 ? -(2 - y) : (2 - y));
	cout << n << endl;
	return 0;
}
