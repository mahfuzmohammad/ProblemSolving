#include <bits/stdc++.h>

using namespace std;

#define _MAXV 1000
#define what_is(x) cout << #x << " = " << x;

const int UNVISITED = -1;

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
		printf( "SCC %d:", ++numSCC );
		while( true ) {
			int v = S.back(); S.pop_back(); /*visited[ v ] = 0;*/  //check visited assignment
			printf( " %d", v );
			if( u == v ) break;
		}

		printf( "\n" );
	}
}

int takeInEdges() {
	int n, u, v;
	scanf( "%d", &n );
	for( int i = 0; i < n; i++ ) {
		scanf( "%d %d", &u, &v );
		edge[ u ].push_back( v );
	}

	return n;
}

void reset() {
	dfsNumberCounter = numSCC = 0;
	memset(dfs_num, UNVISITED, sizeof dfs_num);
	memset(dfs_low, 0, sizeof dfs_low);
	memset(visited, 0, sizeof visited);
	S.clear();

	for( auto& indx:edge ) indx.clear();
}

int main() {
	freopen("in", "r", stdin);
	reset();
	int n = takeInEdges();
	for( int i = 0; i < n; i++ ) {
		if( dfs_num[ i ] == UNVISITED ) tarjanSCC( i );
	}

	return 0;
}