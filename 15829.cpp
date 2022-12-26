#include <iostream>

using namespace std;
#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);


int main(void)
{
	fastio();

	int L;
	cin >> L;

	string s;
	cin >> s;

	int M = 1234567891;
	int r = 31;
	long long hash = 0;
	long long R = 1;

	for (int i = 0; i < L; i++)
	{
		int k = s[i] - 96;
		hash += (k * R) % M;
		hash %= M;
		R= (R * r) % M;
	}

	cout << hash << '\n';

}
/*


*/
