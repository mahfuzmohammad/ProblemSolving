//In the name of Allah, most Gracious, most Compassionate
#include <bits/stdc++.h>

using namespace std;

stack<int> ans;

int lowbit(int x) {
    for(int i = 0; i < 31; i++) {
        int mask = 1 << i;
        //cout << "lowbit " << x << " " << mask << " " << (x&mask) << endl;
        if((x & mask) == mask) return mask;
    }
}

int main() {
    int sum, limit;
    cin >> sum >> limit;

    for(int i = limit; i >= 1; i--) {
        int lb = lowbit(i);
        if(lb <= sum) {
            //cout << i << " " << lb << endl;
            ans.push(i);
            sum -= lb;
        }
    }

    if(sum != 0) {
        cout << -1 << endl;
    } else {
        cout << ans.size() << endl;
        cout << ans.top();
        ans.pop();
        while(!ans.empty()) {
            cout << " " << ans.top();
            ans.pop();
        }
        cout << endl;
    }

    return 0;
}

