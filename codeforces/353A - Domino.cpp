#include <bits/stdc++.h>

using namespace std;

int dp[200][3][3],
    h[200],
    l[200];

bool flag;

int F(int& N, int curr, int hs, int ls) {
    //cout << curr << " " << hs << " " << ls << endl;

    if(curr >= N) {
        if(hs == 0 && ls == 0) {/*cout << "TEST" << endl;*/ flag = false; return 0;}
        flag = true;
        return 1 << 25;
    }

    int ret = 0;

    if(dp[curr][hs][ls] != -1) return dp[curr][hs][ls];

    ret += min( F(N, curr + 1, (hs + h[curr]) % 2, (ls + l[curr]) % 2), 1 + F(N, curr + 1, (hs + l[curr]) % 2, (ls + h[curr]) % 2) );

    dp[curr][hs][ls] = ret;

    return ret;
}

int main() {

    int N;
    cin >> N;

    flag = false;

    for(int i = 0; i < N; i++) {
        cin >> h[i] >> l[i];
    }

    memset(dp, -1, sizeof dp);
    int ans = F(N, 0, 0, 0);

    if(flag && ans >= (1 << 25))
        cout << -1 << endl;
    else cout << ans << endl;

    return 0;
}
