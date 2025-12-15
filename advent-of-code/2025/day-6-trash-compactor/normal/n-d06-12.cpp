#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<string> lines;
    string line;
    size_t maxlen = 0;
    while (getline(cin, line)) {
        lines.push_back(line);
        maxlen = max(maxlen, line.size());
    }
    for (auto& l : lines) l.resize(maxlen, ' ');
    
    vector<string> cols(maxlen);
    for (size_t c = 0; c < maxlen; c++)
        for (size_t r = 0; r < lines.size(); r++)
            cols[c] += lines[r][c];
    
    auto solve = [&](vector<string>& cs) {
        long long total = 0;
        size_t i = 0;
        while (i < cs.size()) {
            while (i < cs.size() && cs[i]. find_first_not_of(' ') == string::npos) i++;
            if (i >= cs.size()) break;
            size_t j = i;
            while (j < cs.size() && cs[j].find_first_not_of(' ') != string::npos) j++;
            char op = cs[i]. back();
            vector<long long> nums;
            for (size_t k = i; k < j; k++) {
                string s = cs[k]. substr(0, cs[k]. size() - 1);
                s.erase(remove(s. begin(), s.end(), ' '), s.end());
                if (! s.empty()) nums.push_back(stoll(s));
            }
            if (op == '+') {
                long long sum = 0;
                for (auto n : nums) sum += n;
                total += sum;
            } else {
                long long prod = 1;
                for (auto n : nums) prod *= n;
                total += prod;
            }
            i = j;
        }
        return total;
    };
    
    cout << solve(cols) << "\n";
    reverse(cols.begin(), cols.end());
    cout << solve(cols) << "\n";
}
