#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>

#define large 400000015

using namespace std;

int trailing0(int x){
    int t0 = 0;
    for(int i = 5; i <= x; i*=5){
        t0 += floor(x / i);
    }

    return t0;
}

int search(int l, int r, int& N){
    if(l > r) return -1;
    int mid = (l + r) / 2, tmid = trailing0(mid);

    if(l == r){
        if(tmid == N) return l;
        else return -1;
    }

    if(tmid < N){
        search(mid + 1, r, N);
    } else {
        search(l, mid, N);
    }

}

int main()
{
    int T, Q, ans;
    scanf("%d", &T);

    for(int i = 1; i <= T; i++){
        scanf("%d", &Q);
        ans = search(0, large, Q);
        if(ans < 0){
            printf("Case %d: impossible\n", i);
        } else {
            printf("Case %d: %d\n", i, ans);
        }
    }

    return 0;
}
