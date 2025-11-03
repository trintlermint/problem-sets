/* 
Resources: 0.049s, 3.56 MB
Maximum single-case runtime: 0.006s
Final score: 100/100 (3.0/3 points)
*/
#include <iostream>

using namespace std;

int main ()
{
	int n;
	cin >> n;
	while(n--)
	{
		long long a,b,p;
		cin >> a >> b >> p;
		a*b!=p ? cout << "16 BIT S/W ONLY" << endl: cout << "POSSIBLE DOUBLE SIGMA" << endl;
	}
}
