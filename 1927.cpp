#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <set>
using namespace std;
#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

int heap[100007];
int sz = 0;

void push(int x)
{
	heap[++sz]=x;
	int idx = sz;
	while (idx != 1) //root ���� 1���� ����
	{
		int parent = idx / 2;
		if (heap[parent] <= heap[idx])
			break; //�θ� �� ������ ������ �����ϹǷ� ����
		swap(heap[parent], heap[idx]); //�θ� �� ũ�Ƿ� swap
		idx = parent;
	}
}
int root()
{
	return heap[1];
	//root ���� 1���� ����
}

void pop()
{
	heap[1] = heap[sz--];
	int idx = 1;
	//���� �ڽ��� �ε����� sz���� ũ�� idx�� Leaf�� ����
	while (2 * idx <= sz) 
	{
		int left = 2 * idx;
		int right = 2 * idx + 1;
		int min_child = left; //�� �ڽ� �� �� ���� �ε����� ����
		if (right <= sz && heap[right] < heap[left])//������ �ڽ� ���� Ȯ��
			min_child = right;  //������ �ڽ��� �� ���� ���
		if (heap[idx] <= heap[min_child])
			break; //idx���� �� �۴ٸ� ����
		swap(heap[idx], heap[min_child]); //idx���� �� ũ�ٸ� swap
		idx = min_child;
	}
}

int main(void)
{
	fastio();
	int n;
	cin >> n;
	while (n--)
	{
		int x;
		cin >> x;

		if (x != 0)
		{
			push(x);
		}
		else
		{
			if (sz == 0)
				cout << 0 << '\n';
			else 
			{
				cout << root() << '\n';
				pop();
			}
		}
	}
			
}
/*
�켱, ���� / ������ �ʿ�
x!=0 ->���� x==0->����
���� ���� �� ���
�ּ��� ����

*/