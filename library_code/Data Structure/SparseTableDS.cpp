//Arrays are 0-indexed

#include <bits/stdc++.h>

using namespace std;

#define MAX_N 1000
#define LOG_TWO_N 10

int A[MAX_N + 5], SpT[MAX_N + 2][LOG_TWO_N + 2];
int n;

void RMQ() {
	for(int i = 0; i < n; i++) {
		SpT[i][0] = i;
	}

	for(int j = 1; (1 << j) <= n; j++) {
		for(int i = 0; i + (1 << j) - 1 < n; i++) {
			if( A[ SpT[i][j - 1] ] < A[ SpT[i + (1 << (j - 1))][j - 1] ] )
				SpT[i][j] = SpT[i][j - 1];
			else
				SpT[i][j] = SpT[i + (1 << (j - 1))][j - 1];
		}
	}
}

int query(int i, int j) {
	int k = (int)floor( log((double)j - i + 1) / log(2.0) );
	if( A[ SpT[i][k] ] <= A[ SpT[j - (1 << k) + 1][k] ] ) return SpT[i][k];
	return SpT[j - (1 << k) + 1][k];
}

int main() {
	int q, x, y;
	scanf("%d %d", &n, &q);

	for(int i = 0; i < n; i++) {
		scanf("%d", &A[i]);
	}

	RMQ();

	for(int i = 0; i < q; i++) {
		scanf("%d %d", &x, &y);
		printf("%d\n", query(x, y));
	}

	return 0;
}
