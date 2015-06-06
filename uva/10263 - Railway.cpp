#include <bits/stdc++.h>

using namespace std;

#define PI acos(-1.0)
#define EPS 1e-9

double toRadian(double deg) {return ((deg*PI)/180.0);}
double toDegree(double radian) {return ((radian*180.0)/PI);}

struct Point { //Integer Point
    double x, y;
    Point(){}
    Point(double _x, double _y):x(_x), y(_y){}

    bool operator < (Point other) const {
        if(fabs(x - other.x) > EPS)
            return x < other.x;
        return y < other.y;
    }

    bool operator == (Point other) const {
        return ((fabs(x - other.x) < EPS) && (fabs(y - other.y) < EPS));
    }
};

double pointDistaceSquared2D (Point a, Point b) {return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);}
double dist (Point a, Point b) {return sqrt(pointDistaceSquared2D(a, b));}
// rotate p by theta degrees CCW w.r.t origin (0, 0)
Point rotate(Point p, double theta) {
    double rad = toRadian(theta);
    return Point(p.x * cos(rad) - p.y * sin(rad),
                 p.x * sin(rad) + p.y * cos(rad));
}

struct line {double a, b, c;};
void pointsToLine(Point p1, Point p2, line &l) {
    if(fabs(p1.x-p2.x) < EPS) {
        l.a = 1.0; l.b = 0.0; l.c = -p1.x;
    } else {
        l.a = -(double)(p1.y-p2.y) / (p1.x-p2.x);
        l.b = 1.0;
        l.c = -(double)(l.a*p1.x)-p1.y;
    }
}

bool areParallel(line l1, line l2) {
    return (fabs(l1.a-l2.a) < EPS) && (fabs(l1.b-l2.b) < EPS);
}

bool areSame(line l1, line l2) {
    return areParallel(l1, l2) && (fabs(l1.c-l2.c) < EPS);
}

bool areIntersect(line l1, line l2, Point &p) {
    if(areParallel(l1, l2)) return false;
    p.x = (l2.b*l1.c-l1.b*l2.c) / (l2.a*l1.b-l1.a*l2.b);
    if(fabs(l1.b) > EPS) p.y = -(l1.a*p.x+l1.c);
    else                 p.y = -(l2.a*p.x+l2.c);
    return true;
}

struct vec {
    double x, y;
    vec(){}
    vec(double _x, double _y):x(_x), y(_y){}
};

vec toVec(Point a, Point b) {return vec(b.x - a.x, b.y - a.y);}
vec scale(vec v, double s) {return vec(v.x*s, v.y*s);}
Point translate(Point p, vec v) {return Point(p.x + v.x, p.y + v.y);}// translate p according to v
double dot(vec a, vec b) {return (a.x*b.x + a.y*b.y);}
double norm_sq(vec v) {return v.x*v.x + v.y*v.y;}

// returns the distance from p to the line defined by
// two points a and b (a and b must be different)
// the closest point is stored in the 4th parameter (byref)
double distToLine(Point p, Point a, Point b, Point &c) {
    // formula: c = a + u* ab
    vec ap = toVec(a, p), ab = toVec(a, b);
    double u = dot(ap, ab) / norm_sq(ab);
    c = translate(a, scale(ab, u));
    return dist(p, c);
}

// returns the distance from p to the line segment ab defined by
// two points a and b (still OK if a == b)
// the closest point is stored in the 4th parameter (byref)
double distToLineSegment(Point p, Point a, Point b, Point &c) {
    vec ap = toVec(a, p), ab = toVec(a, b);
    double u = dot(ap, ab) / norm_sq(ab);
    if (u < 0.0) {
        c = Point(a.x, a.y);
        return dist(p, a);
    }

    if(u > 1.0) {
        c = Point(b.x, b.y);
        return dist(p, b);
    }

    return distToLine(p, a, b, c);
}

double angle(Point a, Point o, Point b) { // returns angle aob in rad
    vec oa = toVec(o, a), ob = toVec(o, b);
    return acos(dot(oa, ob) / sqrt(norm_sq(oa) * norm_sq(ob)));
}

double cross(vec a, vec b) {return a.x*b.y - a.y*b.x;}
// note: to accept collinear points, we have to change the '> 0'
// returns true if point r is on the left side of line pq
bool ccw(Point p, Point q, Point r) {return cross(toVec(p, q), toVec(p, r)) > 0;}
// returns true if point r is on the same line as the line pq
bool collinear(Point p, Point q, Point r) {
    return fabs(cross(toVec(p, q), toVec(p, r))) < EPS;
}

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

//Given the intersection point p1, p2 and radius r find centers
bool circle2PtsRad(Point p1, Point p2, double r, Point &c) {
  double d2 = (p1.x - p2.x) * (p1.x - p2.x) +
              (p1.y - p2.y) * (p1.y - p2.y);
  double det = r * r / d2 - 0.25;
  if (det < 0.0) return false;
  double h = sqrt(det);
  c.x = (p1.x + p2.x) * 0.5 + (p1.y - p2.y) * h;
  c.y = (p1.y + p2.y) * 0.5 + (p2.x - p1.x) * h;
  return true;
}         // to get the other center, reverse p1 and p2

double circleCircumference(double r) {return 2.0*PI*r;}
double circleArea(double r){return PI*r*r;}
double circleSectorArea(double r, double theta) {
    return (circleArea(r)*theta)/360.0;
}

//Given three sides of a triangle
double inCircleRadius(double a, double b, double c) {
    double area = triangleArea(a, b, c);
    double s = trianglePerimeter(a, b, c);
    return (area/s);
}

//Given three sides of a triangle
double circumCircleRadius(double a, double b, double c) {
    double  A = triangleAngle(b, c, a);
    double  d = a / sin(A);
    return d*=0.5;
}

double coneArea(double h, double r) {return (PI*r*r*h)/3.0;}
double coneFrustumArea(double R, double r, double h) {return ((R*R+R*r+r*r)*PI*h)/3.0;}

int main() {
    //freopen("input.txt", "r", stdin);
    int n;
    double x, y;
    Point station, M, p1, p2, temp;

    while(scanf("%lf\n%lf", &x, &y) != EOF) {
        M = Point(x, y);

        double minDist, tempDist;
        scanf("%d", &n);

        scanf("%lf\n%lf", &x, &y); p1 = Point(x, y);
        for(int i = 1; i <= n; i++) {
            scanf("%lf\n%lf", &x, &y); p2 = Point(x, y);
            if(i == 1) {
                minDist = distToLineSegment(M, p1, p2, station);
            } else {
                tempDist = distToLineSegment(M, p1, p2, temp);
                if(tempDist + EPS < minDist) {
                    station = Point(temp.x, temp.y);
                    minDist = tempDist;
                }
            }

            p1 = Point(p2.x, p2.y);
        }

        printf("%0.4lf\n%0.4lf\n", station.x, station.y);
    }

    return 0;
}
