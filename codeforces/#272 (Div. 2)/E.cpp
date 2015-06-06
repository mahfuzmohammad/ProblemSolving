#include <bits/stdc++.h>

using namespace std;

int minLen[2009];
int dp[2009][2009];

int main() {
    ios_base::sync_with_stdio(0);
    string s, p;

    cin >> s >> p;

    for(int i = 0; i < s.size(); i++) {
        int x = i;
        int j;
        for(j = 0; j < p.size(); j++) {
            while(x < s.size() && s[x] != p[j]) x++;
            if(x == s.size()) break;
            else x++;
        }

        if(j == p.size())
            minLen[i] = x - i;
        else minLen[i] = -1;
    }

    for(int i = 0; i < s.size(); i++) {
        for(int r = 0; r <= i; r++) {
            dp[i+1][r] = max(dp[i+1][r], dp[i][r]);
            dp[i+1][r+1] = max(dp[i+1][r+1], dp[i][r]);
            if(minLen[i] >= 0) {
                dp[i + minLen[i]][r + minLen[i] - p.size()] = max(dp[i + minLen[i]][r + minLen[i] - p.size()], dp[i][r]+1);
            }
        }
    }

    cout << dp[s.size()][0];
    for(int i = 1; i <= s.size(); i++) {
        cout << " " << dp[s.size()][i];
    }
    cout << "\n";

    return 0;
}
