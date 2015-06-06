#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    int n, k;
    cin >> n >> k;

    cout << ((n*6)-1)*k << "\n";
    int f = 1;
    for(int i = 0; i < n; i++) {
        cout << f*k << " " << (f+1)*k << " " << (f+2)*k << " " << (f+4)*k << "\n";
        f += 6;
    }

    return 0;
}
