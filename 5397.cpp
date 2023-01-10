#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
using namespace std;
#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

int main(void)
{
	fastio();
	
	int t;
	cin >> t;

	while (t--)
	{
		list<char>key={};
		string s;
		cin >> s;
		auto it = key.begin();
		
		for (auto c : s)
		{
			if (c == '-')
			{
				if (it != key.begin())
				{
					it--;
					it = key.erase(it);
				}
			}
			else if (c == '<')
			{
				if (it != key.begin())
					it--;
			}
			else if (c == '>')
			{
				if (it != key.end())
					it++;
			}
			else
			{
				key.insert(it,c);
			}
		}
		
		for (auto c : key)
			cout << c;
		cout << '\n';
	}

}
/*


*/
