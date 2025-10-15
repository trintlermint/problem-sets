// #343776603 	Oct/15/2025 00:07UTC+2 	trintler 	617A - Elephant 	C++23 (GCC 14-64, msys2) 	Accepted 	62 ms 	0 KB

#include <iostream>
using namespace std;

int main()
{
	int x, i=0;
	cin >> x;
	int cs[] = {5, 4, 3, 2, 1};
	while (x > 0)
	{
    		for (int c = 0; c < 5; ++c)
		{
        		if (x >= cs[c])
			{
            			x -= cs[c];
            			++i;
            			break;
        		}
    		}
	}
	cout << i << endl;
	return 0;
}
