#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>

#define MAXN 14
#define INF 1 << 30

using namespace std;

int dp[(1 << MAXN) + 10];

void reset() {
    for(int i = 0; i <= (1 << MAXN); i++) {
        dp[i] = INF;
    }
}

int input[MAXN + 2][MAXN + 2];

int calc(int N, int mask) {
    if(mask + 1 == (1 << N)) return 0;

    if(dp[mask] != INF) return dp[mask];

    for(int i = 0; i < N; i++) {
        if((mask & (1 << i)) == 0) {
            int surcharge = 0;

            for(int j = 0; j < N; j++) {
                if((mask & (1 << j)) == (1 << j)) {
                    surcharge += input[i][j];
                }
            }

            dp[mask] = min( dp[mask], surcharge + input[i][i] + calc(N, mask | (1 << i)) );
        }
    }

    return dp[mask];
}

int main() {
    #ifdef mahfuz
    freopen("input.txt", "r", stdin);
    #endif

    int T, n;

    cin >> T;

    for(int i = 1; i <= T; i++) {
        reset();
        cin >> n;

        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                cin >> input[j][k];
            }
        }

        cout << "Case " << i << ": " << calc(n, 0) << endl;
    }

    return 0;
}
