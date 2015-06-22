/*
Bismillahir Rahmanir Rahim
Coder: Ahmad Faiyaz
*/

#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <fstream>
#include <ctime>


# define FOR(i, a, b) for (int i=a; i<b; i++)
# define REP(i, a) FOR(i,0,a)

#define EPS 1e-11
#define inf 1234567891
#define LL long long

#define abs(x) (((x)< 0) ? (-(x)) : (x))
#define all(x) (x).begin(), (x).end()
#define ms(x, a) memset((x), (a), sizeof(x))

#define pb push_back
#define FORIT(i,m) for(__typeof((m).begin()) i=(m).begin();i!=(m).end();i++)
#define pii pair<int,int>
#define UNIQUE(c) (c).resize( unique( all(c) ) - (c).begin() )

#define READ(f) {ifstream infile(f) ;if(infile.good()) freopen(f, "r", stdin);}
#define WRITE(f) freopen(f, "w", stdout)
#define CIN ios_base::sync_with_stdio(0);
///int rrr[]={1,0,-1,0};int ccc[]={0,1,0,-1}; //4 Direction
///int rrr[]={1,1,0,-1,-1,-1,0,1};int ccc[]={0,1,1,1,0,-1,-1,-1};//8 direction
///int rrr[]={2,1,-1,-2,-2,-1,1,2};int ccc[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
///int rrr[]={2,1,-1,-2,-1,1};int ccc[]={0,1,1,0,-1,-1}; //Hexagonal Direction
///int month[]={31,28,31,30,31,30,31,31,30,31,30,31}; //month

using namespace std;
struct tuple{
    int x, y, z;
    tuple(){
        x = y = z= 0;
    }

    tuple(int _x,int _y,int _z){
        x = _x;
        y = _y;
        z = _z;
    }
};

vector <tuple> v;
#define MAX 300005


int tree [4*MAX];
int lazy [4*MAX];
void update(int node,int left,int right,int i,int j,int x){

    if(lazy[node]){
        if(left!=right){
            lazy[2*node] = lazy[node];
            lazy[2*node+1] = lazy[node];
        }
        tree[node] = lazy[node];
        lazy[node] =0;
    }

    if(left>=i && right <= j){
        tree[node] = x;
        if(left != right){
            lazy[2*node] = x;
            lazy[2*node+1] = x;
        }
        lazy[node] =0;
        return ;
    }

    if(left > j || right < i) return;

    int mid = (left+right)>>1;
    update(2*node,left,mid,i,j,x);
    update(2*node+1,mid+1,right,i,j,x);

    return;
}


int query(int node,int left,int right,int i,int j){
    if(lazy[node]){
        if(left!=right){
            lazy[2*node] = lazy[node];
            lazy[2*node+1] = lazy[node];
        }
        tree[node] = lazy[node];
        lazy[node] =0;
    }
    if(left >= i && right <= j){
        return tree[node];
    }
    if(left >j || right < i) return -1;

    int mid = (left+right)>>1;
    return max(query(2*node,left,mid,i,j) , query(2*node+1,mid+1,right,i,j));
}


int main(){
    #if defined( faiyaz_pc )
        READ("in.txt");
    #endif
    CIN;
    int n, m,l, r, x;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>l>>r>>x;
        v.pb(tuple(l,r,x));
    }

    for(int i=v.size()-1;i>=0;i--){
        int x = v[i].z ;
        int val = query(1,1,n,x,x);
        update(1,1, n, v[i].x, v[i].y , v[i].z);
        update(1,1, n, x, x, val);
    }

    for(int i=1;i<=n;i++){
        if(i>1)cout<<" ";
        cout<<query(1,1,n,i,i);
    }
    return 0;
}
