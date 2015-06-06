//Arrays are 0-indexed

#include <bits/stdc++.h>

using namespace std;

#define MAX_N 100000
#define LOG_TWO_N 20

int A[MAX_N + 5], SpTmin[MAX_N + 2][LOG_TWO_N + 2], SpTmax[MAX_N + 2][LOG_TWO_N + 2];
int n;

void reset() {
    memset(A, 0, sizeof A);
    memset(SpTmin, 0, sizeof SpTmin);
    memset(SpTmax, 0, sizeof SpTmax);
}

void RMQmin() {
	for(int i = 0; i < n; i++) {
		SpTmin[i][0] = i;
	}

	for(int j = 1; (1 << j) <= n; j++) {
		for(int i = 0; i + (1 << j) - 1 < n; i++) {
			if( A[ SpTmin[i][j - 1] ] < A[ SpTmin[i + (1 << (j - 1))][j - 1] ] )
				SpTmin[i][j] = SpTmin[i][j - 1];
			else
				SpTmin[i][j] = SpTmin[i + (1 << (j - 1))][j - 1];
		}
	}
}

int querymin(int i, int j) {
	int k = (int)floor( log((double)j - i + 1) / log(2.0) );
	if( A[ SpTmin[i][k] ] <= A[ SpTmin[j - (1 << k) + 1][k] ] ) return SpTmin[i][k];
	return SpTmin[j - (1 << k) + 1][k];
}

void RMQmax() {
	for(int i = 0; i < n; i++) {
		SpTmax[i][0] = i;
	}

	for(int j = 1; (1 << j) <= n; j++) {
		for(int i = 0; i + (1 << j) - 1 < n; i++) {
			if( A[ SpTmax[i][j - 1] ] > A[ SpTmax[i + (1 << (j - 1))][j - 1] ] )
				SpTmax[i][j] = SpTmax[i][j - 1];
			else
				SpTmax[i][j] = SpTmax[i + (1 << (j - 1))][j - 1];
		}
	}
}

int querymax(int i, int j) {
	int k = (int)floor( log((double)j - i + 1) / log(2.0) );
	if( A[ SpTmax[i][k] ] >= A[ SpTmax[j - (1 << k) + 1][k] ] ) return SpTmax[i][k];
	return SpTmax[j - (1 << k) + 1][k];
}

int main() {
    //freopen("in.txt", "r", stdin);
	int t, ans = 0, d;

    scanf("%d", &t);

	for(int i = 1; i <= t; i++) {
	    reset();
	    ans = 0;
        scanf("%d %d", &n, &d);

        for(int j = 0; j < n; j++) {
            scanf("%d", &A[j]);
        }

        RMQmin();
        RMQmax();

        for(int j = 0; j <= n - d; j++) {
            ans = max(ans, A[querymax(j, j + d - 1)] - A[querymin(j, j + d - 1)]);
        }

        printf("Case %d: %d\n", i, ans);
	}

	return 0;
}

