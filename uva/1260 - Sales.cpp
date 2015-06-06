#include <bits/stdc++.h>

using namespace std;

const int N = 5000;
int tree[N+5];

// add v to value at x
void add(int x, int v) {
  while(x <= N) {
    tree[x] += v;
    x += (x & -x);
  }
}

// get cumulative sum up to and including x
int get(int x) {
  int res = 0;
  while(x) {
    res += tree[x];
    x -= (x & -x);
  }
  return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    int t, n, a, sum;
    cin >> t;

    for(int i = 0; i < t; i++) {
        memset(tree, 0, sizeof tree);
        sum = 0;
        cin >> n;
        for(int j = 0; j < n; j++) {
            cin >> a;
            sum += get(a);
            add(a, 1);
        }

        cout << sum << "\n";
    }

    return 0;
}
