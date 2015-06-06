#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>

#define maxn 1000000

using namespace std;

double digits[maxn + 2];

void precalc()
{
    digits[0] = 0;

    for(int i = 1; i <= maxn; i++){
        digits[i] = digits[i - 1] + log10(i);
    }
}

int main()
{
    precalc();
    int T, n, base;
    cin >> T;

    for(int i = 1; i <= T; i++){
        cin >> n >> base;
        cout << "Case " << i << ": " << int((digits[n] / log10(base)) + 1) << endl;
    }

    return 0;
}
