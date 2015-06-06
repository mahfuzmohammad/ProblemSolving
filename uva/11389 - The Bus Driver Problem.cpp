#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>

#define MAXN 100

using namespace std;

vector<int> m, e;
bool marked[MAXN + 5];

bool asc(int a, int b){return a < b;}
bool des(int a, int b){return a > b;}

void reset()
{
    m.clear(); e.clear();
    for(int i = 0; i <= MAXN; i++){
        marked[i] = false;
    }
}

int main()
{
    int n, d, r, in, ans;
    cin >> n >> d >> r;

    while(n != 0 && d != 0 && r != 0){
        reset(); ans = 0;
        for(int i = 0; i < n; i++){
            cin >> in;
            m.push_back(in);
        }

        for(int j = 0; j < n; j++){
            cin >> in;
            e.push_back(in);
        }

        sort(m.begin(), m.end(), asc);
        sort(e.begin(), e.end(), des);

        for(int i = 0; i < n; i++){
            if(e[i] + m[i] > d){
                ans += (e[i] + m[i] - d);
            }
        }

        cout << ans * r << endl;
        cin >> n >> d >> r;
    }

    return 0;
}
