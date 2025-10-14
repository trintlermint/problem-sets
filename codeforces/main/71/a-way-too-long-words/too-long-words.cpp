// #343214608 	Oct/12/2025 04:04UTC+2 	trintler 	71A - Way Too Long Words 	C++17 (GCC 7-32) 	Accepted 	46 ms 	0 KB

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<string> ws;

	for (int i = 0; i < n; ++i)
	{
		string w;
		cin >> w;

		if (w.length() > 10)
		{
			ws.push_back(w[0] + to_string((w.end()-w.begin()-2)) + w[w.size()-1]);
		}
		else
		{
			ws.push_back(w);
		}
	}
	for (const string& out:ws)
	{
		cout << out << endl;
	}
	return 0;
}
