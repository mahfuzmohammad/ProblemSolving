#include <bits/stdc++.h>

using namespace std;

int arr[105], dp[105][105];

int f(int l, int r) {
    if(l > r) return 0;
    if(dp[l][r] != -1) return dp[l][r];
    int ret = -1000000000;

    for(int i = l; i <= r; i++) {
        ret = max(ret, (arr[i] - arr[l-1]) - f(i+1, r));
    }

    for(int j = r; j >= l; j--) {
        ret = max(ret, (arr[r] - arr[j-1]) - f(l, j-1));
    }

    return dp[l][r] = ret;
}

int main() {
    //freopen("in", "r", stdin);
    int t, n;
    scanf("%d", &t);

    for(int T = 1; T <= t; T++) {
        scanf("%d", &n);
        for(int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
            if(i > 0) arr[i] += arr[i-1];
        }

        memset(dp, -1, sizeof dp);
        printf("Case %d: %d\n", T, f(0, n-1));
    }

    return 0;
}
