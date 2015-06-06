#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

#define PI acos(0.0) * 2

using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);
    int T;
    double ox, oy, ax, ay, bx, by, r, x1, y1, x2, y2, b, O;
    scanf("%d", &T);

    for(int i = 1; i <= T; i++){
        scanf("%lf %lf %lf %lf %lf %lf", &ox, &oy, &ax, &ay, &bx, &by);
        x1 = fabs(ox - ax);
        y1 = fabs(oy - ay);
        x2 = fabs(ax - bx);
        y2 = fabs(ay - by);
        r = sqrt(x1*x1 + y1*y1);
        b = sqrt(x2*x2 + y2*y2);
        O = 1-((b*b)/(2*r*r));
        printf("Case %d: %0.6lf\n", i, r * acos(O));
    }

    return 0;
}
