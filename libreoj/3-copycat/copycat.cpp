// #Accepted 100 #3. Copycat trintlermint 28 ms	428 K	C++ / 350 B	11/03  20:51:56
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream infile("copycat.in");
    ofstream outfile("copycat.out");
    int T;
    infile >> T;
    infile.ignore(); // discard the newline after the integer

    for (int i = 0; i < T; ++i) {
        string s;
        getline(infile, s);
        outfile << s << '\n';
    }

    infile.close();
    outfile.close();
    return 0;
}
