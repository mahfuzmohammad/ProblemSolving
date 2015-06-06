#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>

#define MAXN 15
#define INF  1 << 30

using namespace std;

struct Point {
    int x, y;
    Point(){}
    Point(int a, int b):x(a), y(b){}
};

int dp[18][(1 << MAXN) + 10];

void reset() {
    for(int i = 0; i <= (1 << MAXN); i++) {
    for (int j = 0; j <= MAXN; ++j) {
        	dp[j][i] = INF;
	}
    }
}

vector<Point> goldPoint;
Point start;

int getDist(Point a, Point b) {
    return max( abs(a.x - b.x), abs(a.y - b.y) );
}

int calc(int N, int mask, int prev) {
    if(N == 0) return 0;

    if(mask + 1 == (1 << N)) {
        dp[prev+1][mask] = min(dp[prev+1][mask], getDist(goldPoint[prev], start));
        return dp[prev+1][mask];
    }

    if(dp[prev+1][mask] != INF) return dp[prev+1][mask];

    for(int i = 0; i < N; i++) {
        if((mask & (1 << i)) == 0) {
            int cost;

            if(prev == -1) cost = getDist(start, goldPoint[i]);
            else cost = getDist(goldPoint[prev], goldPoint[i]);

            dp[prev+1][mask] = min(dp[prev+1][mask], cost + calc(N, mask | (1 << i), i));
        }
    }

    return dp[prev+1][mask];
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output", "w", stdout);
    int T, n, m;
    char ch;

    cin >> T;

    for(int i = 1; i <= T; i++) {
        reset();
        goldPoint.clear();
        cin >> m >> n;

        for(int k = 0; k < m; k++) {
            for(int l = 0; l < n; l++) {
                cin >> ch;
                if(ch == 'g') {
                    goldPoint.push_back(Point(l, k));
                } else if(ch == 'x') {
                    start.x = l;
                    start.y = k;
                }
            }
        }

        int ans = calc(goldPoint.size(), 0, -1);
        cout << "Case " << i << ": " << ans << endl;
    }

    return 0;
}

