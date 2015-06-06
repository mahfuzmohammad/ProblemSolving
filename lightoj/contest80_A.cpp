#include <iostream>

using namespace std;

long long gcd(long long a, long long b){

    if(b == 0){
        return a;
    }

    return gcd(b, a % b);

}

int main(){
    long long gcdV, t, a, b, i, lcm;

    cin >> t;

    for(i = 1; i <= t; i++){
        cin >> a >> b;
        gcdV = gcd(a, b);
        lcm = (a * b) / gcdV;

        cout << "Case " << i << ": " << lcm << " " << gcdV << endl;

    }

    return 0;
}
