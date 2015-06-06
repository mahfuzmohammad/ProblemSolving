#include <iostream>
#include <cstdio>


using namespace std;

int main(){
    double *xi, *yi, count, *diff, last;
	int t, n;

    cin >> t;

    for(int i = 1; i <= t; i++){

        cin >> n;
        count = 1;

        xi = new double[n];
        yi = new double[n];
        diff = new double[n - 1];

        for(int j = 0; j < n; j++){
            cin >> xi[j] >> yi[j];

            //diff[j] = xi[j] - yi[j];
        }

        for(int j = 0; j < n - 1; j++){
            diff[j] = (yi[j] - yi[j+1]) / (xi[j] - xi[j+1]);
        }

        last = diff[0];

        for(int j = 1; j < n - 1; j++){

            if(last != diff[j]){
                ++count;
                //last = diff[j];
            }

        }

	    /*for(int j = 0; j < n - 1; j++){
		    cout << diff[j] << endl;
	    }*/

        cout << "Case " << i << ": " << count << endl;
    }

    return 0;
}
