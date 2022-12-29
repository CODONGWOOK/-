#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);


bool cmp(pair<int, int>x, pair<int, int>y) {
	if (x.first == y.first)
		return x.second < y.second;
	else
		return x.first < y.first;
	
}

int main(void)
{
	fastio();
	
	int n;
	cin >> n;
	vector<pair<int,int>> v;

	for (int i = 0; i < n; i++)
	{
		int x,y;
		cin >> x >> y;
		v.push_back({x,y});
	}
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < n; i++)
	{
		cout << v[i].first <<' '<<v[i].second << '\n';
	}

}
/*


*/
