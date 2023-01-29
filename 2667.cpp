#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>
using namespace std;
#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define x first
#define y second

char board[26][26];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int n;
int main(void)
{
	fastio();

	cin >> n;
	queue<pair<int, int>>q;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];
		}
	}

	vector<int>res;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{

			if (board[i][j] == '1')
			{
				board[i][j] = '0';
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
						if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
						if (board[nx][ny] == '0') continue;
						board[nx][ny] = '0';
						area++;
						q.push({ nx,ny });
					}
				}
				res.push_back(area);
			}

		}
	}
	sort(res.begin(), res.end());
	cout << res.size() << '\n';
	for (auto c : res)
		cout << c << '\n';
	


}
/*


*/