#include <iostream>
#include <string>
#include <stack>
using namespace std;
#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

int main(void)
{
	fastio();
	
	stack<int> stack;
	
	int n;
	cin >> n;
	while (n--)
	{
		string cmd;
		cin >> cmd;

		if (cmd == "push")
		{
			int x;
			cin >> x;
			stack.push(x);
		}
		else if (cmd == "pop")
		{
			if (stack.empty())
				cout << -1 << '\n';
			else {
				cout << stack.top() << '\n';
				stack.pop();
			}
		}
		else if (cmd == "size")
		{
			cout << stack.size() << '\n';
		}
		else if (cmd == "empty")
		{
			cout<<stack.empty()<<'\n';
		}
		else if (cmd == "top")
		{
			if (stack.empty())
				cout << -1 << '\n';
			else
				cout<<stack.top()<<'\n';
		}

	}


}
/*


*/
