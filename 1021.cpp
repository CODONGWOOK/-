#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;
#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

int main(void)
{
	fastio();

	deque<int> dq;
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		dq.push_back(i+1);
	}
	int cnt = 0;
	for (int i = 0; i < m; i++)
	{
		int k;
		cin >> k;
		int idx = find(dq.begin(),dq.end(),k)-dq.begin();
		while (k != dq.front())
		{
			if (idx<(int)dq.size()-idx)
			{
				dq.push_back(dq.front());
				dq.pop_front();
			}
			else
			{
				dq.push_front(dq.back());
				dq.pop_back();
			}
			
			cnt++;
		}
		dq.pop_front();
		
	}
	cout << cnt;

}
/*
¿ÞÂÊ ÇÑÄ­ ÀÌµ¿: pop_front and push_back
¿À¸¥ÂÊ ÇÑÄ­ ÀÌµ¿: pop_back and push_front
1 2 3 4 5 6 7 8 9 10
2 3 4 5 6 7 8 9 10 1
3 4 5 6 7 8 9 10 1
*/

