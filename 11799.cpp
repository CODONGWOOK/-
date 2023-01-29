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
int d[1007]; //최단 거리 테이블
int pre[1007]; //경로 복원 테이블
vector<pair<int, int>>adj[1007]; //가중치,정점2
int v, e, st,en;
int main()
{
    fastio();

    cin >> v >> e;
    fill(d, d + v + 1, INF);
    while (e--)
    {
        int u, v, w; //정점1,정점2,가중치
        cin >> u >> v >> w;
        adj[u].push_back({ w,v }); //가중치,정점2
    }
    cin >> st >> en;
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
            pre[nxt.Y] = cur.Y; //경로 복원 테이블 갱신
        }
    }
    cout << d[en] << '\n';
    vector<int>path;
    int cur = en;
    while (cur != st)
    {
        path.push_back(cur);
        cur = pre[cur];
    }
    path.push_back(cur);
    reverse(path.begin(), path.end());
    cout << path.size() << '\n';
    for (auto x : path)
        cout << x << ' ';
}
/*

*/

