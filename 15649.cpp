#include <iostream>
using namespace std;
#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

bool isused[10];
int arr[10];
int n, m;

void bt(int k) //현재 선택한 수의 개수가 k개임
{
	if (k == m) //m개를 모두 택했으면
	{
		for (int i = 0; i < m; i++)
			cout << arr[i] << ' '; //arr에 기록해둔 수를 출력
		cout << '\n';
		return;
	}
	for (int i = 1; i <= n; i++) //1부터 n까지의 수에 대해
	{
		if (!isused[i]) //아직 i가 선택되지 않았다면
		{
			arr[k] = i; //k번째 수를 i로 정함
			isused[i] = 1; //i를 사용처리
			bt(k + 1); //다음 자리 수를 구하러감.
			isused[i] = 0; //k번째 수를 i로 정한 모든 경우에 대해 다 확인햇으니
					       //i를 다시 사용되지 않았다고 처리함.
		}
	}
}
int main(void)
{
	fastio();
	
	cin >> n >> m;

	bt(0);

	
}
/*
1~N까지 자연수 중에서 중복없이 M개를 고른 수열

*/