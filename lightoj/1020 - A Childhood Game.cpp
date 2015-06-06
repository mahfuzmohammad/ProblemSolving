#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int T, n;
    string name;

    cin >> T;

    for(int i = 1; i <= T; i++){
        cin >> n >> name;
        cout << "Case " << i << ": ";
        if(name == "Bob"){
            if(n % 3 == 0){cout << "Alice" << endl;}
            else {cout << "Bob" << endl;}
        } else {
            if((n - 1) % 3 == 0){cout << "Bob" << endl;}
            else {cout << "Alice" << endl;}
        }
    }

    return 0;
}
