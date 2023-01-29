#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <queue>
using namespace std;
#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);


vector<int>adj[1001];
bool visited[1001];
int main(void)
{
	fastio();
	
	int n, m;
	cin >> n >> m;
	while (m--)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int num = 0; //연결 요소의 개수
	for (int i = 1; i <= n; i++)
	{
		if (visited[i])continue;
		num++;
		queue<int>q;
		q.push(i);
		visited[i] = true;
		while (!q.empty())
		{
			int cur = q.front();
			q.pop();
			for (auto nxt : adj[cur])
			{
				if (visited[nxt]) continue;
				q.push(nxt);
				visited[nxt] = true;
			}
		}

	}
	cout << num;

			
}
/*
무방향 그래프

*/