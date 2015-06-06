#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>

#define i64 long long

using namespace std;

int getExp(i64 a){
    i64 temp = 1;
    int count = 0;

    while(temp < a){
        ++count;
        temp = temp << 1;
    }

    return count;
}

int main()
{
    int t;
    long long n;

    cin >> t;

    for(int i = 1; i <= t; i++){
        cin >> n;
        cout << "Case " << i << ": " << getExp(n + 1) << endl;
    }

    return 0;
}
