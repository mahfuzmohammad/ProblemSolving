#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

#define maxn 100000

using namespace std;

vector< int > fact[maxn + 2];
double dp[maxn + 5];

void genFact() {

    for(int i = 1; i <= maxn; i++) {
        int sqi = sqrt(i);
        for(int j = 2; j <= sqi; j++) {
            if(i % j == 0) {
                fact[i].push_back(j);
                if((i / j) != j) {
                    fact[i].push_back(i / j);
                }
            }
        }
    }

}

void calc() {
    dp[1] = 0;

    for(int i = 2; i <= maxn; i++) {
        int factsize = fact[i].size();
        double temp = 2;
        for(int j = 0; j < factsize; j++) {
            temp += (dp[ i / fact[i][j] ] + 1);
        }

        dp[i] = temp;
        dp[i] /= (factsize + 1);
    }
}

int main() {
    genFact();
    calc();

    int T, N;

    scanf("%d", &T);
    for(int i = 1; i <= T; i++) {
        scanf("%d", &N);
        printf("Case %d: %0.7lf\n", i, dp[N]);
    }

    return 0;
}
