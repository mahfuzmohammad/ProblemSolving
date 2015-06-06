#include <bits/stdc++.h>

#define pattsize 1000005

using namespace std;

int F[pattsize + 2];

void calc_failure_fuction(string& pat) {
    //everything is 1 indexed
    int k, psize = pat.size();
    F[1] = 0; F[0] = 0;

    for(int i = 2; i <= psize; i++) {
        k = F[i - 1];
        while(true) {
            if(pat[k] == pat[i - 1]) {
                F[i] = k + 1;
                break;
            }

            if(k == 0) {F[i] = 0; break;}

            k = F[k];
        }
    }
}

int match(string& txt, string& pat) {
    //everything is 1 indexed
    calc_failure_fuction(pat);
    int i = 0, j = 0, n = txt.size(), m = pat.size(), ans = 0;
    //i -> pattern, j -> text, n -> text size, m -> pattern size

    while(true) {
        if(j == n) break; //End of txt

        if(txt[j] == pat[i]) {
            i++; j++;
            if(i == m) {
                //match found
                ans++;
            }
        } else if(i > 0) {
            i = F[i];
        } else {
            j++;
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);

    string A, B;

    while (cin >> B) {
        if(B == ".") break;
        memset(F, -1, sizeof(F));
        A = B+B;
        int matches = match(A, B) - 1;
        cout << matches << '\n';
    }

    return 0;
}
