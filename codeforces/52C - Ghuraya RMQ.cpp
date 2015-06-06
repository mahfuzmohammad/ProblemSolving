#include <bits/stdc++.h>

#define mx 200000
#define ll long long

using namespace std;

ll  arr[mx + 3];
string temp[5];

struct info {
    long long prop,sum;
} tree[mx*4];

void init(int node, int b, int e) {
    if(b == e) {
        tree[node].prop = 0;
        tree[node].sum = arr[b];
        //cout << b << " " << e << " " << tree[node].sum << endl;
        return;
    }

    int mid = (b + e) / 2;
    int Left = node * 2;
    int Right = node * 2 + 1;
    init(Left, b, mid);
    init(Right, mid + 1, e);
    tree[node].prop = 0;
    tree[node].sum = min(tree[Left].sum, tree[Right].sum);
    //cout << b << " " << e << " " << tree[node].sum << endl;
}

void update(int node,int b,int e,int i,int j,ll x) //change all value to x
{
    if(tree[node].prop) {
        tree[node].sum += tree[node].prop;

        if(b != e) {
            tree[2*node].prop += tree[node].prop;
            tree[2*node + 1].prop += tree[node].prop;
        }

        tree[node].prop = 0;
    }

    if (i > e || j < b)   return;
    if (b >= i && e <= j) // range of node is inside the range of update
    {
        tree[node].sum += x;
        if(b != e) {
            tree[2*node].prop += x;
            tree[2*node + 1].prop += x;
        }

        tree[node].prop = 0;
        return;
    }

    int Left=node*2;
    int Right=(node*2)+1;
    int mid=(b+e)/2;

    update(Left,b,mid,i,j,x);
    update(Right,mid+1,e,i,j,x);
    tree[node].sum=min(tree[Left].sum, tree[Right].sum);
}

ll query(int node,int b,int e,int i,int j)//get sum
{
    if(tree[node].prop) {
        tree[node].sum += tree[node].prop;
        if(b != e) {
            tree[2*node].prop += tree[node].prop;
            tree[2*node + 1].prop += tree[node].prop;
        }

        tree[node].prop = 0;
    }

    if (i > e || j < b) return 10000000000000000LL;

    if (b >= i && e <= j) // range of node is inside the range of update
    {
        return tree[node].sum;
    }


    int Left=node<<1;
    int Right=(node<<1)+1;
    int mid=(b+e)>>1;

    ll p1 = query(Left, b,mid,  i, j);
    ll p2 = query(Right, mid+1, e, i, j);

    return  min(p1, p2);
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int n, q, x, y, v, innum;
    string line;

    cin >> n;

    for(int j = 1; j <= n; j++) {
        cin >> arr[j];
    }

    init(1, 1, n);

    cin >> q;
    getline(cin, line);

    for(int j = 0; j < q; j++) {
        getline(cin, line);
        innum = 0;
        stringstream ss;
        ss << line;

        while(ss >> temp[innum]) {
            innum++;
        }

        x = atoi(temp[0].c_str());
        y = atoi(temp[1].c_str());
        if(innum == 3) {
            v = atoi(temp[2].c_str());

            if(x > y) {
                update(1, 1, n, x + 1, n, v);
                update(1, 1, n, 1, y + 1, v);
            } else {
                update(1, 1, n, x + 1, y + 1, v);
            }

        } else {
            if(x > y) {
                cout << min(query(1, 1, n, x + 1, n), query(1, 1, n, 1, y + 1)) << "\n";
            } else {
                cout << query(1, 1, n, x + 1, y + 1) << "\n";
            }
        }
    }

    return 0;
}
