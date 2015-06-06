#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <cstdio>

using namespace std;

int small(const vector<int> a, const int i, const int j){
    int smallNum = a[0], curr;

    for(int l = i; l < j; l++){

        for(int m = l + 1; m <= j; m++){
            curr = abs(a[l] - a[m]);
            //cout << "in " << l << " " << m << " " << curr << endl;

            if(curr == 0){
                return curr;
            } else {
                smallNum = (smallNum > curr) ? curr : smallNum;
                //cout << smallNum << endl;
            }
        }

    }

    return smallNum;
}

int main(){
    //freopen("input.txt", "r", stdin);
    int t, n, q, input, i, j;
    vector<int> vect;

    cin >> t;

    for(int k = 1; k <= t; k++){
        cout << "Case " << k << ":" << endl;
        cin >> n >> q;

        for(int l = 0; l < n; l++){
            cin >> input;
            vect.push_back(input);
        }

        /*for(int l = 0; l < n - 1; l++){
            cout << vect2[l] << " ";
        }

        cout << endl;*/

        for(int l = 0; l < q; l++){
            cin >> i >> j;
            cout << small(vect, i, j) << endl;
        }



        vect.clear();
    }


    return 0;
}
