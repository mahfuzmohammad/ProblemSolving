#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main(){

    double v1, v2, v3, a1, a2, t1, t2, tMax, d, distanceTravelled, s1, s2;
    int t;

    cin >> t;

    for(int i = 1; i <= t; i++){

        scanf( "%lf %lf %lf %lf %lf", &v1, &v2, &v3, &a1, &a2 );

        //cin >> v1 >> v2 >> v3 >> a1 >> a2;

        t1 = v1 / a1;
        t2 = v2 / a2;

        tMax = (t1 >= t2) ? t1 : t2;

        distanceTravelled = tMax * v3;

        //d = ( ( pow(v1, 2) / a1 ) + ( pow(v2, 2) / a2 )  ) * (0.5);

        d = ( ( t1 * v1 ) + ( t2 * v2 )  ) / 2;


        printf( "Case %d: %.10lf %.10lf\n", i, d, distanceTravelled );
    }

    return 0;
}
