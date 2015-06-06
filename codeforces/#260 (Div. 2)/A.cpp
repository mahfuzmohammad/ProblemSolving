#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

vector<ii> v;

bool cmp (ii a, ii b) {
    if(a.first == b.first) {
        return a.second < b.second;
    }

    return a.first < b.first;
}

int main() {
    ios_base::sync_with_stdio(0);
    int n, a, b;
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> a >> b;
        v.push_back(ii(a, b));
    }

    sort(v.begin(), v.end(), cmp);

    bool flag = false;

    for(int i = 1; i < v.size(); i++) {
        if((v[i].first > v[i-1].first) && (v[i].second < v[i-1].second)) flag |= true;
        if(flag) break;
    }

    if(flag) {
        cout << "Happy Alex\n";
    } else cout << "Poor Alex\n";

    return 0;
}
