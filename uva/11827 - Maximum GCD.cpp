#include <bits/stdc++.h>

using namespace std;

vector<int> v;

int gcd(int a, int b) {
    if(!b) return a;
    return gcd(b, a%b);
}

int main() {
    int t;
    string line, x;
    scanf("%d\n", &t);

    for(int i = 0; i < t; i++) {
        v.clear();
        getline(cin, line);
        stringstream ss(line);
        while(getline(ss, x, ' ')) {
            v.push_back(atoi(x.c_str()));
        }

        int ans = 0;
        for(int j = 0; j < v.size(); j++) {
            for(int k = j+1; k < v.size(); k++) {
                ans = max(ans, gcd(max(v[j], v[k]), min(v[j], v[k])));
            }
        }

        printf("%d\n", ans);
    }

    return 0;
}
