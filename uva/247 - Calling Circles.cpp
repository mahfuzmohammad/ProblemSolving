#include <bits/stdc++.h>

using namespace std;

#define _MAXV 1000
#define what_is(x) cout << #x << " = " << x;

typedef pair<string, string> call;
const int UNVISITED = -1;

vector<call> input;
map<string, int> id;
string map_back[_MAXV];

vector<int> edge[_MAXV+5];
vector<int> S;

int		dfsNumberCounter, numSCC;
int		dfs_num[_MAXV+5], dfs_low[_MAXV+5];
bool	visited[_MAXV+5];

void tarjanSCC( int u ) {
	dfs_low[ u ] = dfs_num[ u ] = dfsNumberCounter++;
	S.push_back( u );
	visited[ u ] = 1;

	for( int j = 0; j < (int)edge[ u ].size(); j++ ) {
		int v = edge[ u ][ j ];
		if( dfs_num[ v ] == UNVISITED ) tarjanSCC( v );
		if( visited[ v ] ) dfs_low[ u ] = min( dfs_low[ u ], dfs_low[ v ] );
	}

	//print SCC
	if( dfs_low[ u ] == dfs_num[ u ] ) {
		//printf( "SCC %d:", ++numSCC );
		int outcnt = 0;
		while( true ) {
			if( outcnt > 0 ) printf( ", " );
			int v = S.back(); S.pop_back(); visited[ v ] = 0;  //check visited assignment
			//printf( "%s", map_back[ v ] );
			cout << map_back[ v ];
			outcnt++;
			if( u == v ) break;
		}

		printf( "\n" );
	}
}

void reset() {
	id.clear(); input.clear();

	dfsNumberCounter = numSCC = 0;
	memset(dfs_num, UNVISITED, sizeof dfs_num);
	memset(dfs_low, 0, sizeof dfs_low);
	memset(visited, 0, sizeof visited);
	S.clear();

	for( auto& i : edge ) i.clear();
	for( auto& name : map_back ) name = "";
}

int main() {
	//freopen("../in", "r", stdin);

	int n, m, cnt = 0;
	string u, v;

	while( scanf("%d %d", &n, &m) && n && m ) {
		reset();
		if( cnt > 0 ) printf( "\n" );
		for( int i = 0; i < m; i++ ) {
			cin >> u >> v;
			input.push_back( call( u, v ) );
			id[ u ] = 0; id[ v ] = 0;
		}

		int indx = 0;
		for( auto& it : id ) {
			map_back[ indx ] = it.first;
			it.second = indx++;
		}

		for( int i = 0; i < m; i++ ) {
			edge[ id[ input[ i ].first ] ].push_back( id[ input[ i ].second ] );
		}

		cout << "Calling circles for data set " << ++cnt << ":\n";
		for( int i = 0; i < n; i++ ) {
			if( dfs_num[i] == UNVISITED ) tarjanSCC( i );
		}
	}

	return 0;
}