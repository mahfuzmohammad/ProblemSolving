#include <bits/stdc++.h>

using namespace std;

string str;
int temp[100005];
int cost[30][30];

int main() {
    ios_base::sync_with_stdio(0);
    //freopen("in", "r", stdin);

    for(int i = 0; i < 26; i++) {
        for(int j = 0; j < 26; j++) {
            cost[i][j] = min(((i-j+26)%26), ((j-i+26)%26));
        }
    }

    int n, p;
    cin >> n >> p;
    cin >> str;

    int lop = n >> 1;
    for(int i = 0; i < lop; i++) {
        if(str[i] != str[n-i-1]) {
            temp[i] = min(cost[str[i]-'a'][str[n-i-1]-'a'], cost[str[n-i-1]-'a'][str[i]-'a']);
        }
    }

    for(int i = 1; i <= n; i++) {
        temp[i] += temp[i-1];
    }

    if(p >= lop) {
        p = (n-p)+1;
    }

    int ans = temp[n-1];
    int l = 1, r = 0;

    while(temp[l-1] == 0) l++;
    l = max(p-l, 0);


    while(temp[p-1] < temp[n-1]) {
        p++;
        r++;
    }

    cout << ans+2*min(l, r)+max(l, r) << "\n";

    return 0;
}
