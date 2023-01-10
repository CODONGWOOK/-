#include <iostream>
using namespace std;
#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

long long POW(long long a, long long b, long long c)
{
	if (b == 1)
		return a % c;
	long long res = POW(a, b / 2, c);

	res = res * res % c;
	if (b % 2 == 0)
		return res;

	return res * a % c;
}

int main(void)
{
	fastio();

	long long a, b, c;
	cin >> a >> b >> c;
	cout << POW(a, b, c);
}
/*

*/