// Bismillahir Rahmanir Rahim
// Author: Md Mahfuzur Rahman Siddiquee
#include <iostream>
#include <cstdio>

using namespace std;

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    string str;
    long long t, i, p, q, length;
    bool status;

    cin >> t;

    for(i = 1; i <= t; i++){

        cin >> str;
        p = 0;
        length = str.length();
        q = length - 1;
        status = true;

        while(p < q){

            if(str[p] != str[q]){
                status = false;
                break;
            }

            ++p;
            --q;

        }

        cout << "Case " << i << ": ";
        if(status)
            cout << "Yes";
        else
            cout << "No";

        cout << endl;

    }

    return 0;
}
