#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>
using namespace std;
#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define x first
#define y second

char board[1002][1002];
int runtime[1002][1002];
int firetime[1002][1002];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int w, h;
int main(void)
{
	fastio();

	int t;
	cin >> t;

	while (t--) {
		cin >> w >> h;
		queue<pair<int, int>>q1;
		queue<pair<int, int>>q2;

		for (int i = 0; i < h; i++)
		{
			fill(firetime[i], firetime[i] + w, -1);
			fill(runtime[i], runtime[i] + w, -1);
		}
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				cin >> board[i][j];

				if (board[i][j] == '*')
				{
					firetime[i][j] = 0;
					q1.push({ i,j });
				}

				if (board[i][j] == '@')
				{
					runtime[i][j] = 0;
					q2.push({ i,j });
				}

			}
		}

		while (!q1.empty())
		{
			auto cur = q1.front();
			q1.pop();

			for (int dir = 0; dir < 4; dir++)
			{
				int nx = cur.x + dx[dir];
				int ny = cur.y + dy[dir];
				if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
				if (firetime[nx][ny] >= 0 || board[nx][ny] == '#') continue;
				firetime[nx][ny] = firetime[cur.x][cur.y] + 1;
				q1.push({ nx,ny });
			}
		}

		bool check = false;
		while (!q2.empty())
		{
			auto cur = q2.front();
			q2.pop();

			for (int dir = 0; dir < 4; dir++)
			{
				int nx = cur.x + dx[dir];
				int ny = cur.y + dy[dir];
				if (nx < 0 || nx >= h || ny < 0 || ny >= w)
				{
					cout << runtime[cur.x][cur.y] + 1 << '\n';
					check = true;
					break;
				}
				if (runtime[nx][ny] >= 0 || board[nx][ny] == '#')
					continue;
				if (firetime[nx][ny] != -1 && firetime[nx][ny] <= runtime[cur.x][cur.y] + 1)
					continue; //불이 -1인 곳에서만 번질 수 있고, 다음좌표에서의 불붙는 시간이 더 빠르거나 같으면 안됨.
				runtime[nx][ny] = runtime[cur.x][cur.y] + 1;
				q2.push({ nx,ny });
			}
			if (check)
				break;
		}
		if(!check)
			cout << "IMPOSSIBLE"<<'\n';
	}
}
/*


*/