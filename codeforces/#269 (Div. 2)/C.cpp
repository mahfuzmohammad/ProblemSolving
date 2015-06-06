#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    ll n, need = 0;
    int ans = 0;
    cin >> n;

    for(int i = 1; i <= 100000000; i++) {
        need = (i << 1);
        need += ((3LL * (ll)i * (ll)(i - 1)) / 2LL);
        //cout << need << endl;

        if(need > n) break;

        ll num = n - (ll)(i << 1);
        if(num < 0) break;
        if(num % 3LL == 0) {
            //cout << i << " " << num << endl;
            ans++;
        }
    }

    cout << ans << "\n";

    return 0;
}
