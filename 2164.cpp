#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);


int main(void)
{
	fastio();

	int n;
	cin >> n;

	queue<int> q;

	for (int i = 1; i <= n; i++) {
		q.push(i);
	}

	while (1)
	{
		if (q.size() == 1)
		{
			break;
		}
		else 
		{
			q.pop();
			q.push(q.front());
			q.pop();
		}
		
	}
	cout << q.front();


}
/*



*/
