#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main () {

    int T, n;
    double ans;
    cin >> T;

    for(int i = 1; i <= T; i++) {
        cin >> n;
        ans = 1;

        int j = 1;

        while(2.0 - ans > 0.000001) {
            ans *= ( double(n) / double(n - j) );
            j++;
        }

        cout << "Case " << i << ": " << j - 1 << endl;
    }

    return 0;

}
