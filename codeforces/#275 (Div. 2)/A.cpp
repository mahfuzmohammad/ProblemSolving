#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ll l, r;
    cin >> l >> r;

    while(l % 2 != 0) l++;
    while(r % 2 != 0) r--;

    if(r - l +1 < 3) {
        cout << -1 << "\n";
    } else {
        cout << l << " " << l+1 << " " << l + 2 << "\n";
    }

    return 0;
}
