#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    string s;

    while(getline(cin, s)) {
        if(s == "DONE") break;
        bool flag = true;
        int l, r;
        l = 0; r = s.size() - 1;

        while(l < r) {
            while(!isalpha(s[l]) && (l < r)) l++;
            while(!isalpha(s[r]) && (l < r)) r--;

            flag &= (toupper(s[l]) == toupper(s[r]));
            l++; r--;
            if(!flag) break;
        }

        if(flag) {
            cout << "You won't be eaten!" << endl;
        } else {
            cout << "Uh oh.." << endl;
        }
    }

    return 0;
}
