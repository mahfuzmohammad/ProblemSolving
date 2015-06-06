#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

bool sortDes(int a, int b){return (a > b);}

int main()
{
    //freopen("input.txt", "r", stdin);
    int t, n, r, prev, k, temp;
    bool flag;
    vector<int> diff;
    scanf("%d", &t);

    for(int i = 1; i <= t; i++){
        diff.clear();
        flag = false;
        scanf("%d", &n);
        prev = 0;
        k = 0;

        for(int j = 0; j < n; j++){
            scanf("%d", &r);
            temp = abs(r - prev);
            diff.push_back(temp);
            k = max(k, temp);
            prev = r;
        }

        temp = k;
        for(int j = 0; j < n; j++){
            if(diff[j] == temp) --temp;
            else if((diff[j] > temp || temp == 0)){flag = true; break;}
        }

        printf("Case %d: %d\n", i, (flag)?k+1:k);
    }

    return 0;
}
