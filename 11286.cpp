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
		if (abs(a) != abs(b)) //절대값이 다르면 
			return abs(a) > abs(b); //절대 값이 더 큰 것

		return a > 0 && b < 0; 
		//절대값이 같다면 두 수가 다르고 앞이 양수,뒤가 음수 일때 true
	}
};
//priority_queue STL은 cmp를 class로 만들어야 한다.
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
우선, 삽입 / 삭제가 필요
x!=0 ->삽입 x==0->삭제
절대값이 가장 작은 값 출력, 같은 값이 여러개면 더 작은 값


*/