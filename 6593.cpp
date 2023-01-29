#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>
#include <tuple>
using namespace std;
#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define x first
#define y second

char building[31][31][31];
int Time[31][31][31];
int dx[6] = { -1,1,0,0,0,0 };
int dy[6] = { 0,0,1,-1,0,0 };
int dz[6] = { 0,0,0,0,1,-1 };
int l,r,c;
int main(void)
{
	fastio();

	while (1)
	{
		cin >> l >> r >> c;
		if (l == 0 && r == 0 && c == 0)
			return 0;

		for (int i = 0; i < l; i++)
		{
			for (int j = 0; j < r; j++)
			{
				fill(Time[i][j], Time[i][j] + 31, -1);
			}
		}
		queue<tuple<int, int, int>>q;

		for (int k = 0; k < l; k++)
		{
			for (int i = 0; i < r; i++)
			{
				for (int j = 0; j < c; j++)
				{
					cin >> building[k][i][j];

					if (building[k][i][j] == 'S')
					{
						Time[k][i][j] = 0;
						q.push({ k,i,j });
					}

				}
			}
		}

		bool check = false;
		while (!q.empty())
		{
			auto cur = q.front();
			q.pop();

			for (int dir = 0; dir < 6; dir++)
			{
				int nx = get<2>(cur) + dx[dir];
				int ny = get<1>(cur) + dy[dir];
				int nz = get<0>(cur) + dz[dir];
				if (nx < 0 || nx >= c || ny < 0 || ny >= r||nz<0||nz>=l) continue;
				if (Time[nz][ny][nx]>=0 || building[nz][ny][nx]=='#') continue;
				Time[nz][ny][nx] = Time[get<0>(cur)][get<1>(cur)][get<2>(cur)]+1;
				q.push({ nz,ny,nx });
				if (building[nz][ny][nx] == 'E')
				{	
					cout << "Escaped in " << Time[nz][ny][nx] << " minute(s).\n";
					check = true;
					break;
				}
			}
			if (check)
				break;
		}
		if(!check)
			cout << "Trapped!" << '\n';
	}
	
}
/*


*/