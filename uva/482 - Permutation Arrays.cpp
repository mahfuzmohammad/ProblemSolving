#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <sstream>
#include <algorithm>

using namespace std;

typedef struct {
    int indx;
    string val;
} T;

vector<T> v;

bool sortIndx(T a, T b){
    return (a.indx < b.indx);
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int t, indx;
    string val;
    T temp;
    string line1, line2;

    scanf("%d", &t);
    getline(cin, line1);

    for(int i = 0; i < t; i++){
        getline(cin, line1);
        v.clear();
        if(i != 0) printf("\n");

        getline(cin, line1);
        getline(cin, line2);

        stringstream ss1, ss2;
        ss1 << line1; ss2 << line2;

        while(ss1 >> indx && ss2 >> val){
            temp.indx = indx;
            temp.val = val;
            v.push_back(temp);
        }

        sort(v.begin(), v.end(), sortIndx);

        for(int j = 0; j < v.size(); j++){
            cout << v[j].val << endl;
        }
    }

    return 0;
}
