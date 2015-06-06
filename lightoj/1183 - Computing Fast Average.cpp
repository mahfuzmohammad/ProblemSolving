#include <bits/stdc++.h>

#define mx 100000
#define ll long long

using namespace std;

int arr[mx + 3];

struct info {
    long long prop,sum;
} tree[mx*4];

void init(int node, int b, int e) {
    if(b == e) {
        tree[node].prop = -1;
        tree[node].sum = 0;
        return;
    }

    int mid = (b + e) / 2;
    int Left = node * 2;
    int Right = node * 2 + 1;
    init(Left, b, mid);
    init(Right, mid + 1, e);
}

void update(int node,int b,int e,int i,int j,ll x) //change all value to x
{
    if(tree[node].prop > -1) {
        tree[node].sum = ((ll)(e-b+1)*tree[node].prop);

        if(b != e) {
            tree[2*node].prop = tree[node].prop;
            tree[2*node + 1].prop = tree[node].prop;
        }

        tree[node].prop = -1;
    }

    if (i > e || j < b)   return;
    if (b >= i && e <= j) // range of node is inside the range of update
    {
        tree[node].sum =((e-b+1)*x);
        tree[node].prop =x;
        return;
    }

    int Left=node*2;
    int Right=(node*2)+1;
    int mid=(b+e)/2;

    update(Left,b,mid,i,j,x);
    update(Right,mid+1,e,i,j,x);
    tree[node].sum=tree[Left].sum+tree[Right].sum;
}

ll query(int node,int b,int e,int i,int j)//get sum
{
    if(tree[node].prop > -1) {
        tree[node].sum = ((ll)(e-b+1)*tree[node].prop);
        if(b != e) {
            tree[2*node].prop = tree[node].prop;
            tree[2*node + 1].prop = tree[node].prop;
        }

        tree[node].prop = -1;
    }

    if (i > e || j < b) return 0;

    if (b >= i && e <= j) // range of node is inside the range of update
    {
        return tree[node].sum;
    }


    int Left=node<<1;
    int Right=(node<<1)+1;
    int mid=(b+e)>>1;

    ll p1 = query(Left, b,mid,  i, j);
    ll p2 = query(Right, mid+1, e, i, j);

    return  p1 + p2;
}

long long gcd(long long a, long long b) {
    if(!b) return a;
    return gcd(b, a % b);
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int t, n, q, x, y, v, cmd;
    scanf("%d", &t);

    for(int i = 1; i <= t; i++) {
        for(int j = 0; j < 4 * mx; j++) {
            tree[j].sum = 0;
            tree[j].prop = -1;
        }

        scanf("%d %d", &n, &q);
        printf("Case %d:\n", i);
        for(int j = 0; j < q; j++) {
            scanf("%d", &cmd);
            if(cmd == 2) {
                scanf("%d %d", &x, &y);
                long long s = query(1, 1, n, x + 1, y + 1);
                long long num = y - x + 1;

                if(s % num == 0) {
                    printf("%lld\n",  s / num);
                } else {
                    long long g;
                    if(s > num) {
                        g = gcd(s, num);
                    } else {
                        g = gcd(num, s);
                    }

                    printf("%lld/%lld\n",  s/g, num/g);
                }

            } else {
                scanf("%d %d %d", &x, &y, &v);
                update(1, 1, n, x + 1, y + 1, v);
            }
        }
    }

    return 0;
}
