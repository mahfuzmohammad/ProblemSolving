#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#define maxpeople 1000

using namespace std;

int money[maxpeople + 5];
vector<int> graph[maxpeople + 5];
int temp[maxpeople + 5];
int numPeople;

void reset(){
    for(int i = 0; i <= maxpeople; i++)
    {
        money[i] = 0;
        temp[i] = 0;
        graph[i].clear();
    }
}

bool bfs(int start)
{
    int u;
    int total = 0;
    int noPeople = 0;
    queue<int> q;
    q.push(start);
    temp[start] = -1;

    while(!q.empty()){
        u = q.front();
        q.pop();
        noPeople += 1;
        total += money[u];
        numPeople -= 1;

        for(int i = 0; i < graph[u].size(); i++)
        {
            if(temp[graph[u][i]] != -1)
            {
                q.push(graph[u][i]);
                temp[graph[u][i]] = -1;
            }
        }
        //cout << "Test" << endl;
    }

    //cout << total << " " << noPeople << endl;

    if(total % noPeople == 0) return true;

    //cout << total % noPeople << endl;

    return false;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int T, n, m, u, v;
    bool result;
    cin >> T;

    for(int c = 1; c <= T; c++){
        reset();
        result = true;
        cin >> n >> m;
        numPeople = n;

        for(int i = 1; i <= n; i++){
            cin >> money[i];
        }

        for(int i = 0; i < m; i++){
            cin >> u >> v;
            graph[u].push_back(v);
            if(temp[u] == 0){temp[u] = 1;}
            if(temp[v] == 0){temp[v] = 1;}
        }

        while(result == true && numPeople != 0){
            int i = 1;
            if(temp[i] == 1){
                result = bfs(i);
            }
            //cout << result << endl;
            ++i;
        }

        cout << "Case " << c << ": ";
        if(result)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }

    return 0;
}
