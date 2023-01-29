#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>
using namespace std;
#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define x first
#define y second

int h[1000001];
int f, s, g, u, d;
int main(void)
{
	fastio();

	cin >> f >> s >> g >> u >> d;
	queue<int>q;

	fill(h, h + 1000001, -1);
	h[s] = 0;
	q.push(s);

	while (!q.empty())
	{
		auto cur = q.front();
		q.pop();

		for (int dir = 0; dir < 2; dir++)
		{
			int nh;
			if (dir == 0)
				nh = cur + u;
			else
				nh = cur - d;
			if (nh<=0||nh>f) continue;
			if (h[nh]!=-1) continue;
			h[nh] = h[cur] + 1;
			q.push(nh);
		}
		if (h[g] != -1)
		{
			cout << h[g];
			return 0;
		}
	}
	cout << "use the stairs";
}
/*


*/