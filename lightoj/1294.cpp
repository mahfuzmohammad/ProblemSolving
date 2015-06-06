#include <iostream>

using namespace std;

int main(){
    long long t, i, n, m;

    cin >> t;

    for(i = 1; i <= t; i++){

        cin >> n >> m;

        cout << "Case " << i << ": " << (n / 2) * m << endl;

    }

    return 0;
}
