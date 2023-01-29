#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <queue>
#include <stack>
using namespace std;
#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);


vector<int>adj[1001];
bool visited[1001];

void stack_dfs(int st)
{
	stack<int>s;
	s.push(st);
	while (!s.empty())
	{
		int cur = s.top();
		s.pop();
		if (visited[cur])continue;
		visited[cur] = true;
		cout << cur << ' ';
		for (int i=0; i<adj[cur].size(); i++)
		{
			int nxt = adj[cur][adj[cur].size() - 1 - i];
			if (visited[nxt]) continue;
			s.push(nxt);
		}
	}
}

void recursive_dfs(int st)
{
	visited[st] = true;
	cout << st << ' ';
	for (auto nxt : adj[st])
	{
		if (visited[nxt])continue;
		recursive_dfs(nxt);
	}
}


void bfs(int st)
{

	queue<int>q;
	q.push(st);
	visited[st] = true;
	while (!q.empty())
	{
		int cur = q.front();
		cout << cur << ' ';
		q.pop();
		for (auto nxt : adj[cur])
		{
			if (visited[nxt]) continue;
			q.push(nxt);
			visited[nxt] = true;
		}
	}

}



int main(void)
{
	fastio();
	int n, m, v;
	cin >> n >> m >> v;
	while (m--)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i = 1; i <= n; i++)
		sort(adj[i].begin(), adj[i].end());
	recursive_dfs(v);
	fill(visited, visited + 1001, 0);
	cout << '\n';
	bfs(v);

			
}
/*
무방향 그래프
1. DFS를 수행한 결과
2. BFS를 수행한 결과
방문된 정점을 순서대로 출력

*/