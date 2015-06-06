#include <iostream>
	#include <string>
	#include <sstream>

	using namespace std;

int main(){
	int t;
	long long a, b, number, counter, temp;

	cin >> t;

	for(int i = 1; i <= t; i++){

		number = 0;
		counter = 0;
		cin >> a >> b;

		if(a == b){

			if( a % 3 == 0 || (a + 1) % 3 == 0 ){
				++counter;
			}

			cout << "Case " << i << ": " << counter << endl;
			continue;

		} else {

			if(a % 3 == 0){
				temp = a + 1;
				counter = (b + 1 - temp) / 3;
				if( (b + 1 - temp) % 3 != 0){
					counter++;
				}
			} else if( (a + 1) % 3 == 0 ){
				temp = a + 2;
				counter = (b + 1 - temp) / 3;
				if( (b + 1 - temp) % 3 != 0){
					counter++;
				}
			} else {
				//temp
				counter = (b + 1 - a) / 3;
				//cout << a << " " << b <<"test" <<endl;
				if( (b + 1 - a) % 3 != 0){
					counter++;
				}
			}

		}

		cout << "Case " << i << ": " << b + 1 - a - counter << endl;

	}

	return 0;
}
