//UVA 10327 - Flip Sort.cpp

#include <iostream>
#include <cstdio>

#define MAXN 1000

using namespace std;

int arr[MAXN + 5];

int main()
{
    //freopen("input.txt", "r", stdin);
    int n, move;

    while(cin >> n) {
        move = 0;
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }

        for(int y = 0; y < n; y++)
        {
            for ( int k =0; k < n -1-y; k++ )
                if(arr[k] > arr[k+1])
                {
                    ++move;
                    int temp = arr[k+1];
                    arr[k+1] = arr[k];
                    arr[k] = temp;
                }
        }

        cout << "Minimum exchange operations : " << move << endl;
    }//end of while

    return 0;
}
