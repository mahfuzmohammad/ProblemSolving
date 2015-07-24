#include <bits/stdc++.h>

using namespace std;

int tree[100005][15], next=1;
bool hasEnd[100005];
vector<string> v;

void reset() {
    memset(tree, -1, sizeof tree);
    next=1;
    memset(hasEnd, 0, sizeof hasEnd);
    v.clear();
}

bool add(string s) {
    int i = 0, cnode = 0;
    bool ret = hasEnd[cnode];
    while(i < s.size()) {
        if(tree[cnode][s[i]-'0'] == -1) {
            cnode = tree[cnode][s[i++]-'0'] = next++;
        } else cnode = tree[cnode][s[i++]-'0'];
        ret |= hasEnd[cnode];
        //cerr << i << " " << cnode << " " << ret << "\n";

        if(i == s.size())
            hasEnd[cnode] = true;
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    int t, n;
    string num;
    bool flag;

    cin >> t;

    for(int i = 1; i <= t; i++) {
        flag = false;
        reset();
        cin >> n;
        for(int j = 0; j < n; j++) {
            cin >> num;
            v.push_back(num);
        }

        sort(v.begin(), v.end());

        for(int j = 0; j < n; j++) {
            flag |= add(v[j]);
            //cout << flag << endl;
        }

        if(flag) {
            cout << "Case " << i << ": NO\n";
        } else {
            cout << "Case " << i << ": YES\n";
        }
    }

    return 0;
}
