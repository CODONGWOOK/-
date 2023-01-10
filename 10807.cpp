#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);


int main(void)
{
	fastio();
	
	int n; cin >> n;

	vector<int>a(n, 0);
	
	for (int i=0; i<n; i++)
	{
		cin >> a[i];
	}
	
	int v; cin >> v;
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] == v)
			cnt++;
	}
	cout << cnt;
}
/*


*/
