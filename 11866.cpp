#include <iostream>
#include <string>
#include <queue>
using namespace std;
#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

int main(void)
{
	fastio();
	
	int n, k;
	cin >> n >> k;
	queue<int> q;
	
	for (int i = 1; i <= n; i++)
	{
		q.push(i);
	}

	cout << '<';
	int cnt = 0;
	while (1)
	{
		cnt++;
		int tmp = q.front();
		if (cnt % k != 0) {
			q.push(tmp);
			q.pop();
		}
		else
		{
			cout << tmp;
			q.pop();
			if (q.empty())
				break;
			cout << ", ";
		}
		
	}
	cout << '>';
}
/*
7 3 -> 3 6 2 7 5 1 4
N K    원순열에서 K번째 사람을 제거

*/
