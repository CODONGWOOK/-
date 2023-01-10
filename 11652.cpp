#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>

using namespace std;
#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);


int main(void)
{
	fastio();
	
	int n;
	cin >> n;
	long long a[100001];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	int cnt = 0;
	long long mx_val = -(111 << 62) - 1;
	int mx_cnt = 0;
	for (int i = 0; i < n; i++)
	{
		if (i == 0 || a[i - 1] == a[i])
			cnt++;
		else
		{
			if (cnt > mx_cnt) 
			{
				mx_cnt = cnt;
				mx_val = a[i - 1];
			}
			cnt = 1;
		}
	}
	if (cnt > mx_cnt)
		mx_val = a[n - 1];
	cout << mx_val;
}
/*


*/