#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main(){

    long ax, ay, bx, by, cx, cy, dx, dy, ab2, bc2;
    double s1, s2, angle, ab_bc, small;

    int t;

    cin >> t;

    for(int i = 1; i <= t; i++){

        cin >> ax >> ay >> bx >> by >> cx >> cy;

        dx = ax + cx - bx;
        dy = ay + cy - by;

        s1 = pow((bx - dx), 2) + pow((by - dy), 2);
        s2 = pow((ax - cx), 2) + pow((ay - cy), 2);

        ab2 = pow((bx - ax), 2) + pow((by - ay), 2);

        bc2 = pow((bx - cx), 2) + pow((by - cy), 2);


        ab_bc = sqrt(ab2 * bc2);

        small = ( s1 < s2 ) ? s1 : s2;

        angle = pow(ab_bc, 2) - pow( ( bc2 + ab2 - small ) / 2, 2 );

        printf("Case %d: %d %d %.0lf\n", i, dx, dy, sqrt(angle));

    }

    return 0;
}
