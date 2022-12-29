#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);


int main(void)
{
	fastio();

	int k;
	cin >> k;

	stack<int> s;
	int sum = 0;
	for (int i = 0; i < k; i++)
	{
		int n;
		cin >> n;

		if (n != 0) {
			s.push(n);
			sum += n;
		}
		else
		{
			sum -= s.top();
			s.pop();
		}
	}
	cout << sum;

}


/*
 
*/
