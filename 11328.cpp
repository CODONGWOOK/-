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
	
	while (n--)
	{
		string a,b;
		cin >> a >> b;
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());

		if (a == b)
			cout << "Possible" << '\n';
		else
			cout << "Impossible" << '\n';
	}

}
/*


*/
