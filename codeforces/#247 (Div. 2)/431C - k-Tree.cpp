//In the name of Allah, most Gracious, most Compassionate
#include <bits/stdc++.h>

using namespace std;

int dp[200][200];
int n, k, d;

int f(int n, int flag) {
    if(n < 0) return 0;
    if(n == 0 && flag >= 1) return 1;

    if(dp[flag][n] != -1) return dp[flag][n];

    int ans = 0;
    for(int i = 1; i <= min(k, n); i++) {
        if(i >= d) {
            ans += f(n - i, flag + 1);
        } else {
            ans += f(n - i, flag);
        }

        ans %= 1000000007;
    }

    dp[flag][n] = (ans % 1000000007);
    return dp[flag][n];
}

int main() {

    memset(dp, -1, sizeof dp);
    scanf("%d %d %d", &n, &k, &d);
    printf("%d\n", f(n, 0))   ;

    return 0;
}
