#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

#define MAXSIZE 100

using namespace std;

struct Point {
    int x, y;
    Point(){}
    Point(int a, int b):x(a), y(b){}
};

int dp[MAXSIZE + 2][MAXSIZE + 2];
vector<Point> in;

bool cmp (Point a, Point b) {
    return a.y < b.y;
}

int main() {
    int n, w, k, t, x, y;
    cin >> t;

    for(int i = 1; i <= t; i++) {
        in.clear();
        cin >> n >> w >> k;

        for(int j = 0; j < n; j++) {
            cin >> x >> y;
            in.push_back( Point(x, y) );
        }

        sort(in.begin(), in.end(), cmp);

        int maxsofar = 0, tempmax = 0;

        for(int j = n - 1; j >= 0; j--) {
            tempmax = 0;

            for(int l = j; l < n; l++) {
                if(in[l].y >= in[j].y && in[l].y <= in[j].y + w) {
                    tempmax++;
                }
            }

            maxsofar = max(maxsofar, tempmax);
            dp[1][j] = maxsofar;
        }


        for(int times = 2; times <= k; times++) {
            dp[times][n - 1] = dp[times - 1][n - 1];
            maxsofar = 0;

            for(int j = n - 2; j >= 0; j--) {
                tempmax = 0;
                for(int l = j; l < n - 1; l++) {
                    if(in[l].y >= in[j].y && in[l].y <= in[j].y + w) {
                        tempmax++;
                    }

                    maxsofar = max(maxsofar, tempmax + dp[times - 1][l + 1]);
                }

                dp[times][j] = maxsofar;
            }
        }

        cout << "Case " << i << ": " << dp[k][0] << endl;
    }

    return 0;
}
