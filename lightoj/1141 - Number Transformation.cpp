#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <stack>
#include <queue>
#include <algorithm>

#define SIZE 1000000
#define IMPOSSIBLE 100000

using namespace std;

int cost[102][1002];
bool arr[SIZE + 1];
vector<int> primes;
vector<int> primFact[1002];
int PrimeSize;

void reset()
{
    for(int i = 0; i <= 100; i++)
        for(int j = 0; j <= 1000; j++)
            if(i == j) cost[i][j] = 0;
            else cost[i][j] = IMPOSSIBLE;
}

void sieve(){
    int sqofSize = sqrt(SIZE);
    for(int i = 3; i <= sqofSize; i += 2){
        if(arr[i] == 0){
            int ii = i * i;
            int i2 = 2 * i;
            for(int j = ii; j <= SIZE; j += i2){
                arr[j] = true;
            }
        }
    }
}

bool isPrime(int n){
    if(n == 2) return true;
    if(n % 2 == 1 && !arr[n])
        return true;
    return false;
}

void genPrimes()
{
    sieve();
    for(int i = 2; i <= SIZE; i++)
        if(isPrime(i))
            primes.push_back(i);

    PrimeSize = primes.size();
}

void primeFactorize(int n){

    for(int i = 0; primes[i] < n; i++){
        if(n % primes[i] == 0) {
            primFact[n].push_back(primes[i]);
        }
    }
}

void BFS(int a)
{
    queue<int> q;
    cost[a][a] = 0;
    q.push(a);

    while(!q.empty())
    {
        int u = q.front();
        q.pop();

        for(int i = 0; i < primFact[u].size(); i++){
            if((u + primFact[u][i] <= 1000) && (cost[a][u + primFact[u][i]] >= cost[a][u] + 1)){
                cost[a][u + primFact[u][i]] = cost[a][u] + 1;
                q.push(u + primFact[u][i]);
                //cout << u << " " << u + primFact[u][i] << endl;
            }
        }
    }
}

void genCost()
{
    reset();
    genPrimes();
    for(int i = 1; i <= 1000; i++){
        primeFactorize(i);
    }

    for(int i = 1; i <= 100; i++){
        BFS(i);
    }
}


int main()
{
    //freopen("input.txt", "r", stdin);
    genCost();

    int T, s, t;
    scanf("%d", &T);

    for(int i = 1; i <= T; i++){
        scanf("%d %d", &s, &t);
        printf("Case %d: %d\n", i, ((cost[s][t] == IMPOSSIBLE)?-1:cost[s][t]));
    }

    return 0;
}
