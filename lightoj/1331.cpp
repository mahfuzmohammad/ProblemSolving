#include <iostream>
#include <cstdio>
#include <cmath>


using namespace std;

#define PI acos(-1.0)

int main(){
    double r1, r2, r3, s, areat, area, sect1, sect2, sect3, /*PI = 3.1415926535897932,*/ a, b, c, a2, b2, c2, degree;
    int t;

    degree = 180.0 / PI;

    scanf("%d", &t);

    for(int i = 1; i <= t; i++){
        scanf("%lf %lf %lf", &r1, &r2, &r3);

        if(r1 == r2 && r2 == r3 && r3 == r1){

            s = r1 * 3;

            areat = sqrt( s * pow((r1), 3) );

            area = areat - ((PI * pow(r1, 2)) / 2);

            printf( "Case %d: %f\n", i, area);

        } else {
            s = (r1 + r2 + r3);
            a = r1 + r2;
            a2 = a * a;
            b = r2 + r3;
            b2 = b * b;
            c = r1 + r3;
            c2 = c * c;

            areat = sqrt( s * r1 * r2 * r3 );

            sect1 = acos( (a2 + c2 - b2) / (2 * a * c) ) * degree;
            sect2 = acos( (a2 + b2 - c2) / (2 * a * b) ) * degree;
            sect3 = 180.0 - sect1 - sect2;

            area = areat - ( ( PI / 360 )* ( (sect1 * pow(r1,2)) + (sect2 * pow(r2,2)) + (sect3 * pow(r3,2)) )  );

            printf( "Case %d: %lf\n", i, area);
        }


    }

    return 0;
}
