#include <bits/stdc++.h>

#define mx 100000

using namespace std;

int arr[mx + 3];

struct info {
    long long prop,sum;
} tree[mx*3];

void update(int node,int b,int e,int i,int j,int x)
{
    if (i > e || j < b)   return;
    if (b >= i && e <= j) // range of node is inside the range of update
    {
        tree[node].sum+=((e-b+1)*x);
        tree[node].prop+=x;
        return;
    }
    int Left=node*2;
    int Right=(node*2)+1;
    int mid=(b+e)/2;
    update(Left,b,mid,i,j,x);
    update(Right,mid+1,e,i,j,x);
    tree[node].sum=tree[Left].sum+tree[Right].sum+(e-b+1)*tree[node].prop;
}

long long query(int node,int b,int e,int i,int j,long long carry=0)
{
    if (i > e || j < b) return 0;

    if(b>=i and e<=j) return tree[node].sum+carry*(long long)(e-b+1);


    int Left=node<<1;
    int Right=(node<<1)+1;
    int mid=(b+e)>>1;

    long long p1 = query(Left, b,mid,  i, j,   carry+tree[node].prop);
    long long p2 = query(Right, mid+1, e, i, j,carry+tree[node].prop);

    return  p1+p2;

}

int main() {
    //freopen("in.txt", "r", stdin);
    int t, n, q, x, y, v, cmd;
    scanf("%d", &t);

    for(int i = 1; i <= t; i++) {
        memset(tree, 0, sizeof tree);
        scanf("%d %d", &n, &q);
        printf("Case %d:\n", i);
        for(int j = 0; j < q; j++) {
            scanf("%d", &cmd);
            if(cmd) {
                scanf("%d %d", &x, &y);
                printf("%lld\n", query(1, 1, n, x + 1, y + 1));
            } else {
                scanf("%d %d %d", &x, &y, &v);
                update(1, 1, n, x + 1, y + 1, v);
            }
        }
    }

    return 0;
}
