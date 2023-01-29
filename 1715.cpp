#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <queue>
using namespace std;
#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);



int main(void)
{
	fastio();
	
	priority_queue<int, vector<int>, greater<int>>pq;

	int n;
	cin >> n;
	while (n--)
	{
		int x;
		cin >> x;
		pq.push(x);
	}

	int sum = 0;
	int cnt = 0;
	while (pq.size()>1)
	{
		int a = pq.top();
		pq.pop();
		int b = pq.top();
		pq.pop();
		sum += a + b;
		pq.push(a + b);
	}
	cout << sum;
			
}
/*
�ּҰ� �Ǳ����ؼ��� ����������� ���ʷ� ���ؾ� �Ѵ�
-> minheap���� �ּڰ������ ����

10 20 40
10 20 30 40 -> 10+20 + 30+30 +60+40=190
*/