#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <set>
using namespace std;
#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

bool check[1000001]; //모두 제곱ㄴㄴ수로 설정
int main(void)
{
	fastio();

	long long min, max;
	cin >> min >> max;
	int count = 0;
	for (long long i = 2; i * i <= max; i++)
	{
		long long n = min / (i * i); //몫

		if (min % (i * i) != 0) 
			n++;  
		//min영역에 n*i*i가 존재해야 하므로 나누어 몫에 1더하기
		//예) 30/4=7 7*4=28 min이 30이므로 8*4=32로 만들어줘야함

		while (n * i * i <= max) //몫*i*i가 max의 범위에 있을 때까지
		{
			check[n * i * i - min] = 1; //제곱수 설정
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
num%(i*i)!=0일 경우 제곱 ㄴㄴ수 

*/