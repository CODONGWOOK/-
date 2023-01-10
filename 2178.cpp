#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>
using namespace std;
#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define x first
#define y second

char board[101][101];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int dist[101][101];
int n,m;
int main(void)
{
	fastio();
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
		}
	}
	for(int i=0; i<n; i++)
		fill(dist[i], dist[i] + m, -1);

	queue<pair<int, int>>q;
	dist[0][0] = 0;
	q.push({ 0,0 });
	while (!q.empty())
	{
		pair<int, int> cur = q.front();
		q.pop();

		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.x + dx[dir];
			int ny = cur.y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (dist[nx][ny] >= 0 || board[nx][ny] != '1') continue;
			//dist를 통해 방문처리
			// dist가 여전히 -1보다 크다는 것은 방문을 한 것을 의미.
			//따라서 굳이 visited가 필요하지 않음.
			dist[nx][ny] = dist[cur.x][cur.y]+1;
			q.push({ nx,ny });
		}
	}
	cout << dist[n-1][m-1]+1;
}
/*


*/

