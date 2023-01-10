#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);



int main(void)
{
	fastio();
	
	int n;
	cin >> n;
	int a[10] = {};

	int max = 0;
	while (n != 0)
	{
		if (n % 10 == 6)
		{
			a[9]++;
		}
		else
		{
			a[n % 10]++;
		}
		n /= 10;
	}
	
	for (int i = 0; i < 9; i++)
	{
		if (max <= a[i])
			max = a[i];
	}

	if (max <= (a[9] + 1) / 2)
		max = (a[9] + 1) / 2;
	
	cout << max;

}
/*

*/
