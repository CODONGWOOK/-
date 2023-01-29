#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <queue>
#include <stack>
using namespace std;
#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

vector<int>adj[100001];
int parent[100001];

void dfs(int cur)
{
	for (int nxt : adj[cur])
	{
		if (parent[cur] == nxt)continue; //nxt가 현재 정점의 부모면 생략
		parent[nxt] = cur; //현재 정점을 nxt의 부모로 설정
		dfs(nxt);
	}
}
int main(void)
{
	fastio();
	
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1); //root=1번
	for (int i = 2; i <= n; i++)
		cout << parent[i] << '\n';
}
/*



*/