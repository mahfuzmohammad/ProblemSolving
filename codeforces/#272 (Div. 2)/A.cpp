#include <bits/stdc++.h>

using namespace std;

const int inf = 10000000;

int dp[10005][15];
bool vis[10005][15];

int f(int n, int x, int &m) {
    if(n < 0) return inf;
    if(n == 0) {
        if(x == 0) return 0;
        return inf;
    }

    if(vis[n][x]) return dp[n][x];
    vis[n][x] = true;

    dp[n][x] = 1 + min(f(n - 1, (x+1)%m, m), f(n - 2, (x+1)%m, m));
    return dp[n][x];
}

int main() {
    ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    int ans = f(n, 0, m);
    if(ans >= inf) ans = -1;
    cout << ans << "\n";

    return 0;
}
