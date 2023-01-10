#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

int main(void)
{
	fastio();
	
	string a, b;
	cin >> a >> b;
	int alpha[26] = {};
	for (auto c : a) alpha[c - 'a']++;
	for (auto c : b) alpha[c - 'a']--;

	int cnt = 0;
	for (auto c : alpha)
	{
		if (c != 0)
			cnt += abs(c);
	}

	cout << cnt;
}
/*


*/
