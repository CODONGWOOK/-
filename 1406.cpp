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
	
	string s;
	cin >> s;

	list<char>List;
	for (int i = 0; i < s.length(); i++)
	{
		List.push_back(s[i]);
	}
	list<char>::iterator cursor = List.end();
	int m;
	cin >> m;
	while (m--)
	{
		char cmd;
		cin >> cmd;
		if (cmd == 'L')
		{
			if (cursor != List.begin())
				cursor--;
		}
		else if (cmd == 'D')
		{
			if (cursor != List.end())
				cursor++;
		}
		else if (cmd == 'B')
		{
			if (cursor != List.begin())
			{
				cursor--;
				cursor=List.erase(cursor);
			}
		}
		else if (cmd == 'P')
		{
			char n;
			cin >> n;

			List.insert(cursor, n);
		}
		else
			break;
	}
	for (auto c: List)
	{
		cout << c;
	}

}
/*


*/
