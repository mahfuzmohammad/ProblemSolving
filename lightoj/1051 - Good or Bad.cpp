#include <bits/stdc++.h>

using namespace std;

enum TAG {BAD, GOOD, MIXED};

char str[55];
int dp[55][2][5][6];

int f(int pos, bool pvow, int v, int c, int& len) {
    if(v >= 3 || c >= 5) return BAD;
    if(pos >= len) {
        if(v >= 3 || c >= 5) return BAD;
        else return GOOD;
    }

    if(dp[pos][(int)pvow][v][c] != -1) return dp[pos][(int)pvow][v][c];

    int ret1, ret2;

    if(str[pos] == '?') {
        ret1 = f(pos+1, true, ((pvow)?v+1:1), 0, len);
        ret2 = f(pos+1, false, 0, ((!pvow)?c+1:1), len);
        if(ret1 == ret2) {
            return dp[pos][(int)pvow][v][c] = ret1;
        } else {
            return dp[pos][(int)pvow][v][c] = MIXED;
        }
    } else if(isVowel(str[pos])) {
        ret1 = f(pos+1, true, ((pvow)?v+1:1), 0, len);
        return dp[pos][(int)pvow][v][c] = ret1;
    }

    ret2 = f(pos+1, false, 0, ((!pvow)?c+1:1), len);
    return dp[pos][(int)pvow][v][c] = ret2;
}

int main() {
    //freopen("in", "r", stdin);
    int t, len, v, c;
    scanf("%d", &t);

    for(int i = 1; i <= t; i++) {
        v = 0, c = 0;
        scanf("%s", str);
        len = strlen(str);

        memset(dp, -1, sizeof dp);
        int ans = f(0, true, 0, c, len);

        printf("Case %d: ", i);
        if(ans == MIXED) {
            printf("MIXED\n");
        } else if (ans == BAD) {
            printf("BAD\n");
        } else {
            printf("GOOD\n");
        }

    }

    return 0;
}
