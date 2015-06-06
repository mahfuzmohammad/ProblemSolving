#include <bits/stdc++.h>

#define mx 200000
#define ll long long

using namespace std;

ll  arr[mx + 3],
    freq[mx + 3];

ll  tree[4 * mx],
    lazy[4 * mx];

void init(int node, int b, int e) {
    if(b == e) {
        lazy[node] = 0;
        tree[node] = 0;
        return;
    }

    int mid = (b + e) / 2;
    int Left = node * 2;
    int Right = node * 2 + 1;
    init(Left, b, mid);
    init(Right, mid + 1, e);
    lazy[node] = 0;
    tree[node] = 0;
}

void update(int node,int b,int e,int i,int j,ll x) //change all value to x
{
    if(lazy[node]) {
        tree[node] += ((ll)(e-b+1)*lazy[node]);

        if(b != e) {
            lazy[2*node] += lazy[node];
            lazy[2*node + 1] += lazy[node];
        }

        lazy[node] = 0;
    }

    if (i > e || j < b)   return;
    if (b >= i && e <= j) // range of node is inside the range of update
    {
        tree[node] +=((e-b+1)*x);
        if(b != e) {
            lazy[2*node] += x;
            lazy[2*node + 1] += x;
        }

        lazy[node] = 0;
        return;
    }

    int Left=node*2;
    int Right=(node*2)+1;
    int mid=(b+e)/2;

    update(Left,b,mid,i,j,x);
    update(Right,mid+1,e,i,j,x);
    tree[node]=tree[Left]+tree[Right];
}

ll query(int node,int b,int e,int i,int j)//get sum
{
    if(lazy[node]) {
        tree[node] += ((ll)(e-b+1)*lazy[node]);
        if(b != e) {
            lazy[2*node] += lazy[node];
            lazy[2*node + 1] += lazy[node];
        }

        lazy[node] = 0;
    }

    if (i > e || j < b) return 0;

    if (b >= i && e <= j) // range of node is inside the range of update
    {
        return tree[node];
    }


    int Left=node<<1;
    int Right=(node<<1)+1;
    int mid=(b+e)>>1;

    ll p1 = query(Left, b,mid,  i, j);
    ll p2 = query(Right, mid+1, e, i, j);

    return  p1 + p2;
}

bool cmp(ll a, ll b) {
    return (a > b);
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int n, q, x, y;

    cin >> n >> q;
    init(1, 1, n);

    for(int j = 0; j < n; j++) {
        cin >> arr[j];
    }

    for(int j = 0; j < q; j++) {
        cin >> x >> y;
        update(1, 1, n, x, y, 1);

        /*cout << endl;
        for(int k = 1; k <= n; k++) {
            cout << k << " " << query(1, 1, n, k, k) << endl;
        }*/
    }

    for(int j = 1; j <= n; j++) {
        freq[j - 1] = query(1, 1, n, j, j);
    }

    sort(arr, arr + n, cmp);
    sort(freq, freq + n, cmp);

    ll sum = 0;

    for(int j = 0; j < n; j++) {
        //cout << j << " " << arr[j] << " " << freq[j] << endl;
        sum += (arr[j] * freq[j]);
    }

    cout << sum << endl;

    return 0;
}
