#include <iostream>
#include <algorithm>
using namespace std;
#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);



int main(void)
{
	fastio();
	
	int n;
	cin >> n;
	int a[51] = {};

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	int idx = 0;
	int cnt = 0;
	while(1)
	{
		int max = 0;
			for (int i = 1; i < n; i++)
			{
				if (a[i] > max) { //max 찾기
					max = a[i];
					idx = i;
				}
			}

			if (a[0] <= max)
			{
				a[idx]--;
				a[0]++;
				cnt++;
			}
			else
				break;

	}
	cout << cnt;
	


}
/*
다솜이는 기호 1번

5 10 7 3 8
*/
