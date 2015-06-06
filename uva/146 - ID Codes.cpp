#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);
    string str, str1;

    while(cin >> str){
        if(str == "#") break;
        str1 = str;
        next_permutation(str1.begin(), str1.end());
        if(str1 > str){
            cout << str1  << endl;
        } else {
            cout << "No Successor" << endl;
        }
    }

    return 0;
}
