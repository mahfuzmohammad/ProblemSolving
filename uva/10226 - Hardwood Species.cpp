#include <bits/stdc++.h>

using namespace std;

vector<string> v;
//set<string> s;
map<string, int> m;

int main() {
    //freopen("in.txt", "r", stdin);
    string tree;
    int tot = 0, t;

    scanf("%d", &t);
    getline(cin, tree);
    getline(cin, tree);

    for(int i = 0; i < t; i++) {
        v.clear();
        //s.clear();
        m.clear();
        tot = 0;

        while(getline(cin, tree)) {
            if(!tree[0]) {
                break;
            }

            v.push_back(tree);
            //s.insert(tree);
            //m[tree]++;
            //tot++;
        }

        if(i > 0) printf("\n");

        /*set<string>::iterator sit;
        for(sit = s.begin(); sit != s.end(); sit++) {
            m[*sit] = 0;
        }*/

        for(int j = 0; j < v.size(); j++) {
            m[v[j]]++;
        }

        map<string, int>::iterator mit;
        for(mit = m.begin(); mit != m.end(); mit++) {
            printf("%s %0.4lf\n", (mit->first).c_str(), double(double(mit->second) / double(v.size())) * 100.0 );
        }
    }

    return 0;
}
