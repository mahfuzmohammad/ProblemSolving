#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>

#define PI acos(-1.0)

using namespace std;

int main()
{
    int T;
    double R, n, angle;

    scanf("%d", &T);

    for(int i = 1; i <= T; i++){
        scanf("%lf %lf", &R, &n);
        angle = (PI / n);
        printf("Case %d: %0.7lf\n", i, (sin(angle) / (1 + sin(angle))) * R);
    }

    return 0;
}
