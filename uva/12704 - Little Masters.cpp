#include <bits/stdc++.h>

using namespace std;

int t;
double x, y, r;

double dist(double x, double y) {
    return sqrt(x*x + y*y);
}

int main() {

    scanf("%d", &t);

    for(int i = 0; i < t; i++) {
        scanf("%lf %lf %lf", &x, &y, &r);
        double d = dist(x, y);
        printf("%0.2lf %0.2lf\n", r - d, r+ d);
    }

    return 0;
}
