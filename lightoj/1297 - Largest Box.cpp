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
    int T;
    double L, W, x1, x2;
    scanf("%d", &T);

    for(int i = 1; i <= T; i++){
        scanf("%lf %lf", &L, &W);
        x1 = ((W + L) + sqrt(pow(W + L, 2) - 3 * W * L)) / 6;
        x2 = ((W + L) - sqrt(pow(W + L, 2) - 3 * W * L)) / 6;
        printf("Case %d: %0.7lf\n", i, max((W - 2*x1)*(L - 2*x1)*x1, (W - 2*x2)*(L - 2*x2)*x2));
    }

    return 0;
}
