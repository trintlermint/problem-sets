#include <iostream>
using namespace std;

int main()
{
	int n;
	while(cin >> n)
	{
		if (n == 42)
		{
			break;
		} else {
			cout << n << endl;
			continue;
		}
	}
}
