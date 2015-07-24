#include <bits/stdc++.h>

using namespace std;

int arr[1005];
int dp[1005];

int f(int pos, int n) {
    if(pos >= n) return 0;
    if(dp[pos] != -1) return dp[pos];
    int ret = max(arr[pos] + f(pos + 2, n), f(pos+1, n));
    return dp[pos] = ret;
}

int main() {
    //freopen("in", "r", stdin);
    int t, n;
    scanf("%d", &t);

    for(int T = 1; T <= t; T++) {
        scanf("%d", &n);
        for(int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        int a1, a2;
        memset(dp, -1, sizeof dp);
        a1 = f(0, n-1);
        memset(dp, -1, sizeof dp);
        a2 = f(1, n);
        printf("Case %d: %d\n", T, max(a1, a2));
    }

    return 0;
}
