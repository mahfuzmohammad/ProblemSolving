#include <bits/stdc++.h>
#define _MAXN 2005

using namespace std;

long long dp[_MAXN][_MAXN];
bool ispal[_MAXN][_MAXN];

int main() {

    string str;
    cin >> str;

    for(int i = 0; i < str.size(); i++) {
        ispal[i][i] = true;
        dp[i][i] = 1;
        if(i > 0) {

            if(str[i] == str[i - 1]) {
                ispal[i - 1][i] = true;
                dp[i - 1][i] = 3;
            } else {
                dp[i - 1][i] = 2;
            }
        }
    }

    for(int i = 3; i <= str.size(); i++) {
        for(int j = 0; j <= str.size() - i; j++) {
            if(str[j] == str[j + i - 1]) {
                ispal[j][j + i - 1] = ispal[j + 1][j + i - 2];
            }

            dp[j][j + i - 1] = ispal[j][j + i - 1] + dp[j][j + i - 2] + dp[j + 1][j + i - 1] - dp[j + 1][j + i - 2];
        }
    }

    long long ans = 0;
    for(int i = 0; i < str.size() - 1; i++) {
        ans += (dp[0][i] * dp[i + 1][str.size() - 1]);
        if(i > 0) {
            ans -= (dp[0][i - 1] * dp[i + 1][str.size() - 1]);
        }
    }

    cout << ans << endl;

    return 0;
}
