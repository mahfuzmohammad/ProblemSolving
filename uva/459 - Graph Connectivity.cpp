//UVA 459 - Graph Connectivity.cpp

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

#define MAXNODE 26

using namespace std;

vector<int> graph[MAXNODE + 5];
int travelinfo[MAXNODE + 5];

void reset(){
    for(int i = 0; i < MAXNODE; i++){
        graph[i].clear();
        travelinfo[i] = 0;
    }
}//end of reset

void travel(int start){
    int u, gSize;
    travelinfo[start] = 1;
    queue<int> q;
    q.push(start);

    while(!q.empty()){
        u = q.front();
        q.pop();
        gSize = graph[u].size();

        for(int i = 0; i < gSize; i++){
            if(travelinfo[graph[u][i]] == 0){
                travelinfo[graph[u][i]] = 1;
                q.push(graph[u][i]);
            }
        }
    }//end of while
}//end of travel

int main()
{
    //freopen("input.txt", "r", stdin);
    int testCase, maximals, maxNode;
    char max;
    string rel, dummy;

    cin >> testCase;

    for(int i = 0; i < testCase; i++){
        reset();
        maximals = 0;

        cin >> max;
        maxNode = max - 'A';

        getline(cin, dummy);

        while(getline(cin, rel)){
            if(rel.size() == 0) break;
            graph[rel[0] - 'A'].push_back(rel[1] - 'A');
            graph[rel[1] - 'A'].push_back(rel[0] - 'A');
        }

        for(int j = 0; j <= maxNode; j++){
            if(travelinfo[j] == 0){
                ++maximals;
                travel(j);
            }
        }

        cout << maximals << endl;

        if(i < testCase - 1) cout << endl;
    }

    return 0;
}
