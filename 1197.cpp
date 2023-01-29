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

vector<pair<int, int>>adj[10001];//비용,정점번호 

bool chk[10001];
//최소 신장 트리에 속해있는지 체크

int main()
{
    fastio();

    int v, e;
    cin >> v >> e;
    for (int i = 0; i < e; i++)
    {
        int a, b, cost;
        cin >> a >> b >> cost;
        adj[a].push_back({ cost,b });
        adj[b].push_back({ cost,a });
    }
    //비용,정점1,정점2
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,greater<tuple<int, int, int>>>pq;
    
    chk[1] = 1;
    for (auto nxt : adj[1])
        pq.push({ nxt.X,1,nxt.Y });
    int cnt = 0;
    int res = 0;
    while (cnt < v - 1)
    {
        int cost, a, b;
        tie(cost, a, b) = pq.top();
        pq.pop();
        if (chk[b])continue;
        res += cost;
        chk[b] = 1;
        cnt++;
        for (auto nxt : adj[b])
        {
            if (!chk[nxt.Y])
                pq.push({ nxt.X,b,nxt.Y });
        }
    }
    cout << res;
}
/*
*/



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


vector<int> p(10001, -1);

int find(int x)
{
    if (p[x] < 0)
        return x;
    return p[x] = find(p[x]);
}
bool group(int u, int v)
{
    u = find(u);
    v = find(v);
    if (u == v)return true;
    if (p[u] == p[v])
        p[u]--;
    if (p[u] < p[v])
        p[v] = u;
    else
        p[u] = v;
    return false;
}
tuple<int, int, int>edge[100001];
//비용 정점1 정점2
int main()
{
    fastio();

    int v, e;
    cin >> v >> e;
    for (int i = 0; i < e; i++)
    {
        int a, b, cost;
        cin >> a >> b >> cost;
        edge[i] = { cost,a,b };
    }
    sort(edge, edge + e); //첫 번째 원소인 비용을 기준으로 정렬
    int cnt = 0;
    int res = 0;

    for (int i = 0; i < e; i++)
    {
        int a, b, cost;
        tie(cost, a, b) = edge[i];
        if (group(a, b)) continue;
        res += cost;
        cnt++;
        if (cnt == v - 1)
            break;
    }
    cout << res;
}
/*
*/