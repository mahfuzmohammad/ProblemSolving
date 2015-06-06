#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#define MAXUV 20000


using namespace std;

vector<int> graph[MAXUV + 5];
int temp[MAXUV + 5];
int exists[MAXUV + 5];
int result[2];

void resetResult(){
    result[0] = 0;
    result[1] = 0;
}

void reset(){
    for(int i = 0; i <= MAXUV; i++){
        graph[i].clear();
        temp[i] = -1;
        exists[i] = 0;
    }
}

int color(int a){
    if(a == 0){
        return 1;
    }

    return 0;
}

void BFS(int start){
    queue<int> q;
    temp[start] = 0;
    result[0] += 1;
    q.push(start);

    while(!q.empty()){
        int u = q.front();
        q.pop();
        int size = graph[u].size();

        for(int i = 0; i < size; i++){
            if(temp[graph[u][i]] == -1){
                int clr = color(temp[u]);
                temp[graph[u][i]] = clr;
                result[clr] += 1;
                q.push(graph[u][i]);
            }
        }
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int T, n, u, v, rslt, indx, maxV;

    cin >> T;

    for(int i = 1; i <= T; i++){
        reset();
        rslt = 0;
        indx = 1;
        maxV = 0;
        cin >> n;

        for(int j = 0; j < n; j++){
            cin >> u >> v;
            exists[u] = 1;
            exists[v] = 1;
            maxV = max(maxV, max(u,v));
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        while(indx <= maxV){
            if(temp[indx] == -1 && exists[indx] == 1){
                resetResult();
                BFS(indx);
                rslt += max(result[0], result[1]);
            }

            indx += 1;
        }

        cout << "Case " << i << ": " << rslt << endl;
    }

    return 0;
}
