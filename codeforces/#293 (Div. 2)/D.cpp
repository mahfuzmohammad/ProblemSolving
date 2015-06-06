#include <bits/stdc++.h>

using namespace std;

double dp[2005][2005];
bool vis[2005][2005];

double E(int turnLeft, int manLeft, double p) {
    if(turnLeft == 0 || manLeft == 0) return 0.0;
    if(vis[turnLeft][manLeft]) return dp[turnLeft][manLeft];
    vis[turnLeft][manLeft] = 1;
    double ret;
    ret = p * (1.0 + E(turnLeft - 1, manLeft - 1, p)) + (1.0 - p) * E(turnLeft - 1, manLeft, p);
    return dp[turnLeft][manLeft] = ret;
}

int main() {
    int n, t;
    double p;
    cin >> n >> p >> t;
    printf("%0.8lf\n", E(t, n, p));

    return 0;
}
