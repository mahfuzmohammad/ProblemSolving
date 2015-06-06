#include <bits/stdc++.h>

using namespace std;

bool cmp (char a, char b) {
    if(tolower(a) == tolower(b)) {
        return a < b;
    }

    return tolower(a) < tolower(b);
}

int main() {
    //freopen("input.txt", "r", stdin);
    int t;
    string s;

    cin >> t;

    for(int i = 0; i < t; i++) {
        cin >> s;
        sort(s.begin(), s.end(), cmp);
        do {
            cout << s << endl;
        } while (next_permutation(s.begin(), s.end(), cmp));
    }

    return 0;
}
