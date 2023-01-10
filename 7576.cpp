#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>
using namespace std;
#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define x first
#define y second

int board[1001][1001];
int day[1001][1001];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int n,m;
int main(void)
{
	fastio();
	cin >> n >> m;
	queue<pair<int, int>>q;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 1)
				q.push({ i,j });

			if (board[i][j] == 0)  //덜익은 토마토는 day를 음수로 처리
				day[i][j] = -1;
		}
	}

	while (!q.empty())
	{
		auto cur = q.front();
		q.pop();

		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.x + dx[dir];
			int ny = cur.y + dy[dir];
			if (nx < 0 || nx >=m  || ny < 0 || ny >= n) continue;
			if (day[nx][ny]>=0) continue;
			//day가 >=0이면 방문처리가 되었거나 보드가 -1이라는 것이므로 무시
			day[nx][ny] = day[cur.x][cur.y]+1;
			q.push({ nx,ny });
		}
	}
	int max = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (day[i][j] == -1)
			{
				cout << -1;
				return 0;
			}
			if (max < day[i][j])
				max = day[i][j];
		}
	}
	cout << max;
}
/*
1: 익은 토마토  0:안익은 토마토 -1:빈공간

*/

