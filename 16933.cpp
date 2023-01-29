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
int dist[1001][1001][11][2];
// dist[x][y][0] : 벽을 하나도 부수지 않고 (x,y)까지 오는데 걸리는 비용
// dist[x][y][1] : 벽을 하나만 부수고 (x,y)까지 오는데 걸리는 비용, (x,y)가 벽이라서 부수는 경우 포함
//dist [x][y][w][d%2] d%2==0 이면 낮 / d%2==1이면 밤
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,1,-1 };
int n, m, k;
int main(void)
{
	fastio();


	cin >> n >> m >> k;


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
		}
	}

	queue<tuple<int, int, int,int>>q;
	dist[0][0][0][0] = 1; //시작점이므로 벽을 부수지 않음.
	q.push({ 0,0,0,0 });
	while (!q.empty())
	{
		int x, y, w,d;
		tie(x, y, w,d) = q.front();
		q.pop();
		if (x == n - 1 && y == m - 1)
		{
			cout << dist[x][y][w][d%2];
			return 0;
		}
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			int nw = w;
			int nd = 1-d;
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue; //탐색할 지점이 범위를 벗어나면 생략
			
			if (board[nx][ny] == '0') //(nx ,ny)에 벽이 없으면 그대로 탐색
			{
				if (dist[nx][ny][nw][nd]) continue; //이미 방문했으면 생략

				dist[nx][ny][nw][nd] = dist[x][y][w][d] + 1;
				q.push({ nx,ny,nw,nd });
			}
			else //벽이 있으면
			{
				if (w == k) continue; //벽을 이미 k번깼으면 생략

				if (d == 0) //낮이면 벽을 깨고 방문
				{
					nw++;
					if (dist[nx][ny][nw][nd]) continue;
					dist[nx][ny][nw][nd] = dist[x][y][w][d] + 1;
					q.push({ nx,ny,nw,nd });
				}
				else //밤이면 낮이 올 때까지 기다림.
				{
					if (dist[nx][ny][nw][nd]) continue;
					dist[x][y][w][nd] = dist[x][y][w][d] + 1;
					q.push({ x,y,w,nd });
				}
			}
		
		}
		
	}
	cout << -1;
}
/*


*/