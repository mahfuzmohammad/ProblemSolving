#include <iostream>
using namespace std;

int main(){
    int m, n, result, left;
    unsigned int t;

    cin >> t;

    for(unsigned int i = 1; i <= t; i++){
        left = 0;
        cin >> m >> n;


        if(m == 1 || n == 1){
            cout << "Case " << i << ": " << m * n << endl;
        } else if(m == 2 || n == 2){
            result = (m * n) / 4;
            if(result > 1 && result % 2 != 0){
                result = (result + 1) / 2;
            }else if(result % 2 == 0){
                result /= 2;
                left = (m * n) - (result * 8);
            }
            cout << "Case " << i << ": " << (result * 4) + left << endl;
        } else if((m * n) % 2 == 0){
            cout << "Case " << i << ": " << (m * n) / 2 << endl;
        } else {
            cout << "Case " << i << ": " << ((m * n) + 1) / 2 << endl;
        }
    }

    return 0;
}
