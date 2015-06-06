#include <iostream>

using namespace std;


int main()
{
    int T, n, disorder;
    int arr[105];

    cin >> T;

    for(int i = 1 ; i <= T; i++)
    {
        cin >> n;
        disorder = 0;

        for(int j = 1; j <= n; j++)
        {
            cin >> arr[j];
        }

        //cout << "dis " << disorder << endl;

        for(int j = 1; j <= n; j++)
        {
            if(arr[j] != j)
            {
                for(int k = j + 1; k <= n; k++)
                {
                    if(arr[k] == j)
                    {
                        arr[k] = arr[j];
                        arr[j] = j;
                        disorder++;
                    }
                }
            }
        }

        cout << "Case " << i << ": " << disorder << endl;
    }

    return 0;
}
