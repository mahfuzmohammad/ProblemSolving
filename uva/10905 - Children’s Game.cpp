#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> v;

bool cmp(string a, string b){
    string xy = a + b;
    string yx = b + a;
    return (xy > yx);
}

int main()
{
    int n;
    string str;

    cin >> n;

    while(n != 0){
        v.clear();
        for(int i = 0; i < n; i++){
            cin >> str;
            v.push_back(str);
        }

        sort(v.begin(), v.end(), cmp);
        for(int i = 0; i < n; i++){
            cout << v[i];
        }
        cout << endl;
        cin >> n;
    }

    return 0;
}
