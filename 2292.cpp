#include <iostream>
#include <algorithm>
using namespace std;
#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);



int main(void)
{
	fastio();
	
	int n;
	cin >> n;

	int res = 1;
	int cnt = 6;
	int end = 1;
	
	while (1)
	{
		if (end >= n) {
			cout << res << '\n';
			break;
		}

		end += cnt;
		cnt += 6;
		res++;
	}

}
/*



*/
