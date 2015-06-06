#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#define MAXN 200

using namespace std;

vector<int> graph[MAXN + 5];
int color[MAXN + 5];

void reset(){
    for(int i = 0; i <= MAXN; i++){
        graph[i].clear();
        color[i] = -1;
    }
}

int getcolor(int x){
    if(x == 0)
        return 1;

    return 0;
}

void isColorable(){
    queue<int> q;
    color[0] = 0;
    q.push(0);

    while(!q.empty()){
        int u = q.front();
        int cColor = getcolor(color[u]);
        int size = graph[u].size();
        q.pop();

        for(int i = 0; i < size; i++){
            if(color[graph[u][i]] == -1){
                color[graph[u][i]] = cColor;
                q.push(graph[u][i]);
            } else {
                if(color[graph[u][i]] != cColor){
                    cout << "NOT BICOLORABLE." << endl;
                    return;
                }
            }
        }//end of for
    }// end of while

    cout << "BICOLORABLE." << endl;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int n, l, u, v;

    cin >> n;

    while( n != 0 ){
        reset();
        cin >> l;

        for(int i = 0; i < l; i++){
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        isColorable();
        cin >> n;
    }

    return 0;
}
