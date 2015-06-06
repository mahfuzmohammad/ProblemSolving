//In the name of Allah, most Gracious, most Compassionate
#include <bits/stdc++.h>

using namespace std;

vector<string> v;
vector<int> ans;

int main() {

    string str;
    for(int i = 0; i < 4; i++) {
        cin >> str;
        v.push_back(str.substr(2, str.size()));
    }

    bool flag = false;

    for(int i = 0; i < 4; i++) {
        flag = true;
        for(int j = 0; j < 4; j++) {
            if(j == i) continue;
            if(((2 * v[i].size()) <= v[j].size())) {
                flag &= true;
            } else {
                //cout << "TEST" << endl;
                flag &= false;
            }
        }

        if(flag) {
            ans.push_back(i);
        }

        flag = true;
        for(int j = 0; j < 4; j++) {
            if(j == i) continue;
            if((v[i].size() >= (2 * v[j].size()))) {
                flag &= true;
            } else {
                //cout << "TEST" << endl;
                flag &= false;
            }
        }

        if(flag) {
            ans.push_back(i);
        }
    }

    //cout << ans.size() << endl;

    if(ans.size() == 1) {
        cout << char('A' + ans[0]) << endl;
    } else {
        cout << 'C' << endl;
    }

    return 0;
}
