#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>

#define PI acos(-1.0)

using namespace std;

int main()
{
    int T;
    double r1, r2, h, p, r;
    cin >> T;

    for(int i = 1; i <= T; i++){
        cin >> r1 >> r2 >> h >> p;
        r = r2 + (r1 - r2)*(p / h);
        printf("Case %d: %0.7lf\n", i, ((PI * p * (r*r + r*r2 + r2*r2)) / 3));
    }

    return 0;
}
