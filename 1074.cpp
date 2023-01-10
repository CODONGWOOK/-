#include <iostream>
using namespace std;
#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

int z(int n,int r,int c)
{
	if (n == 0) return 0;
	int half = 1 << (n - 1);
	if (r < half && c < half)
		return z(n - 1, r, c);
	else if (r < half && c >= half)
		return half * half + z(n - 1, r, c - half);
	else if (r >= half && c < half)
		return 2 * half * half + z(n - 1, r - half, c);
	else
		return 3 * half * half + z(n - 1, r - half, c - half);
}


int main(void)
{
	fastio();
	
	int n, r, c;
	cin >> n >> r >> c;
	cout<<z(n, r, c);
}
/*
0  1 4  5 
2  3 6  7
8  9 12 13
10 11 14 15
*/