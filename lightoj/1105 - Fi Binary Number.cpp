#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>

#define MAXN 43
#define XTRM 1000000000

using namespace std;

int dp[MAXN + 5];

int main() {

    dp[0] = 1; dp[1] = 2;
    int n = 2;

    while(true) {
        dp[n] = 1 + dp[n - 1] + dp[n - 2];
        if(dp[n] >= XTRM) break;
        n++;
    }

    int T, temp;
    string ans;
    vector<int> v;
    cin >> T;

    for(int i = 1; i <= T; i++) {
        ans = "";
        v.clear();
        cin >> n;

        while(n > 0) {
            temp = (lower_bound(dp, dp + MAXN, n) - dp);
            v.push_back(temp);
            n -= (dp[temp - 1] + 1);
        }

        for(int j = 0; j <= v[0]; j++)
            ans += "0";

        for(int j = 0; j < v.size(); j++)
            ans[v[j]] = '1';

        reverse(ans.begin(), ans.end());

        cout << "Case " << i << ": " << ans << endl;
    }

    return 0;
}
