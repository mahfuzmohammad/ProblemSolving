//Geometry
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

vector<ii> v;

bool cmp(ii a, ii b) {
    if(a.first == b.first) return (a.second > b.second);
    return (a.first < b.first);
}

double dist(int i, int j) {
    return sqrt( (v[i].first - v[j].first)*(v[i].first - v[j].first)
                +(v[i].second - v[j].second)*(v[i].second - v[j].second) );
}

int main() {
    //freopen("input.txt", "r", stdin);
    int t, pnum, x, y;
    scanf("%d", &t);

    for(int i = 0; i < t; i++) {
        v.clear();
        scanf("%d", &pnum);

        for(int j = 0; j < pnum; j++) {
            scanf("%d %d", &x, &y);
            v.push_back(ii(x, y));
        }

        sort(v.begin(), v.end(), cmp);

        /*for(int j = 0; j < v.size(); j++) {
            cout << j << " " << v[j].first << " " << v[j].second << endl;
        }
        cout << endl;*/

        double ans = dist(v.size() - 1, v.size() - 2);
        int maxy = v[v.size() - 2].second;

        for(int j = v.size() - 2; j >= 0; j--) {
            if(v[j].second > maxy) {
                double d = dist(j, j+1);
                ans += (d - ((d * (maxy-v[j+1].second)) / (v[j].second-v[j+1].second)));
                //cout << j << " " << maxy << " " << ans << " " << dist(j, j+1) << endl;
                maxy = v[j].second;
            }
        }

        printf("%0.2lf\n", ans);
    }

    return 0;
}
