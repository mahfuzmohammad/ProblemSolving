#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
    if(!b) return a;
    return gcd(b, a%b);
}

int main() {
    int n;
    while(scanf("%d", &n) && (n != 0)) {
        int g = 0;
        for(int i = 1; i < n; i++) {
            for(int j = i+1; j <= n; j++) {
                g += gcd(max(i,j), min(i, j));
            }
        }

        printf("%d\n", g);
    }

    return 0;
}
