#include <bits/stdc++.h>

using namespace std;

double EPS = 1e-8;

int func (int x1, int y1, int x2, int y2, int x, int y) {
    return ( (y1-y2)*x - (x1-x2)*y + (x1*y2-x2*y1) );
}

bool getSlope(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
    return ((y1-y2)*(x3-x4) == (y3-y4)*(x1-x2));
}

double xcord (int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
    return double( (x3-x4)*(x1*y2-x2*y1)-(x1-x2)*(x3*y4-x4*y3) ) / double( (x1-x2)*(y3-y4)-(x3-x4)*(y1-y2) );
}

double ycord (int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
    return double( (x1*y2-x2*y1)*(y3-y4)-(y1-y2)*(x3*y4-x4*y3) ) / double( (x1-x2)*(y3-y4)-(x3-x4)*(y1-y2) );
}

bool isInside (int x1, int y1, int x2, int y2, int x, int y) {
    if(x1>x2) swap(x1, x2);
    if(y1>y2) swap(y1, y2);
    return ( ((x > x1) && (x < x2) && (y >= y1) && (y <= y2)) || ((x >= x1) && (x <= x2) && (y > y1) && (y < y2)) );
}

bool isOnBorderOrInside (int x1, int y1, int x2, int y2, int x, int y) {
    if(x1>x2) swap(x1, x2);
    if(y1>y2) swap(y1, y2);

    return ((x >= x1) && (x <= x2) && (y >= y1) && (y <= y2));
}

bool isSamePoint (int x1, int y1, int x2, int y2) {
    return ((x1 == x2) && (y1 == y2));
}

int main() {
    //freopen("in", "r", stdin);
    int n,
        x1, x2, x3, x4,
        y1, y2, y3, y4,
        s1, s2, s3, s4;

    double m1, m2;

    scanf("%d", &n);

    printf("INTERSECTING LINES OUTPUT\n");
    for(int i = 0; i < n; i++) {
        scanf("%d %d %d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);

        if(getSlope(x1, y1, x2, y2, x3, y3, x4, y4)) {
            if((func(x1, y1, x2, y2, x3, y3) == 0) && (func(x1, y1, x2, y2, x4, y4) == 0)) {
                printf("LINE\n");
            } else {
                printf("NONE\n");
            }

        } else {
            printf("POINT %0.2lf %0.2lf\n",
                    xcord(x1, y1, x2, y2, x3, y3, x4, y4)+EPS,
                    ycord(x1, y1, x2, y2, x3, y3, x4, y4)+EPS);
        }
    }

    printf("END OF OUTPUT\n");

    return 0;
}
