#include <bits/stdc++.h>

#define _INF 1 << 30

using namespace std;

string str, str2;
int size1, size2, mlen;

int dplen[32][32];
long long dp[32][32][64];

void reset() {
    for(int i = 0; i < 32; i++) {
        for(int j = 0; j < 32; j++) {
            dplen[i][j] = _INF;
        }
    }

    memset(dp, -1, sizeof dp);
}

int L(int i, int j) {
    if(i == size1 && j == size2) {
        return 0;
    }

    if(dplen[i][j] != _INF) return dplen[i][j];

    int temp = _INF;

    if(i < size1 && j >= size2) {
        temp = min(temp, 1 + L(i + 1, j));
    } else if (i >= size1 && j < size2) {
        temp = min(temp, 1 + L(i, j + 1));
    } else {
        if(str[i] == str2[j]) {
            temp = min(temp, 1 + L(i + 1, j + 1));
        } else {
            temp = min(temp, 1 + L(i + 1, j));
            temp = min(temp, 1 + L(i, j + 1));
        }
    }

    dplen[i][j] = temp;
    return temp;
}

long long F(int i, int j, int len) {
    if(len > mlen) {
        return 0;
    }

    if(i == size1 && j == size2) {
        if(len == mlen ) return 1;
        return 0 ;
    }

    if(dp[i][j][len] != -1) return dp[i][j][len];

    long long temp = 0;

    if(i < size1 && j >= size2) {
        temp += F(i + 1, j, len + 1);
    } else if(i >= size1 && j < size2) {
        temp += F(i, j + 1, len + 1);
    } else {
        if(str[i] == str2[j]) {
            temp += F(i + 1, j + 1, len + 1);
        } else {
            temp += F(i + 1, j, len + 1);
            temp += F(i, j + 1, len + 1);
        }
    }

    dp[i][j][len] = temp;
    return dp[i][j][len];
}

int main() {

    int T;

    cin >> T;

    for(int i = 1; i <= T; i++) {
        cin >> str >> str2;
        size1 = str.size();
        size2 = str2.size();

        reset();
        mlen = L(0, 0);
        cout << "Case " << i << ": " << mlen << " " << F(0, 0, 0) << endl;
    }

    return 0;
}
