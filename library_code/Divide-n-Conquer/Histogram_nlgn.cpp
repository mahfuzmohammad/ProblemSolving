//Arrays are 0-indexed

#include <bits/stdc++.h>

using namespace std;

#define MAX_N 30000
#define LOG_TWO_N 20

int A[MAX_N + 5], SpT[MAX_N + 2][LOG_TWO_N + 2];
int n;

void reset() {
    memset(A, 0, sizeof A);
    memset(SpT, 0, sizeof SpT);
}

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

int calc(int l, int r) {
    if(l > r) return -1;
    int mn = query(l, r);
    int mx = (r - l + 1) * A[mn];
    mx = max(mx, max(calc(l, mn - 1), calc(mn + 1, r)));
    return mx;
}

int main() {
    //freopen("in.txt", "r", stdin);
	int t, ans;

    scanf("%d", &t);

	for(int i = 1; i <= t; i++) {
	    reset();
        scanf("%d", &n);

        for(int j = 0; j < n; j++) {
            scanf("%d", &A[j]);
        }

        RMQ();

        ans = calc(0, n - 1);
        printf("Case %d: %d\n", i, ans);
	}

	return 0;
}

