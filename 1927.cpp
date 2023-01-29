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
	while (idx != 1) //root 노드는 1부터 시작
	{
		int parent = idx / 2;
		if (heap[parent] <= heap[idx])
			break; //부모가 더 작으면 조건을 만족하므로 생략
		swap(heap[parent], heap[idx]); //부모가 더 크므로 swap
		idx = parent;
	}
}
int root()
{
	return heap[1];
	//root 노드는 1부터 시작
}

void pop()
{
	heap[1] = heap[sz--];
	int idx = 1;
	//왼쪽 자식의 인덱스가 sz보다 크면 idx는 Leaf에 도달
	while (2 * idx <= sz) 
	{
		int left = 2 * idx;
		int right = 2 * idx + 1;
		int min_child = left; //두 자식 중 더 작은 인덱스를 담음
		if (right <= sz && heap[right] < heap[left])//오른쪽 자식 유무 확인
			min_child = right;  //오른쪽 자식이 더 작을 경우
		if (heap[idx] <= heap[min_child])
			break; //idx값이 더 작다면 생략
		swap(heap[idx], heap[min_child]); //idx값이 더 크다면 swap
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
우선, 삽입 / 삭제가 필요
x!=0 ->삽입 x==0->삭제
가장 작은 값 출력
최소힙 구현

*/