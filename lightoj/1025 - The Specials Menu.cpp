#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

long long dp[62][62][62];

void reset() {
    for(int i = 0; i <= 60; i++) {
        for(int j = 0; j <= 60; j++) {
            for(int k = 0; k <= 60; k++) {
                dp[i][j][k] = 0;
            }
        }
    }
}

int main() {
    #ifdef mahfuz
    freopen("input.txt", "r", stdin);
    #endif

    int T, wsize;
    long long cnt;
    string W;

    cin >> T;

    for(int i = 1; i <= T; i++) {
        reset();
        cin >> W;
        wsize = W.size(); cnt = 0;

        for(int j = 0; j < wsize; j++) {
            dp[1][j][j] = 1;

            for(int k = j + 1; k < wsize; k++) {
                dp[1][j][k] = dp[1][j][k - 1] + 1;
            }
        }

        for(int j = wsize - 2; j >= 0; j--) {
            for(int k = j + 1; k < wsize; k++) {
                if(W[j] == W[k]) {
                    dp[2][j][k] = 1 + dp[2][j][k - 1] + dp[2][j + 1][k] - dp[2][j + 1][k - 1];
                } else {
                    dp[2][j][k] = dp[2][j][k - 1] + dp[2][j + 1][k] - dp[2][j + 1][k - 1];
                }
            }
        }

        for(int len = 3; len <= wsize; len++) {
            for(int j = wsize - len; j >= 0; j--) {
                for(int k = j + len - 1; k < wsize; k++) {
                    if(W[j] == W[k]) {
                        dp[len][j][k] = dp[len - 2][j + 1][k - 1] + dp[len][j][k - 1] + dp[len][j + 1][k] - dp[len][j + 1][k - 1];
                    } else {
                        dp[len][j][k] = dp[len][j][k - 1] + dp[len][j + 1][k] - dp[len][j + 1][k - 1];
                    }
                }
            }
        }

        for(int len = 1; len <= wsize; len++) {
            cnt += dp[len][0][wsize - 1];
        }

        cout << "Case " << i << ": " << cnt << endl;
    }

    return 0;
}
