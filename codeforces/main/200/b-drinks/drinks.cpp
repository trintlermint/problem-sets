#include <iostream>

using namespace std;

int main()
{
	int n;
	double jv = 0;
	cin >> n;
	int x = n;
	while(n--)
	{
		int p;
		cin >> p;
		jv += p;
	}
	printf("%.10f\n", jv/x);
}
