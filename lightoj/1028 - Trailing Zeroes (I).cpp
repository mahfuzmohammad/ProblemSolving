#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

#define MAXN 5000000
#define i64 long long

using namespace std;

bool arr[MAXN + 2];
vector<int> prime;

void sieve(){

    int sqofSize = sqrt(MAXN);

    for(int i = 3; i <= sqofSize; i += 2){

        if(!arr[i]){
            int ii = i * i;
            int i2 = 2 * i;
            for(int j = ii; j <= MAXN; j += i2){
                arr[j] = true;
            }
        }

    }

}

void genPrime()
{
    sieve();
    prime.push_back(2);
    for(int i = 3; i <= MAXN; i+= 2){
        if(!arr[i]) prime.push_back(i);
    }
}

int primeFact(i64 n){
    i64 sqn = sqrt(n);
    //cout << "sq " << sqn << endl;
    int div = 0, ans = 1;

    for(int i = 0; prime[i] <= sqn; i++){
        while(n % prime[i] == 0){
            div++;
            n /= prime[i];
        }

        ans *= (div + 1);
        div = 0;

        sqn = sqrt(n);
    }

    if(n > 1){
        ans *= 2;
    }

    return ans;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    genPrime();
    int T;
    i64 N;
    cin >> T;

    for(int i = 1; i <= T; i++){
        cin >> N;
        cout << "Case " << i << ": " << primeFact(N) - 1 << endl;
    }

    return 0;
}
