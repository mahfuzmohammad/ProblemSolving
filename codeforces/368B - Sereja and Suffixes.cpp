//In the name of Allah, most Gracious, most Compassionate

#include <bits/stdc++.h>

using namespace std;

#define _MAXN 100000

int arr[_MAXN + 5],
    dp[_MAXN + 5];

bool flag[_MAXN + 5];

int main() {
    int n, m, q;
    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for(int i = n - 1; i >= 0; i--) {
        if(!flag[arr[i]]) {
            dp[i]++;
            flag[arr[i]] = true;
        }

        dp[i] += dp[i + 1];
    }

    for(int i = 0; i < m; i++) {
        scanf("%d", &q);
        printf("%d\n", dp[q - 1]);
    }

    return 0;
}
