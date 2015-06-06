#include <iostream>
#include <cstdio>
#include <cmath>
#define PI 2 * acos(0.0)

using namespace std;

int main(){
    double radius, t;

    cin >> t;

    for(int i = 1; i <= t; i++){
        cin >> radius;
        //cout << "Case " << i << ": " << (4 * radius * radius) - (PI * radius * radius) << endl;
        printf("Case %d: %.2f\n", i, (4 * radius * radius) - (PI * radius * radius));
    }
}
