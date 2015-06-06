// Bismillahir Rahmanir Rahim
// Author: Md Mahfuzur Rahman Siddiquee
#include <set>
#include <map>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int t, size, size2, sum;
	string name, name2, str, str2;
	char *cstr, *p;

	cin >> t;
	cin.ignore();

	for(int i = 1; i <= t; i++){

		name = "";
		name2 = "";
		sum = 0;

		getline(cin, str);

		cstr = new char[str.size() + 1];
		strcpy(cstr, str.c_str());

		p=strtok (cstr," ");

		while (p!=NULL)
		{
			name += p;
			p=strtok(NULL," ");
		}

		delete[] cstr;

		getline(cin, str2);

		cstr = new char[str2.size() + 1];
		strcpy(cstr, str2.c_str());

		p=strtok (cstr," ");

		while (p!=NULL)
		{
			name2 += p;
			p=strtok(NULL," ");
		}

		delete[] cstr;

		size = name.size();
		size2 = name2.size();

		if(size == size2){

			for (int j = 0; j < size; j++){
				sum += (toupper(name[j]) - toupper(name2[j]));
			}

			if(sum == 0){
				cout << "Case " << i << ": Yes" << endl;
			}

		} else {
			cout << "Case " << i << ": No" << endl;
		}

}


return 0;
}
