//UVA 11805 - Bafana Bafana.cpp

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);
    int T, N, K, P, r;
    scanf("%d", &T);

    for(int i = 1; i <= T; i++){
        scanf("%d %d %d", &N, &K, &P);
        r = (K + P) % N;
        printf("Case %d: %d\n", i, ((r == 0)?N:r));
    }

    return 0;
}
