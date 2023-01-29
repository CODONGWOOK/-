#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <queue>
#include <stack>
#include <tuple>
using namespace std;
#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define X first
#define Y second

const int INF = 1e9+10;
int d[20007]; //최단 거리 테이블
vector<pair<int, int>>adj[20007]; //가중치,정점2
int v, e, st;
int main()
{
    fastio();

    cin >> v >> e >> st;
    fill(d, d + v + 1, INF);
    while (e--)
    {
        int u, v, w; //정점1,정점2,가중치
        cin >> u >> v >> w;
        adj[u].push_back({ w,v }); //가중치,정점2
    }

    d[st] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
    pq.push({ d[st], st });
    while (!pq.empty())
    {
        auto cur = pq.top();
        pq.pop();
        if(d[cur.Y]!=cur.X)
            continue;
        for (auto nxt : adj[cur.Y])
        {
            if (d[nxt.Y] <= d[cur.Y] + nxt.X)
                continue;
            d[nxt.Y] = d[cur.Y] + nxt.X;
            pq.push({ d[nxt.Y],nxt.Y });
        }
    }
    for (int i = 1; i <= v; i++)
    {
        if (d[i] == INF)
            cout << "INF" << '\n';
        else
            cout << d[i] << '\n';
    }
    
}
/*

*/

