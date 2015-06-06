#include <bits/stdc++.h>

using namespace std;

vector<int> v;
bool vis[30];

int main() {

	ios_base::sync_with_stdio(0);
	// freopen("in", "r", stdin);

	int k;
	string str;

	cin >> k >> str;

	for(int i = 0; i < str.size(); i++) {

		if( !vis[ str[i] - 'a' ] ) {
			v.push_back(i);
			vis[ str[i] - 'a' ] = true;
		}

	}

	if( v.size() >= k ) {
		cout << "YES\n";
		for(int i = 1; i < k; i++) {
			cout << str.substr(v[i-1], v[i]-v[i-1]) << "\n";
		}

		cout << str.substr(v[k-1], str.size() - v[k-1]) << "\n";
	} else {
		cout << "NO\n";
	}
	
	return 0;
}