#include <bits/stdc++.h>

using namespace std;

#define PI acos(-1.0)

struct Point { //Integer Point
    int x, y;
    Point(){}
    Point(int _x, int _y):x(_x), y(_y){}
};

int pointDistaceSquared2D (Point a, Point b) {return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);}
double pointDistace2D (Point a, Point b) {return sqrt(double(pointDistaceSquared2D(a, b)));}

double toRadian(double deg) {return ((deg*PI)/180.0);}
double toDegree(double radian) {return ((radian*180.0)/PI);}

double trianglePerimeter(double a, double b, double c) {return (a+b+c)*0.5;}
double triangleArea(double b, double h) {return (b*h)*0.5;}
double triangleArea(double a, double b, double c) {
    double s = trianglePerimeter(a, b, c);
    return sqrt( s*(s-a)*(s-b)*(s-c) );
}

double triangleAngle(double a, double b, double c) {//angle opposite to line c
    double nume = a*a+b*b-c*c;
    double denom = 2.0*a*b;
    return acos(nume/denom);
}

double circlePerimeter(double r) {return 2.0*PI*r;}
double circleArea(double r){return PI*r*r;}
double circleSectorArea(double r, double theta) {
    return (circleArea(r)*theta)/360.0;
}

int main() {
    //freopen("in", "r", stdin);
    int t, x1, y1, r1, x2, y2, r2;
    scanf("%d", &t);

    for(int i = 1; i <= t; i++) {
        scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
        double  c = pointDistace2D(Point(x1, y1), Point(x2, y2));

        if(double(r1+r2) <= c) {
            printf("Case %d: %0.10lf\n", i, 0.0);
        } else if (c+min(r1, r2) <= max(r1, r2)) {
            //cout << "TEST1" << endl;
            printf("Case %d: %0.10lf\n", i, circleArea(min(r1, r2)));
        } else if (c < max(r1, r2) && (r1 != r2)) {
            double  taWhole = triangleArea(r1, r2, c),
                    h = (taWhole / c)*4.0,
                    taSmall = triangleArea(min(r1, r2), min(r1, r2), h),
                    taLarge = triangleArea(max(r1, r2), max(r1, r2), h),
                    thetaSmall = 360.0 - toDegree(triangleAngle(min(r1, r2), min(r1, r2), h)),
                    sectorSmall = circleSectorArea(min(r1, r2), thetaSmall),
                    thetaLarge = toDegree(triangleAngle(max(r1, r2), max(r1, r2), h)),
                    sectorLarge = circleSectorArea(max(r1, r2), thetaLarge);

            printf("Case %d: %0.10lf\n", i, sectorLarge+taSmall+sectorSmall-taLarge );
        } else {
            //cout << "TEST3" << endl;
            double  taWhole = triangleArea(r1, r2, c),
                    h = (taWhole / c)*4.0,
                    taR1 = triangleArea(r1, r1, h),
                    taR2 = triangleArea(r2, r2, h),
                    theta1 = toDegree(triangleAngle(r1, c, r2))*2.0,
                    sector1 = circleSectorArea(r1, theta1),
                    theta2 = toDegree(triangleAngle(r2, c, r1))*2.0,
                    sector2 = circleSectorArea(r2, theta2);

            printf("Case %d: %0.10lf\n", i, (sector1-taR1)+(sector2-taR2));
        }

    }

    return 0;
}
