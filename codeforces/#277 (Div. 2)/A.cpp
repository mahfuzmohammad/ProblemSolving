#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    long long n;
    cin >> n;

    if((n & 1) == 0) {
        cout << (n >> 1) << "\n";
    } else {
        cout << (n >> 1) - n << "\n";
    }

    return 0;
}
