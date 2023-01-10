#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);



int main(void)
{
	fastio();
	
	string s;
	cin >> s;

	vector<int>a(26, 0);

	for (int i=0; i<s.length(); i++)
	{
		a[s[i] - 97]++;
	}

	for (int i=0; i<26; i++)
	{
		cout << a[i] << ' ';
	}

}
/*

*/
