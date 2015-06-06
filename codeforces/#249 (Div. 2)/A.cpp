//In the name of Allah, most Gracious, most Compassionate
#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, m, a, s = 0, cnt = 0;
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        cin >> a;
        s += a;
        if(s > m) {
            cnt++;
            s = a;
        }
    }

    if(s != 0) {
        cnt++;
    }

    cout << cnt << endl;

    return 0;
}
