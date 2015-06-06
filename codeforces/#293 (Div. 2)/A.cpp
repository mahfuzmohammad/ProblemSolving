#include <bits/stdc++.h>

using namespace std;

pair<char, int> incL(char a) {
    if(char(a + 1) > 'z') return pair<char, int>('a', 1);
    return pair<char, int>(char(a + 1), 0);
}

string inc(string& a, int len) {
    int sum = 1;
    string n = "";
    for(int i = len-1; i >= 0; i--) {
        if(sum) {
            pair<char, int> temp = incL(a[i]);
            n += temp.first;
            sum = temp.second;
        } else {
            n += a[i];
        }
    }

    if(sum) {
        n += 'a';
    }

    reverse(n.begin(), n.end());
    return n;
}

int main() {
    string a, b;
    cin >> a >> b;
    int len = a.size();
    string c = inc(a, len);
    //cerr << c << "\n";
    if((c < b) && (c.size() == b.size())) {
        cout << c << "\n";
    } else {
        cout << "No such string\n";
    }

    return 0;
}
