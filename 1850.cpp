#include <iostream>
#include <algorithm>
using namespace std;
#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

long long gcd(long long a, long long b)
{
	if (a < b)
		swap(a, b);

	while (b != 0)
	{
		long long c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int main(void)
{
	fastio();

	long long n, m;
	cin >> n >> m;

	long long k=gcd(n, m);

	for (long long i = 0; i < k; i++)
	{
		cout << 1;
	}

}
/*



*/
