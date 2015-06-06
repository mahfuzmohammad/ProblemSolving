#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>

#define MAXN 500

using namespace std;

double dp[MAXN + 2][MAXN + 2];

void reset() {
    for(int i = 0; i <= MAXN; i++) {
        for(int j = 0; j <= MAXN; j++) {
            dp[i][j] = -1.0;
        }
    }
}

double calc(int R, int B) {
    //cout << R << " " << B << endl;
    if(R <= 0) return 1;
    if(B <= 0) return 0;

    if(dp[R][B] != -1.0) return dp[R][B];

    dp[R][B] = ( ( double(R) / double(R+B) ) * calc(R - 1, B - 1) ) + ( ( double(B) / double(R+B) ) * calc(R, B - 2) );
    //cout << dp[R][B] << endl;
    return dp[R][B];
}

int main() {
    int T, R, B;
    scanf( "%d", &T );
    reset();

    for(int i = 1; i <= T; i++) {
        //reset();
        //memset(dp, -1.0, sizeof(dp));
        scanf( "%d %d", &R, &B );

        printf( "Case %d: %0.7lf\n", i, calc(R, B) );
    }

    return 0;
}
