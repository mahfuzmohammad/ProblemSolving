//In the name of Allah, most Gracious, most Compassionate
#include <bits/stdc++.h>

using namespace std;

#define vlong long long
#define isBitOn(X,i) (X>>i)&1

const int maxbit = 63;

vlong C[maxbit + 2][maxbit + 2];

bool iseqKbit(vlong x, int k) {
    int temp = 0;
    for(int i = 0; i <= maxbit; i++)
        temp += isBitOn(x, i);
    return (temp == k);
}

vlong cntBits(vlong x, int k) {
    vlong cnt = iseqKbit(x, k);
    for(int i = maxbit; i >= 0 && k >= 0; i--) {
        if(isBitOn(x, i))
            cnt += C[i][k--];
    }

    return cnt;
}

int main() {

    C[0][0] = 1;
    for(int i = 1; i <= maxbit; i++) {
        for(int j = 0; j <= i; j++) {
            C[i][j] = C[i - 1][j] + ((j)?C[i - 1][j - 1]:0);
        }
    }

    vlong m;
    int k;

    scanf("%I64d %d", &m, &k);
    vlong l = 1, r = 1000000000000000007L;

    while (l < r) {
        vlong mid = (l + r) / 2L;
        if(cntBits(2*mid, k) - cntBits(mid, k) < m)
            l = mid + 1;
        else r = mid;
    }

    printf("%I64d\n", l);

    return 0;
}
