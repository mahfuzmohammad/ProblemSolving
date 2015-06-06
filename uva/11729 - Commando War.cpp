#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct job {
    int b, j;
    job(int b, int j):b(b), j(j){}
};

vector<job> v;

bool descending(job a, job b){
    return (a.j > b.j);
}

int main()
{
    int N, B, J, cost, cas = 0, ans;
    cin >> N;

    while(N != 0){
        v.clear();
        cost = 0; ans = 0;
        for(int i = 0; i < N; i++){
            cin >> B >> J;
            v.push_back(job(B, J));
        }

        sort(v.begin(), v.end(), descending);

        for(int i = 0; i < N; i++){
            cost += v[i].b;
            ans = max(ans, cost + v[i].j);
        }

        cout << "Case " << ++cas << ": " << ans << endl;
        cin >> N;
    }

    return 0;
}
