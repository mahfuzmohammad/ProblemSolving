#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

#define PI acos(0.0) * 2

using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);
    int T, a, b;
    double ans, den;
    scanf("%d", &T);

    for(int i = 1; i <= T; i++){
        scanf("%d : %d", &a, &b);
        den = acos(double(a*a - b*b) / double(a*a + b*b)) * 0.5 * sqrt(double(a*a + b*b)) + a;
        ans = 200 / den;
        printf("Case %d: %0.7lf %0.7lf\n", i, a*ans, b*ans);
    }

    return 0;
}
