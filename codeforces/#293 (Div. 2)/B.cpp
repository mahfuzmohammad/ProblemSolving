#include <bits/stdc++.h>

using namespace std;

char s[200005], t[200005];
bool vis[200005];
map<char, int> m;

int main() {
    int slen, tlen;
    scanf("%s\n%s", s, t);

    slen = strlen(s);
    tlen = strlen(t);

    for(int i = 0; i < tlen; i++) {
        m[t[i]]++;
    }

    int yay = 0, wops = 0;
    for(int i = 0; i < slen; i++) {
        if(m[s[i]] > 0) {
            yay++;
            m[s[i]]--;
            vis[i] = 1;
        }
    }

    for(int i = 0; i < slen; i++) {
        if(vis[i]) continue;

        if(isupper(s[i])) {
            if(m[tolower(s[i])] > 0) {
                wops++;
                m[tolower(s[i])]--;
            }
        } else if(islower(s[i])) {
            if(m[toupper(s[i])] > 0) {
                wops++;
                m[toupper(s[i])]--;
            }
        }
    }

    printf("%d %d\n", yay, wops);

    return 0;
}
