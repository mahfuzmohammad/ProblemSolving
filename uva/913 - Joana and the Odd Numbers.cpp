//UVA 913 - Joana and the Odd Numbers.cpp

#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    long long N, n, S, ans;

    while(cin >> N) {
        n = (N + 1) / 2;
        S = (n * (2 + (n - 1) * 2)) / 2;
        ans = 1 + (S - 1) * 2;
        cout << 3 * ans - 6 << endl;
    }

    return 0;
}
