// #823360	trintlermint	03/11/2025 20:36	970 B	17ms	2.78 MB	Evaluated: 100 points
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

int main() {
    ifstream infile("polybius.in");
    ofstream outfile("polybius.out");
    
    int p;
    string t, s;
    
    infile >> p >> t >> s;
    
    if (p == 1) {
        string result = "";
        
        for (char c : s) {
            size_t pos = t.find(c);

            int row = (pos / 5) + 1;
            int col = (pos % 5) + 1;

            result += (char)('0' + row);
            result += (char)('0' + col);
        }
        
        outfile << result << endl;
    }
    else if (p == 2) {
        string result = "";
        
        for (size_t i = 0; i < s.length(); i += 2) {
            int row = s[i] - '0';
            int col = s[i + 1] - '0';

            int index = (row - 1) * 5 + (col - 1);
#
            result += t[index];
        }
        
        outfile << result << endl;
    }
    
    infile.close();
    outfile.close();
    
    return 0;
}
