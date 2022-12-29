#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);


int main(void)
{
	fastio();
	
	int n;
	cin >> n;
	vector<int> v;

	for (int i = 0; i < n; i++)
	{
		int k;
		cin >> k;
		v.push_back(k);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++)
	{
		cout << v[i] << '\n';
	}

}
/*


*/
