#include <bits/stdc++.h>
#define _MAXN 5000

using namespace std;

vector<int> v;

int main() {

    int n, m, c;
    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; i++) {
        scanf("%d", &c);
        v.push_back(c);
    }

    sort(v.begin(), v.end());

    int l = 0, bl = 0, best = 0;

    for(int i = 0; i < n; i++) {
        int tempbest = 0;

        for(int j = 0; j < n; j++) {
            tempbest += !(v[j] == v[(j + l) % n]);
        }

        if(tempbest > best) {
            best = tempbest;
            bl = l;
        }

        l++;
    }

    printf("%d\n", best);
    for(int i = 0; i < n; i++) {
        printf("%d %d\n", v[i], v[(i + bl) % n]);
    }

    return 0;
}
