#include <bits/stdc++.h>

using namespace std;

#define PI acos(-1.0)
#define EPS 1e-9
#define EARTH_RAD (6371009) // in meters

double toRadian(double deg) {return ((deg*PI)/180.0);}
double toDegree(double radian) {return ((radian*180.0)/PI);}
double handleNegZero(double x) {return ((abs(x) < EPS)?0.0:x);}

struct point_i { int x, y;     // whenever possible, work with point_i
  point_i() { x = y = 0; }                      // default constructor
  point_i(int _x, int _y) : x(_x), y(_y) {} };         // user-defined

struct Point { //Integer Point
    double x, y;
    Point(){}
    Point(double _x, double _y):x(_x), y(_y){}

    bool operator < (const Point &p) const {
        if(abs(x - p.x) <= EPS) return ((y - p.y) <= EPS);
        return ((x - p.x) <= EPS);
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

// Given three colinear points p, q, r, the function checks if
// point q lies on line segment 'pr'
bool onSegment(Point p, Point q, Point r)
{
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
       return true;

    return false;
}

// To find orientation of ordered triplet (p, q, r).
// The function returns following values
// 0 --> p, q and r are colinear
// 1 --> Clockwise
// 2 --> Counterclockwise
int orientation(Point p, Point q, Point r)
{
    // See 10th slides from following link for derivation of the formula
    // http://www.dcs.gla.ac.uk/~pat/52233/slides/Geometry1x1.pdf
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);

    if (val == 0) return 0;  // colinear

    return (val > 0)? 1: 2; // clock or counterclock wise
}

// The main function that returns true if line segment 'p1q1'
// and 'p2q2' intersect.
bool LineSegmentIntersect(Point p1, Point q1, Point p2, Point q2)
{
    // Find the four orientations needed for general and
    // special cases
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);

    // General case
    if (o1 != o2 && o3 != o4)
        return true;

    // Special Cases
    // p1, q1 and p2 are colinear and p2 lies on segment p1q1
    if (o1 == 0 && onSegment(p1, p2, q1)) return true;

    // p1, q1 and p2 are colinear and q2 lies on segment p1q1
    if (o2 == 0 && onSegment(p1, q2, q1)) return true;

    // p2, q2 and p1 are colinear and p1 lies on segment p2q2
    if (o3 == 0 && onSegment(p2, p1, q2)) return true;

     // p2, q2 and q1 are colinear and q1 lies on segment p2q2
    if (o4 == 0 && onSegment(p2, q1, q2)) return true;

    return false; // Doesn't fall in any of the above cases
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

double trianglePerimeter(double a, double b, double c) {return (a+b+c);}
double triangleArea(double b, double h) {return (b*h)*0.5;}
double triangleArea(double a, double b, double c) {
    double s = trianglePerimeter(a, b, c)*0.5;
    return sqrt( s*(s-a)*(s-b)*(s-c) );
}

double triangleAreaFromMedian(double med1, double med2, double med3) { //given three median
    double h = (med1+med2+med3) * 0.5;
    return ((4.0/3.0) * sqrt(h*(h-med1)*(h-med2)*(h-med3)));
}

//in radian
double triangleAngle(double a, double b, double c) {//angle opposite to line c
    double nume = a*a+b*b-c*c;
    double denom = 2.0*a*b;
    return acos(nume/denom);
}

int insideCircle(point_i p, point_i c, int r) { // all integer version
  int dx = p.x - c.x, dy = p.y - c.y;
  int Euc = dx * dx + dy * dy, rSq = r * r;             // all integer
  return Euc < rSq ? 0 : Euc == rSq ? 1 : 2;
} //inside/border/outside

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

double cordlen(double angle, double r) {
    return 2.0 * r * sin(angle / 2.0);
}

double circleCircumference(double r) {return 2.0*PI*r;}
double circleArea(double r){return PI*r*r;}
double circleSectorArea(double r, double theta) {
    return (circleArea(r)*theta)/360.0;
}

double areaOfRegionEnclosedByThreeTouchingCircle(double r1, double r2, double r3) {
    double s = trianglePerimeter(r1, r2, r3);
    double a = r1 + r2;
    double a2 = a * a;
    double b = r2 + r3;
    double b2 = b * b;
    double c = r1 + r3;
    double c2 = c * c;

    double areat = sqrt( s * r1 * r2 * r3 );

    double sect1 = toDegree(acos( (a2 + c2 - b2) / (2 * a * c) ));
    double sect2 = toDegree(acos( (a2 + b2 - c2) / (2 * a * b) ));
    double sect3 = 180.0 - sect1 - sect2;

    double area = areat - ( ( PI / 360 )* ( (sect1 * pow(r1,2)) + (sect2 * pow(r2,2)) + (sect3 * pow(r3,2)) )  );
    return area;
}

//Given three sides of a triangle
double inCircleRadius(double a, double b, double c) {
    double area = triangleArea(a, b, c);
    double s = trianglePerimeter(a, b, c)*0.5;
    return (area/s);
}

//Given three sides of a triangle
double circumCircleRadius(double a, double b, double c) {
    double  A = triangleAngle(b, c, a);
    double  d = a / sin(A);
    return d*=0.5;
}

Point centerOfCircumCircle(Point A, Point B, Point C) {
    double D = 2.0 * (A.x * (B.y - C.y) + B.x * (C.y - A.y) + C.x * (A.y - B.y));
    double Uy = ((A.x*A.x+A.y*A.y)*(C.x-B.x)+(B.x*B.x+B.y*B.y)*(A.x-C.x)+(C.x*C.x+C.y*C.y)*(B.x-A.x)) / D;
    double Ux = ((A.x*A.x+A.y*A.y)*(B.y-C.y)+(B.x*B.x+B.y*B.y)*(C.y-A.y)+(C.x*C.x+C.y*C.y)*(A.y-B.y)) / D;
    return Point(Ux, Uy);
}

double coneArea(double h, double r) {return (PI*r*r*h)/3.0;}
double coneFrustumArea(double R, double r, double h) {return ((R*R+R*r+r*r)*PI*h)/3.0;}

//Polygon
// returns the perimeter, which is the sum of Euclidian distances
// of consecutive line segments (polygon edges)
double perimeter(const vector<Point> &P) {
  double result = 0.0;
  for (int i = 0; i < (int)P.size()-1; i++)  // remember that P[0] = P[n-1]
    result += dist(P[i], P[i+1]);
  return result; }

// returns the area, which is half the determinant
double area(const vector<Point> &P) {
  double result = 0.0, x1, y1, x2, y2;
  for (int i = 0; i < (int)P.size()-1; i++) {
    x1 = P[i].x; x2 = P[i+1].x;
    y1 = P[i].y; y2 = P[i+1].y;
    result += (x1 * y2 - x2 * y1);
  }
  return fabs(result) / 2.0; }

// returns true if we always make the same turn while examining
// all the edges of the polygon one by one
bool isConvex(const vector<Point> &P) {
  int sz = (int)P.size();
  if (sz <= 3) return false;   // a point/sz=2 or a line/sz=3 is not convex
  bool isLeft = ccw(P[0], P[1], P[2]);               // remember one result
  for (int i = 1; i < sz-1; i++)            // then compare with the others
    if (ccw(P[i], P[i+1], P[(i+2) == sz ? 1 : i+2]) != isLeft)
      return false;            // different sign -> this polygon is concave
  return true; }                                  // this polygon is convex

// returns true if point p is in either convex/concave polygon P
bool inPolygon(Point pt, const vector<Point> &P) {
  if ((int)P.size() == 0) return false;
  double sum = 0;    // assume the first vertex is equal to the last vertex
  for (int i = 0; i < (int)P.size()-1; i++) {
    if (ccw(pt, P[i], P[i+1]))
         sum += angle(P[i], pt, P[i+1]);                   // left turn/ccw
    else sum -= angle(P[i], pt, P[i+1]); }                 // right turn/cw
  return fabs(fabs(sum) - 2*PI) < EPS; }

// line segment p-q intersect with line A-B.
Point lineIntersectSeg(Point p, Point q, Point A, Point B) {
  double a = B.y - A.y;
  double b = A.x - B.x;
  double c = B.x * A.y - A.x * B.y;
  double u = fabs(a * p.x + b * p.y + c);
  double v = fabs(a * q.x + b * q.y + c);
  return Point((p.x * v + q.x * u) / (u+v), (p.y * v + q.y * u) / (u+v)); }

// cuts polygon Q along the line formed by Point a -> Point b
// (note: the last Point must be the same as the first Point)
vector<Point> cutPolygon(Point a, Point b, const vector<Point> &Q) {
  vector<Point> P;
  for (int i = 0; i < (int)Q.size(); i++) {
    double left1 = cross(toVec(a, b), toVec(a, Q[i])), left2 = 0;
    if (i != (int)Q.size()-1) left2 = cross(toVec(a, b), toVec(a, Q[i+1]));
    if (left1 > -EPS) P.push_back(Q[i]);       // Q[i] is on the left of ab
    if (left1 * left2 < -EPS)        // edge (Q[i], Q[i+1]) crosses line ab
      P.push_back(lineIntersectSeg(Q[i], Q[i+1], a, b));
  }
  if (!P.empty() && !(P.back() == P.front()))
    P.push_back(P.front());        // make P's first Point = P's last Point
  return P; }

// Returns a list of points on the convex hull in counter-clockwise order.
// Note: the last point in the returned list is the same as the first one.
// Uses 'Monotone Chain Algorithm', Runtime Complexity: O(n log n)
vector<Point> convex_hull(vector<Point> P)
{
	int n = P.size(), k = 0;
	vector<Point> H(2*n);

	// Sort points lexicographically
	sort(P.begin(), P.end());

	// Build lower hull
	for (int i = 0; i < n; ++i) {
		while (k >= 2 && !ccw(H[k-2], H[k-1], P[i])) k--;
		H[k++] = P[i];
	}

	// Build upper hull
	for (int i = n-2, t = k+1; i >= 0; i--) {
		while (k >= t && !ccw(H[k-2], H[k-1], P[i])) k--;
		H[k++] = P[i];
	}

	H.resize(k);
	return H;
}

double gcDistance(Point A, Point B) {
  double pLat = A.x, pLong = A.y, qLat = B.x, qLong = B.y, radius = EARTH_RAD;
  pLat *= PI / 180; pLong *= PI / 180;
  qLat *= PI / 180; qLong *= PI / 180;
  return radius * acos(cos(pLat)*cos(pLong)*cos(qLat)*cos(qLong) +
                       cos(pLat)*sin(pLong)*cos(qLat)*sin(qLong) +
                       sin(pLat)*sin(qLat));
}

Point GPSto2DPoint(double lat, double lon) {
    double mapW = 3600.0, mapH = 3600.0;
    double x = (lon+180.0)*(mapW/360.0);
    double latRad = toRadian(lat);
    double mercN = log(tan((PI/4.0)+(latRad / 2.0)));
    double y = (mapH / 2.0) - (mapW * mercN/(2.0*PI));
    return Point(x, y);
}

int main() {

    return 0;
}

/**
Note:

Vector representation of line
=============================
P(t) = a + u * t

Here,   max_t = 1 & min_t = 0
        u = direction vector
        a = displacement vector
        P(t) = the point for a value of 't'

Vector representation of circle
===============================

x = cx + r * cos(theta)
y = cy + r * sin(theta)

(cx, cy) = coordinate of center
r = radius

**/
