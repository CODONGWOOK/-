#include <iostream>
#include <algorithm>
#include <string>
#include <deque>
using namespace std;
#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

int main(void)
{
	fastio();

int t;
	cin >> t;

	
	while (t--)
	{
		string p;
		cin >> p;

		int n;
		cin >> n;
		deque<int>dq;


		char start;
		cin >> start;
			
		for (int i = 0; i < n; i++)
		{
			int k;
			cin >> k;
			dq.push_back(k);
			if (i < n - 1)
			{
				char next;
				cin >> next;
			}
		}

		char end;
		cin >> end;

		bool check = true;
		int count = 0;
		for (int i = 0; i < p.size(); i++)
		{
			if (!dq.empty())
			{
				if (p[i] == 'D')
				{
					if (count % 2 == 0)
						dq.pop_front();
					else
						dq.pop_back();
					
				}
				else
					count++;
			}
			else
			{
				if (p[i] == 'D')
				{
					cout << "error"<<'\n';
					check = false;
					break;
				}
			}
		}

		if (check)
		{
			cout << '[';
			while (!dq.empty())
			{
				if (count % 2 == 0)
				{
					cout << dq.front();
					dq.pop_front();
				}
				else
				{
					cout << dq.back();
					dq.pop_back();
				}

				if(dq.size()>0)
				cout << ',';

			}
			cout << ']'<<'\n';
		}


	}

}
/*
R:뒤집기 D:버리기
배열이 비었을 때 D사용=error
*/

