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
			//dist�� ���� �湮ó��
			// dist�� ������ -1���� ũ�ٴ� ���� �湮�� �� ���� �ǹ�.
			//���� ���� visited�� �ʿ����� ����.
			dist[nx][ny] = dist[cur.x][cur.y]+1;
			q.push({ nx,ny });
		}
	}
	cout << dist[n-1][m-1]+1;
}
/*


*/

