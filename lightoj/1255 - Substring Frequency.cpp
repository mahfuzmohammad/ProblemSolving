#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>

#define pattsize 1000005

using namespace std;

int F[pattsize + 2];

void calc_failure_fuction(char pat[]) {
    //everything is 1 indexed
    int k, psize = strlen(pat);
    F[1] = 0; F[0] = 0;

    for(int i = 2; i <= psize; i++) {
        k = F[i - 1];
        while(true) {
            if(pat[k] == pat[i - 1]) {
                F[i] = k + 1;
                break;
            }

            if(k == 0) {F[i] = 0; break;}

            k = F[k];
        }
    }
}

int match(char txt[], char pat[]) {
    //everything is 1 indexed
    calc_failure_fuction(pat);
    int i = 0, j = 0, n = strlen(txt), m = strlen(pat), ans = 0;

    while(true) {
        if(j == n) break; //End of txt

        if(txt[j] == pat[i]) {
            i++; j++;
            if(i == m) {
                //match found
                ans++;
            }
        } else if(i > 0) {
            i = F[i];
        } else {
            j++;
        }
    }

    return ans;
}

int main() {
    //freopen("txtinput", "r", stdin);
    //freopen("kmp", "w", stdout);

    int T;
    char A[pattsize + 2], B[pattsize + 2];

    scanf("%d", &T);
    for(int i = 1; i <= T; i++) {
        memset(F, -1, sizeof(F));
        scanf("%s%s", A, B);
        printf("Case %d: %d\n", i, match(A, B));
    }

    return 0;
}
