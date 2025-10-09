#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	long long m=0,v;
	vector<long long> ns;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> v;
		ns.push_back(v);
	}
	for (int i = 1; i < n; i++)
	{
		if (ns[i] < ns[i-1])
		{
			m += (ns[i-1]-ns[i]);
			ns[i] = ns[i-1];
		}
	}
	cout << m << endl;
	return 0;
}
