#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>
using namespace std;
#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define x first
#define y second

int board[101][101];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int n,m,k;
int main(void)
{
	fastio();

	cin >> m >> n >> k;
	queue<pair<int, int>>q;

	while (k--)
	{
		pair<int, int>a,b;
		cin >> a.x >> a.y >> b.x >> b.y;

		for (int i = a.x; i < b.x; i++)
		{
			for (int j = a.y; j < b.y; j++)
			{
				board[i][j] = 1;
			}
		}
	}
	vector<int>area_arr;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{

			if (board[i][j] == 0)
			{
				board[i][j] = 1;
				int area = 1;
				q.push({ i,j });
				while (!q.empty())
				{
					auto cur = q.front();
					q.pop();

					for (int dir = 0; dir < 4; dir++)
					{
						int nx = cur.x + dx[dir];
						int ny = cur.y + dy[dir];
						if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
						if (board[nx][ny] == 1) continue;
						board[nx][ny] = 1;
						area++;
						q.push({ nx,ny });
					}
				}
				area_arr.push_back(area);
			}

		}
	}
	sort(area_arr.begin(), area_arr.end());
	cout << area_arr.size() << '\n';
	for (auto c : area_arr)
		cout << c << ' ';
	


}
/*


*/