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
// dist[x][y][0] : ���� �ϳ��� �μ��� �ʰ� (x,y)���� ���µ� �ɸ��� ���
// dist[x][y][1] : ���� �ϳ��� �μ��� (x,y)���� ���µ� �ɸ��� ���, (x,y)�� ���̶� �μ��� ��� ����
//dist [x][y][w][d%2] d%2==0 �̸� �� / d%2==1�̸� ��
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
	dist[0][0][0][0] = 1; //�������̹Ƿ� ���� �μ��� ����.
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
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue; //Ž���� ������ ������ ����� ����
			
			if (board[nx][ny] == '0') //(nx ,ny)�� ���� ������ �״�� Ž��
			{
				if (dist[nx][ny][nw][nd]) continue; //�̹� �湮������ ����

				dist[nx][ny][nw][nd] = dist[x][y][w][d] + 1;
				q.push({ nx,ny,nw,nd });
			}
			else //���� ������
			{
				if (w == k) continue; //���� �̹� k�������� ����

				if (d == 0) //���̸� ���� ���� �湮
				{
					nw++;
					if (dist[nx][ny][nw][nd]) continue;
					dist[nx][ny][nw][nd] = dist[x][y][w][d] + 1;
					q.push({ nx,ny,nw,nd });
				}
				else //���̸� ���� �� ������ ��ٸ�.
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