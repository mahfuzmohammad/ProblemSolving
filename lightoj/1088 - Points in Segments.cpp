#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

#define maxn 100000

using namespace std;

int arr[maxn + 2];

int lowbound(int n, int l, int r){
    if(l == r) return l;
    if(l > r) return -1;

    int mid = (l + r) / 2;

    if(arr[mid] >= n){
        return lowbound(n, l, mid);
    }

    return lowbound(n, mid + 1, r);
}

int upbound(int n, int l, int r){
    if(l == r) return l;
    if(l > r) return -1;

    int mid = (l + r) / 2;

    if(arr[mid] <= n){
        return upbound(n, mid + 1, r);
    }

    return upbound(n, l, mid);
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int t, n, q, A, B, l, r;
    scanf("%d", &t);

    for(int i = 1; i <= t; i++){
        scanf("%d %d", &n, &q);
        for(int j = 0; j < n; j++){
            scanf("%d", arr+j);
        }

        printf("Case %d:\n", i);
        for(int j = 0; j < q; j++){
            scanf("%d %d", &A, &B);
            l = lowbound(A, 0, n);
            r = upbound(B, 0, n);

            l = min(l, n);
            r = min(r, n);

            printf("%d\n", r - l);
        }
    }

    return 0;
}
