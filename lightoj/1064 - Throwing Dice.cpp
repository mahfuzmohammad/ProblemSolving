#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>

#define MAXX 150

using namespace std;

long long dp[MAXX + 2][MAXX + 2];

long long gcd(long long a, long long b) {
    if(b == 0) return a;

    return gcd(b, a % b);
}

int main() {
    #ifdef mahfuz
    freopen("input.txt", "r", stdin);
    #endif

    for (int j = 1; j <= 6 && j <= 150; j++)
        dp[1][j] = 1;

    for (int i = 2; i <= 24; i++)
        for (int j = 1; j <= 150; j++)
            for (int k = 1; k <= 6 && k < j; k++)
                dp[i][j] += dp[i-1][j-k];


    for(int i = 1; i <= 24; i++) {
        for(int j = 0; j <= 150; j++) {
            long long temp = 0;
            for(int k = max(1, j); k <= 150; k++) {
                temp += dp[i][k];
            }

            dp[i][j] = temp;
        }
    }

    /*for(int i = 0; i <= 4; i++) {
        for(int j = 0; j <= 12; j++) {
            printf("%6ld", dp[i][j]);
        }
        cout << endl;
    }*/

    int T, n, x;
    long long denum, num, gcdtemp;

    cin >> T;

    for(int i = 1; i <= T; i++) {
        cin >> n >> x;
        denum = dp[n][0];
        num = dp[n][x];

        gcdtemp = gcd(denum, num);
        denum /= gcdtemp;
        num /= gcdtemp;

        //cout << denum << " " << num << " " << gcdtemp << endl;
        if(denum == 1)
            cout << "Case " << i << ": " << num << endl;
        else
            cout << "Case " << i << ": " << num << "/" << denum << endl;
    }

    return 0;
}
