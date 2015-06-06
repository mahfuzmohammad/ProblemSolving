#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int dp[(1 << 10) + 5][1005];
bool visited[(1 << 10) + 5][1005];

int fact[12];
int rep[12];

void calcFact() {
    fact[0] = 1;
    for(int i = 1; i <= 11; i++)
        fact[i] = i * fact[i - 1];
}

int calc(int mask, int mod, int& d, int& sSize, string& s) {

    if(visited[mask][mod]) return dp[mask][mod];

    if( mask == ((1 << sSize) - 1) ) {
        if(mod == 0) {
            visited[mask][mod] = true;
            dp[mask][mod] = 1;
            return dp[mask][mod];
        }

        return 0;
    }

    for(int i = 0; i < sSize; i++) {
        if( (mask & (1 << i)) == 0 ) {
            dp[mask][mod] += calc( mask | (1 << i), ((mod * 10) + (s[i] - '0')) % d, d, sSize, s );
            visited[mask][mod] = true;
        }
    }

    return dp[mask][mod];

}

int main() {

    calcFact();
    int T, d, sSize, p;
    string s;

    cin >> T;

    for(int i = 1; i <= T; i++) {
        cin >> s >> d;
        sSize = s.size();

        memset(rep, 0, sizeof(rep));
        for(int j = 0; j < sSize; j++)
            rep[s[j] - '0']++;

        memset(visited, 0, sizeof(visited));
        memset(dp, 0, sizeof(dp));
        p = calc(0, 0, d, sSize, s);

        for(int j = 0; j < 10; j++) {
            p /= fact[rep[j]];
        }

        cout << "Case " << i << ": " << p << endl;
    }

    return 0;

}
