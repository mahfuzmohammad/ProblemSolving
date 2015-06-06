#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>

#define maxmn 10

using namespace std;

int A[maxmn + 2];
int dp[maxmn + 2][maxmn + 2];

int solve(int m, int n)
{
    int ans = 0;
    for(int i = 1; i <= m; i++) {
        dp[1][i] = 1;
        ans++;
    }

    for(int k = 2; k <= n; k++) {
        ans = 0;
        for(int i = 1; i <= m; i++) {
            int temp = 0;
            for(int j = 1; j <= m; j++) {
                if(abs(A[j] - A[i]) <= 2) {
                    temp += dp[k - 1][j];
                }
            }

            dp[k][i] = temp;
            ans += temp;
        }
    }

    return ans;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int T, m, n;
    cin >> T;

    for(int i = 1; i <= T; i++) {
        cin >> m >> n;
        for(int j = 1; j <= m; j++) {
            cin >> A[j];
        }

        memset(dp, -1, sizeof(dp));
        cout << "Case " << i << ": " << solve(m, n) << endl;
    }

    return 0;
}
