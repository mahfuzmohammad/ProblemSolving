//CF127A
//Geometry

#include <bits/stdc++.h>

using namespace std;

struct Point { //Integer Point
    int x, y;
    Point(){}
    Point(int _x, int _y):x(_x), y(_y){}
};

int pointDistaceSquared (Point a, Point b) {
    return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
}

int main() {
    int n, k;
    double ans = 0.0;
    Point a, b;
    scanf("%d %d", &n, &k);
    scanf("%d %d", &a.x, &a.y);

    for(int i = 1; i < n; i++) {
        scanf("%d %d", &b.x, &b.y);
        ans += sqrt(double(pointDistaceSquared(a, b)));
        a = b;
    }

    ans /= 50.0;
    ans *= double(k);
    printf("%0.7lf\n", ans);

    return 0;
}

