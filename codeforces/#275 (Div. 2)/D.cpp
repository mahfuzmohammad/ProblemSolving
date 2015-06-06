#include <bits/stdc++.h>

using namespace std;

const int maxn = 100005;
int arr[32][maxn];
int num[maxn];
int tree[maxn*3];

struct qu {
    int l, r, x;
    qu(){}
    qu(int _l, int _r, int _x):l(_l), r(_r), x(_x){}
};

vector<qu> q;

void init(int root, int b, int e ) {
    if( b == e ) { //if the subgraph consist of only one node
        tree[root] = num[b];
        return;
    }

    int Left = root*2; // Left is the root of left subgraph
    int Right = root*2+1; // Right is the root of right subgraph
    int mid = (b+e)/2; //middle point of division

    init(Left, b, mid); //build left subgraph
    init(Right,mid+1,e); //build right subgraph

    tree[root] = tree[Left] & tree[Right]; //we need to know the sum of left and right subtree
}

int query(int root, int b, int e, int i, int j) {

    if (i > e || j < b)   return ((1 << 30) - 1); //out of range
    if (b >= i && e <= j) return tree[root]; //relevant segment

    int Left = root * 2;  //decompose more
    int Right = root*2+1;
    int mid=(b+e)/2;

    int p1 = query(Left,b,mid,i,j);
    int p2 = query(Right,mid+1,e,i,j);

    return p1&p2; //sum of left and right side
}

int main() {
    ios_base::sync_with_stdio(0);
    int n, m, l, r, x;
    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        cin >> l >> r >> x;
        q.push_back(qu(l, r, x));
    }

    for(int b = 0; b < 30; b++) {
        for(int i = 0; i < m; i++) {
            if ((q[i].x & (1 << b)) != 0) {
                arr[b][q[i].l]++;
                arr[b][q[i].r+1]--;
            }
        }

        for(int i = 1; i <= n; i++) {
            arr[b][i+1] += arr[b][i];
            num[i] += ((1 << b) * (arr[b][i] > 0));
        }
    }

    init(1, 1, n);

    bool flag = true;
    for(int i = 0; i < m; i++) {
        flag &= (query(1, 1, n, q[i].l, q[i].r) == q[i].x);
    }

    if(flag) {
        cout << "YES\n";
        for(int i = 1; i <= n; i++) {
            if(i > 1) cout << " ";
            cout << query(1, 1, n, i, i);
        }
        cout << "\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}
