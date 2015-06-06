#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>

#define MAXN 100
#define INF  1 << 30

using namespace std;

int cost[MAXN + 2][MAXN + 2];

void reset() {
    for(int i = 0; i <= MAXN; i++) {
        for(int j = 0; j <= MAXN; j++) {
            cost[i][j] = INF;
        }
    }
}

int calc(string& str) {
    int strsize = str.size();

    for(int i = 0; i < strsize; i++) {
        cost[1][i] = 0;
    }

    for(int i = 0; i < strsize - 1; i++) {
        if(str[i] == str[i + 1])
            cost[2][i] = 0;
        else cost[2][i] = 1;
    }

    for(int len = 3; len <= strsize; len++) {
        for(int i = 0; i < strsize - len + 1; i++) {
            if(str[i] == str[i + len - 1]) {
                cost[len][i] = min(cost[len][i], cost[len - 2][i + 1]);
            } else {
                cost[len][i] = min(cost[len - 1][i], cost[len - 1][i + 1]) + 1;
            }
        }
    }

    return cost[strsize][0];
}


int main() {
    #ifdef mahfuz
    freopen("input.txt", "r", stdin);
    #endif

    int T;
    string str;

    cin >> T;

    for(int i = 1; i <= T; i++) {
        reset();
        cin >> str;
        cout << "Case " << i << ": " << calc(str) << endl;
    }

    return 0;
}
