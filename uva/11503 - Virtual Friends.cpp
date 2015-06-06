#include <bits/stdc++.h>

#define elem 100000

using namespace std;

vector< pair<string, string> > input;
set<string> nameset;
map<string, int> m;
int par[elem + 5];
int setsize[elem + 5];

void makeset(int n){par[n] = n;}

int find_representative(int a){
    if(par[a] == a) return a;
    par[a] = find_representative(par[a]);
    return par[a];
}

void uni(int a, int b){
    int u = find_representative(a);
    int v = find_representative(b);

    if(u != v){
        setsize[v] = setsize[u] + setsize[v];
        par[u] = v;
    }
}

void reset() {
    input.clear();
    nameset.clear();
    m.clear();
    for(int i = 0; i <= elem; i++) {
        makeset(i);
        setsize[i] = 1;
    }
}

int main()
{
    int t, n;
    char temp[22];
    string u, v;

    scanf("%d", &t);

    for(int i = 0; i < t; i++) {
        reset();
        scanf("%d", &n);
        //cout << n << endl;
        for(int j = 0; j < n; j++) {
            scanf("%s", temp);
            u = temp;
            scanf("%s", temp);
            v = temp;
            input.push_back(pair<string, string>(u, v));
            nameset.insert(u);
            nameset.insert(v);
        }

        set<string>::iterator it;
        int id = 0;
        for(it = nameset.begin(); it != nameset.end(); it++) {
            m[*it] = ++id;
        }

        for(int j = 0; j < input.size(); j++) {
            uni(m[input[j].first], m[input[j].second]);
            printf("%d\n", setsize[find_representative(m[input[j].second])]);
        }
    }

    return 0;
}
