#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// first naive
/*
int main()
{
	// check max, set it, then check second max, for all string positions after first max
	string in;
	ll res = 0;
	while(cin >> in)
	{
		auto f_idx = max_element(in.begin(), in.end());
		in.erase(in.begin(), f_idx + 1);
		auto s_idx = max_element(in.begin(), in.end());
		string battery;
		battery += *f_idx; battery += *s_idx;
		res+=stoi(battery);
	}
	cout << res << '\n';
}
*/
/* second naive
int main() {
    string in;
    long long res = 0;
    while (cin >> in) {
        int max_val = 0;
        for (size_t i = 0; i < in.size(); ++i) {
            for (size_t j = i + 1; j < in.size(); ++j) {
                int val = (in[i] - '0') * 10 + (in[j] - '0');
                max_val = max(max_val, val);
            }
        }
        res += max_val;
    }
    cout << res << '\n';
}
*/
/* Best sol i found part 1
int main()
{
	string in; ll res = 0;
	while(cin >> in)
	{
		auto f_idx = max_element(in.begin(), in.end() - 1);
		char first_max = *f_idx;
		auto s_idx = max_element(f_idx + 1, in.end());
		char second_max = *s_idx;
		string battery;
		battery += first_max;
		battery += second_max;
		res += stoi(battery);
	}
	cout << res << '\n';
	return 0;
}
*/
/* Naive sol part 2
int main()
{
	string in;
	ll res = 0;
	while(cin >> in)
	{
		int remove_count = in.length() - 12;
		string battery; 

		for (char c : in) {
			while (!battery.empty() && battery.back() < c && remove_count > 0) {
				battery.pop_back();
				remove_count--;
			}
			battery.push_back(c);
		}
		battery.resize(12);
		res += stoll(battery);
	}
	cout << res << '\n';
	return 0;
}
*/
/* Recursive solution part 2*/
string get_battery(string::const_iterator start, string::const_iterator end, int k) {
	if (k == 0) return "";
	auto search_limit = end - (k - 1);
	auto max_pos = max_element(start, search_limit);
	return *max_pos + get_battery(max_pos + 1, end, k - 1);
}

int main()
{
	string in;
	ll res = 0;
	while(cin >> in)
	{
		string battery = get_battery(in.begin(), in.end(), 12);
		res += stoll(battery);
	}
	cout << res << '\n';
	return 0;
}
