#include <bits/stdc++.h>

using namespace std;

string s1, s2;
int slen;

int reachFinal(int idx, int pos, int& orgPos) {
    if(idx == slen) return (pos == orgPos);

    int temp = 0;
    if(s2[idx] == '+') temp += reachFinal(idx+1, pos+1, orgPos);
    else if(s2[idx] == '-') temp += reachFinal(idx+1, pos-1, orgPos);
    else temp += (reachFinal(idx+1, pos+1, orgPos) + reachFinal(idx+1, pos-1, orgPos));
    return temp;
}

int main() {
    //ios_base::sync_with_stdio(0);
    cin >> s1 >> s2;
    slen = s1.size();
    int orgPos = 0;

    for(int i = 0; i < slen; i++) {
        if(s1[i] == '+') {
            orgPos++;
        } else orgPos--;
    }

    int cnt = reachFinal(0, 0, orgPos);
    int tot = 1;

    for(int i = 0; i < slen; i++) {
        if(s2[i] == '?') {
            tot *= 2;
        }
    }

    //cout << double(cnt) / double(tot) << "\n";
    printf("%0.12lf\n", double(cnt) / double(tot));

    return 0;
}
