#include <bits/stdc++.h>
#define _MOD 100000000

using namespace std;

int dp[105][105][12][12];

int func(int f, int h, int fl, int hl, int& mfl, int& mhl) {
    /*cout << f << " " << h << " " << fl << " " << hl << endl;*/
    if( fl < 0 || hl < 0 || f < 0 || h < 0) return 0;
    if( (f == 0 && h == 0) ) {return 1;}

    if(dp[f][h][fl][hl] != -1) return dp[f][h][fl][hl];

    int temp = 0;
    temp += func(f - 1, h, fl - 1, mhl, mfl, mhl);
    temp %= _MOD;
    temp += func(f, h - 1, mfl, hl - 1, mfl, mhl);
    temp %= _MOD;

    dp[f][h][fl][hl] = temp;
    return dp[f][h][fl][hl];
}

int main() {
    int f, h, fl, hl;

    scanf("%d %d %d %d", &f, &h, &fl, &hl);
    memset(dp, -1, sizeof dp);
    printf("%d\n", func(f, h, fl, hl, fl, hl));

    return 0;
}
