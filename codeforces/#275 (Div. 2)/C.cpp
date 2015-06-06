#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k, p = 0, l, r;
    cin >> n >> k;

    l = 1;
    r = n;
    cout << l++;
    p++;
    k--;
    while(k > 0) {
        if(p > 0) cout << " ";
        if(p % 2 == 1) {
            cout << r--;
        } else {
            cout << l++;
        }

        k--;
        p++;
    }

    if(p < n)  {
        if(p%2 == 0) {
            for(int i = p; i < n; i++) {
                if(p > 0) cout << " ";
                cout << r--;
            }
        } else {
            for(int i = p; i < n; i++) {
                if(p > 0) cout << " ";
                cout << l++;
            }
        }
    }

    cout << "\n";

    return 0;
}
