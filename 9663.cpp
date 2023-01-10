#include <iostream>
using namespace std;
#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

bool isused1[16];
bool isused2[32];
bool isused3[32];
int n;
int cnt = 0;
void bt(int cur)
{
	if (cur == n)
	{
		cnt++;
		return;
	}
	for (int i = 0; i < n; i++)
	{
		if (isused1[i] || isused2[i + cur] || isused3[cur - i + n - 1])
			continue; //사용처리가 되었으면 PASS

		isused1[i] = 1;
		isused2[i + cur] = 1;
		isused3[cur - i + n - 1] = 1;
		bt(cur + 1);
		isused1[i] = 0;
		isused2[i + cur] = 0;
		isused3[cur - i + n - 1] = 0;
	}
}
int main(void)
{
	fastio();

	cin >> n;

	bt(0);
	cout << cnt;
}
/*


*/
/*


*/