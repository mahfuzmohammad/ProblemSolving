#include <bits/stdc++.h>

using namespace std;

int main() {
    int q, n, m, a, b;

    while(scanf("%d", &q)) {
        if(!q) break;
        scanf("%d %d", &n, &m);

        for(int i = 0; i < q; i++) {
            scanf("%d %d", &a, &b);
            if(a == n || b == m) {
                printf("divisa\n");
            } else if(b > m) {
                if(a < n) {
                    printf("NO\n");
                } else {
                    printf("NE\n");
                }
            } else if(b < m) {
                if(a < n) {
                    printf("SO\n");
                } else {
                    printf("SE\n");
                }
            }
        }
    }

    return 0;
}
