#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);


bool bsh(vector<int> v,int search)
{
	int l = 0;
	int r = v.size() - 1;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (v[mid] == search)
			return true;
		else if (v[mid] > search)
			r = mid - 1;
		else
			l = mid + 1;
	}
	return false;
}

int main(void)
{
	fastio();

	int n;
	cin >> n;
	
	vector<int> v(n, 0);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	
	int m;
	cin >> m;

	for (int i = 0; i < m; i++)
	{
		int k;
		cin >> k;
		if (bsh(v, k))
			cout << 1 << '\n';
		else
			cout << 0 << '\n';
	}
	
}


/*
 1 2 3 4 5


*/
