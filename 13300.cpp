#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

int student[7][2];
int main(void)
{
	fastio();
	
	int n, k;
	cin >> n >> k;
	

	for (int i = 0; i < n; i++)
	{
		int s, y;
		cin >> s >> y;
		student[y][s]++;
	}

	int cnt = 0;

	for (int i = 1; i < 7; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			if (student[i][j] % k == 0)
				cnt += student[i][j] / k;
			else
				cnt += student[i][j] / k + 1;
		}
	}
	cout << cnt;

}
/*
성별: 여자=0/남자=1
학년: 1~6
K= 한방에 들어갈 수 있는 최대 인원수
같은 성별끼리배치 + 같은 학년끼리 배치 + 
*/
