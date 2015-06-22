//Segment Tree with single value update
//This segtree keeps tracks of range sum

#include <bits/stdc++.h>

#define mx 100001

using namespace std;

int arr[mx]; //original array
int tree[mx*3]; //tree

// build tree for first time
// b is the left end of subsection of original array or subgraph
// e is the right end of subsection of original array or subgraph
void init(int root, int b, int e ) {
    if( b == e ) { //if the subgraph consist of only one node
        tree[root] = arr[b];
        return;
    }

    int Left = root*2; // Left is the root of left subgraph
    int Right = root*2+1; // Right is the root of right subgraph
    int mid = (b+e)/2; //middle point of division

    init(Left, b, mid); //build left subgraph
    init(Right,mid+1,e); //build right subgraph

    tree[root] = tree[Left] + tree[Right]; //we need to know the sum of left and right subtree
}

// Performs query on array from range [i, j]
// here root is the the root of current subgraph
// b is the left end of subsection of original array or this subgraph
// e is the right end of subsection of original array or this subgraph
int query(int root, int b, int e, int i, int j) {

    if (i > e || j < b)   return 0; //out of range
    if (b >= i && e <= j) return tree[root]; //relevant segment

    int Left = root * 2;  //decompose more
    int Right = root*2+1;
    int mid=(b+e)/2;

    int p1 = query(Left,b,mid,i,j);
    int p2 = query(Right,mid+1,e,i,j);

    return p1+p2; //sum of left and right side
}

// Updates a single element in the tree
// which index in orginal array is i
void update(int root, int b, int e, int i, int newvalue) {

    if (i > e || i < b)   return; //out of range
    if (b >= i && e <= i) { //relevant
        tree[root]=newvalue;
        return;
    }

    int Left=root*2;  // decompose more
    int Right=root*2+1;
    int mid=(b+e)/2;

    update(Left,b,mid,i,newvalue);
    update(Right,mid+1,e,i,newvalue);

    tree[root]=tree[Left]+tree[Right];
}


int main()
{
    int n;
    cin>>n;
    for(int i = 1; i <= n; i++)
        cin>>arr[i];

    init(1,1,n);

    update(1,1,n,2,0);
    cout<<query(1,1,n,1,3)<<endl;
    update(1,1,n,2,2);
    cout<<query(1,1,n,2,2)<<endl;
    return 0;
}
