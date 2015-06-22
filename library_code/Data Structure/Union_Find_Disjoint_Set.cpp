#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

#define elem 5

using namespace std;

int par[elem + 5];

void makeset(int n){par[n] = n;}

int find_representative(int a){
    if(par[a] == a) return a;
    par[a] = find_representative(par[a]);
    return par[a];
}

void uni(int a, int b){
    int u = find_representative(a);
    int v = find_representative(b);

    if(u != v){par[u] = v;}
}

int main()
{
    for(int i = 1; i <= 5; i++){makeset(i);}

    for(int i = 0; i < 5; i++){
        int a, b;
        cin >> a >> b;
        uni(a, b);
    }

    for(int i = 0; i < 5; i++){
        int a;
        cin >> a;
        cout << find_representative(a) << endl;
    }

    return 0;
}
