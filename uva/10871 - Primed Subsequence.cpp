#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
#include <sstream>
#include <algorithm>

#define MAXN 10000

using namespace std;

int seq[MAXN + 5], seqsum[MAXN + 5];

bool isPrime(int n){
    if(n == 2) return true;

    if(n % 2 == 0) return false;
    for(int i = 3; i * i <= n; i += 2) {
        if(n % i == 0) return false;
    }

    return true;
}

int main() {
    #ifdef mahfuz
    freopen("inputuva", "r", stdin);
    #endif

    int t, n, seqlen, l, r, s;
    scanf("%d", &t);

    for(int i = 0; i < t; i++) {
        seqlen = 10009;
        scanf("%d", &n);
        for(int j = 1; j <= n; j++) {
            scanf("%d", seq + j);
            seqsum[j] = seq[j] + seqsum[j - 1];
        }

        for(l = 1; l < n - 1; l++) {
            for(r = l + 1; r <= n && (r - l + 1) < seqlen; r++) {
                if(isPrime(seqsum[r] - seqsum[l - 1])) {
                    seqlen = (r - l + 1);
                    s = l;
                }
            }

            if(seqlen == 2) break;
        }

        if(seqlen == 10009) {
            printf("This sequence is anti-primed.\n");
        } else {
            printf("Shortest primed subsequence is length %d:", seqlen);
            for(int j = s; j < s + seqlen; j++) {
                printf(" %d", seq[j]);
            }
            printf("\n");
        }
    }

    return 0;
}
