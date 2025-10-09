#include <iostream>
#include <cmath>
#include <vector>
#include <cstdio>
using namespace std;

int main() {
    double x;
    vector<double> xs;
    while (cin >> x)
    {
        xs.push_back(x);
    }
    for (auto i = xs.rbegin(); i != xs.rend(); ++i)
    {
        printf("%.4f\n", sqrt(*i));
    }
    return 0;
}

