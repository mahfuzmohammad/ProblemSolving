#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);
    int t, n, w, ans;
    long long x, y;
    vector<long long> v;

    cin >> t;

    for(int i = 1; i <= t; i++){
        v.clear();
        ans = 0;
        cin >> n >> w;

        for(int j = 0; j < n; j++){
            cin >> x >> y;
            v.push_back(y);

        }
        sort(v.begin(), v.end());

        for(int j = 0; j < v.size(); ){
            long long k = v[j] + w;

            if(v[j] > k) j++;

            while(v[j] <= k && j < v.size()){
                j++;
            }

            ans++;
        }

        cout << "Case " << i << ": " << ans << endl;
    }

    return 0;
}
