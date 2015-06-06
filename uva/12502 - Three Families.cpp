#include <bits/stdc++.h>

using namespace std;

int main() {

    int t, x, y, z;
    cin >> t;

    for(int i = 0; i < t; i++) {
        cin >> x >> y >> z;
        cout << (z * (2 * x - y)) / (x + y) << "\n";
    }

    return 0;
}
