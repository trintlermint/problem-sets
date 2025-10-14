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
