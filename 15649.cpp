#include <iostream>
using namespace std;
#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

bool isused[10];
int arr[10];
int n, m;

void bt(int k) //���� ������ ���� ������ k����
{
	if (k == m) //m���� ��� ��������
	{
		for (int i = 0; i < m; i++)
			cout << arr[i] << ' '; //arr�� ����ص� ���� ���
		cout << '\n';
		return;
	}
	for (int i = 1; i <= n; i++) //1���� n������ ���� ����
	{
		if (!isused[i]) //���� i�� ���õ��� �ʾҴٸ�
		{
			arr[k] = i; //k��° ���� i�� ����
			isused[i] = 1; //i�� ���ó��
			bt(k + 1); //���� �ڸ� ���� ���Ϸ���.
			isused[i] = 0; //k��° ���� i�� ���� ��� ��쿡 ���� �� Ȯ��������
					       //i�� �ٽ� ������ �ʾҴٰ� ó����.
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
1~N���� �ڿ��� �߿��� �ߺ����� M���� �� ����

*/