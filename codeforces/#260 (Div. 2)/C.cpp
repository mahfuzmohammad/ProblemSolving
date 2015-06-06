#include <bits/stdc++.h>

using namespace std;

long long arr[100005];
long long dp[100005];

long long f(int i) {
    if(i > 100000) return 0L;
    if(dp[i] != -1) return dp[i];

    long long temp;
    temp = max(arr[i] + f(i + 2), arr[i+1] + f(i+3));
    dp[i] = temp;
    return dp[i];
}

int main() {
    ios_base::sync_with_stdio();
    //freopen("in.txt", "r", stdin);
    int n, a;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a;
        arr[a] += (long long)a;
    }

    memset(dp, -1, sizeof dp);
    cout << f(1) << "\n";

    return 0;
}
