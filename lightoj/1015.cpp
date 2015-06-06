#include <iostream>
using namespace std;

int main(){

    int t, dust, student, input;

    cin >> t;

    for(int i = 1; i <= t; i++){
        cin >> student;
        dust = 0;

        for(int j = 0; j < student; j++){
            cin >> input;
            if(input >= 0){
                 dust += input;
            }
        }

        cout << "Case " << i << ": " << dust << endl;
    }

    return 0;
}
