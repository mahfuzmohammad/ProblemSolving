#include <bits/stdc++.h>
#define _MAXN 200000
#define ll long long

using namespace std;

int n, m, cmd, p, x;
ll  cap[_MAXN + 5],
    val[_MAXN + 5];

int nextpos[_MAXN + 5];

bool overflow[_MAXN + 5];

int dropWaterAt (int pos, ll amnt) {

    if(pos > n) return n + 1;

    if(overflow[pos]) {

        int next = nextpos[pos];
        int droped = dropWaterAt(next, amnt);
        nextpos[pos] = droped;

    } else {

        val[pos] += amnt;
        if(val[pos] > cap[pos]) {
            ll extra = val[pos] - cap[pos];
            val[pos] = cap[pos];
            overflow[pos] = true;
            nextpos[pos] = dropWaterAt(pos + 1, extra);
        }

    }

    return nextpos[pos];
}

int main() {

    scanf("%d", &n);

    for(int i = 1; i <= n; i++) {
        scanf("%d", &cap[i]);
        nextpos[i] = i;
    }

    scanf("%d", &m);

    for(int i = 0; i < m; i++) {
        scanf("%d", &cmd);

        if(cmd == 1) {
            scanf("%d %d", &p, &x);
            nextpos[p] = dropWaterAt(nextpos[p], x);
        } else {
            scanf("%d", &p);
            printf("%I64d\n", val[p]);
        }
    }

    return 0;
}
