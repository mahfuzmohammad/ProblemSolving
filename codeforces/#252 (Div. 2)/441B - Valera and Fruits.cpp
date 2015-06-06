//In the name of Allah, most Gracious, most Compassionate
#include <bits/stdc++.h>

using namespace std;

#define ii pair<int, int>

int day[3009];

int main() {

    int n, v, a, b, ans = 0, temp;
    cin >> n >> v;

    for(int i = 0; i < n; i++) {
        cin >> a >> b;
        day[a] += b;
    }

    ans += min(day[0], v);
    temp = max(day[0], v) - v;
    //cout << temp << endl;

    for(int i = 1; i <= 3000; i++) {
        int t = min(day[i] + temp, v);
        ans += t;
        if(t == v) {
            temp = min(day[i] + temp - v, day[i]);
        } else {
            temp = 0;
        }

        //cout << t << " " << v << " " << temp << endl;
    }

    //cout << temp << endl;
    if(temp) ans += min(temp, v);

    cout << ans << endl;

    return 0;
}
