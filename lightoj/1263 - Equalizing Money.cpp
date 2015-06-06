#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <cmath>
#include <algorithm>

#define MAXN 1000

using namespace std;

typedef struct {
    bool status; int amount;
} msg;

int money[MAXN + 5];
vector<int> v[MAXN + 5];
int mark[MAXN + 5];
set<int> s;

void reset(){
    s.clear();
    for(int i = 0; i <= MAXN; i++){
        money[i] = 0;
        mark[i] = 0;
        v[i].clear();
    }
}

bool isdivisable(int n){
    int totalmoney = 0, totalpeople = 0, u;
    queue<int> q;
    mark[n] = 1;
    totalpeople++;
    totalmoney+= money[n];
    q.push(n);

    while(!q.empty()){
        u = q.front();
        q.pop();

        for(int i = 0; i < v[u].size(); i++){
            if(!mark[v[u][i]]){
                mark[v[u][i]] = 1;
                totalpeople++;
                totalmoney+=money[v[u][i]];
                q.push(v[u][i]);
            }
        }
    }

    if(totalmoney % totalpeople == 0){
        s.insert(totalmoney / totalpeople);
        return true;
    }

    return false;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int T, n, m, x, y;
    bool flag;
    cin >> T;

    for(int i = 1; i <= T; i++){
        reset();
        flag = true;
        cin >> n >> m;
        for(int j = 1; j <= n; j++){
            cin >> money[j];
        }

        for(int j = 0; j < m; j++){
            cin >> x >> y;
            v[x].push_back(y);
            v[y].push_back(x);
        }

        for(int j = 1; j <= n; j++){
            if(!mark[j]) {flag &= isdivisable(j);}
        }

        cout << "Case " << i << ": " << ((s.size() == 1 && flag)?"Yes":"No") << endl;
    }

    return 0;
}
