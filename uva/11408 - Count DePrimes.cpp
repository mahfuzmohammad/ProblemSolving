#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

#define maxsize 5000000
#define MAXN    5000000

using namespace std;

int arr[maxsize + 2];
int ans[MAXN + 2];

void sieve(){
    //int sqofSize = sqrt(maxsize);
    int loopsize = maxsize / 2;
    for(int i = 2; i <= loopsize; i++){
        if(arr[i] == 0){
            int ii = i * i;
            int i2 = 2 * i;
            for(int j = i2; j <= maxsize; j += i){
                arr[j] = 1;
                ans[j] += i;
            }
        }
    }
}

bool isPrime(int n){
    if(n == 2) return true;
    if(n % 2 == 1 && arr[n] == 0)
        return true;
    return false;
}

void genAns() {
    sieve();
    for(int i = 2; i <= MAXN; i++) {
        if(isPrime(i) || isPrime(ans[i])) {
            ans[i] = ans[i - 1] + 1;
        } else {
            ans[i] = ans[i - 1];
        }
    }
}

int main() {
    genAns();
    //cout << "TEST" << endl;

    int a, b;
    cin >> a;

    while(a != 0) {
        cin >> b;
        cout << ans[b] - ans[a - 1] << endl;
        cin >> a;
    }

    return 0;
}
