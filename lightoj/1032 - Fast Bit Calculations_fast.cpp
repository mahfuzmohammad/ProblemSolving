#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
pll dp[2][2][35];
bool visited[2][2][35];

pll f(int prev, int pos, int issmall, int& n) {
    if(pos == -1) return pll(1L, 0L);

    if(visited[prev][issmall][pos]) return dp[prev][issmall][pos];
    if(issmall)
        visited[prev][issmall][pos] = 1;

    pll zero, one;
    ll k=0, a = 0;

    if(issmall) {
        zero = f(0, pos-1, 1, n);
        one = f(1, pos-1, 1, n);
    } else {
        if(n & (1 << pos)) {
            zero = f(0, pos-1, 1, n);
            one = f(1, pos-1, 0, n);
        } else {
            zero = f(0, pos-1, 0, n);
        }
    }

    k = zero.first + one.first;
    a = one.first * prev + one.second + zero.second;

    if(issmall)
        dp[prev][issmall][pos] = pll(k, a);

    return pll(k, a);
}

int main() {
    //freopen("in.txt", "r", stdin);
    int t, n;
    scanf("%d", &t);
    memset(visited, 0, sizeof visited);
    for(int i = 1; i <= t; i++) {
        scanf("%d", &n);
        pll ans = f(0, 30, 0, n);
        printf("Case %d: %lld\n", i, ans.second);
    }

    return 0;
}
