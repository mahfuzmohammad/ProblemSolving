#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <algorithm>

#define MAXN 1000


using namespace std;


int cities[MAXN + 5];
int countC[MAXN + 5];
vector<int> citiMap[MAXN + 5];
int num, maxVisited;


void reset()
{
    num = 0;
    for(int i = 0; i <= MAXN; i++)
    {
        countC[i] = 0;
        citiMap[i].clear();
    }
}


void clearCiti()
{
    for(int i = 0; i <= MAXN; i++)
    {
        cities[i] = 0;
    }
}

void countCiti()
{
    for(int i = 0; i <= MAXN; i++)
    {
        countC[i] += cities[i];
    }
}

int getResult(int k)
{
    for(int i = 0; i <= MAXN; i++)
    {
        if(countC[i] == k)
            ++num;
    }

    return num;
}


void BFS(int source)
{
    clearCiti();
    queue<int> q;
    q.push(source);
    cities[source] += 1;


    while(!q.empty())
    {
        int u = q.front();
        q.pop();

        for(int i = 0; i < citiMap[u].size(); i++)
        {
            if(cities[citiMap[u][i]] == 0)
            {
                cities[citiMap[u][i]] = 1;
                q.push(citiMap[u][i]);
            }
        }
    }

    countCiti();

}


int main()
{
    freopen("input.txt", "r", stdin);
    int t, k, n, m, personCity, u, v;
    queue<int> ith;

    cin >> t;


    for(int i = 1; i <= t; i++)
    {
        reset();

        cin >> k >> n >> m;

        for(int j = 0; j < k; j++)
        {
            cin >> personCity;
            ith.push(personCity);
        }

        for(int j = 0; j < m; j++)
        {
            cin >> u >> v;

            citiMap[u].push_back(v);
        }


        while(!ith.empty())
        {
            int p = ith.front();
            ith.pop();

            BFS(p);
        }


        /*maxVisited = *max_element(cities + 1, cities + 1001);

        for(int j = 0; j <= MAXN; j++)
        {
            if(cities[j] == maxVisited)
            {
                ++num;
                //cout << j << endl;
            }

        }*/

        cout << "Case " << i << ": " << getResult(k) << endl;

        /*for(int j = 0; j <= 6; j++)
        {
            cout << cities[j] << " ";
        }

        cout << endl;*/
    }

    return 0;
}
