#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>
#include <tuple>
using namespace std;
#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define X first
#define Y second

char board[1001][1001];
int dist[1001][1001][2];
// dist[x][y][0] : ���� �ϳ��� �μ��� �ʰ� (x,y)���� ���µ� �ɸ��� ���
// dist[x][y][1] : ���� �ϳ��� �μ��� (x,y)���� ���µ� �ɸ��� ���, (x,y)�� ���̶� �μ��� ��� ����
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,1,-1 };
int n, m;
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
	
	queue<tuple<int, int, int>>q;
	dist[0][0][0] = 1; //�������̹Ƿ� ���� �μ��� ����.
	q.push({ 0,0,0 });

	while (!q.empty())
	{
		int x, y, w;
		tie(x, y, w) = q.front();
		q.pop();
		if (x == n - 1 && y == m - 1)
		{
			cout << dist[x][y][w];
			return 0;
		}
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			int nw = w;
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue; //Ž���� ������ ������ ����� ����
			if (board[nx][ny] == '1')//���� �μ��� ���
				nw++;
			if (nw > 1 || dist[nx][ny][nw]) continue;
			dist[nx][ny][nw] = dist[x][y][w] + 1;
			q.push({ nx,ny,nw});
			
		}
	}
	cout << -1;
}
/*


*/