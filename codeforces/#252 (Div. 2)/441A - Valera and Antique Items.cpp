//In the name of Allah, most Gracious, most Compassionate
#include <bits/stdc++.h>

using namespace std;

//vector<int> v[60];
vector<int> ans;

int main() {

    int n, v, k, x;
    bool flag;
    cin >> n >> v;

    for(int i = 0; i < n; i++) {
        flag = false;
        cin >> k;
        for(int j = 0; j < k; j++) {
            cin >> x;
            if(v > x) flag = true;
        }

        if(flag) ans.push_back(i + 1);
    }

    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++) {
        if(i > 0) cout << " ";
        cout << ans[i];
    }
    cout << endl;

    return 0;
}
