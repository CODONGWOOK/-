#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);


bool occur[2000001];
int main(void)
{
	fastio();

	int n;
	cin >> n;
	vector<int>a(n, 0);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	int x;
	cin >> x;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		// x-a[i]가 존재하는지 확인
		if (x - a[i] > 0 && occur[x - a[i]]) cnt++;

		occur[a[i]] = true;
	}
	cout << cnt;
}
/*
10000000>=a_i>=1
a_i+a_j=x



*/

