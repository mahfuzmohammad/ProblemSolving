#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> odd;
vector<int> input;

void genOdd()
{
    long long j = 1;
    for(int i = 0; i < 100000; i++){
        odd.push_back(j);
        j += 2;
    }
}

long long genAns(long long n)
{
    long long sum = 0;
    sum += ((n - 1) * (input[0] - input[n - 1]));

    for(long long i = 1; i < n - 1; i++){
        sum += ((n - odd[i]) * input[i]);
    }

    return sum;
}

long long update(int x, long long v, long long n, long long curr){
    long long sum = curr;
    if(x == 0) {
        sum -= ((n - 1) * input[x]);
        sum += ((n - 1) * v);
        input[x] = v;
    } else if(x == n - 1) {
        sum += ((n - 1) * input[x]);
        sum -= ((n - 1) * v);
        input[x] = v;
    } else {
        sum -= ((n - odd[x]) * input[x]);
        sum += ((n - odd[x]) * v);
        input[x] = v;
    }

    return sum;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    genOdd();
    int T, x, c;
    long long n, q, data, v, sum;
    scanf("%d", &T);

    for(int i = 1; i <= T; i++){
        input.clear();
        scanf("%lld %lld", &n, &q);
        for(int j = 0; j < n; j++){
            scanf("%d", &data);
            input.push_back(data);
        }

        sum = genAns(n);
        printf("Case %d:\n", i);

        for(int j = 0; j < q; j++){
            scanf("%d", &c);
            if(c == 1){
                printf("%lld\n", sum);
            } else {
                scanf("%d %lld", &x, &v);
                sum = update(x, v, n, sum);
            }
        }
    }

    return 0;
}
