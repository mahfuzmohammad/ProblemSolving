#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <stack>
#include <algorithm>

#define i64 long long

using namespace std;

i64 factval[20];

void genFact()
{
    i64 fact = 1;
    factval[0] = 1;
    for(int i = 1; i <= 19; i++) {fact *= i; factval[i]= fact;}
}

int main()
{
    //freopen("input.txt", "r", stdin);
    genFact();
    int T;
    i64 n;
    stack<int> stk;

    cin >> T;

    for(int i = 1; i <= T; i++) {
        cin >> n;

        while(!stk.empty())
            stk.pop();

        for(int j = 19; j >= 0; j--) {
            if(n >= factval[j]) {
                n -= factval[j];
                stk.push(j);
            }

            if(n == 0) break;
        }

        cout << "Case " << i << ": ";
        if(n != 0)
            cout << "impossible" << endl;
        else {
            cout << stk.top() << "!";
            stk.pop();
            while(!stk.empty()) {
                cout << "+" << stk.top() << "!";
                stk.pop();
            }

            cout << endl;
        }
    }

    return 0;
}
