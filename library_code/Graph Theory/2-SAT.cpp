// 2 SAT satisfy and truth assignment
// LightOj 1251 - http://www.lightoj.com/volume_showproblem.php?problem=1251

#include <bits/stdc++.h>

using namespace std;

#define _MAXM 16000

// adj. list for original and transposed graph
vector<int> graph[_MAXM+5], graphT[_MAXM+5];
int vis[_MAXM+5]; // stores visiting time/order
stack<int> S; // stores top-sort order
int timer = 0;

vector<int> res; // stores result

void dfs1(int x) {
	vis[x] = -1; // set visited

	for(int i = 0; i < graph[x].size(); i++) {
		if( vis[ graph[x][i] ] != -1 )
			dfs1( graph[x][i] );
	}

	S.push(x);
}

void dfs2(int x) {
	vis[x] = timer;

	for(int i = 0; i < graphT[x].size(); i++) {
		if( vis[ graphT[x][i] ] == -1 )
			dfs2( graphT[x][i] );
	}
}

// reset
void reset() {
	timer = 0;
	res.clear();
	for(int i = 0; i <= _MAXM; i++) {
		graph[i].clear();
		graphT[i].clear();
		vis[i] = 0;
	}
}

int main() {
	// freopen("../in", "r", stdin);
	int T, n, m, a, b;
	scanf("%d", &T);

	for(int t = 1; t <= T; t++) {

		reset();
		scanf("%d %d", &n, &m);
		for(int j = 0; j < n; j++) {
			scanf("%d %d", &a, &b);

			// add edges
			// m-x ~ -x and m+x ~ +x
			graph[m-a].push_back(m+b);
			graph[m-b].push_back(m+a);

			graphT[m+b].push_back(m-a);
			graphT[m+a].push_back(m-b);
		}

		for(int i = 1; i <= m; i++) {
			// swap the if statements to maximize + class
			// now maximizing - class
			if( !vis[m-i] )
				dfs1( m-i );
			if( !vis[m+i] )
				dfs1( m+i );
		}

		while(!S.empty()) {
			timer++;
			int v = S.top(); S.pop();
			if( vis[v] == -1 ) {
				dfs2(v);
			}
		}

		bool isValid = true;
		for(int i = 1; i <= m; i++) {
			if( vis[m-i] == vis[m+i] ) {
				isValid = false;
				break;
			}

			if( vis[m+i] > vis[m-i] ) {
				res.push_back(i);
			}
		}

		printf("Case %d: ", t);
		if(!isValid) {
			printf("No\n");
		} else {
			printf("Yes\n%d", (int)res.size());
			for(int i = 0; i < res.size(); i++) {
				printf(" %d", res[i]);
			}
			printf("\n");
		}
	}

	return 0;
}
