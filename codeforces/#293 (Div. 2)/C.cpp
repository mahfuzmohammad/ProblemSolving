#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int arr[100005];
map<int, int> pos;

inline int swipe(int p, int k) {
    return (p/k);
}

void printarr(int n) {
    for(int i = 0; i < n; i++) {
        if(i > 0) cout << " ";
        cout << arr[i];
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    int n, m, k, x;
    cin >> n >> m >> k;

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        pos[arr[i]] = i;
    }

    ll ans = 0;
    for(int i = 0; i < m; i++) {
        cin >> x;
        ans += (ll)(swipe(pos[x], k) + 1);
        int cpos = pos[x];
        if(cpos > 0) {
            pos[x] = cpos-1;
            pos[arr[cpos-1]] = cpos;
            swap(arr[cpos], arr[cpos-1]);
        }

        //printarr(n);
    }

    cout << ans << "\n";

    return 0;
}
