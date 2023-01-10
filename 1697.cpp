#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>
using namespace std;
#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define x first
#define y second

int findtime[100002];
int dx[2] = {-1,1};
int n,k;
int main(void)
{
	fastio();
	cin >> n >> k;
	queue<int>	q;

	fill(findtime, findtime + 100001, -1);
	findtime[n] = 0;
	q.push(n);

	while (findtime[k]==-1)
	{
		auto cur = q.front();
		q.pop();

		for (int dir = 0; dir < 3; dir++)
		{
			int nx;
			if (dir == 2)
				nx = 2 * cur;
			else
				nx = cur + dx[dir];

			if (nx < 0||nx>100000) continue;
			if (findtime[nx] != -1) continue;
			findtime[nx] = findtime[cur] + 1;
			q.push(nx);
		}
	}
	cout << findtime[k];

}
/*
이동 방법: x-1 / x+1 / 2*x;

n==k일 때 구하기

*/

