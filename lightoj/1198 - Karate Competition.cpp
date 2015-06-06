#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool des(int a, int b){return (a > b);}

int main()
{
    //freopen("input.txt", "r", stdin);
    int T, N, in, ans;
    bool isDelete;
    vector<int> a;
    vector<int> b;

    cin >> T;

    for(int i = 1; i <= T; i++){
        a.clear();
        b.clear();
        ans = 0;

        cin >> N;
        for(int j = 0; j < N; j++){cin >> in; a.push_back(in);}
        for(int j = 0; j < N; j++){cin >> in; b.push_back(in);}

        sort(a.begin(), a.end());
        sort(b.begin(), b.end(), des);

        for(int j = 0; j < a.size(); ){
            isDelete = false;
            for(int k = 0; k < b.size(); ){
                if(a[j] > b[k]){ans += 2; a.erase(a.begin() + j); b.erase(b.begin() + k); isDelete = true; break;}
                else{k++;}
            }

            if(!isDelete){j++;}
        }

        for(int j = 0; j < a.size(); ){
            isDelete = false;
            for(int k = 0; k < b.size(); ){
                if(a[j] == b[k]){ans += 1; a.erase(a.begin() + j); b.erase(b.begin() + k); isDelete = true; break;}
                else{k++;}
            }

            if(!isDelete){j++;}
        }

        cout << "Case " << i << ": " << ans << endl;
    }

    return 0;
}
