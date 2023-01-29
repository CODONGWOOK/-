#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <set>
using namespace std;
#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

bool check[1000001]; //��� ������������ ����
int main(void)
{
	fastio();

	long long min, max;
	cin >> min >> max;
	int count = 0;
	for (long long i = 2; i * i <= max; i++)
	{
		long long n = min / (i * i); //��

		if (min % (i * i) != 0) 
			n++;  
		//min������ n*i*i�� �����ؾ� �ϹǷ� ������ �� 1���ϱ�
		//��) 30/4=7 7*4=28 min�� 30�̹Ƿ� 8*4=32�� ����������

		while (n * i * i <= max) //��*i*i�� max�� ������ ���� ������
		{
			check[n * i * i - min] = 1; //������ ����
			n++;
		}
	}
	for (int i = 0; i <= max - min; i++)
	{
		if (!check[i])
			count++;
	}
	cout << count;
}
/*
num%(i*i)!=0�� ��� ���� ������ 

*/