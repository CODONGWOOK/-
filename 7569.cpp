#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>
#include <tuple>
using namespace std;
#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define X first
#define Y second

int board[101][101][101];
int day[101][101][101];
int dx[6] = { 1,0,-1,0,0,0 };
int dy[6] = { 0,1,0,-1,0,0 };
int dz[6] = { 0,0,0,0,1,-1 };
int h,n, m;
int main(void)
{
	fastio();
	cin >> m >> n >> h;
	queue<tuple<int, int, int>>q;
	for (int z = 0; z < h; z++)
	{
		for (int y = 0; y < n; y++)
		{
			for (int x = 0; x < m; x++)
			{
				cin >> board[z][y][x];
				if (board[z][y][x] == 1)
					q.push({ z,y,x });

				if (board[z][y][x] == 0)  //������ �丶��� day�� ������ ó��
					day[z][y][x] = -1;
			}
		}
	}

	while (!q.empty())
	{
		auto cur = q.front();
		q.pop();

		for (int dir = 0; dir < 6; dir++)
		{
			int nx = get<2>(cur) + dx[dir];
			int ny = get<1>(cur) + dy[dir];
			int nz = get<0>(cur) + dz[dir];
			if (nx < 0 || nx >= m || ny < 0 || ny >= n || nz < 0 || nz >= h) continue;
			if (day[nz][ny][nx] >= 0) continue;
			//day�� >=0�̸� �湮ó���� �Ǿ��ų� ���尡 -1�̶�� ���̹Ƿ� ����
			day[nz][ny][nx] = day[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
			q.push({ nz,ny,nx });
		}
	}
	int max = 0;
	for (int z = 0; z < h; z++)
	{
		for (int y = 0; y < n; y++)
		{
			for (int x = 0; x < m; x++)
			{
				if (day[z][y][x] == -1)
				{
					cout << -1;
					return 0;
				}
				if (max < day[z][y][x])
					max = day[z][y][x];
			}
		}
	}

	cout << max;
}
/*
1: ���� �丶��  0:������ �丶�� -1:�����

*/

