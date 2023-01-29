#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <queue>
using namespace std;
#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

class cmp {
public:
	bool operator() (int a, int b)
	{
		if (abs(a) != abs(b)) //���밪�� �ٸ��� 
			return abs(a) > abs(b); //���� ���� �� ū ��

		return a > 0 && b < 0; 
		//���밪�� ���ٸ� �� ���� �ٸ��� ���� ���,�ڰ� ���� �϶� true
	}
};
//priority_queue STL�� cmp�� class�� ������ �Ѵ�.
int main(void)
{
	fastio();
	
	priority_queue<int, vector<int>, cmp>pq;
	int n;
	cin >> n;
	while (n--)
	{
		int x;
		cin >> x;
		if (x != 0)
		{
			pq.push(x);
		}
		else
		{
			if (pq.empty())
				cout << 0 << '\n';
			else
			{
				cout << pq.top() << '\n';
				pq.pop();
			}
		}

	}
			
}
/*
�켱, ���� / ������ �ʿ�
x!=0 ->���� x==0->����
���밪�� ���� ���� �� ���, ���� ���� �������� �� ���� ��


*/