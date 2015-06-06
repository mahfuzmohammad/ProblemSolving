#include <bits/stdc++.h>

using namespace std;

int cap[1005];
int t, n, m;

bool isPossible(int c) {
    int l = 0, r = 1;
    int need = 0;

    while(l <= n && r <= n) {
        if(cap[r] - cap[l] <= c) {
            r++;
        } else {
            l = r - 1;
            need++;
        }
    }

    return (need + 1 <= m);
}

int main() {
    //freopen("in.txt", "r", stdin);
    scanf("%d", &t);

    for(int i = 1; i <= t; i++) {
        int low = 0, high = 1000000000;
        scanf("%d %d", &n, &m);

        for(int j = 1; j <= n; j++) {
            scanf("%d", &cap[j]);
            low = max(low, cap[j]);
            cap[j] += cap[j - 1];
        }

        int best = high;
        while(low <= high) {
            int mid = (low + high) / 2;
            if(isPossible(mid)) {
                best = min(best, mid);
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        printf("Case %d: %d\n", i, best);
    }

    return 0;
}
