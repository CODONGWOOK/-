#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);



int main(void)
{
	fastio();
	
	int n, m;
	cin >> n >> m;
	vector<int>a;
	vector<int>b;

	for (int i = 0; i < n; i++)
	{
		int k;
		cin >> k;
		a.push_back(k);
	}
	for (int i = 0; i < m; i++)
	{
		int k;
		cin >> k;
		b.push_back(k);
	}
	vector<int>c;
	int a_idx = 0;
	int b_idx = 0;
	for (int i = 0; i < n+m; i++)
	{
		if (b_idx == m)
			c.push_back(a[a_idx++]);
		else if (a_idx == n)
			c.push_back(b[b_idx++]);
		else if (a[a_idx] <= b[b_idx])
			c.push_back(a[a_idx++]);
		else
			c.push_back(b[b_idx++]);
	}
	for (auto i : c)
		cout << i<<' ';
}
/*


*/