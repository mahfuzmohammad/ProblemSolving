#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
    int T;
    double a, b, c, b2, ac;

    cin >> T;

    for(int i = 1; i <= T; i++) {
        scanf("%lf %lf %lf", &a, &b, &c);
        ac = a * c;
        b2 = b * b;

        if(b2 - ac <= 0){
            cout << "Case " << i << ": -1" << endl;
        } else {
            printf( "Case %d: %.10lf\n", i, ((2*b+c+a) / (b2 - ac)) * ac );
        }
    }

    return 0;
}
