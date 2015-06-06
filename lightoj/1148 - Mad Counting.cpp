#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int arr[1000001];
bool mark[1000001];

void reset()
{
    for(int i = 0; i <= 1000000; i++){
        arr[i] = 0;
        mark[i] = false;
    }
}

inline int min_population(int num, int x)
{
    if(num % (x + 1) == 0) return num;

    return (((num / (x + 1)) + 1) * (x + 1));
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int T, N, temp, ans, vSize;
    vector<int> v;
    scanf("%d", &T);

    for(int i = 1; i <= T; i++){
        reset(); ans = 0;
        v.clear();
        scanf("%d", &N);
        for(int j = 0; j < N; j++){
            scanf("%d", &temp);
            arr[temp]++;
            if(!mark[temp]){
                v.push_back(temp);
                mark[temp] = true;
            }
        }

        vSize = v.size();
        //sort(v.begin(), v.end());

        for(int j = 0; j < vSize; j++){
            ans += min_population(arr[v[j]], v[j]);
        }

        printf("Case %d: %d\n", i, ans);
    }

    return 0;
}
