#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> head, knights;

bool ascending(int a, int b){return a < b;}

int main(){
    int n, m, a, cost, h, k;
    cin >> n >> m;

    while(n!= 0 && m!=0){
        head.clear(); knights.clear();
        cost = 0;
        for(int i = 0; i < n; i++){cin >> a; head.push_back(a);}
        for(int i = 0; i < m; i++){cin >> a; knights.push_back(a);}
        if(n > m){cout << "Loowater is doomed!" << endl; cin >> n >> m; continue;}

        sort(head.begin(), head.end(), ascending);
        sort(knights.begin(), knights.end(), ascending);

        h = 0; k = 0;
        for( ; h < n && k < m; ){
            if(head[h] <= knights[k]){
                cost += knights[k];
                h++; k++;
            } else {k++;}
        }

        if(h < n){cout << "Loowater is doomed!" << endl;}
        else {cout << cost << endl;}
        cin >> n >> m;
    }

    return 0;
}
