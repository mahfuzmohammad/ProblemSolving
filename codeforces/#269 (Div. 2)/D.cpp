#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int F[200005];
int A[200005], B[200005];
ll txt[200005], pat[200005];
int w, ns;

void calc_failure_fuction() {
    //everything is 1 indexed
    int k, psize = ns - 1;
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

// Returns the number of occurance of
// pat in txt
int match() {
    //everything is 1 indexed
    calc_failure_fuction();
    int i = 0, j = 0, n = w - 1, m = ns - 1, ans = 0;
    //i -> pattern, j -> text, n -> text size, m -> pattern size

    while(true) {
        if(j == n) break; //End of txt

        if(txt[j] == pat[i]) {
            i++; j++;
            if(i == m) {
                //match found
                ans++;
                i = F[i];
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
    //freopen("in", "r", stdin);
    //freopen("kmp", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin >> w >> ns;

    for(int i = 0; i < w; i++)
        cin >> A[i];

    for(int i = 0; i < ns; i++)
        cin >> B[i];

    memset(F, -1, sizeof(F));
    for(int i = 1; i < w; i++)
        txt[i-1] = (ll)A[i] - (ll)A[i - 1];

    for(int i = 1; i < ns; i++)
        pat[i-1] = (ll)B[i] - (ll)B[i - 1];

    if(ns == 1)
        cout << w << "\n";
    else
        cout << match() << "\n";

    return 0;
}
