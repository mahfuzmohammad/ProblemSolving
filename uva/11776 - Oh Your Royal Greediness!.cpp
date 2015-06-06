#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

enum timetype {s, e};

struct info {
    int t;
    timetype tp;
    info(int a, timetype b):t(a), tp(b){}
};

vector<info> v;

bool comp(info a, info b){
    if(a.t == b.t) return (a.tp < b.tp);
    return a.t < b.t;
}

int main()
{
    int N, S, E, count, ans, cas = 0;
    //timetype temp;

    cin >> N;

    while(N != -1){
        v.clear(); count = 0; ans = 0;

        for(int i = 0; i < N; i++){
            cin >> S >> E;
            v.push_back(info(S, s));
            v.push_back(info(E, e));
        }

        sort(v.begin(), v.end(), comp);
        int vSize = N << 1;

        for(int i = 0; i < vSize; i++){
            if(v[i].tp == s){
                count++;
            } else {
                count--;
            }

            ans = max(ans, count);
        }

        cout << "Case " << ++cas << ": " << ans << endl;
        cin >> N;
    }

    return 0;
}
