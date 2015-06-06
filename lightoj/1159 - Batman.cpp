#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

#define MAXN 50

using namespace std;

int lcstbl[MAXN + 2][MAXN + 2][MAXN + 2];

int lcs(string& a, string& b, string& c) {
    int aSize = a.size(),
        bSize = b.size(),
        cSize = c.size();

    for(int i = 1; i <= aSize; i++) {
        for(int j = 1; j <= bSize; j++) {
            for(int k = 1; k <= cSize; k++) {
                if(a[i - 1] == b[j - 1] && a[i - 1] == c[k - 1]) {
                    lcstbl[i][j][k] = 1 + lcstbl[i - 1][j - 1][k - 1];
                } else {
                    lcstbl[i][j][k] = max( lcstbl[i - 1][j][k], max( lcstbl[i][j - 1][k], lcstbl[i][j][k - 1] ) );
                }
            }
        }
    }

    return lcstbl[aSize][bSize][cSize];
}

int main() {
    int T;
    string a, b, c;

    cin >> T;

    for(int i = 1; i <= T; i++) {
        cin >> a >> b >> c;
        cout << "Case " << i << ": " << lcs(a, b, c) << endl;
    }

    return 0;
}
