#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    int T, n;
    double ans;
    cin >> T;

    for(int i = 1; i <= T; i++) {
        cin >> n;
        ans = 0;

        for(int j = 1; j <= n; j++) {
            ans += (double(n) / double(j));
        }

        printf("Case %d: %0.7lf\n", i, ans);
    }

    return 0;
}
