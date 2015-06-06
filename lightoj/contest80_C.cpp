#include <iostream>
#include <cmath>

using namespace std;

int main(){
    long long t, dashF, sqRt, count, i, j;

    cin >> t;

    for(i = 1; i <= t ; i++){

        count = 0;
        cin >> dashF;
        sqRt = sqrt(dashF);

        if(dashF % 2 != 0){

            for(j = 1; j <= sqRt; j += 2){

                if(dashF % j == 0){
                    ++count;
                }

            }

        } else {

            for(j = 1; j <= sqRt; j ++){

                if(dashF % j == 0){
                    ++count;
                }

            }

        }


        cout << "Case " << i << ": " << count << endl;

    }

    return 0;
}
