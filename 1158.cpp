#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
using namespace std;
#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

int pre[5001];
int nxt[5001];
int main(void)
{
	fastio();
	
	int n, k;
	cin >> n >> k;

	//�Ӹ��� ������ ����ǵ��� ���� ���Ḯ��Ʈ ����
	for (int i = 1; i <= n; i++)
	{
		pre[i] = (i == 1) ? n : i - 1;
		nxt[i] = (i == n) ? 1 : i + 1;
	}
	int len = n;
	vector<int>v;
	int i = 1;
	for (int cur = 1; len != 0; cur = nxt[cur])
	{
		//���Ḯ��Ʈ�� ��ȸ�ϸ� ���� ����
		if (i == k)
		{
			pre[nxt[cur]] = pre[cur];
			nxt[pre[cur]] = nxt[cur];
			v.push_back(cur);
			i = 1;
			len--;
		}
		else
			i++;
	}
	cout << '<';
	for (size_t i = 0; i < v.size(); i++)
	{
		cout << v[i];
		if (i != v.size() - 1) cout << ", ";
	}
	cout << '>';

}
/*

1 2 3 4 5 6 7    k=3
*/
