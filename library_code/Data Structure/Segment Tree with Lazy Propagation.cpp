#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>

#define mx 1000

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
