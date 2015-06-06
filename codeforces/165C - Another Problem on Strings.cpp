//In the name of Allah, most Gracious, most Compassionate

#include <bits/stdc++.h>

using namespace std;

#define _MAXN 1000000

char in[_MAXN + 5];
int mem[_MAXN + 5];

int main() {
    int k, slen;
    scanf("%d", &k);
    scanf("\n%s", in);

    slen = strlen(in);

    int cnt = 0;
    for(int i = 0; i < slen; i++) {
        if(in[i] == '1') cnt++;
        mem[i] = cnt;
    }

    /*for(int i = 0; i < slen; i++) {
        cout << mem[i] << " ";
    }
    cout << endl;*/

    //mem[slen] = cnt + 1;

    long long ans = 0;

    for(int i = 0; i < slen; i++) {
        if(k == 0 && in[i] == '1') continue;
        int lookfor = mem[i - 1] + k;
        ans += (long long)(upper_bound(mem + i, mem + slen, lookfor) - lower_bound(mem + i, mem + slen, lookfor));
        //cout << i << " " << lookfor << " " << ans << endl;
    }

    printf("%I64d\n", ans);

    return 0;
}
