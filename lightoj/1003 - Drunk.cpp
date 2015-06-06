#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <algorithm>

#define vs vector<string>

using namespace std;

enum COLOR {WHITE, BLACK, GREY};

map <string, vs> edge;
map <string, COLOR> visited;

set<string> node;

void dfs(string str, bool& flag)
{
    visited[str] = GREY;
    for(int i = 0; i < edge[str].size(); i++) {
        if(visited[edge[str][i]] == WHITE) {
            dfs(edge[str][i], flag);
        } else if (visited[edge[str][i]] == GREY) {
            flag = true;
        }
    }

    visited[str] = BLACK;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int T, m;
    string str, str2;
    bool flag;

    set<string>::iterator it;

    cin >> T;

    for(int i = 1; i <= T; i++) {
        edge.clear();
        visited.clear();
        node.clear();
        flag = false;

        cin >> m;
        for(int j = 0; j < m; j++) {
            cin >> str >> str2;
            edge[str2].push_back(str);
            visited[str] = WHITE;
            visited[str2] = WHITE;
            node.insert(str);
            node.insert(str2);
        }

        for(it = node.begin(); it != node.end(); it++) {
            if(flag) break;

            if(visited[*it] == WHITE) {
                dfs(*it, flag);
            }
        }

        cout << "Case " << i << ": ";
        if(flag) cout << "No" << endl;
        else cout << "Yes" << endl;
    }

    return 0;
}
