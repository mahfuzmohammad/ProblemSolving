#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll arr[25];

int getlen(ll x) {
    int cnt = 0;

    while(x > 0) {
        x /= 10LL;
        cnt++;
    }

    return cnt;
}

int main() {
    //freopen("in.txt", "r", stdin);
    ll w, m, k;
    //scanf("%I64d %I64d %I64d", &w, &m, &k);
    cin >> w >> m >> k;
    //cout << w << m << k << endl;

    arr[0] = 1;
    for(int i = 1; i <= 20; i++) {
        arr[i] = arr[i - 1] * 10LL;
        //cout << i << " " << arr[i] << endl;
    }

    int len = getlen(m);
    ll ans = 0;
    //cout << len << endl;

    do {
        //cout << w << " " << m << " " << k << " " << len << " " << arr[len] << endl;
        //cout << len << " " << arr[len] << " " << m << " " << arr[len] - m << " " << (arr[len] - m) * k << endl;
        if((arr[len] - m) * len <= (w / k)) {
            ans += (arr[len] - m);
            ll temp = w % k;
            w /= k;
            w -= ((arr[len] - m)) * len;
            w *= k;
            w += temp;
            m = arr[len];
            //cout << ans << " " << w << " " << len << " " << arr[len] << endl;
            len++;
        } else {
            //cout << "TEST" << endl;
            ans += (w / ((ll)len * k));
            w = 0;
        }

    } while (w > 0);

    cout << ans << endl;

    return 0;
}
