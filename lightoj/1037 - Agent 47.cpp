#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>

#define MAXN 15
#define INF 1 << 30

using namespace std;

int dp[(1 << MAXN) + 10];
int health[MAXN + 2];
int damage[MAXN + 2][MAXN + 2];

void reset() {
    for(int i = 0; i <= (1 << MAXN); i++) {
        dp[i] = INF;
    }
}

int calc(int N, int mask) {
    if(mask + 1 == (1 << N)) return 0;
    int power;

    if(dp[mask] != INF) return dp[mask];

    for(int i = 0; i < N; i++) {
        if( (mask & (1 << i)) == 0 ) {

            power = 1;
            for(int j = 0; j < N; j++) {
                if((mask & (1 << j)) == (1 << j)) {
                    power = max(power, damage[j][i]);
                }
            }

            int currShotNeeded = health[i] / power;
            if(health[i] % power != 0) currShotNeeded++;

            dp[mask] = min(dp[mask], currShotNeeded + calc(N, mask | (1 << i)));
        }
    }

    return dp[mask];
}

int main() {
    #ifdef mahfuz
    freopen("input.txt", "r", stdin);
    #endif

    int T, N;
    string str;

    cin >> T;

    for(int i = 1; i <= T; i++) {
        reset();
        cin >> N;

        for(int j = 0; j < N; j++) {
            cin >> health[j];
        }

        for(int j = 0; j < N; j++) {
            cin >> str;
            for(int k = 0; k < N; k++) {
                damage[j][k] = str[k] - '0';
            }
        }

        cout << "Case " << i << ": " << calc(N, 0) << endl;
    }

    return 0;
}
