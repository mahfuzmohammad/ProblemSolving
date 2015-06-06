#include <bits/stdc++.h>

using namespace std;

#define PI acos(-1.0)

struct Point { //Integer Point
    double x, y;
    Point(){}
    Point(double _x, double _y):x(_x), y(_y){}
};

double pointDistaceSquared2D (Point a, Point b) {return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);}
double pointDistace2D (Point a, Point b) {return sqrt(double(pointDistaceSquared2D(a, b)));}

double toRadian(double deg) {return ((deg*PI)/180.0);}
double toDegree(double radian) {return ((radian*180.0)/PI);}

double trianglePerimeter(double a, double b, double c) {return (a+b+c)*0.5;}
double triangleArea(double b, double h) {return (b*h)*0.5;}
double triangleArea(double a, double b, double c) {
    double s = trianglePerimeter(a, b, c);
    return sqrt( s*(s-a)*(s-b)*(s-c) );
}

//in radian
double triangleAngle(double a, double b, double c) {//angle opposite to line c
    double nume = a*a+b*b-c*c;
    double denom = 2.0*a*b;
    return acos(nume/denom);
}

double circleCircumference(double r) {return 2.0*PI*r;}
double circleArea(double r){return PI*r*r;}
double circleSectorArea(double r, double theta) {
    return (circleArea(r)*theta)/360.0;
}

int main() {
    //freopen("in", "r", stdin);
    double x1, y1, x2, y2, x3, y3;

    while(scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3) != EOF) {
        double  a = pointDistace2D(Point(x1, y1), Point(x2, y2)),
                b = pointDistace2D(Point(x1, y1), Point(x3, y3)),
                c = pointDistace2D(Point(x2, y2), Point(x3, y3));

        double  A = triangleAngle(b, c, a);
        double  d = a / sin(A);
        d*=0.5;

        printf("%0.2lf\n", circleCircumference(d));
    }

    return 0;
}
