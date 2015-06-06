#include <bits/stdc++.h>

using namespace std;

string str;
long long dp[(1 << 16) + 2][21];

int toint(char ch) {
    if(ch >= '0' && ch <= '9') return (ch - '0');
    return (ch - 'A' + 10);
}

long long f(int mask, int m, int& k, int& b) {

    if(mask + 1 == (1 << str.size())) {
        if (m == 0) return 1;
        return 0;
    }

    if(dp[mask][m] != -1) return dp[mask][m];

    long long temp = 0;

    for(int i = 0; i < str.size(); i++) {
        if((mask & (1 << i)) == 0) {
            temp += f(mask | (1 << i),  ((m * b) + toint(str[i])) % k, k, b);
        }
    }

    dp[mask][m] = temp;
    return dp[mask][m];
}

int main() {
    //freopen("input.txt", "r", stdin);
    int t, base, k;

    cin >> t;

    for(int i = 1; i <= t; i++) {
        cin >> base >> k >> str;
        memset(dp, -1, sizeof dp);
        cout << "Case " << i << ": " << f(0, 0, k, base) << endl;
    }

    return 0;
}
