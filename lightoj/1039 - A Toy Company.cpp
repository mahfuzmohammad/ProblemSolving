#include <bits/stdc++.h>

using namespace std;

#define FIN(a) freopen(a, "r", stdin)
#define IN(a) scanf("%d", &a)
#define INchar(a) scanf("%c", &a)
#define INstring(a) scanf("%s", &a)
#define INnewline() scanf("\n");
#define INspace() scanf(" ");

////Knights move
//int movx[] = {1, 1, 2, 2, -1, -1, -2, -2};
//int movy[] = {2, -2, 1, -1, 2, -2, 1, -1};

int t, n, s, e;
char start[4], end[4];
string fa, fb, fc;

bool forbidden[20000];
int cost[20000];
bool visited[20000];

int getID(char a, char b, char c) {
    return (26 * 26 * (a - 'a') + 26 * (b - 'a') + (c - 'a'));
}

int getID(string str) {
    return (26 * 26 * (str[0] - 'a') + 26 * (str[1] - 'a') + (str[2] - 'a'));
}

string next(string s, int i) {
    int x = s[i] - 'a';
    x++;
    x %= 26;
    s[i] = char('a' + x);
    return s;
}

string prev(string s, int i) {
    int x = s[i] - 'a';
    x--;

    if(x < 0) x += 26;

    s[i] = char('a' + x);
    return s;
}

void reset() {
    memset(forbidden, false, sizeof forbidden);
    memset(visited, false, sizeof visited);
    memset(cost, 0, sizeof cost);
}

void bfs(string s, string e) {
    queue<string> q;

    if(!forbidden[getID(s)]) {
        cost[getID(s)] = 0;
        visited[getID(s)] = true;
        q.push(s);
    }

    while(!q.empty()) {
        string u = q.front();
        int uid = getID(u);
        q.pop();
        //cout << u << endl;
        if(u == e) break;

        for(int i = 0; i < 3; i++) {
            string n = next(u, i), p = prev(u, i);
            int nid = getID( n ), pid = getID( p );

            if(!visited[ nid ] && !forbidden[nid]) {
                visited[ nid ] = true;
                cost[nid] = 1 + cost[uid];
                q.push(n);
            }

            if(!visited[pid] && !forbidden[pid]) {
                visited[pid] = true;
                cost[pid] = 1 + cost[uid];
                q.push(p);
            }
        }
    }
}

int main() {
    //FIN("in.txt");
    IN(t);

    for(int i = 1; i <= t; i++) {
        reset();
        INnewline();
        INstring(start);
        INnewline();
        INstring(end);
        string strt = start, ed = end;

        s = getID(strt);
        e = getID(ed);
        IN(n);

        for(int j = 0; j < n; j++) {
            INnewline();
            cin >> fa >> fb >> fc;

            for(int k = 0; k < fa.size(); k++) {
                for(int l = 0; l < fb.size(); l++) {
                    for(int m = 0; m < fc.size(); m++) {
                        forbidden[getID(fa[k], fb[l], fc[m])] = true;
                    }
                }
            }
        }

        bfs(strt, ed);
        if(visited[e])
            printf("Case %d: %d\n", i, cost[getID(ed)]);
        else
            printf("Case %d: %d\n", i, -1);
    }

    return 0;
}
