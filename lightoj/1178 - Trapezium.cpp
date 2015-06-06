#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
    int T;
    double a, b, c, d;
    cin >> T;

    for(int i = 1; i <= T; i++) {
        scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
        printf("Case %d: %.10lf\n", i, ( (c + a) * sqrt( (-c+a+b+d)*(-a+b+c+d)*(c-a+d-b)*(c-a+b-d) ) ) / (4 * fabs(a - c)) );
    }

    return 0;
}
