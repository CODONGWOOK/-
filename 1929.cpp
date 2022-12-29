#include <iostream>
#include <cmath>
using namespace std;
#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

bool prime[1000001];

int main(void)
{
	fastio();

	int m,n;
	cin >> m >> n;

	prime[1] = -1;
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (prime[i] == -1)
			continue;
		for (int j = i+i; j <= n; j+=i)
		{
			prime[j] = -1;
		}
	}

	for (int i = m; i <= n; i++)
	{
		if(!prime[i])
			cout << i << '\n';
	}

	
}


/*
   2 3 4 5 6 7 8 9 10
11 12 13 14 15 16 17 18 19 20
21 22 23 24 .. . .. . .
.........

3 16
*/
