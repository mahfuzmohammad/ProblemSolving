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

bool pal[MAXN + 2][MAXN + 2];
int  minPalCut[MAXN + 2][MAXN + 2];

void reset() {
    for(int i = 0; i <= MAXN; i++) {
        for(int j = 0; j <= MAXN; j++) {
            pal[i][j] = false;
            minPalCut[i][j] = INF;
        }
    }
}


void genPals(string& str, int sSize) {
    int strSize = sSize;

    for(int i = 0; i < strSize; i++) {
        pal[i][i] = true;
    }

    for(int i = 0; i < strSize - 1; i++) {
        if(str[i] == str[i + 1]) {
            pal[i][i + 1] = true;
            minPalCut[i][i + 1] = 0;
        }
    }

    for(int len = 3; len <= strSize; len++) {
        for(int i = 0; i < strSize - len + 1; i++) {
            if(str[i] == str[i + len - 1] && pal[i + 1][i + len - 2]) {
                pal[i][i + len - 1] = true;
                minPalCut[i][i + len - 1] = 0;
            }
        }
    }
}


int minCutPal(int ssize) {
    for(int i = 0; i < ssize; i++) {
        minPalCut[i][i] = 0;
    }

    for(int i = 0; i < ssize; i++) {
        for(int j = 0; j < i; j++) {
            if(pal[0][i]) {
                minPalCut[0][i] = 0;
                break;
            } else {
                minPalCut[0][i] = min(minPalCut[0][i], minPalCut[0][j] + 1 + minPalCut[j + 1][i]);
            }
        }
    }

    return minPalCut[0][ssize - 1];
}


int main() {
    #ifdef mahfuz
    freopen("input.txt", "r", stdin);
    #endif

    int T, sSize;
    string s;

    cin >> T;

    for(int i = 1; i <= T; i++) {
        reset();
        cin >> s;
        sSize = s.size();
        genPals(s, sSize);
        cout << "Case " << i << ": " << minCutPal(sSize) + 1 << endl;
    }

    return 0;
}
