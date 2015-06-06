#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <algorithm>

#define MAXN 30

using namespace std;

long long c[MAXN + 2][MAXN + 2];

void reset()
{
    for(int i = 0; i <= MAXN; i++)
        for(int j = 0; j <= MAXN; j++)
            c[i][j] = 0;
}

void nPr(int n)
{
    reset();
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= i; j++){
            if(j == 0) c[i][j] = 1;
            else {
                c[i][j] = c[i][j - 1] * (i + 1 - j);
            }
        }
    }
}


int main()
{
    int T, n, k;
    scanf("%d", &T);
    nPr(MAXN);

    for(int i = 1; i <= T; i++){
        scanf("%d %d", &n, &k);
        printf("Case %d: %ld\n", i, ((k > 30)?0:((k == 0)?1:(c[n][k] / c[k][k]) * c[n][k])));
    }

    return 0;
}
