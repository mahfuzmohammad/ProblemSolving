#include <bits/stdc++.h>

using namespace std;

struct obj {
    string name;
    int id;
    obj(){}
    obj(string a, int _id):name(a), id(_id){}
};

vector<obj> v;

bool cmp(obj a, obj b) {
    return a.name < b.name;
}

int main() {
    ios_base::sync_with_stdio(0);
    int n, x;
    string f, s;
    cin >> n;

//    memset(pos, -1, sizeof pos);
    for(int i = 0; i < n; i++) {
        cin >> f >> s;
        //arr[i] = pair<string, string>(f, s);
        v.push_back(obj(f, i));
        v.push_back(obj(s, i));
    }

    sort(v.begin(), v.end(), cmp);

//    for(int i = 0; i < v.size(); i++) {
//        if(pos[v[i].id] == -1) {
//            pos[v[i].id] = i;
//        }
//    }

//    for(int i = 0; i < v.size(); i++) {
//        cout << v[i].name << " " << v[i].id << "\n";
//    }
//
//    for(int i = 0; i < n; i++) {
//        cout << pos[i] << " ";
//    }
//    cout << endl;

    int curr = 0, found = 0;
    for(int i = 0; i < n; i++) {
        cin >> x;
        x--;

        while(curr < v.size()) {
            if(v[curr++].id == x) {
                found++;
                break;
            }
        }
    }

    if(found == n) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}
