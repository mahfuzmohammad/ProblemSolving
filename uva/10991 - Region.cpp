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

//in radian
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
    int t;
    double r1, r2, r3;

    scanf("%d", &t);

    for(int i = 0; i < t; i++) {
        scanf("%lf %lf %lf", &r1, &r2, &r3);
        double  area = triangleArea(r1+r2, r1+r3, r2+r3);
        double  th1 = toDegree(triangleAngle(r1+r2, r1+r3, r2+r3)),
                th2 = toDegree(triangleAngle(r1+r2, r2+r3, r1+r3)),
                th3 = toDegree(triangleAngle(r2+r3, r1+r3, r1+r2));

        double  sec1 = circleSectorArea(r1, th1),
                sec2 = circleSectorArea(r2, th2),
                sec3 = circleSectorArea(r3, th3);

        printf("%0.6lf\n", area-(sec1+sec2+sec3));
    }

    return 0;
}
