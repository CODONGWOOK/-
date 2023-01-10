#include <iostream>
using namespace std;
#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

void hanoi(int n, char from, char tmp, char to)
{
	if (n == 1) {
		cout << from << ' ' << to << '\n';
		return;
	}

		hanoi(n - 1, from, to, tmp);
		cout << from << ' ' << to << '\n';
		hanoi(n - 1, tmp, from, to);

}


int main(void)
{
	fastio();

	int n;
	cin >> n;
	cout << (1 <<n) - 1 << '\n';
	hanoi(n, '1', '2', '3');

}
/*

*/