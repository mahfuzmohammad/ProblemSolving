#include <bits/stdc++.h>

using namespace std;

bool m[105][105];

int main() {

	int n, k, pos;
	cin >> n >> k;

	pos = ((n*n)+1) >> 1;

	if( k > pos ) {
		cout << "NO\n";
	} else {

		cout << "YES\n";
		for(int i = 0; i < n; i++) {
			for(int j = i%2; j < n && k > 0; j+=2, k--) {
				m[i][j] = true;
			}
		}

		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				if(m[i][j]) {
					cout << "L";
				} else {
					cout << "S";
				}
			}
			cout << "\n";
		}

	}


	return 0;
}