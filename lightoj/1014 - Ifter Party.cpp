#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);
    int t, p, l;
    stack<long long> st;

    cin >> t;

    for(int i = 1; i <= t; i++){
        cin >> p >> l;
        int num = p - l;
        cout << "Case " << i << ":";

        if(num <= l) {
            cout << " impossible" << endl;
            continue;
        }

        int sqnum = sqrt(num);

        for(int j = 1; j <= sqnum; j++){
            if(num % j != 0)
                continue;

            if(j > l)
                cout << " " << j;

            int temp = num / j;

            if(temp > l && temp != j)
                st.push(temp);
        }

        while(!st.empty()){
            cout << " " << st.top();
            st.pop();
        }

        cout << endl;
    }

    return 0;
}
