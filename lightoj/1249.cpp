// Bismillahir Rahmanir Rahim
// Author: Md Mahfuzur Rahman Siddiquee
#include <set>
#include <map>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int t, n, x, y, z;
    string name[100];
    long long vol[100];
    long long *max, *min;
    bool flag;

    cin >> t;

    for(int i = 1; i <= t; i++){
        flag = true;
        cin >> n;

        for(int j = 0; j < n; j++){
            cin >> name[j] >> x >> y >> z;
            vol[j] = x * y * z;
        }

        max = max_element(vol, vol + n);
        min = min_element(vol, vol + n);

        cout << "Case " << i << ": ";

        if(*max == *min){
            cout << "no thief" << endl;
            continue;
        }/* else {

            for(int j = 0; j < n; j++){

                if(j == max - vol){
                    continue;
                } else {

                    if(*min != vol[j]){
                        flag = false;
                        break;
                    }

                }

            }//end of for

        }// end of if*/

        cout << name[max - vol];

        /*if(flag){
            cout << " took chocolate from all" << endl;
        } else {*/
            cout << " took chocolate from " << name[min - vol] << endl;
        //}

    }

    return 0;
}
