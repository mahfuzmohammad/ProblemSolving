#include <iostream>
#include <cstdio>
#include <cmath>

#define size 5000000

using namespace std;

unsigned long long t[size + 5];

void EulerTotient(){
    unsigned long long sum = 0;

    for(int i = 2; i <= size; i++)
        t[i] = i;

    for(int i = 1; i <= size; i++){
        if(t[i] == i)//check whether not processed
        {
            for(int k = i; k <= size; k+= i){
                t[k] /= i; t[k] *= (i - 1);
            }
        }

        if(i >= 2)
        {
            sum += (t[i] * t[i]);
            t[i] = sum;
        }
    }
}// end of eulertotient

int main(){
    EulerTotient();
    int tC, a, b;

    cin >> tC;

    for(int i = 1; i <= tC; i++)
    {
        cin >> a >> b;
        cout << "Case " << i << ": " << t[b] - t[a - 1] << endl;
    }


    return 0;
}
