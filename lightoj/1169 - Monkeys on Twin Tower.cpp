#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>

#define MAXN 1000
#define INF 1 << 30

using namespace std;

int dp[3][MAXN + 2],
    timeleft[MAXN + 2],
    timeright[MAXN + 2],
    jumplefttoright[MAXN + 2],
    jumprighttoleft[MAXN + 2];

void reset() {
    for(int i = 0; i <= MAXN; i++) {
        dp[0][i] = INF;
        dp[1][i] = INF;
    }
}

int calc(int curr, int n, int ctower) {
    if(curr == n - 1) {
        if(ctower == 0) return timeleft[curr];

        return timeright[curr];
    }

    if(dp[ctower][curr] != INF) return dp[ctower][curr];

    int cost;

    if(ctower == 0) {
        cost = timeleft[curr] + min( calc(curr + 1, n, 0), jumplefttoright[curr + 1] + calc(curr + 1, n, 1) );
    } else {
        cost = timeright[curr] + min( calc(curr + 1, n, 1), jumprighttoleft[curr + 1] + calc(curr + 1, n, 0) );
    }

    dp[ctower][curr] = min(dp[ctower][curr], cost);

    return dp[ctower][curr];
}

int main() {
    int T, n;
    cin >> T;

    for(int i = 1; i <= T; i++) {
        reset();
        cin >> n;

        for(int j = 0; j < n; j++) {
            cin >> timeleft[j];
        }

        for(int j = 0; j < n; j++) {
            cin >> timeright[j];
        }

        for(int j = 1; j < n; j++) {
            cin >> jumplefttoright[j];
        }

        for(int j = 1; j < n; j++) {
            cin >> jumprighttoleft[j];
        }

        cout << "Case " << i << ": " << min(calc(0, n, 0), calc(0, n, 1)) << endl;
    }

    return 0;
}
