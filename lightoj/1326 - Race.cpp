#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>

#define MOD 10056
#define MAXN 1000

using namespace std;

int dp[MAXN + 2];
int nCr[MAXN + 2][MAXN + 2];

int main() {

    for(int n = 1; n <= MAXN; n++) {
        for(int r = 0; r <= n; r++) {
            if(r == 0 || r == n) nCr[n][r] = 1;
            else {
                nCr[n][r] = nCr[n - 1][r] + nCr[n - 1][r - 1];
                nCr[n][r] %= MOD;
            }
        }
    }

    dp[1] = 1;

    for(int i = 2; i <= MAXN; i++) {
        int tot = 1;
        for(int j = i - 1; j >= 1; j--) {
            tot += (nCr[i][j] * dp[i - j]) % MOD;
            tot %= MOD;
        }

        dp[i] = tot;
    }

    int T, n;
    cin >> T;

    for(int i = 1; i <= T; i++) {
        cin >> n;
        cout << "Case " << i << ": " << dp[n] << endl;
    }

    return 0;
}
