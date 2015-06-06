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
    int t, n, m, input, x, y;
    char charIn;

    cin >> t;

    for(int i = 1; i <= t; i++){
        cin >> n >> m;
        int *arr = new int[n];

        for(int j = 0; j < n; j++){
            cin >> input;
            arr[j] = input;
            //cout << input << endl;
        }

        for(int k = 0; k < m; k++){

            cin >> charIn;
            //cout << charIn;

            if (charIn == 'S'){

                cin >> input;

                for(int j = 0; j < n; j++){
                    arr[j] += input;
                }

                continue;

            } else if (charIn == 'M'){

                cin >> input;

                for(int j = 0; j < n; j++){
                    arr[j] *= input;
                }

                continue;

            } else if (charIn == 'D'){

                cin >> input;

                for(int j = 0; j < n; j++){
                    arr[j] /= input;
                }

                continue;

            } else if (charIn == 'P'){

                cin >> x >> y;
                //cout << x << y << endl;

                swap(arr[x], arr[y]);

                continue;

            } else if (charIn == 'R'){

                reverse(arr, arr + n);

                continue;

            }

        }//for m

        cout << "Case " << i << ":" << endl;

        for(int l = 0; l < n; l++){
            cout << arr[l];
            if(l < n - 1){
                cout << " ";
            }
        }

        cout << endl;

        delete[] arr;


    }


    return 0;
}
