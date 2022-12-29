#include <iostream>
using namespace std;
#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

int main(void)
{
	fastio();

	int n; cin >> n;

	int cnt = 0;
	while (n >= 0) {
		if (n % 5 == 0) {	
			cnt += (n / 5);	
			cout << cnt ;
			return 0;
		}

		n -= 3;	
		cnt++;	
	}
	cout << -1 << endl;
}


/*
18-> 15 -> 3+1 =4
11 -> 8 -> 5 -> 1+1+1= 3
*/
