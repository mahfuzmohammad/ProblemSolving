//In the name of Allah, most Gracious, most Compassionate
//Algorithm: Suffix Array
//Runtime: O(n log n)
//Input string up to 10^5

#include <bits/stdc++.h>

using namespace std;

#define MAX_N 100010

char T[MAX_N]; //input string
int n; //the length of input string
int RA[MAX_N], tempRA[MAX_N]; //rank array and temporary rank array
int SA[MAX_N], tempSA[MAX_N]; //suffix array and temporary suffix array
int c[MAX_N]; //for counting/radix sort

void countingSort(int k) { // O(n)
	int i, sum, maxi = max(300, n); //up to 255 ASCII chars or length of n
	memset(c, 0, sizeof c);

	for (int i = 0; i < n; ++i) { //count the frequency of each integer rank
		c[i + k < n ? RA[i + k] : 0]++;
	}

	for (int i = sum = 0; i < maxi; ++i) { //cumulative sum
		int t = c[i]; c[i] = sum; sum += t;
	}

	for (int i = 0; i < n; ++i) { //suffle the suffix array if necessary
		tempSA[c[SA[i] + k < n ? RA[SA[i] + k] : 0]++] = SA[i];
	}

	for (int i = 0; i < n; ++i) { //update the suffix array SA
		SA[i] = tempSA[i];
	}
}

void constructSA() {
	int i, k, r;
	for (i = 0; i < n; i++) RA[i] = T[i]; //initial ranking
	for (i = 0; i < n; i++) SA[i] = i; //initial SA : {0, 1, 2, ... , n - 1}
	for (k = 1; k < n; k <<= 1) { //repear sorting process log n times
		countingSort(k); //actually radix sort: sort based on the second item
		countingSort(0); //then (stable) sort based on the first item
		tempRA[SA[0]] = r = 0; //re-ranking; start from r = 0
		for (i = 1; i < n; i++) {
			tempRA[SA[i]] = (RA[SA[i]] == RA[SA[i-1]] && RA[SA[i]+k] == RA[SA[i-1] + k]) ? r : ++r;
		}

		for (i = 0; i < n; i++) { //update the rank array RA
			RA[i] = tempRA[i];
		}

		if (RA[SA[n-1]] == n-1) break; //optimization trick
	}
}

int main()
{
	//freopen("in", "r", stdin);
	scanf("%s", T);
	n = (int)strlen(T);
	T[n++] = '$';
	constructSA();

	for (int i = 0; i < n; i++) {
		printf("%2d\t%s\n", SA[i], T + SA[i]);
	}

	return 0;
}