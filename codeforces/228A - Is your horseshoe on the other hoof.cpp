#include <iostream>
#include <cstdio>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
    int n = 0, s;
    set<int> st;

    while(cin >> s){
        st.insert(s);
        ++n;
    }

    cout << n - st.size() << endl;

    return 0;
}
