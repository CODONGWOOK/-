#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <queue>
#include <stack>
using namespace std;
#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);


vector<int>adj[32001];
int deg[32001];

int main()
{
    fastio();

    int n, m;
    cin >> n >> m;
    
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        deg[v]++;
    }
    queue<int>q;
    for (int i = 1; i <= n; i++)
    {
        if (deg[i] == 0)
            q.push(i);
    }
    vector<int>result;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        result.push_back(cur);
        for (auto nxt : adj[cur])
        {
            deg[nxt]--;
            if (deg[nxt] == 0)
                q.push(nxt);
        }
    }
    for (auto x : result)
        cout << x << ' ';


}
/*
*/