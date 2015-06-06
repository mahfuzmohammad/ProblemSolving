#include <bits/stdc++.h>

#define _MAXN 10000000
#define _MOD  1000000007
#define ll    long long

using namespace std;

ll dp[2][_MAXN + 5];

int main() {

    int n;
    scanf("%d", &n);

    dp[0][0] = 1;
    for(int i = 1; i <= n; i++) {
        dp[0][i] = 3LL * dp[1][i - 1];
        dp[0][i] %= _MOD;
        dp[1][i] = 2LL * dp[1][i - 1] + dp[0][i - 1];
        dp[1][i] %= _MOD;
    }

    cout << dp[0][n] << endl;

    return 0;
}
